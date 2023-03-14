// constants won't change. Used here to set a pin number:

const int NUMLEDS = 4;
const int greenLed[NUMLEDS] = { 12, 11, 10, 9 };
const int redLed1 = 7;
const int redLed2 = 6;
const int analogInPin = A0;

unsigned long lastLEDChange[NUMLEDS];
const long interval = 200;  // interval at which to blink (milliseconds)

int sensorValue = 0;
const int sensorThreshold = 50;


void printGreenState() {
  char buffer[200];
  sprintf(buffer,
          "LED States (%d, %d, %d, %d); led Timings (%d, %d, %d, %d)",
          digitalRead(greenLed[0]), digitalRead(greenLed[1]), digitalRead(greenLed[2]), digitalRead(greenLed[3]),
          lastLEDChange[0], lastLEDChange[1], lastLEDChange[2], lastLEDChange[3]);
  Serial.println(buffer);
}

void printSensor(int sensorV) {
  char buffer[40];
  sprintf(buffer,"Sensor = %d",sensorV);
  Serial.println(buffer);
}

// Serial.print("sensor = ");
// Serial.print(sensorValue);
// Serial.print("\t output = ");
// Serial.println(outputValue);

void flipGreenLed(int led) {
  unsigned long t = millis();
  unsigned long elapsed = t - lastLEDChange[led];
  if (elapsed >= (interval * 2)) {
    lastLEDChange[led] = t;                                    //stores the millis value in the selected array
    digitalWrite(greenLed[led], !digitalRead(greenLed[led]));  //changes led state
  }
}

void greenOff() {
  for (int i = 0; i < NUMLEDS; i++) {
    digitalWrite(greenLed[i], LOW);  //changes led state
  }
}

void greenInit() {
  for (int i = 0; i < NUMLEDS; i++) {
    if (i % 2 == 0) {
      digitalWrite(greenLed[i], HIGH);
    } else {
      digitalWrite(greenLed[i], LOW);
    }
  }
}

void setRedLeds(int state){
  digitalWrite(redLed1, state);
  digitalWrite(redLed2, state);
}



void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);

  for (int i = 0; i < NUMLEDS; i++) {
    pinMode(greenLed[i], OUTPUT);
    lastLEDChange[i] = 0;
  }
  greenInit();
  setRedLeds(LOW);
}

void loop() {
  sensorValue = analogRead(analogInPin);
  printSensor(sensorValue);
  if (sensorValue < sensorThreshold) {
    greenOff();
    setRedLeds(HIGH);
    delay(2000);
    setRedLeds(LOW);  
    greenInit();      
  } 
  for (int i = 0; i < NUMLEDS; i++) {
    flipGreenLed(i);
  }
  

}
