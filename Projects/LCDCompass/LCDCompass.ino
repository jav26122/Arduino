
#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4LCD lcd;
Zumo32U4ButtonA buttonA;
Zumo32U4Buzzer buzzer;

L3G gyro;
LSM303 compass;

float gyroOffsetY;
float gyroOffsetX;
float aAngley = 0;
float aAnglex = 0;
float angley = 0;
float anglex = 0;


void setup()
{
  Wire.begin();

  // Set up the L3GD20H gyro.
  gyro.init();

  // 800 Hz output data rate,
  // low-pass filter cutoff 100 Hz.
  gyro.writeReg(L3G::CTRL1, 0b11111111);

  // 2000 dps full scale.
  gyro.writeReg(L3G::CTRL4, 0b00100000);

  // High-pass filter disabled.
  gyro.writeReg(L3G::CTRL5, 0b00000000);

  // Set up the LSM303D accelerometer.
  compass.init();

  // 50 Hz output data rate
  compass.writeReg(LSM303::CTRL1, 0x57);

  // 8 g full-scale
  compass.writeReg(LSM303::CTRL2, 0x18);

  lcd.clear();
  lcd.print(F("Gyro cal"));
  ledYellow(1);

  // Delay to give the user time to remove their finger.
  delay(500);

  // Calibrate the gyro.
  for (uint16_t i = 0; i < 1024; i++)
  {
    // Wait for new data to be available, then read it.
    while(!gyro.readReg(L3G::STATUS_REG) & 0x08);
    gyro.read();

    // Add the Y axis reading to the total.
    gyroOffsetY += gyro.g.y;
    gyroOffsetX += gyro.g.x;
  }
  gyroOffsetY /= 1024;
  gyroOffsetX /= 1024;

  lcd.clear();
  ledYellow(0);

  // Display the angle until the user presses A.
  while (!buttonA.getSingleDebouncedRelease())
  {
    // Update the angle using the gyro as often as possible.
    updateAngleGyro();

    // Every 20 ms (50 Hz), correct the angle using the
    // accelerometer and also print it.
    static uint8_t lastCorrectionTime = 0;
    uint8_t m = millis();
    if ((uint8_t)(m - lastCorrectionTime) >= 20)
    {
      lastCorrectionTime = m;
      correctAngleAccel();
      printAngles();
    }
  }
  delay(500);
}


void calGyro()
{
  lcd.clear();
  lcd.print(F("Gyro cal"));
  ledYellow(1);
  delay(500);
  angley = 0;
  anglex = 0;
  for (uint16_t i = 0; i < 1024; i++)
  {
    // Wait for new data to be available, then read it.
    while(!gyro.readReg(L3G::STATUS_REG) & 0x08);
    gyro.read();

    // Add the Y axis reading to the total.
    gyroOffsetY += gyro.g.y;
    gyroOffsetX += gyro.g.x;
  }
  gyroOffsetY /= 1024;
  gyroOffsetX /= 1024;
}


int count = 0;
float LastX;
float LastY;
int currentX = 0;
int currentY = 0;
int difX;
int difY;
void loop()
{
  count++;
  if (buttonA.isPressed())
  {
    calGyro();
  }

  // Update the angle using the gyro as often as possible.
  updateAngleGyro();



  // Every 20 ms (50 Hz), correct the angle using the
  // accelerometer, print it, and set the motor speeds.
  static byte lastCorrectionTime = 0;
  byte m = millis();
  if ((byte)(m - lastCorrectionTime) >= 20)
  {
    lastCorrectionTime = m;

    correctAngleAccel();


  }

    if (count > 250) // this controls the update rate of the 'old' value
    {
      LastX = anglex;
      LastY = angley;
      count = 0;
    }
    
    //lcd.clear();
    if (anglex > -80)
    {
      
      if (currentX > 0)
      {
        currentX--;
        delay(50);
      }
      lcd.clear();
      
      
    }
    else if (anglex < -100)
    {
      if (currentX < 7)
      {
          currentX++;
          delay(50);
      }
      lcd.clear();
      
      
    }
    if (angley < -80)
    {
      if (currentY < 1)
      {
        currentY++;
        delay(50);
      }
      lcd.clear();
    }
    else if(angley > -100)
    {
      if (currentY > 0)
      {
        currentY--;
        delay(50);
      }
      lcd.clear();
    }
    lcd.gotoXY(currentX, currentY);
    lcd.print("0");
    //lcd.print(F("   "));
    delay(10);


}

// down Y goes up, up y goes down
// 


void correctAngleAccel()
{
  compass.read();

  // Calculate the angle according to the accelerometer.
  aAngley = -atan2(compass.a.z, -compass.a.x) * 180 / M_PI;
  aAnglex = -atan2(compass.a.z, -compass.a.y) * 180 / M_PI;

  // Calculate the magnitude of the measured acceleration vector,
  // in units of g.
  LSM303::vector<float> const aInG = {
    (float)compass.a.x / 4096,
    (float)compass.a.y / 4096,
    (float)compass.a.z / 4096}
  ;
  float mag = sqrt(LSM303::vector_dot(&aInG, &aInG));

  // Calculate how much weight we should give to the
  // accelerometer reading.  When the magnitude is not close to
  // 1 g, we trust it less because it is being influenced by
  // non-gravity accelerations, so we give it a lower weight.
  float weight = 1 - 5 * abs(1 - mag);
  weight = constrain(weight, 0, 1);
  weight /= 10;

  // Adjust the angle estimation.  The higher the weight, the
  // more the angle gets adjusted.
  angley = weight * aAngley + (1 - weight) * angley;
  anglex = weight * aAnglex + (1 - weight) * anglex;
}


void printAngles()
{
  lcd.gotoXY(0, 0);
  lcd.print(angley);
  lcd.print("  ");

  lcd.gotoXY(0, 1);
  lcd.print(anglex);
  lcd.print("  ");
}




void updateAngleGyro()
{
  // Figure out how much time has passed since the last update.
  static uint16_t lastUpdate = 0;
  uint16_t m = micros();
  uint16_t dt = m - lastUpdate;
  lastUpdate = m;

  gyro.read();

  // Calculate how much the angle has changed, in degrees, and
  // add it to our estimation of the current angle.  The gyro's
  // sensitivity is 0.07 dps per digit.
  angley += ((float)gyro.g.y - gyroOffsetY) * 70 * dt / 1000000000;
  anglex += ((float)gyro.g.x - gyroOffsetX) * 70 * dt / 1000000000;
}

