#include <dht.h> //dht library voor de temperatuur-luchtvochtigheidssensor
#define datapin 5
dht DHT; //maakt dht object

//Setup motors Links
int enL = 11;
int enLPlus = 13;
int enLMin = 12;

//Setup motors Rechts
int enR = 10;
int enRPlus = 8;
int enRMin = 7;

//setup ultrasone
int trigPin = 3;
int echoPin = 2;

void setup() {
  Serial.begin(9600);
  //motor setup
  pinMode(enL, OUTPUT);
  pinMode(enLPlus, OUTPUT);
  pinMode(enLMin, OUTPUT);
  pinMode(enR, OUTPUT);
  pinMode(enRPlus, OUTPUT);
  pinMode(enRMin, OUTPUT);

  //ultrasone setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
}

void loop()
{
Rechts(30000);


}
