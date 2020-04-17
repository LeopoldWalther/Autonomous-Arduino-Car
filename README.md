# Autonomous-Arduino-Car
This project is about developing a script for controlling a 4-wheeled Arduino
car to move autonomous through unknown territory.

## Quickstart
This script is designed for an Arduino with four electric motors and two sonar
sensors, pinned as following:
-   trigger Pin Sonar Front = A0
-   echo Pin Sonar Front = A1
-   trigger Pin Sonar Rear = A2
-   echo Pin Sonar Rear = A3
-   motor power pin A = 5
-   motor powet pin B = 10
-   motor control pin left1 = 8 //N3
-   motor control pin left2 = 9; //N4
-   motor control pin right1 = 6; //N1
-   motor control pin right2 = 7; //N2

## Structure
Defined functions:
- void moveForeward()
- void moveBackward()
- void spinRight()
- void spinLeft()
- int calculateDistance(int trigPin, int echoPin)

## Dependencies

servo library: <Servo.h>

## Known Bugs
* Currently the differences in resistance of the four motors make it difficult
  to control the car precisely, it moves not completely straight when all
  motors are given same power.
