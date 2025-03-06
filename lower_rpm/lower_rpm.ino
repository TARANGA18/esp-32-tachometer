#define ESC_PIN 18  // Use a PWM-capable pin

void setup() {
  ledcAttachPin(ESC_PIN, 0); // Attach ESC to channel 0
  ledcSetup(0, 50, 16);      // 50 Hz PWM, 16-bit resolution
  
  delay(2000); // Wait for ESC to initialize

  // Send minimum throttle (adjust if needed)
  ledcWrite(0, 3276); // ~5% duty cycle (1000us pulse for min speed)
}

void loop() {
  // Set throttle (adjust for desired speed)
  ledcWrite(0, 8192); // ~25% duty cycle (1500us pulse for mid speed)
  delay(5000);

  ledcWrite(0, 4915); // Lower throttle
  delay(5000);
}
