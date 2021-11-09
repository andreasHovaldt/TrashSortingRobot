#include <Wire.h>
#include <Zumo32U4.h>
Zumo32U4Motors motors;

int mSpeed = 0;
int mDuration = 0;
int mCommand = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  roverMovement(mCommand, mSpeed, mDuration);
}

void roverMovement(int moveCommand, int moveSpeed, int moveDuration) {   //Run the robot with specified command, speed and duration
  switch (moveCommand) { //0 = Forward,  1 = Backwards, 2 = Right, 3 = Left
    case 0:
      moveForward(moveSpeed, moveDuration);
      break;

    case 1:
      moveBackwards(moveSpeed, moveDuration);
      break;

    case 2:
      moveTurn(moveCommand, moveSpeed, moveDuration);
      break;

    case 3:
      moveTurn(moveCommand, moveSpeed, moveDuration);
      break;

    default:
      moveStop();
      Serial.println("Error");
  }
  moveStop();
}

void moveForward(int moveSpeed, int moveDuration) {               //Function for moving the robot forwards
  motors.setSpeeds(moveSpeed, moveSpeed);
  delay(moveDuration);
}

void moveBackwards(int moveSpeed, int moveDuration) {             //Function for moving the robot backwards
  motors.setSpeeds(-moveSpeed, -moveSpeed);
  delay(moveDuration);
}

void moveStop() {                                                 //Function for stopping the motors of the robot
  motors.setSpeeds(0, 0);
}

void moveTurn(int moveCommand, int moveSpeed, int moveDuration) { //Function for turning the robot
  switch (moveCommand) {
    case 3:
      motors.setSpeeds(-moveSpeed, moveSpeed); //Turn left
      break;

    case 2:
      motors.setSpeeds(moveSpeed, -moveSpeed); //Turn right
      break;

    default:
      motors.setSpeeds(0, 0);
      break;

  }
  delay(moveDuration);
}
