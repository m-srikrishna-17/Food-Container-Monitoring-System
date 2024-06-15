#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// Initialize the I2C LCD with the address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2); // Adjust the address if needed (0x27 or 0x3F)

// Initialize the DHT11 sensor on pin 2
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// Define the pin for the buzzer
#define BUZZER_PIN 3

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);

  // Initialize the buzzer pin as an output
  pinMode(BUZZER_PIN, OUTPUT);

  // Display initial message
  lcd.print(" FOOD SAFETY ");
  lcd.setCursor(0, 1);
  lcd.backlight();
  lcd.print(" MONITORING_SYS ");
  delay(2000); // Show initial message for 2 seconds
  lcd.clear();

  dht.begin();
}

void loop() {
  // Read the temperature and humidity from DHT11 sensor
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Check if any reads failed and exit early to try again
  if (isnan(temperature) || isnan(humidity)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

  // Read the gas and light sensor values from analog pins
  int gas = analogRead(A1);
  int ldr = analogRead(A0);

  // Convert temperature and humidity to int for display
  int temp = static_cast<int>(temperature);
  int hum = static_cast<int>(humidity);

  // Scale LDR and gas sensor values for better display
  ldr = ldr / 10; // Assuming the LDR value needs scaling
  gas = gas / 10; // Assuming the gas value needs scaling

  // Check environmental conditions
  String alertMessage = "";
  if (temp < 13 || temp > 15) {
    alertMessage += "Temp ";
  }
  if (hum < 50 || hum > 80) {
    alertMessage += "Hum ";
  }
  if (ldr < 60 || ldr > 100) {
    alertMessage += "LDR ";
  }
  if (gas < 1 || gas > 100) {
    alertMessage += "Gas ";
  }

  // Display the sensor data on the LCD
  lcd.setCursor(0, 0);
  lcd.print("TEM ");
  lcd.print(temp);
  lcd.setCursor(8, 0);
  lcd.print("HUM ");
  lcd.print(hum);

  lcd.setCursor(0, 1);
  lcd.print("LDR ");
  lcd.print(ldr);
  lcd.setCursor(8, 1);
  lcd.print("GAS ");
  lcd.print(gas);

  // Print the sensor data to the Serial Monitor
  Serial.print("Temp: ");
  Serial.print(temp);
  Serial.print(" Hum: ");
  Serial.print(hum);
  Serial.print(" LDR: ");
  Serial.print(ldr);
  Serial.print(" Gas: ");
  Serial.println(gas);

  // Send sensor data to NodeMCU
  String data = "<" + String(temp) + "," + String(hum) + "," + String(ldr) + "," + String(gas) + ">";
  Serial.println(data);

  // Print alert message if conditions are not met and activate the buzzer
  if (alertMessage != "") {
    lcd.setCursor(0, 1);
    lcd.print("ALERT: ");
    lcd.print(alertMessage);
    Serial.print("ALERT: ");
    Serial.println(alertMessage);

    // Ring the buzzer
//    digitalWrite(BUZZER_PIN, HIGH);
//    delay(500); // Buzzer on for 500 milliseconds
//    digitalWrite(BUZZER_PIN, LOW);
//  }

  // Add a delay before the next loop iteration
  delay(2000);
}

