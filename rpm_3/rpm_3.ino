#define SENSOR_PIN  2  // Pin connected to A3144 OUT
volatile int pulseCount = 0;
unsigned long lastTime = 0;
unsigned long rpm = 0;

void IRAM_ATTR pulseDetected() {
  pulseCount++;  // Increment pulse count on each detection
}

void setup() {
  Serial.begin(115200);
  
  pinMode(SENSOR_PIN, INPUT_PULLUP);  // Set sensor pin as input
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), pulseDetected, FALLING);  // Interrupt on falling edge of the signal

  lastTime = millis();  // Initialize lastTime for RPM calculation
}

void loop() {
  unsigned long currentTime = millis();
  
  // Every second, calculate and print the RPM
  if (currentTime - lastTime >= 1000) {
    rpm = pulseCount * 60;  // Convert pulse count to RPM
    Serial.print("RPM: ");
    Serial.println(rpm);
    pulseCount = 0;  // Reset pulse count for the next second
    lastTime = currentTime;  // Update the lastTime
  }
}
