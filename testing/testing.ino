
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

#define SERVOMIN 120
#define SERVOMAX 550
#define SERVO_FREQ 50
#define NUM_SERVOS 8

// GLOBAL SERVO MOVEMENT TIMING
int SERVO_STEP_DELAY = 70;  // Increase value for slower movement

// Track current angles for Channels 0 through 7
int currentAngle[NUM_SERVOS] = { 90, 90, 90, 90, 90, 90, 90, 90 };

int angleToPulse(int angle) {
  return map(angle, 0, 180, SERVOMIN, SERVOMAX);
}

void servoWrite(int channel, int angle) {
  pwm.setPWM(channel, 0, angleToPulse(angle));
  currentAngle[channel] = angle;
}

// Move Channels 0 through 7 smoothly at the same time
void moveAll(int target0, int target1, int target2, int target3, int target4, int target5, int target6, int target7) {
  int targets[NUM_SERVOS] = { target0, target1, target2, target3, target4, target5, target6, target7 };
  bool moving = true;

  while (moving) {
    moving = false;
    for (int i = 0; i < NUM_SERVOS; i++) {
      if (currentAngle[i] < targets[i]) {
        currentAngle[i]++;
        servoWrite(i, currentAngle[i]);
        moving = true;
      } else if (currentAngle[i] > targets[i]) {
        currentAngle[i]--;
        servoWrite(i, currentAngle[i]);
        moving = true;
      }
    }
    delay(SERVO_STEP_DELAY);
  }
}

// Set all 8 servos smoothly to 90 degrees
void set() {
  moveAll(
    90, 90,
    90, 90,
    90, 90,
    90, 90
  );
}

// Sit posture
void sit() {
  moveAll(
    130, 20,
    50, 150,
    130, 20,
    50, 150
  );
}

// Stand posture
void stand() {
  moveAll(
    90, 90,
    90, 90,
    90, 90,
    90, 90
  );
}

void setup() {
  Wire.begin();
  pwm.begin();
  pwm.setOscillatorFrequency(27000000);
  pwm.setPWMFreq(SERVO_FREQ);

  // Initialize all eight channels at 90 degrees
  for (int i = 0; i < NUM_SERVOS; i++) {
    servoWrite(i, 90);
  }
  delay(1000);
}

void loop() {
  set();
  delay(5000);

  sit();
  delay(5000);

  stand();
  delay(5000);
}
