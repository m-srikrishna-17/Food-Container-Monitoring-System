# Food-Container-Monitoring-System
The Food Container Monitoring System uses Arduino Uno, ESP8266, and sensors (DHT11, MQ3, LDR) to monitor temperature, humidity, gas, and light. Data is displayed on an LCD and sent to ThingSpeak for real-time visualization.
# Food Container Monitoring System Using IoT

This project is a Food Container Monitoring System that uses various sensors and IoT technologies to monitor and report the status of food containers. The system utilizes an Arduino Uno (Atmega328) microcontroller, an ESP8266 Wi-Fi module, and several sensors to collect data such as temperature, humidity, gas levels, and light intensity. The data is then sent to ThingSpeak for real-time visualization.

## Table of Contents

- [Overview](#overview)
- [Components](#components)
- [Circuit Diagram](#circuit-diagram)
- [Installation](#installation)
- [Usage](#usage)
- [ThingSpeak Configuration](#thingspeak-configuration)
- [Contributing](#contributing)
- [License](#license)

## Overview

The Food Container Monitoring System is designed to help keep track of the conditions inside food containers, which is crucial for maintaining food quality and safety. The system monitors:

- Temperature and Humidity (using DHT11 sensor)
- Gas levels (using MQ3 sensor)
- Light intensity (using LDR sensor)
- Displays the collected data on an LCD (I2C)

The collected data is sent to ThingSpeak, an IoT analytics platform, for visualization and further analysis.

## Components

- Arduino Uno (Atmega328)
- ESP8266 Wi-Fi Module
- DHT11 Temperature and Humidity Sensor
- MQ3 Gas Sensor
- LDR (Light Dependent Resistor) Sensor
- LCD Display (I2C)
- Breadboard and Jumper Wires
- Power Supply

## Circuit Diagram

![Circuit Diagram](path_to_circuit_diagram_image)

## Installation

1. **Clone the Repository**

   ```sh
  [ git clone https://github.com/yourusername/Food-Container-Monitoring-System.git
   cd Food-Container-Monitoring-System](https://github.com/m-srikrishna-17/Food-Container-Monitoring-System)
   ```

2. **Install Arduino IDE**

   Download and install the Arduino IDE from [here](https://www.arduino.cc/en/Main/Software).

3. **Install Required Libraries**

   Open the Arduino IDE and install the following libraries:
   - DHT Sensor Library
   - Adafruit Unified Sensor Library
   - LiquidCrystal_I2C
   - ESP8266WiFi
   - ThingSpeak

   You can install these libraries using the Library Manager in the Arduino IDE.

## Usage

1. **Connect the Hardware**

   Assemble the hardware components as per the circuit diagram.

2. **Configure the Code**

   Open the `Food_Container_Monitoring.ino` file in the Arduino IDE. Update the following sections with your specific details:

   ```cpp
   // Wi-Fi credentials
   const char* ssid = "your_SSID";
   const char* password = "your_PASSWORD";

   // ThingSpeak credentials
   const char* writeAPIKey = "your_THINGSPEAK_WRITE_API_KEY";
   const long channelID = your_THINGSPEAK_CHANNEL_ID;
   ```

3. **Upload the Code**

   Connect the Arduino Uno to your computer using a USB cable and upload the code to the Arduino board.

4. **Monitor Data**

   Once the code is uploaded and the system is powered on, it will start collecting data from the sensors and send it to ThingSpeak. You can monitor the data in real-time on your ThingSpeak channel.

## ThingSpeak Configuration

1. **Create a ThingSpeak Account**

   If you do not already have a ThingSpeak account, create one at [ThingSpeak](https://thingspeak.com/).

2. **Create a Channel**

   - Create a new channel in ThingSpeak.
   - Add fields for Temperature, Humidity, Gas Level, and Light Intensity.
   - Note down the Channel ID and Write API Key.

3. **Update the Code**

   Use the Channel ID and Write API Key in the Arduino code as shown in the [Usage](#usage) section.

## Contributing

Contributions are welcome! Please fork this repository and submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---***---***---***---***---

Feel free to reach out if you have any questions or need further assistance.

Happy Monitoring!
