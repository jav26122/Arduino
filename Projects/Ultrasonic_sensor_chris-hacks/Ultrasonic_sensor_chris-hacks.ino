/*
   Ultrasonic Sensor reading in Inches
*/


#include <Servo.h>
// #include <SoftwareSerial.h>

Servo myservo;  // create servo object to control a servo
int pos = 0;    // variable to store the servo position
const int trigPin = 10;
const int echoPin = 12;
long duration;
int distanceInch;
int i;

int enA = 6;  // LEFT motor 
int in1 = 0; 
int in2 = 1; 

int enB = 5; // RIGHT motor
int in3 = 2;
int in4 = 3; 

int forward; //1=wheels move forward, 0=reverse
int backward;

void setup()
{
  pinMode(13, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);  // chris print statements


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);



 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
//  int counter = 0;
//  int iterator = 5;
//  int Distances[iterator];
//  int Angles[iterator];
//  int largestDistance = 0;
//  for(int i = 0; i < 255; i += (255 / iterator))
//  {
//    myservo.write(i);
//    delay(500);
//    Distances[counter] = GetObjectDistance();
//    Angles[counter] = i;
//    ++counter;
//   }
//
//   for (int i=0; i < iterator; ++i)
//   {
//      if (Distances[i] > Distances[largestDistance])
//      {
//        largestDistance = i;   
//      }
//      
//   }
//
//  Serial.println(largestDistance);
//  Serial.println(Distances[largestDistance]);
right_only(200, 1);

} // End of Loop

//*************************************************

//*********** My Custom Functions *****************
//*************************************************

// Read ultrasonic sensor and convert object distance to inches


int GetObjectDistance (void)
{
  // for (int thiscount = 1; thiscount < 5; thiscount++)
    int distanceToObject;


  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  // distanceToObject = duration*0.0133/2;
  distanceToObject = duration * 0.00665;
  return distanceToObject;

}


// Flash LED once for each inch of distance to object

void flashNumInches(int numInches)
{
  int i;

  for (i = 0; i < numInches; i++)
  {
    delay (300);
    digitalWrite(13, HIGH);
    delay (300);
    digitalWrite(13, LOW);
  }

}

void move_straight(int wheel_speed, int forward)
{
  if(forward == 1)
  {
    digitalWrite(in1, LOW);     // H-bridge drive motor forward
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);     // H-bridge drive motor forward
    digitalWrite(in4, HIGH);
  }
  else
  {
    digitalWrite(in1, HIGH);  // H-bridge drive motor reverse
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);     // H-bridge drive motor forward
    digitalWrite(in4, LOW );
  }

  analogWrite(enA, wheel_speed);
  analogWrite(enB, wheel_speed);

}
void stop_wheels()
{
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);

  digitalWrite(enA, LOW);
  digitalWrite(enB, LOW);

  
}

void right_only (int wheel_speed, bool forward)
{

  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
  digitalWrite(enB, LOW);


// First - set H Bridge control pins for forward or reverse
  if(forward == true)
  {
    digitalWrite(in1, LOW);     // H-bridge drive motor forward
    digitalWrite(in2, HIGH);
  }
  else
  {
    digitalWrite(in1, HIGH);  // H-bridge drive motor reverse
    digitalWrite(in2, LOW);
  }

  // Second - set speed of motor, and enable H-Bridge to drive motor
  analogWrite(enA, wheel_speed);
  delay(200);
  stop_wheels();
  

}

void left_only(int wheel_speed, bool forward)
{

  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(enA, LOW);
  
// First - set H Bridge control pins for forward or reverse
  if(forward == true)
  {
    digitalWrite(in3, LOW);     // H-bridge drive motor forward
    digitalWrite(in4, HIGH);
  }
  else
  {
    digitalWrite(in3, HIGH);  // H-bridge drive motor reverse
    digitalWrite(in4, LOW);
  }

  // Second - set speed of motor, and enable H-Bridge to drive motor
  analogWrite(enB, wheel_speed);

}
