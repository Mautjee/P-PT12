String GetSerialMessage() {
  while (Serial.available() > 0 || ReadingSerial == true) {
    if (Serial.available() > 0) {
      String s = (String)(char) Serial.read();
      if (s == "#" && !ReadingSerial) {
        ReadingSerial = true;
      }
      else if (s == "%" && ReadingSerial) {
        ReadingSerial = false;
        return serialMessage;
      }
      else if (ReadingSerial) {
        serialMessage += s;
        //Serial.println(s);
      }
    }
  }
}
