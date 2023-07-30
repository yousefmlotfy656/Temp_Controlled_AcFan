Arduino Temperature Controlled Fan with Serial Monitor (Using TMP36 Temperature Sensor)
This Arduino project demonstrates a temperature-controlled fan system. The system uses a TMP36 analog temperature sensor to measure the room temperature. Based on the temperature readings, the Arduino board adjusts the fan speed to maintain a comfortable environment. The status of the temperature and fan speed is displayed on the Serial Monitor of your computer.

Components Required
Arduino UNO board
TMP36 analog temperature sensor
5V relay module
Transistor for fan speed control
Fan (or any other AC home appliance)
Connecting wires
Circuit Diagram
The circuit connections for the temperature-controlled fan system with display on the Serial Monitor are as follows:

TMP36 Temperature Sensor:

VCC to 5V
GND to GND
Output pin to Arduino analog pin A0
Fan Speed Control:

PWM pin (fan speed control) to Arduino digital pin 9
Transistor Base pin to GND (through a suitable resistor, e.g., 220Ω)
Transistor Emitter pin to GND
Transistor Collector pin to PWM pin of the fan
5V Relay Module:

VCC to 5V
GND to GND
Signal pin to Arduino digital pin 9
Working Principle
The temperature-controlled fan system reads the ambient temperature using the TMP36 analog temperature sensor. The temperature reading is then displayed on the Serial Monitor of your computer. Based on the temperature value, the Arduino adjusts the fan speed to maintain the desired temperature range.

How It Works
The system initializes by setting up the TMP36 temperature sensor pin, the relay for fan speed control, and starting the fan at 100% speed in the setup() function.

In the loop() function, the TMP36 temperature sensor is read using the analogRead() function.

The sensor value is converted to voltage, and then the temperature in Celsius is calculated based on the TMP36 sensor's characteristics.

The temperature value is compared with a minimum threshold temperature (tempmin), and the fan speed is adjusted accordingly using PWM.

If the temperature is below the tempmin value (set to 26°C in this project), the fan is turned off completely.

If the temperature is above the tempmin value, the fan speed increases linearly from 0% to 100% as the temperature increases from the tempmin value to 40°C.

The fan speed is adjusted using PWM to control the transistor that controls the power to the fan.

The temperature and fan speed percentage are displayed on the Serial Monitor of your computer.

Usage
Connect all the components as per the provided circuit diagram.

Upload the Arduino code to the board.

Connect the Arduino board to your computer using a USB cable.

Open the Arduino IDE and open the Serial Monitor (Tools > Serial Monitor).

The Serial Monitor will display the current temperature in Celsius and the corresponding fan speed percentage.

Observe how the fan speed changes based on the temperature readings to maintain a comfortable environment.

This temperature-controlled fan system with display on the Serial Monitor can be extended to control other home appliances based on the room temperature, making it a part of a smart home automation setup. It offers a simple and efficient solution for maintaining a comfortable living space without the need for manual intervention.