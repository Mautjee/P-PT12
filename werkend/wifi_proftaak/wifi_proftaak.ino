#include <dht.h>
#define datapin A3
dht DHT; //maakt dht object

//Setup motors Links
int enL = 9;
int enLPlus = 8;
int enLMin = 6;

//Setup motors Rechts
int enR = 3;
int enRPlus = 4;
int enRMin = 5;

//setup ultrasone
int trigPin = A4;
int echoPin = A5;

//setup pomp
int pompPin = A0;



String message = "";
bool berichtOntvangen = false;
String command = "";
int value = 0;
bool isReceivingMessage = false;


const char ssid[] = "Joseph.Phone";
const char pass[] = "2keerjoe";

#include <WiFi.h>
#include <PubSubClient.h>

void callback(char* topic, byte* payload, unsigned int length) {
  // handle message arrived
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Getmessage((char)payload[i]);
  }
  Serial.println();
}

WiFiClient net;
PubSubClient client("eijsenring.com", 1883, callback, net);

unsigned long lastMillis = 0;

void serialwrite(String writeline)
{
  if (Serial.available() > 0) {
    Serial.println(writeline);
  }
}


void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, pass);

  //  client.setServer("eijsenring.com", 1883);
  //  client.setCallback(messageReceived);
  connect();


  pinMode(enL, OUTPUT);
  pinMode(enLPlus, OUTPUT);
  pinMode(enLMin, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(enRPlus, OUTPUT);
  pinMode(enRMin, OUTPUT);

  //ultrasone setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(pompPin, OUTPUT);

}

void connect() {
  Serial.print("checking wifi...");
  while (WiFi.status() != WL_CONNECTED) {
    serialwrite(".");
    delay(1000);
  }

  Serial.print("\nconnecting...");
  while (!client.connect("arduino", "try", "try")) {
    serialwrite(".");
    delay(1000);
  }

  Serial.println("\nconnected!");

  client.subscribe("PT12");
  client.subscribe("PT12/arduino/Drive_controls");
  // client.unsubscribe("/hello");
}

void loop() {
  client.loop();

  if (!client.connected()) {
    connect();
  }

  if (berichtOntvangen) {
    Readmessage(message);
    Serial.println(message);
    berichtOntvangen = false;
    message = "";
  }

  //  // publish a message roughly every second.
  //  if (millis() - lastMillis > 1000) {
  //    lastMillis = millis();
  //    client.publish("/hello", "world");
  //  }


  //Testing purposes
  int distance = MeasureDistance();

  Serial.println(distance);
  Timer(5000);
  Serial.println(" ");

  //End testing puproses
}


