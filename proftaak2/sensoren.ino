int MeasureDistance() {
  int distance;
  int duration;

  duration = PingSonar();

  distance = duration * 0.034 / 2;
  return distance;
}

int PingSonar() {
  //clears the trigPin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  //Activate trigPin for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  //retrieve value from echoPin
  int echoTime = pulseIn(echoPin, HIGH);
  return echoTime;
}

void TempSensor(){
  int readSensor = DHT.read22(datapin);
  float temp = DHT.temperature;
  float humid = DHT.humidity;

  Serial.print("Temperatuur is: ");
  Serial.println(temp);
  Serial.print("luchtvochtigheid is: ");
  Serial.println(humid);
  Serial.println("");
}

