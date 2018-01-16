void RemoteControl(String inmessage, int value) {
  if (inmessage == "DRIVE_FORWARD") {
    if (value > 0) {
      serialwrite("driving forward: "); serialwrite(String(value)); serialwrite("");
      Rechtdoor(value);
    }
    else {
      serialwrite("Wrong commando");
    }
  }
  else if (inmessage == "DRIVE_BACKWARD") {
    if (value > 0) {
      serialwrite("driving back: "); serialwrite(String(value)); serialwrite("");
    }
    else {
      serialwrite("Wrong commando");
    }
  }
  else if (inmessage == "TURN_LEFT") {
    if (value > 0) {
      serialwrite("driving back: "); serialwrite(String(value)); serialwrite("");
      Links(value);
    }
    else {
      serialwrite("Wrong commando");
    }
  }
  else if (inmessage == "TURN_RIGHT") {
    if (value > 0) {
      serialwrite("driving back: "); serialwrite(String(value)); serialwrite("");
      Rechts(value);
    }
    else {
      serialwrite("Wrong commando");
    }
  }
  else if (inmessage == "PUMP_ON") {
    if (value > 0) {
      serialwrite("Pomp aan ");serialwrite("");
      analogWrite(pompPin, HIGH);
    }
    else {
      serialwrite("Wrong commando");
    }
  }
  else if (inmessage == "PUMP_OFF") {
    if (value > 0) {
      serialwrite("Pomp uit ");serialwrite("");
      analogWrite(pompPin, LOW);
    }
    else {
      serialwrite("Wrong commando");
    }
  }
}
