const int pwmPin = 5; // PWM pin to ESC

void setup() {
  ledcSetup(0, 50, 16);     // 50Hz PWM, 16-bit resolution
  ledcAttachPin(pwmPin, 0);

  // Arm ESC at 1000 µs
  ledcWrite(0, usToDuty(1000));
  delay(3000); // ESC arming time

  // Ramp up slowly from 1000 to 1150 µs
  for (int pulse = 1000; pulse <= 1150; pulse++) {
    ledcWrite(0, usToDuty(pulse));
    delay(100); // ~1.5 seconds total
  }

  // Now hold at 1150 µs (approx. 300 RPM)
  ledcWrite(0, usToDuty(1100));
}

void loop() {
  // Keep running at 1150 µs
  delay(1000);
}

int usToDuty(int us) {
  return map(us, 1000, 2000, 3276, 6553);  // for 16-bit PWM
}
