
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 120
#define SERVOMAX 550
#define SERVO_FREQ 50
#define NUM_SERVOS 8

// ==========================================
// SERVO MOVEMENT SETTINGS
// ==========================================

int SERVO_STEP_DELAY = 20;
int WALK_DELAY = 100;

// Current servo angles
int currentAngle[NUM_SERVOS] = {
  90, 90, 90, 90,
  90, 90, 90, 90
};

// ==========================================
// WALKING ANGLES
// ==========================================

// Even channels = HIP
// Odd channels = KNEE
int HIP_FORWARD = 75;
int HIP_BACKWARD = 110;
int KNEE_UP = 75;
int KNEE_DOWN = 80;


// ==========================================
// SERVO CONTROL
// ==========================================

int angleToPulse(int angle) {

  return map(angle, 0, 180, SERVOMIN, SERVOMAX);

}


void servoWrite(int channel, int angle) {

  angle = constrain(angle, 0, 180);

  pwm.setPWM(channel, 0, angleToPulse(angle));

  currentAngle[channel] = angle;

}


// ==========================================
// SMOOTH MOVEMENT OF ALL 8 SERVOS
// ==========================================

void moveAll(
  int target0, int target1,
  int target2, int target3,
  int target4, int target5,
  int target6, int target7
) {

  int targets[NUM_SERVOS] = {
    target0, target1,
    target2, target3,
    target4, target5,
    target6, target7
  };

  bool moving = true;

  while (moving) {

    moving = false;

    for (int i = 0; i < NUM_SERVOS; i++) {

      if (currentAngle[i] < targets[i]) {

        currentAngle[i]++;
        servoWrite(i, currentAngle[i]);
        moving = true;

      }

      else if (currentAngle[i] > targets[i]) {

        currentAngle[i]--;
        servoWrite(i, currentAngle[i]);
        moving = true;

      }

    }

    delay(SERVO_STEP_DELAY);

  }

}


// ==========================================
// INITIAL POSITION
// ==========================================

void set() {

  moveAll(
    90, 90,
    90, 90,
    90, 90,
    90, 90
  );

}


// ==========================================
// SIT POSTURE (ORIGINAL ANGLES UNCHANGED)
// ==========================================

void sit() {

  moveAll(
    130, 20,
    50, 150,
    130, 20,
    50, 150
  );

}


// ==========================================
// STAND POSTURE (ORIGINAL ANGLES UNCHANGED)
// ==========================================

void stand() {

  moveAll(
    90, 90,
    90, 90,
    90, 90,
    90, 90
  );

}


// ==========================================
// DOG WALKING GAIT
// ==========================================

// CHANNEL MAPPING:
//
// 0 = Front Left HIP
// 1 = Front Left KNEE
//
// 2 = Front Right HIP
// 3 = Front Right KNEE
//
// 4 = Rear Left HIP
// 5 = Rear Left KNEE
//
// 6 = Rear Right HIP
// 7 = Rear Right KNEE
void walkPhase1() {

  moveAll(
    HIP_FORWARD, KNEE_UP,       // Front Left
    HIP_BACKWARD, KNEE_DOWN,    // Front Right
    HIP_BACKWARD, KNEE_DOWN,    // Rear Left
    HIP_FORWARD, KNEE_UP        // Rear Right
  );

  delay(100);
}


// PHASE 2
// Front Left + Rear Right come down

void walkPhase2() {

  moveAll(
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN
  );

  delay(100);
}


// PHASE 3
// Front Right + Rear Left lift together

void walkPhase3() {

  moveAll(
    HIP_BACKWARD, KNEE_DOWN,
    HIP_FORWARD, KNEE_UP,
    HIP_FORWARD, KNEE_UP,
    HIP_BACKWARD, KNEE_DOWN
  );

  delay(100);
}


// PHASE 4
// Front Right + Rear Left come down

void walkPhase4() {

  moveAll(
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN,
    HIP_BACKWARD, KNEE_DOWN
  );

  delay(100);
}


// COMPLETE WALKING CYCLE

void walk() {

  walkPhase1();
  walkPhase2();

  walkPhase3();
  walkPhase4();

}
// ==========================================
// COMPLETE WALKING CYCLE
// ==========================================

void walk() {

  walkPhase1();

  walkPhase2();

  walkPhase3();

  walkPhase4();

}


// ==========================================
// SETUP
// ==========================================

void setup() {

  Wire.begin();

  pwm.begin();

  pwm.setOscillatorFrequency(27000000);

  pwm.setPWMFreq(SERVO_FREQ);

  // Initialize all servos at 90 degrees

  for (int i = 0; i < NUM_SERVOS; i++) {

    servoWrite(i, 90);

  }

  delay(1000);

  stand();

}


// ==========================================
// MAIN LOOP
// ==========================================

void loop() {

  walk();

}
