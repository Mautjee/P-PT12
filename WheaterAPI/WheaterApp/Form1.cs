using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Net;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Newtonsoft.Json;

namespace WheaterApp
{
    public partial class Form1 : Form
    {
        private WheaterAPI.root api = new WheaterAPI.root();
        #region WheaterInfo
        const string APPID = "1b5d684d0770c40eccf2c841635621e2";
        string CityName = "Eindhoven";
        #endregion
        public Form1()
        {
            InitializeComponent();
            //Get Wheater and parse it into the labels
            api = GetWheater(CityName, APPID);
            PlaceLabel.Text = "Where: " + api.sys.country +" "+ api.name;
        }
        private WheaterAPI.root GetWheater(string City, string AppId)
        {
            using (WebClient web = new WebClient())
            {
                //url for the API
                string url = string.Format("http://api.openweathermap.org/data/2.5/weather?q={0}&appid={1}&untis=metric", City, AppId);
                //Get the Json file with wheater information
                var json = web.DownloadString(url);
                WheaterAPI.root output = JsonConvert.DeserializeObject<WheaterAPI.root>(json);
                return output;
                //CountryLabel.Text = string.Format("{0}", API.sys.country);
            }
        }
    }
}