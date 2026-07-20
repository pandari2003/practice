#include <Servo.h>

Servo servoB1;
Servo servoB2;
Servo servoB3;
Servo servoB4;

Servo servoH1;
Servo servoH2;
Servo servoH3;
Servo servoH4;

Servo servoKN1;
Servo servoKN2;
Servo servoKN3;
Servo servoKN4;

const int servoB1pin = 2; //front right (servo 1)
const int servoB2pin = 3; //back right (servo 2)
const int servoB3pin = 4; //front left (servo 4)
const int servoB4pin = 5; //back left (servo 3)

const int servoH1Pin = 6; // back right (servo 8)
const int servoH2Pin = 7; // Front Right (servo 5)
const int servoH3Pin = 8; // back Left(servo 7)
const int servoH4Pin = 9; // front left (servo 6)

const int servoKN1Pin = 10; // back right (servo 12)
const int servoKN2Pin = 11; // Front Right (servo 9)
const int servoKN3Pin = 12; // back Left (servo 11)
const int servoKN4Pin = 13; // front left (servo 10)

/************************left move***************//*
void Leftmove(){
    for (int step = 0; step < 2; step++)
  {
    //---------------- STEP 1 ----------------//
    for (int i = 110; i >= 70; i--)
    {
      servoB3.write(90);
      servoB1.write(i);
      servoKN4.write(i);
      servoB4.write(180 - i);
      servoB2.write(90);

      delay(50);
    }
    delay(40);

    for (int i = 70; i <= 110; i++)
    {
      servoB3.write(90);
      servoB1.write(i);
      servoKN1.write(i);
      servoB4.write(180 - i);
      servoB2.write(90);

      delay(50);
    }
    delay(40);
  }
}*/

/*****************right move**********************/
void Rightmove() {
  for (int step = 0; step < 2; step++) {
    //---------------- STEP 1 ----------------//
    for (int i = 70; i <= 110; i++) {
      servoB1.write(90);
      servoB3.write(i);
      servoKN2.write(i);
      servoB2.write(180 - i);
      servoB4.write(90);

      delay(50);
    }
    for (int i = 110; i >= 70; i--) {
      servoB1.write(90);
      servoB3.write(i);
      servoKN2.write(i);
      servoB2.write(180 - i);
      servoB4.write(90);

      delay(50);
    }
    delay(40);
  }
}

void setup() {
  Serial.begin(9600);

  // Attach servos
  servoB1.attach(servoB1pin);
  servoB2.attach(servoB2pin);
  servoB3.attach(servoB3pin);
  servoB4.attach(servoB4pin);

  servoH1.attach(servoH1Pin);
  servoH2.attach(servoH2Pin);
  servoH3.attach(servoH3Pin);
  servoH4.attach(servoH4Pin);

  servoKN1.attach(servoKN1Pin);
  servoKN2.attach(servoKN2Pin);
  servoKN3.attach(servoKN3Pin);
  servoKN4.attach(servoKN4Pin);

  // Set all servos to 90 degrees
  servoB1.write(90);
  servoB2.write(90);
  servoB3.write(90);
  servoB4.write(90);

  servoH1.write(90);
  servoH2.write(90);
  servoH3.write(90);
  servoH4.write(90);

  servoKN1.write(90);
  servoKN2.write(90);
  servoKN3.write(90);
  servoKN4.write(90);

  Serial.println("All servos set to 90 degrees");
}
void loop() {

 // Leftmove();
  Rightmove();

}