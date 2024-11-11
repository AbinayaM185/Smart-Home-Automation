# Smart-Home-Automation
This smart home automation project aims to enhance home safety and comfort by integrating various sensors and actuators. The system will automatically control lights and fans based on motion detection and temperature readings, while also providing fire detection capabilities. The key components of the project include:

PIR Sensor: For motion detection to turn on lights and fans.
DHT11 Sensor: To monitor temperature and control the fan based on heat levels.
Flame Sensor: To detect fire and activate a buzzer for alerting.
Microcontroller: To process sensor data and control actuators.

Components Required: 

Microcontroller: Arduino Uno or similar
PIR Sensor: For motion detection
DHT11 Sensor: For temperature and humidity measurement
Flame Sensor: For fire detection
Buzzer: For alarm sound when fire is detected
Relay Module: To control the fan and lights
LEDs: For visual indication of system status
Resistors and Jumper Wires: For connections

Functionality

Automatic Light and Fan Control:

The PIR sensor detects motion in the room.
If motion is detected, the system turns on the lights and fan.
If no motion is detected for a specified period, the lights and fan turn off.

Temperature-Based Fan Control:

The DHT11 sensor continuously monitors the room temperature.
If the temperature exceeds a predefined threshold (e.g., 30°C), the fan is activated to cool the room.

Fire Detection and Alarm:

The flame sensor continuously checks for the presence of fire.
If a flame is detected, the buzzer is activated to alert the occupants.
