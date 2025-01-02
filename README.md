# Automatic-Car-Parking
Automatic Car Parking System

This project implements an automatic car parking system using Arduino, ultrasonic sensors, an LCD display, and a servo motor. The system detects cars approaching the gate and automatically opens and closes the gate based on proximity

# How It Works
The ultrasonic sensor measures the distance of an approaching car.
When the car is detected within 10 cm, the gate (servo motor) opens.
The LCD display shows the distance and gate status.
After 2 seconds, the gate automatically closes.
If no car is detected, the system displays "No Car Detected"
Setup Instructions
Clone this repository or copy the code into the Arduino IDE.
Upload the code to your Arduino board.
Assemble the circuit as per the diagram.
Power up the system and monitor car detection through the LCD display.

#Notes
Adjust the ultrasonic sensor's position to ensure accurate car detection.
The detection threshold (10 cm) can be modified in the code as needed.
Ensure the servo motor can rotate freely without obstructions.
