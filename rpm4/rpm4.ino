#define SENSOR_PIN 21  // Pin connected to A3144 OUT

volatile unsigned long pulseCount = 0;  // Counts the number of pulses
unsigned long lastTime = 0;             // Stores last time RPM was calculated
unsigned long rpm = 0;                  // Stores calculated RPM

// This function is triggered every time the sensor detects a magnet (falling edge)
void IRAM_ATTR pulseDetected() {
  pulseCount++;
}

void setup() {
  Serial.begin(115200);

  pinMode(SENSOR_PIN, INPUT_PULLUP);  // Set pin as input with internal pull-up resistor
  attachInterrupt(digitalPinToInterrupt(SENSOR_PIN), pulseDetected, FALLING);  // Trigger on falling edge

  lastTime = millis();  // Initialize the timer
}

void loop() {
  unsigned long currentTime = millis();

  // Calculate RPM every 1 second (1000 milliseconds)
  if (currentTime - lastTime >= 1000) {
    noInterrupts();  // Temporarily disable interrupts to safely access pulseCount
    unsigned long count = pulseCount;
    pulseCount = 0;   // Reset pulse count
    interrupts();     // Re-enable interrupts

    rpm = count * 60;  // 1 pulse per revolution -> 60 pulses per minute = RPM

    Serial.print("RPM: ");
    Serial.println(rpm);

    lastTime = currentTime;
  }
}
