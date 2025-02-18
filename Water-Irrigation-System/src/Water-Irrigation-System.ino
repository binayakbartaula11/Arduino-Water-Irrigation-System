// Pin definitions
const int relayPin = 3;        // Pin controlling the relay
const int soilSensorPin = 6;   // Pin reading the soil moisture sensor
bool waterStatus;              // Variable to store the water status (dry or wet)

// Setup function runs once when the program starts
void setup() {
  pinMode(relayPin, OUTPUT);    // Set relayPin as output to control the relay
  pinMode(soilSensorPin, INPUT); // Set soilSensorPin as input to read the moisture sensor
}

// Loop function runs continuously
void loop() {
  waterStatus = digitalRead(soilSensorPin);  // Read the soil moisture sensor value
  
  // If the soil is dry (LOW), turn the relay ON to water the plant, otherwise turn it OFF
  digitalWrite(relayPin, (waterStatus == LOW) ? HIGH : LOW);

  delay(400);  // Wait for 400 milliseconds before the next reading
}
