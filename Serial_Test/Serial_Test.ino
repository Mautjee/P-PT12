9String message = "";
bool berichtOntvangen = false;
String command = "";
int value = 0;

bool isReceivingMessage = false;
bool remotecontrolenabled = false;
bool deurOpen = false;
String _message;

const int ledGroen = 2;
const int ledRood = 3;
const int buttonPress = 4;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);

  pinMode(ledGroen, OUTPUT);
  pinMode(ledRood, OUTPUT);
  pinMode(buttonPress, INPUT);

  
}

void loop() {
  // put your main code here, to run repeatedly:
  if (berichtOntvangen) {
    Readmessage(message);
    //Serial.println(message);
    berichtOntvangen = false;
    message = "";
  }
  else if (!berichtOntvangen) {
    Getmessage();
  }

  if(deurOpen){
      digitalWrite(ledGroen, HIGH);
      digitalWrite(ledRood, LOW);
    }
    else{
        digitalWrite(ledRood, HIGH);
        digitalWrite(ledGroen, LOW);
      }
  
}
