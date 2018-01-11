void Getmessage() {
  if (Serial.available() > 0)
  {
    char input = Serial.read();
    if ('#' == input && !isReceivingMessage)
    {
      isReceivingMessage = true;
    }
    else if (isReceivingMessage)
    {
      if ('%' == input) {
        isReceivingMessage = false;
        berichtOntvangen = true;
      }
      else {
        message = message + input;
      }
    }
  }
}
void getRemoteMessage(bool remotecontrolenabled, String theMessage){
  if (remotecontrolenabled) {
    int split = theMessage.indexOf(':');

    if (split > 0)
    {
      String message = theMessage.substring(0 , split);
      int value = theMessage.substring(split + 1).toInt();
      RemoteControl(message, value);
    }
    else{
      RemoteControl(message,0);
    }
    
  }
  else {
    Serial.println("activeer eerst Remote_Control");
  }
}
void Readmessage(String theMessage) {

  if (theMessage == "REMOTE_CONTROL") {
    remotecontrolenabled =  true;
    Serial.println("Remote Control enabled");
    
  }
  else if (theMessage == "LOCAL_CONTROL") {
    LocalControl();
    remotecontrolenabled = false;
  }
  else if (theMessage == "EMERGENCY"){
        deurOpen = true;
    }
   else if (theMessage == "NORMAL_MODE"{
        deurOpen = false;
   }
  else{
    getRemoteMessage(remotecontrolenabled,theMessage);
  }

}

