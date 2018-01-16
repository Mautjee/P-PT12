unsigned long newMillisec;
bool timer = false;
int i = 0;

void Rechtdoor(int runTime) {

  while (!timer) {

    digitalWrite(enLPlus, HIGH);
    digitalWrite(enLMin, LOW);
    digitalWrite(enRPlus, HIGH);
    digitalWrite(enRMin, LOW);
    analogWrite(enL, 200);
    analogWrite(enR, 220);

    Timer(runTime);

  }
  serialwrite("Done");
  digitalWrite(enL, 0);
  digitalWrite(enR, 0);
  timer = false; //reset bool timer

}

void Rechts(int runTime) {

  while (!timer) {

    digitalWrite(enLPlus, HIGH);
    digitalWrite(enLMin, LOW);
    digitalWrite(enRPlus, LOW);
    digitalWrite(enRMin, HIGH);
    analogWrite(enL, 200);
    analogWrite(enR, 200);

    Timer(runTime);

  }
  serialwrite("Done");
  analogWrite(enL, 0);
  analogWrite(enR, 0);
  timer = false; //reset bool timer
}

void Links(int runTime) {

  while (!timer) {

    digitalWrite(enLPlus, LOW);
    digitalWrite(enLMin, HIGH);
    digitalWrite(enRPlus, HIGH);
    digitalWrite(enRMin, LOW);
    analogWrite(enL, 200);
    analogWrite(enR, 200);

    Timer(runTime);

  }
  serialwrite("Done");
  analogWrite(enL, 0);
  analogWrite(enR, 0);
  timer = false; //reset bool timer
}

void stopdriving()
{
  
}

void Timer(int runTime) {
  unsigned long thisMillisec = millis();
  if (thisMillisec - newMillisec > runTime) {
    serialwrite(String(thisMillisec));
    newMillisec = thisMillisec;
    timer = true; //exit the while loop when thisMillisec hits runTime
  }
}
