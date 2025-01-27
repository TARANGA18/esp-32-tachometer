const int hallSensorPin = 16;
volatile unsigned long rpmCount = 0;
unsigned long previousMillis = 0;
const unsigned long interval = 1000; // measure every second
float rpm = 0;

void IRAM_ATTR rpmCounter() {
  rpmCount++;
}

void setup() {
  Serial.begin(9600);
  pinMode(hallSensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(hallSensorPin), rpmCounter, FALLING);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    rpm = (rpmCount * 60) / (interval / 1000); // convert to RPM
    rpmCount = 0;

    Serial.print("RPM: ");
    Serial.println(rpm);
  }
}
