<<<<<<< HEAD
/*
   Ultrasonic Sensor reading in Inches
*/


#include <Servo.h>
// #include <SoftwareSerial.h>

Servo myservo;  // create servo object to control a servo
int pos = 42;    // variable to store the servo position
const int trigPin = 10;
const int echoPin = 12;
long duration;
int distanceInch;

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
  //Serial.begin(9600);  // chris print statements


  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enB, OUTPUT);



 myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

int servoScaler = 30;
const int STEPS = 6;

void loop()
{
	stop_wheels();
  delay(500);
	int distances[STEPS];
	for(int i = 0; i < STEPS; i++)
	{
		myservo.write(servoScaler * i);
    delay(500);
		distances[i] = GetObjectDistance();	

	}

	int largestDistance = 0;
	int largestIndex;
	for(int j = 0; j < STEPS; j++)
	{
		if(distances[j] > largestDistance)
		{
			largestDistance = distances[j];
			largestIndex = j;
		}
	}
	
	int aggregate = 0;
	for(int i = 0; i < STEPS; i++)
	{
		aggregate += distances[i];
	}

	float average = aggregate / STEPS;


	//Yes, I'm well aware that this may be swayed, but FUCK IT we gotta finish the algorithm!
	int slack = 30;
	if(largestDistance < 20)
	{
		//TODO: Behavior when the car is about to crash into a wall!
		move_straight(200, 1);
    delay(800);

	} else
	{
    if(largestDistance - average < slack)
    {
	      //Fuck me
			if(largestIndex > STEPS / 2)
			{
				int pwm = largestIndex - STEPS / 2;
				right_only(100 * pwm, 0);
	      delay(250);
			} else
			{
				int pwm = largestIndex + STEPS / 2;
				left_only(100 * pwm, 0);
	      delay(250);
			}
    }
	
		// How long is it gonna move?
		move_straight(200, 0);
		delay(500);
		stop_wheels();
	}
 


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
=======
void setup()
{
    int ying = yep;
    Serial.begin(9600);
}

void loop()
{
    Serial.println("We really out here");
}

>>>>>>> 40880b6bd7dae37e210bf8dc670876d0c8290f26
