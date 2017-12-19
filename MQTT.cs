using System;
using System.Collections.Generic;
using System.Linq;
using System.Reflection;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using uPLibrary.Networking.M2Mqtt;
using uPLibrary.Networking.M2Mqtt.Messages;

namespace Classes
{
    class MQTT
    {
        public string ip;
        public int port;
        private string formdetails;
        private string returnmethode;


        MqttClient client = null;

        public MQTT(string getformdetails, string returnmethode)
        {
            //this.getnamespace = setnamespace + ".";
            this.formdetails = getformdetails;
            this.returnmethode = returnmethode;
        }

        public void setup_mqtt_server(string server_adress, int server_port)
        {

            try
            {
                client = new MqttClient(server_adress, Convert.ToInt32(server_port), false, null, null, MqttSslProtocols.None);
                client.MqttMsgPublishReceived += server_MqttMsgPublishReceived;
                string clientId = Guid.NewGuid().ToString();
                client.Connect(clientId);
                MessageBox.Show("Connected");
            }
            catch (Exception a)
            {
                MessageBox.Show("Could not connect to server: " + Environment.NewLine + "'" + a.Message + "'");
            }
        }

        public void server_MqttMsgPublishReceived(object sender, MqttMsgPublishEventArgs e)
        {
            string got_ontopic = e.Topic;
            string got_message = Encoding.UTF8.GetString(e.Message);
            //MessageBox.Show("got: '" + got_message + "' on topic: '" + got_ontopic + "'");

            var form = Activator.CreateInstance(Type.GetType(formdetails)) as Form;
            form.GetType().GetMethod(returnmethode).Invoke(form, new[] { e.Topic, Encoding.UTF8.GetString(e.Message) });

            //frm.getmessage(e.Topic, Encoding.UTF8.GetString(e.Message));
        }

        public void send_message(string topic, string message)
        {
            client.Publish(topic, // topic
                                 Encoding.UTF8.GetBytes(message), // message body
                                 MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE, // QoS level
                                 true); // retained
        }

        public void subscribe(string[] topic)
        {
            client.Subscribe(topic, new byte[] { MqttMsgBase.QOS_LEVEL_EXACTLY_ONCE });
        }

        public void unsubscribe(string[] topic)
        {
            client.Unsubscribe(topic);
        }
    }
}
