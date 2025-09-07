

const int emfPin = 35;   // Analog input pin connected through voltage divider
int emfValue = 0;        // Variable to store ADC reading
int threshold = 100;     // Noise threshold (adjustable)

void setup() {
  Serial.begin(115200);   // Start serial communication for monitoring
  delay(1000);
  Serial.println("ESP32 Back EMF Detector Started...");
}

void loop() {
  // Read analog value from the inductor/motor setup
  emfValue = analogRead(emfPin);

  // Check if value crosses threshold (to avoid false noise)
  if (emfValue > threshold) {
    Serial.print("Back EMF detected! ADC Value: ");
    Serial.println(emfValue);
  } else {
    Serial.println("No significant Back EMF.");
  }

  delay(200); // Small delay to make readings stable
}


}
