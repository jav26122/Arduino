#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Buzzer buzzer;
Zumo32U4LineSensors lineSensors;
Zumo32U4Motors motors;
Zumo32U4ButtonA buttonA;
Zumo32U4LCD lcd;

int16_t lastError = 0;
float startTime = millis();

#define NUM_SENSORS 5
unsigned int lineSensorValues[NUM_SENSORS];
const uint16_t maxSpeed = 400;


void calibrateSensors()
{
  lcd.clear();

  // Wait 0.5 second and then begin automatic sensor calibration
  // by rotating in place to sweep the sensors over the line
  delay(500);
  for(uint16_t i = 0; i < 120; i++)
  {
    if (i > 30 && i <= 90)
    {
      motors.setSpeeds(-200, 200);
    }
    else
    {
      motors.setSpeeds(200, -200);
    }
    lineSensors.calibrate();
  }
  motors.setSpeeds(0, 0);
}

void showReadings()
{
    lcd.clear();
    lcd.gotoXY(0, 0);
    lcd.print("T: ");
    lcd.print(millis() - startTime);
    lineSensors.readCalibrated(lineSensorValues);
    lcd.gotoXY(0, 1);
    for (uint8_t i = 0; i < 3; i++)
    {
        lcd.print(lineSensorValues[i] / 100);
    }
}

void setup()
{
    lineSensors.initFiveSensors();

  // Play a little welcome song
    buzzer.play("MSL24>>C>>E>>G>>E>>C>>R>>C>>E>>G>>E>>C>>R>>C>>E>>G>>E>>C>>R>>");

  // Wait for button A to be pressed and released.
    lcd.clear();
    lcd.print(F("Press A"));
    lcd.gotoXY(0, 1);
    lcd.print(F("to calib"));
    buttonA.waitForButton();

    calibrateSensors();

    // Play music and wait for it to finish before we start driving.
    lcd.clear();
    lcd.print(F("Go!"));
    buzzer.play("L16 cdegreg4");
    //while(buzzer.isPlaying());
    startTime = millis();
    showReadings();

}


void loop()
{
    int16_t position = lineSensors.readLine(lineSensorValues);

  // Our "error" is how far we are away from the center of the
  // line, which corresponds to position 2000.
    int16_t error = position - 2000;

  // Get motor speed difference using proportional and derivative
  // PID terms (the integral term is generally not very useful
  // for line following).  Here we are using a proportional
  // constant of 1/4 and a derivative constant of 6, which should
  // work decently for many Zumo motor choices.  You probably
  // want to use trial and error to tune these constants for your
  // particular Zumo and line course.
    int16_t speedDifference = error / 4 + 6 * (error - lastError);

    lastError = error;

  // Get individual motor speeds.  The sign of speedDifference
  // determines if the robot turns left or right.
  int16_t leftSpeed;
  int16_t rightSpeed;
  if (error < 200)
  {
        leftSpeed = (int16_t)maxSpeed + speedDifference / 2;
        rightSpeed = (int16_t)maxSpeed + speedDifference / 2;
  }
  else
  {
        leftSpeed = (int16_t)maxSpeed + speedDifference;
        rightSpeed = (int16_t)maxSpeed - speedDifference;
  }
  
  // Constrain our motor speeds to be between 0 and maxSpeed.
  // One motor will always be turning at maxSpeed, and the other
  // will be at maxSpeed-|speedDifference| if that is positive,
  // else it will be stationary.  For some applications, you
  // might want to allow the motor speed to go negative so that
  // it can spin in reverse.
    leftSpeed = constrain(leftSpeed, -10, (int16_t)maxSpeed);
    rightSpeed = constrain(rightSpeed, -10, (int16_t)maxSpeed);

    motors.setSpeeds(leftSpeed, rightSpeed);
    showReadings();
}
