
const int analogInPin = A0;

int sensorValue = 0;

void printSensor(int sensorV) {
  char buffer[40];
  sprintf(buffer,"Sensor = %d",sensorV);
  Serial.println(buffer);
}

void setup() {
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  printSensor(sensorValue);
}
