// Define the pin connected to the ESC signal wire
const int pwmPin = 18; // Adjust pin number based on your setup

// Set PWM properties
const int freq = 5000; // Frequency in Hz
const int pwmChannel = 0;
const int resolution = 8; // 8-bit resolution (0-255)

void setup() {
  // Configure the PWM functionalitites of the pin
  ledcSetup(pwmChannel, freq, resolution);
  
  // Attach the PWM channel to the GPIO pin
  ledcAttachPin(pwmPin, pwmChannel);
}

void loop() {
  int speed = 30; // Set the desired speed (0-255)
  ledcWrite(pwmChannel, speed);
  delay(100);
}
