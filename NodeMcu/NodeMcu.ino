#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>
#include <EMailSender.h>

// WiFi credentials
const char* ssid = "rangan";
const char* password = "EdaMone0";

// Email credentials
const char* smtpUser = "srikrishna0017@gmail.com"; // Sender's email address
const char* smtpPassword = "spie iund zlcq ihak"; // Sender's email app-specific password
const char* myEmail = "srikrishna0017@gmail.com";
const char* smtpServer = "smtp.gmail.com";
const uint16_t smtpPort = 465;
const char* recipientEmail = "srikrishna.m2022ece@sece.ac.in"; // Recipient's email address

// ThingSpeak credentials
unsigned long myChannelNumber = 2566841; // Your ThingSpeak channel number
const char* myWriteAPIKey = "B4HPTXL4Y0Q3KGUZ";

// Client and email sender initialization
WiFiClient client;
EMailSender emailSender(smtpUser, smtpPassword, myEmail, smtpServer, smtpPort);

void setup() {
  Serial.begin(9600);
  Serial.println("Starting setup...");

  // Initialize WiFi connection
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected");

  // Initialize ThingSpeak
  ThingSpeak.begin(client);
  Serial.println("ThingSpeak client started");
}

void loop() {
  if (Serial.available() > 0) {
    String data = Serial.readStringUntil('\n');
    data.trim(); // Remove any trailing newline characters

    Serial.println("Received data: " + data); // Debugging

    // Parse the received data
    int tempIndex = data.indexOf('<') + 1;
    int humIndex = data.indexOf(',', tempIndex);
    int ldrIndex = data.indexOf(',', humIndex + 1);
    int gasIndex = data.indexOf(',', ldrIndex + 1);
    int endIndex = data.indexOf('>', gasIndex + 1);

    if (tempIndex > 0 && humIndex > 0 && ldrIndex > 0 && gasIndex > 0 && endIndex > 0) {
      String tempStr = data.substring(tempIndex, humIndex);
      String humStr = data.substring(humIndex + 1, ldrIndex);
      String ldrStr = data.substring(ldrIndex + 1, gasIndex);
      String gasStr = data.substring(gasIndex + 1, endIndex);

      Serial.println("Parsed data - Temp: " + tempStr + ", Hum: " + humStr + ", LDR: " + ldrStr + ", Gas: " + gasStr); // Debugging

      int temp = tempStr.toInt();
      int hum = humStr.toInt();
      int ldr = ldrStr.toInt();
      int gas = gasStr.toInt();

      // Debugging parsed values
      Serial.println("Parsed int values - Temp: " + String(temp) + ", Hum: " + String(hum) + ", LDR: " + String(ldr) + ", Gas: " + String(gas));

      // Send the data to ThingSpeak
      ThingSpeak.setField(1, temp);
      ThingSpeak.setField(2, hum);
      ThingSpeak.setField(3, ldr);
      ThingSpeak.setField(4, gas);

      int x = ThingSpeak.writeFields(myChannelNumber, myWriteAPIKey);
      if (x == 200) {
        Serial.println("Channel update successful.");
      } else {
        Serial.println("Problem updating channel. HTTP error code " + String(x));
      }

      // Check conditions and send email alert if not satisfied
      if (temp < 24 || temp > 30 || hum < 50 || hum > 70 || ldr < 60 || ldr > 100 || gas < 20 || gas > 200) {
        sendEmailAlert(temp, hum, ldr, gas);
      }
    } else {
      Serial.println("Data parsing error");
    }
  }
}

void sendEmailAlert(int temp, int hum, int ldr, int gas) {
  EMailSender::EMailMessage message;
  message.subject = "Environmental Condition Alert";
  message.message = "Temperature: " + String(temp) + "°C\n"
                    "Humidity: " + String(hum) + "%\n"
                    "Light Intensity (LDR): " + String(ldr) + "\n"
                    "Gas Level: " + String(gas) + "\n"
                    "\n"
                    "One or more environmental conditions are not within the optimal range.";

  EMailSender::Response resp = emailSender.send(recipientEmail, message);

  if (resp.status == true) {
    Serial.println("Email alert sent successfully");
  } else {
    Serial.println("Failed to send email alert. Error: " + resp.code + " - " + resp.desc);
  }
}

