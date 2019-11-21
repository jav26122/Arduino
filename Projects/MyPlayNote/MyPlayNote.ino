#include <Wire.h>
#include <Zumo32U4.h>
#include <math.h>



Zumo32U4Buzzer buzzer;
Zumo32U4ButtonB buttonB;

void myPlayNote(int note, float duration, int octave)
{
  float freq = floor(15.434 * exp(0.0578 * (note + 12 * octave)));
  buzzer.playFrequency(freq, duration, 15);
  
}


void setup() {
  // put your setup code here, to run once:


}

  int C = 1; //todo: put these in a dictionary? 
  int Cs = 2;
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
  myPlayNote(C, 1000, vol);
  delay(1000);
  myPlayNote(D, 500, vol);
  delay(500);
  myPlayNote(E, 500, vol);
  delay(500);
  myPlayNote(F, 500, vol);
  delay(500);
  myPlayNote(G, 500, vol);
  delay(500);
  myPlayNote(A, 500, vol);
  delay(500);
  myPlayNote(B, 500, vol);
  delay(500);
  myPlayNote(C, 1000, vol);
  delay(1000);
  myPlayNote(B, 500, vol);
  delay(500);
  myPlayNote(A, 500, vol);
  delay(500);
  myPlayNote(G, 500, vol);
  delay(500);
  myPlayNote(F, 500, vol);
  delay(500);
  myPlayNote(E, 500, vol);
  delay(500);
  myPlayNote(D, 500, vol);
  delay(500);
  myPlayNote(C, 1000, vol);
  delay(1000);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (buttonB.isPressed())
  {
    CMajor(1);
    delay(1000);
  }
}
