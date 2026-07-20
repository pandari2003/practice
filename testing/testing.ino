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
 

 
/****************BACKWARD****************/
void walkBackward() {
  // Repeat walking cycle
  for (int step = 0; step < 10; step++) {
    //---------------- STEP 1 ----------------//
    // Reverse of Forward STEP 1
    for (int i = 100; i >= 70; i--) {
      servoH1.write(i);
      servoH3.write(i);
      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(30);
    }

    // Lift Legs 1 & 3
    for (int k = 120; k >= 60; k--) {
      servoKN1.write(k);
      servoKN4.write(k);
      delay(30);
    }

    // Lower Legs 1 & 3
    for (int k = 60; k <= 120; k++) {
      servoKN1.write(k);
      servoKN4.write(k);
      delay(30);
    }

    //---------------- STEP 2 ----------------//
    // Reverse of Forward STEP 2
    for (int i = 70; i <= 100; i++) {
      servoH1.write(i);
      servoH3.write(i);
      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(30);
    }

    // Lift Legs 2 & 4
    for (int k = 120; k >= 60; k--) {
      servoKN2.write(k);
      servoKN3.write(k);
      delay(30);
    }

    // Lower Legs 2 & 4
    for (int k = 60; k <= 120; k++) {
      servoKN2.write(k);
      servoKN3.write(k);
      delay(30);
    }

    //---------------- Return Center ----------------//
    // Reverse of Forward Return Center
    for (int i = 100; i >= 90; i--) {
      servoH1.write(i);
      servoH3.write(i);
      servoH2.write(180 - i);
      servoH4.write(180 - i);

      delay(30);
    }
  }
}
/*
void Sit() {
  for (int i = 90; i >= 0; i--) {
    // Left pair
    servoH2.write(i);
    servoH3.write(i);
    servoKN2.write(i-45);
    servoKN3.write(i-45);

    // Right pair
    servoH1.write(180 - i);
    servoH4.write( 180- i);
    servoKN1.write(230 - i);
    servoKN4.write(230 - i);

    delay(80);  // Same speed as Stand
  }

  delay(60);
}

stand
void Stand() {
  for (int i = 0; i <= 90; i++) {
    // Left pair
    servoH2.write(i);
    servoH3.write(i);
    servoKN2.write(i-45);
    servoKN3.write(i-45);

    // Right pair
    servoH1.write(180 - i);
    servoH4.write(180 - i);
    servoKN1.write(230 - i);
    servoKN4.write(230 - i);

    delay(50);  // Adjust speed here
  }

  delay(50);
}
 */
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
walkBackward();
/*
Sit();
delay(10000);
Stand();
delay(10000);
*/


}