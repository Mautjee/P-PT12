void RemoteControl(String message, int value) {
  if (message == "LEDGROEN") {
    if (value > 0) {
      digitalWrite(ledGroen, HIGH);
      Serial.println("LED is aan");
    }
    else {
      digitalWrite(ledGroen, LOW);
      Serial.println("LED is UIT");
    }
  }
  if (message == "D"){
    
  }
}

void LocalControl() {
  {
    Serial.println("Local control enabled");
  }
}
