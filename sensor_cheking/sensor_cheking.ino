// Code by -Md. Sabbir Hasan Talukder
// Supervised by - Dr. Md. Enamul Hoque
// Final year BSC in Physics project
// Copyright - Department of Physics, SUST, Sylhet, Bangladesh
// licence - GNU GPL v3 



#define SENSOR_PIN  2  // Pin connected to A3144 OUT

void setup() {
  Serial.begin(115200);  // Start serial communication
  pinMode(SENSOR_PIN, INPUT_PULLUP);  // Set sensor pin as input
}

void loop() {
  int sensorState = digitalRead(SENSOR_PIN);  // Read the sensor state

  if (sensorState == LOW) {
    Serial.println("Magnet detected!");  // Sensor detects a magnet (output goes LOW)
  } else {
    Serial.println("No magnet detected!");  // No magnet detected (output is HIGH)
  }
  delay(500);  // Wait for half a second before checking again
}
