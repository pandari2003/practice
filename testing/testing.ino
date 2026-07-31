#include <Servo.h>

Servo servoBa1;
Servo servoBa2;
Servo servoBa3;
Servo servoBa4;

Servo servoHa1;
Servo servoHa2;
Servo servoHa3;
Servo servoHa4;

Servo servoKNa1;
Servo servoKNa2;
Servo servoKNa3;
Servo servoKNa4;

const int servoBa1pin = 2;   //front right
const int servoBa2pin = 5;   //front left
const int servoBa3pin = 8;   //back right
const int servoBa4pin = 11;  //back left

const int servoHa1Pin = 3;   // Front Right
const int servoHa2Pin = 6;   // front left
const int servoHa3Pin = 9;   // back right
const int servoHa4Pin = 12;  // back Left

const int servoKNa1Pin = 4;   // Front Right
const int servoKNa2Pin = 7;   // front left
const int servoKNa3Pin = 10;  // back right
const int servoKNa4Pin = 13;  // back Left



/**************** walk Forward ******************/
void walkForward() {
  // Repeat walking cycle
  for (int step = 0; step < 10; step++) {

   for (int k = 80; k <= 110; k++) {
      
     servoKNa1.write(k);
      servoKNa2.write(k);
      servoKNa3.write(180-k);
      //servoKNa4.write(k);
      delay(50);
    }

    for (int i = 90; i <= 120; i++) {
      

      servoHa1.write(i);
      servoHa3.write(180-i);
      servoHa2.write(i);
      servoHa4.write(180-i);
      delay(60);
    }
for (int k = 110; k >= 80; k--) {
      
      servoKNa1.write(k);
      servoKNa2.write(k);
      servoKNa3.write(180-k); 
      //servoKNa4.write(k);
      //delay(50);
    }

for(int i=120; i>80; i--) {
      

      servoHa1.write(i);
      servoHa3.write(180-i);
      servoHa2.write(i);
      servoHa4.write(180-i);
      delay(60);
    }






    /*
    // Lift Legs 1 & 4

    for (int i = 90; i >= 60; i--) {
      //
     // servoHa3.write(i);
     // servoHa4.write(i);
      servoHa1.write(180 - i);
     // servoHa2.write(180 - i);

      delay(50);
    }
        for (int k = 90; k >= 30; k--) {
      //
      servoKNa1.write(k);
      //servoKNa2.write(k);
     // servoKNa3.write(k);
     // servoKNa4.write(k);
      delay(50);
    }

    // Lower Legs 1 & 4

    for (int i = 60; i <= 90; i++) {
      //
      //servoHa3.write(i);
     // servoHa4.write(i);
      servoHa1.write(180 - i);
     // servoHa2.write(180 - i);

      delay(50);
    }
        for (int k = 30; k <= 90; k++) {
      //
      servoKNa1.write(k);
     // servoKNa2.write(k);
      //servoKNa3.write(k);
      //servoKNa4.write(k);
      delay(50);
    }
*/
  }
}

void setup() {
  Serial.begin(115200);

  servoHa3.attach(servoHa3Pin);
  servoHa1.attach(servoHa1Pin);
  servoHa4.attach(servoHa4Pin);
  servoHa2.attach(servoHa2Pin);

  servoKNa3.attach(servoKNa3Pin);
  servoKNa1.attach(servoKNa1Pin);
  servoKNa4.attach(servoKNa4Pin);
  servoKNa2.attach(servoKNa2Pin);

  servoBa1.attach(servoBa1pin);
  servoBa3.attach(servoBa3pin);
  servoBa2.attach(servoBa2pin);
  servoBa4.attach(servoBa4pin);

  Serial.println("Quadruped Robot Started");
}
void loop() {
  walkForward();
}
