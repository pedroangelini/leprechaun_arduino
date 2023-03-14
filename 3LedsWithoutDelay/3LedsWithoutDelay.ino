// constants won't change. Used here to set a pin number:

const int NUMLEDS = 4;

const int greenLed[NUMLEDS] = { 13, 12, 11, 10 };
unsigned long lastLEDChange[NUMLEDS];
const long interval = 200;  // interval at which to blink (milliseconds)


void setup() {
  long t = millis();
  for (int i = 0; i < NUMLEDS; i++) {
    pinMode(greenLed[i], OUTPUT);
    digitalWrite(greenLed[i], LOW);
    lastLEDChange[i] = 0;
  }

}

void loop() {
  for (int i = 0; i < NUMLEDS; i++) {
    flipLed(i);
  }
}



void flipLed(int led) {
  unsigned long t = millis();
  unsigned long elapsed = t - lastLEDChange[led];
  if ( elapsed >= (interval * 2)) {

    lastLEDChange[led] = t;  //stores the millis value in the selected array

    digitalWrite(greenLed[led], !digitalRead(greenLed[led]));  //changes led state
  }
}
