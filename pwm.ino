// Code by -Md. Sabbir Hasan Talukder
// Supervised by - Dr. Md. Enamul Hoque
// Final year BSC in Physics project
// Copyright - Department of Physics, SUST, Sylhet, Bangladesh
// licence - GNU GPL v3


#define PWM_PIN 18
#define PWM_CHANNEL 0
#define PWM_FREQ 50
#define PWM_RES 16

void setup() {
  ledcSetup(PWM_CHANNEL, PWM_FREQ, PWM_RES);
  ledcAttachPin(PWM_PIN, PWM_CHANNEL);
}

void loop() {
  // Ramp from 1000 to 1040 microseconds for very low speed
  for (int us = 1000; us <= 1040; us++) {
    int duty = map(us, 1000, 2000, 3276, 6553); // 5% to 10% duty cycle range
    ledcWrite(PWM_CHANNEL, duty);
    delay(50);  // slower ramp for smooth control
  }

  // Hold at max throttle (1040 µs)
  int maxDuty = map(1040, 1000, 2000, 3276, 6553);
  ledcWrite(PWM_CHANNEL, maxDuty);

  // Infinite hold
  while (true) {
    delay(1000);
  }
}
