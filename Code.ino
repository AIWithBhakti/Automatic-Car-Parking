#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27, 20, 4); // Adjust the address as needed
Servo myServo;

const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 6;

void setup() {
  lcd.begin(16,2);
  lcd.backlight();
  myServo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  
  lcd.setCursor(0, 0);
  lcd.print("Car Parking Sys");
  delay(2000);
  lcd.clear();
}

void loop() {
  long duration, distance;

  // Trigger the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * 0.034) / 2; // Calculate distance in cm

  // Display distance on LCD
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance);
  lcd.print(" cm     "); // Extra spaces to clear previous characters

  // Check if the distance is less than a threshold (e.g., 10 cm)
  if (distance < 10) {
    lcd.setCursor(0, 1);
    lcd.print("Car Detected!   ");
    myServo.write(90); // Open the gate
    delay(2000); // Keep the gate open for 2 seconds
    myServo.write(0); // Close the gate
    lcd.setCursor(0, 2);
    lcd.print("Gate Closed!    ");
  } else {
    lcd.setCursor(0, 1);
    lcd.print("No Car Detected  ");
  }

  delay(500); // Delay before the next reading
}
