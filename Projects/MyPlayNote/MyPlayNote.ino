#include <Wire.h>
#include <Zumo32U4.h>
#include <math.h>



Zumo32U4Buzzer buzzer;
Zumo32U4ButtonB buttonB;
Zumo32U4LCD lcd;

void myPlayNote(int note, float duration, int octave, int volume)
{
  float freq = floor(15.434 * exp(0.0578 * (note + 12 * octave)));
  buzzer.playFrequency(freq, duration, volume);
  
}


void setup() {
  // put your setup code here, to run once:


}

  int C = 1; //todo: put these in a dictionary? 
  int Cs = 2; // nah its fine
  int D = 3;
  int Ds = 4;
  int E = 5;
  int F = 6;
  int Fs = 7;
  int G = 8;
  int Gs = 9;
  int A = 10;
  int As = 11;
  int B = 12;

void CMajor(int vol)
{
  myPlayNote(C, 1000, 4, vol);
  delay(1000);
  myPlayNote(D, 500, 4, vol);
  delay(500);
  myPlayNote(E, 500, 4, vol);
  delay(500);
  myPlayNote(F, 500, 4, vol);
  delay(500);
  myPlayNote(G, 500, 4, vol);
  delay(500);
  myPlayNote(A, 500, 4, vol);
  delay(500);
  myPlayNote(B, 500, 4, vol);
  delay(500);
  myPlayNote(C, 1000, 5, vol);
  delay(1000);
  myPlayNote(B, 500, 4, vol);
  delay(500);
  myPlayNote(A, 500, 4, vol);
  delay(500);
  myPlayNote(G, 500, 4, vol);
  delay(500);
  myPlayNote(F, 500, 4, vol);
  delay(500);
  myPlayNote(E, 500, 4, vol);
  delay(500);
  myPlayNote(D, 500, 4, vol);
  delay(500);
  myPlayNote(C, 1000, 4, vol);
  delay(1000);
}


float _16th = 0.0625 * 1000;
float _8th = _16th * 2;
float _q = _8th * 2;
float _h = _q * 2;
float w = 1000;

void Sandstorm(int volume, int octave, float speed)
{
  float __16th = _16th / speed;
  float __8th = _8th / speed;
  float __q = _q / speed;
  float __h = _h = speed;
  float _w = w / speed;
  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Cs, __16th / 2, octave + 1, volume); // Bar B
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __8th / 2, octave + 1, volume);
  delay(__8th);
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th); 
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __8th / 2, octave + 1, volume);
  delay(__8th);
  myPlayNote(Fs, __16th / 2, octave, volume);
  delay(__16th);  
  myPlayNote(Fs, __16th / 2, octave, volume);
  delay(__16th);    

  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Cs, __16th / 2, octave + 1, volume); // Bar B
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __8th / 2, octave + 1, volume);
  delay(__8th);
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th); 
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __16th / 2, octave + 1, volume);
  delay(__16th);  
  myPlayNote(B, __8th / 2, octave + 1, volume);
  delay(__8th);
  myPlayNote(Fs, __16th / 2, octave, volume);
  delay(__16th);  
  myPlayNote(Fs, __16th / 2, octave, volume);
  delay(__16th);  

  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Gs, __16th / 2, octave, volume); // Bar A
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __16th / 2, octave, volume);
  delay(__16th);
  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);
  myPlayNote(Cs, __16th / 2, octave + 1, volume);
  delay(__16th);

  myPlayNote(Gs, __8th / 2, octave, volume);
  delay(__8th);
}

void loop() {
  // put your main code here, to run repeatedly:
  float _16th = 0.0625 * 1000;
  float _8th = _16th * 2;
  float _q = _8th * 2;
  float _h = _q * 2;
  float w = 1000;
  lcd.clear();
  lcd.print("Press B");
  if (buttonB.isPressed())
  {
    lcd.clear();
    lcd.print("B Pressed");
    //myPlayNote(C, 500, 3, 7);
    delay(500);
    Sandstorm(15, 6, 1);
  }
}
