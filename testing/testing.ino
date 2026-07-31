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

const int servoB1pin = 2;   //front right
const int servoB3pin = 5;   //front left
const int servoB2pin = 8;   //back right
const int servoB4pin = 11;  //back left

const int servoH2Pin = 3;   // Front Right
const int servoH4Pin = 6;   // front left
const int servoH1Pin = 9;   // back right
const int servoH3Pin = 12;  // back Left

const int servoKN2Pin = 4;   // Front Right
const int servoKN4Pin = 7;   // front left
const int servoKN1Pin = 10;  // back right
const int servoKN3Pin = 13;  // back Left



/******************************/
void forword() {
  // Repeat walking cycle
  for (int step = 0; step < 10; step++) {
 //
    //---------------- STEP 1 ----------------//
    for (int i = 90; i >= 70; i--) {
   //
      servoH1.write(i);
      servoH3.write(i);
      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(50);
    }

    // Lift Legs 1 & 4
    for (int k = 90; k >= 70; k--) {
   //
      servoKN1.write(k);
      servoKN3.write(k);
      delay(50);
    }

    // Lower Legs 1 & 4
    for (int k = 70; k <= 90; k++) {
   //
      servoKN1.write(k);
      servoKN3.write(k);
      delay(50);
    }

    //---------------- STEP 2 ----------------//
    for (int i = 70; i <= 110; i++) {
   //
      servoH1.write(i);
      servoH3.write(i);
      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(50);
    }

    // Lift Legs 2 & 3
    for (int k = 90; k >= 70; k--) {
   //
      servoKN2.write(k);
      servoKN4.write(k);
      delay(50);
    }

    // Lower Legs 2 & 3
    for (int k = 70; k <= 90; k++) {
   //
      servoKN2.write(k);
      servoKN4.write(k);
      delay(50);
    }

    //---------------- Return Center ----------------//
    for (int i = 110; i >= 90; i--) {
   //
      servoH1.write(i);
      servoH3.write(i);

      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(50);
    }
  }
  delay(30);

}
//servoB1.write(jk);
//servoH1.write(i);
//servoKN1.write(k);
/******************************/

void setup() {
  Serial.begin(115200);

  servoH1.attach(servoH1Pin);
  servoH2.attach(servoH2Pin);
  servoH3.attach(servoH3Pin);
  servoH4.attach(servoH4Pin);

  servoKN1.attach(servoKN1Pin);
  servoKN2.attach(servoKN2Pin);
  servoKN3.attach(servoKN3Pin);
  servoKN4.attach(servoKN4Pin);

  servoB1.attach(servoB1pin);
  servoB2.attach(servoB2pin);
  servoB3.attach(servoB3pin);
  servoB4.attach(servoB4pin);

  Serial.println("Quadruped Robot Started");
}


void loop(){
  forword();
}


