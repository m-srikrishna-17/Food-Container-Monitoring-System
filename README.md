# Food Container Monitoring System

## Overview
This project implements a food container monitoring system using IoT to ensure the quality and safety of stored food items. The system utilizes an Arduino Uno (Atmega328) and an ESP8266 module to collect data from various sensors and transmit it to ThinkSpeak for data visualization. Alerts are sent via email when certain conditions are met.

## Table of Contents
1. [Overview](#overview)
2. [Hardware Components](#hardware-components)
3. [Software Components](#software-components)
4. [Installation and Setup](#installation-and-setup)
    - [Hardware Setup](#hardware-setup)
    - [Software Setup](#software-setup)
5. [Usage](#usage)
6. [Troubleshooting](#troubleshooting)
7. [License](#license)
8. [Acknowledgements](#acknowledgements)


## Hardware Components
- **Arduino Uno (Atmega328)**
- **ESP8266 Wi-Fi Module**
- **DHT11 Temperature and Humidity Sensor**
- **MQ3 Alcohol Sensor**
- **LDR (Light Dependent Resistor)**
- **LCD Display with I2C Interface**

## Software Components
- **Arduino IDE**
- **ThinkSpeak API**
- **SMTP Library for Email Alerts**

## Installation and Setup

### Hardware Setup
1. **Connect the DHT11 Sensor:**
   - VCC to 5V
   - GND to GND
   - Data to Digital Pin 2

2. **Connect the MQ3 Sensor:**
   - VCC to 5V
   - GND to GND
   - Analog Output to Analog Pin A0

3. **Connect the LDR:**
   - One end to 5V
   - The other end to a voltage divider resistor to GND and the junction to Analog Pin A1

4. **Connect the LCD with I2C Interface:**
   - SDA to A4
   - SCL to A5
   - VCC to 5V
   - GND to GND

5. **Connect the ESP8266:**
   - VCC to 3.3V (Ensure you have a 3.3V regulator if using 5V Arduino)
   - GND to GND
   - TX to RX of Arduino (through a voltage divider if necessary)
   - RX to TX of Arduino (through a voltage divider if necessary)
   - CH_PD to 3.3V

### Software Setup
Clone the Repository:

```
git clone https://github.com/m-srikrishna-17/Food-Container-Monitoring-System
cd Food-Container-Monitoring-System
```

1. **Arduino IDE:**
   - Download and install the Arduino IDE from [Arduino Website](https://www.arduino.cc/en/software).
   - Install required libraries:
     ```plaintext
     - DHT Sensor Library
     - Adafruit Unified Sensor Library
     - ESP8266WiFi
     - ThinkSpeak
     - LiquidCrystal_I2C
     - SMTPClient
     ```

2. **ThinkSpeak:**
   - Create an account on [ThinkSpeak](https://thingspeak.com/).
   - Create a new channel and note down the Write API Key.

3. **Email Setup:**
   - Use an email service that allows SMTP (e.g., Gmail).
   - Enable "Allow less secure apps" if using Gmail for testing purposes.

## Usage
1. **Upload the Code:**
   - Connect your Arduino to your computer and upload the code.
   - Ensure the serial monitor is set to 9600 baud rate to check the debug messages.

2. **Monitor Data:**
   - Open ThinkSpeak and navigate to your channel to visualize the data.
   - Check your email for alerts if conditions are met.

## Troubleshooting
- Ensure all sensor connections are correct.
- Verify WiFi credentials and network stability.
- Check the ThinkSpeak API key and channel ID.
- Make sure the email service allows SMTP and the credentials are correct.

## License
This project is licensed under the MIT License - see the LICENSE file for details.

## Acknowledgements
- [Arduino](https://www.arduino.cc/)
- [ThinkSpeak](https://thingspeak.com/)
- [DHT11 Library](https://github.com/adafruit/DHT-sensor-library)
- [LiquidCrystal I2C Library](https://github.com/johnrickman/LiquidCrystal_I2C)
- [ESP8266WiFi Library](https://github.com/esp8266/Arduino)
- [SMTPClient Library](https://github.com/khoih-prog/SMTPClient)

---

## License
This project is licensed under the MIT License. See the LICENSE file for more details.

---
