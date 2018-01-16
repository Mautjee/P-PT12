void Getmessage(char input) {
  if ('#' == input && !isReceivingMessage)
  {
    isReceivingMessage = true;
  }
  else if (isReceivingMessage)
  {
    if (';' == input) {
      isReceivingMessage = false;
      berichtOntvangen = true;
    }
    else {
      message = message + input;
    }
  }

}
void getRemoteMessage(String theMessage) {

  int split = theMessage.indexOf(':');

  if (split > 0)
  {
    String message = theMessage.substring(0 , split);
    int value = theMessage.substring(split + 1).toInt();
    RemoteControl(message, value);
  }
  else {
    RemoteControl(message, 0);
  }

}
