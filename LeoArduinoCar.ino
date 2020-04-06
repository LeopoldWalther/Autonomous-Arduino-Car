//this is the source code for the home-watch-car
//libaries
#include <Servo.h> //servo library


//global variables

//definde sonar Pins
const int trigPinSonFront = A0;
const int echoPinSonFront = A1;
const int trigPinSonRear = A2;
const int echoPinSonRear = A3;

//define motor power pins
const int motorEnergyA = 5; 
const int motorEnergyB = 10; 

//define motor control pins
const int motorLeft1 = 8; //N3
const int motorLeft2 = 9; //N4
const int motorRight1 = 6; //N1
const int motorRight2 = 7; //N2

//define speed levels
const int speed10 = 100;
const int speed13 = 130;
const int speed14 = 140;
const int speed15 = 150;
const int speed18 = 180;
const int speed20 = 200;
const int speed25 = 255;

// create object of class Servo
//Servo myServo;

//variables for sonar1
long duration;
int distance;

int testeddistanceSonFront;
int testeddistanceSonRear;



void setup()
{

  // define pins as output pins
  pinMode(motorLeft1,OUTPUT);
  pinMode(motorLeft2,OUTPUT);
  pinMode(motorRight1,OUTPUT);
  pinMode(motorRight2,OUTPUT);
  
  pinMode(motorEnergyA,OUTPUT);
  pinMode(motorEnergyB,OUTPUT);
  
  digitalWrite(motorEnergyA,OUTPUT);  
  digitalWrite(motorEnergyB,OUTPUT);   

  //define trigger Pin as output and echo Pin as input
  pinMode(trigPinSonFront, OUTPUT);
  pinMode(echoPinSonFront, INPUT);
  pinMode(trigPinSonRear, OUTPUT);
  pinMode(echoPinSonRear, INPUT);
  
  // for logging messages
  Serial.begin(9600);


}
void loop()
{


  moveForeward();



  // testing sonar
  /*
  testeddistanceSonFront = calculateDistance(trigPinSonFront, echoPinSonFront);
  Serial.print("Distance to front obstacle: ");
  Serial.print(testeddistanceSonFront);
  Serial.print("     ;");

  testeddistanceSonRear = calculateDistance(trigPinSonRear, echoPinSonRear);
  Serial.print("Distance rear obstacle: ");
  Serial.println(testeddistanceSonRear);
  */

  //testing drive mode
  /*
  moveForeward();
  delay(2000);
  moveBackward();
  delay(2000);
  spinRight();
  delay(2000);
  spinLeft();
  delay(2000);
  */




}


// Functions

void moveForeward()
{
  digitalWrite(motorEnergyA,HIGH);  
  digitalWrite(motorEnergyB,HIGH);

  analogWrite(motorLeft1, speed13);
  analogWrite(motorLeft2,0);
  analogWrite(motorRight1, speed25); 
  analogWrite(motorRight2, 0);    
}

void moveBackward()
{
  digitalWrite(motorEnergyA,HIGH);  
  digitalWrite(motorEnergyB,HIGH);

  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, speed25);
  analogWrite(motorRight1, 0); 
  analogWrite(motorRight2, speed13);    
}

void spinRight()
{
  digitalWrite(motorEnergyA,HIGH);  
  digitalWrite(motorEnergyB,HIGH);

  analogWrite(motorLeft1, speed13);
  analogWrite(motorLeft2, 0);
  analogWrite(motorRight1, 0); 
  analogWrite(motorRight2, speed13);  
}

void spinLeft()
{
  digitalWrite(motorEnergyA,HIGH);  
  digitalWrite(motorEnergyB,HIGH);

  analogWrite(motorLeft1, 0);
  analogWrite(motorLeft2, speed25);
  analogWrite(motorRight1, speed25); 
  analogWrite(motorRight2, 0);  
}

int calculateDistance(int trigPin, int echoPin)
  {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);

    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10); // In order to generate the ultrasound you need to set the Trig on a High State for 10 µs. That will send out an 8 cycle sonic burst which will travel at the speed sound and it will be received in the Echo pin. The Echo pin will output the time in microseconds the sound wave traveled.
    digitalWrite(trigPin, LOW);

    duration = pulseIn(echoPin, HIGH);
    distance = duration*0.0343/2; // For example, if the object is 10 cm away from the sensor, and the speed of the sound is 340 m/s or 0.034 cm/µs the sound wave will need to travel about 294 u seconds. But what you will get from the Echo pin will be double that number because the sound wave needs to travel forward and bounce backward.  So in order to get the distance in cm we need to multiply the received travel time value from the echo pin by 0.034 and divide it by 2.

    return distance;
  }

  
