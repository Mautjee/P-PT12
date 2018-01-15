String message;
char readChar;
bool command = false;

void receiveMessage() {
  uint8_t buf[RH_ASK_MAX_MESSAGE_LEN];
  uint8_t buflen = sizeof(buf);

  if (driver.recv(buf, &buflen)) {
    int i;

    for (int i = 0; i < buflen; i++) {
      readChar = (char)buf[i];
    }
    
    if (readChar == '#' || command == true) {
      command = true;
      message += readChar;
      if (readChar == '%') {
        command = false;
        Serial.println(message);
        message = "";
      }
    }
  }
}

void convertSerial(String text) {
  if (text.indexOf("FORWARD") > 0) {
    // String contains FORWARD
  }else if(text.indexOf("BACKWARD") > 0){
  }else if(text.indexOf("LEFT") > 0){
  }else if(text.indexOf("RIGHT") > 0){
  }else if(text.indexOf("STRAIGHT") > 0){
  }else if(text.indexOf("BACKWARD") > 0){
    // CHECK / set speed
  }
}
