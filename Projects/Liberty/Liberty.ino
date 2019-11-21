#include <Wire.h>
#include <Zumo32U4.h>
#include <math.h>



Zumo32U4Buzzer buzzer;
Zumo32U4ButtonB buttonB;

//40Hz-10KHz Volume 0-15
void myPlayNote(int note, float duration, int octave, int volume)
{
  float freq = floor(15.434 * exp(0.0578 * (note + 12 * octave)));
  buzzer.playFrequency(freq, duration, volume);

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

void loop() {
  // put your main code here, to run repeatedly:
  float speed = 1;
  int vol = 10;
  if (buttonB.isPressed())
  {
    myPlayNote(A, 200 * speed, 5, vol);
    delay(200* speed);
    myPlayNote(B, 200* speed, 5, vol);
    delay(200* speed);
    myPlayNote(Cs, 400* speed, 6, vol);
    delay(400* speed);

    myPlayNote(A, 200* speed, 5, vol);
    delay(200* speed);
    myPlayNote(B, 200* speed, 5, vol);
    delay(200* speed);
    myPlayNote(Cs, 400* speed, 6, vol);
    delay(400* speed);

    myPlayNote(E, 600* speed, 5, vol);
    delay(600* speed);
    myPlayNote(D, 200* speed, 5, vol);
    delay(200* speed);
    myPlayNote(C, 200* speed, 5, vol);
    delay(600* speed);

    myPlayNote(E, 600* speed, 5, vol);
    delay(600* speed);
    myPlayNote(D, 200* speed, 5, vol);
    delay(200* speed);
    myPlayNote(C, 200* speed, 5, vol);
    delay(600* speed);

  }
}
