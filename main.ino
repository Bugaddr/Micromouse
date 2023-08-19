/**
  Name: micromouse_v1
  Purpose: Maze solver for ultrasonic sensor based micromouse

  @author Pranay Pawar
  @version 0.1
  Left hand following algorithm is being used
*/

// *** Pins ***
const int buzzer = A0;
const int motor_L1 = 5;
const int motor_L2 = 4;
const int motor_R3 = 3;
const int motor_R4 = 2;
const int echo_R = 6;
const int trig_R = 7;
const int echo_F = 8;
const int trig_F = 9;
const int echo_B = 11;
const int trig_B = 10;
const int echo_L = 12;
const int trig_L = 13;

// *** Variables ***
const int WALL_TRESH = 20;
char move_dir;
long dist_front, dist_right, dist_left, dist_back;
int wall_front, wall_right, wall_left, wall_back;

void setup() {
  // Initialize buzzer
  pinMode(buzzer, OUTPUT);

  // Initialize motors and keep all off
  pinMode(motor_L1, OUTPUT);
  pinMode(motor_L2, OUTPUT);
  pinMode(motor_R3, OUTPUT);
  pinMode(motor_R4, OUTPUT);

  // Initialize ultrasonic sensor
  pinMode(echo_F, INPUT);
  pinMode(echo_R, INPUT);
  pinMode(echo_L, INPUT);
  pinMode(echo_B, INPUT);
  pinMode(trig_F, OUTPUT);
  pinMode(trig_R, OUTPUT);
  pinMode(trig_L, OUTPUT);
  pinMode(trig_B, OUTPUT);

  // Serial comm at 9600 bps for debugging
  Serial.begin(9600);
}

void loop() {
  // Check walls
  walls();
  // Left hand rule algorithm
  if (wall_left == 1 && wall_front == 0 && wall_right == 1) {
    move('F'); // Only straight
  } else if (wall_left == 0 && wall_front == 1 && wall_right == 1) {
    move('L'); // Only left
  } else if (wall_left == 1 && wall_front == 1 && wall_right == 0) {
    move('R'); // Only right
  } else if (wall_left == 0 && wall_front == 1 && wall_right == 0) {
    move('L'); // Left suggested at T-intersection
  } else if (wall_left == 0 && wall_front == 0 && wall_right == 1) {
    move('L'); // Left T-intersection
  } else if (wall_left == 1 && wall_front == 0 && wall_right == 0) {
    move('F'); // Right T-intersection
  } else if (wall_left == 1 && wall_front == 1 && wall_right == 1) {
    move('L'); // U-turn at dead-end
  } else if (wall_left == 0 && wall_front == 0 && wall_right == 0) {
    move('F'); // 4-Lane intersection [Can be checked by moving further]
    delay(30); // Uncalibrated
    move('S'); // Stop
    if (wall_left == 0 && wall_front == 0 && wall_right == 0) {
      Serial.println("END OF MAZE");
    } else {
      move('L'); // 4-Way intersection if left or right value changes
    }
  }
}

/**
  Triggers ultrasonic sensor sound wave

  @param trig_pin variable with pin name
*/
void trigger(int trig_pin) {
  // Clear out prevoius triggers (Fail-safe)
  digitalWrite(trig_pin, LOW);
  delayMicroseconds(2);
  // Send sound waves for 10ms
  digitalWrite(trig_pin, HIGH);
  delayMicroseconds(10);
  // Stop the sound wave
  digitalWrite(trig_pin, LOW);
}

/**
  Checks if there is wall in surrounding

*/
void walls() {
  // Calculate front sensor distance
  trigger(trig_F);
  dist_front = pulseIn(echo_F, HIGH) * 0.034 / 2;
  // Calculate right sensor distance
  trigger(trig_R);
  dist_right = pulseIn(echo_R, HIGH) * 0.034 / 2;
  // Calculate left sensor distance
  trigger(trig_L);
  dist_left = pulseIn(echo_L, HIGH) * 0.034 / 2;
  // Calculate back sensor distance
  trigger(trig_B);
  dist_back = pulseIn(echo_B, HIGH) * 0.034 / 2;

  // Check walls // 0=no-wall 1=wall
  wall_front = 0, wall_right = 0, wall_left = 0, wall_back = 0;
  if (dist_front < WALL_TRESH) {
    wall_front = 1;
  }
  if (dist_right < WALL_TRESH) {
    wall_right = 1;
  }
  if (dist_left < WALL_TRESH) {
    wall_left = 1;
  }
  if (dist_back < WALL_TRESH) {
    wall_back = 1;
  }

  // Debug dist
  Serial.print("L");
  Serial.print(dist_left);
  Serial.print(" F");
  Serial.print(dist_front);
  Serial.print(" R");
  Serial.print(dist_right);
  Serial.print(" B");
  Serial.println(dist_back);
  // Debug wall
  Serial.print(wall_left);
  Serial.print(wall_front);
  Serial.print(wall_right);
  Serial.println(wall_back);
}

/**
  Sends command to moters to move in specific direction

  @param move_dir F for front, B for back etc etc.
*/
void move(char move_dir) {
  // Give beep
  short_beep();
  // Turn
  if (move_dir == 'F') {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_R3, LOW);
    digitalWrite(motor_R4, HIGH);
  } else if (move_dir == 'B') {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_R3, LOW);
    digitalWrite(motor_R4, HIGH);
  } else if (move_dir == 'R') {
    digitalWrite(motor_L1, HIGH);
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_R3, LOW);
    digitalWrite(motor_R4, HIGH);
  } else if (move_dir == 'L') {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, HIGH);
    digitalWrite(motor_R3, HIGH);
    digitalWrite(motor_R4, LOW);
  } else if (move_dir == 'S') {
    digitalWrite(motor_L1, LOW);
    digitalWrite(motor_L2, LOW);
    digitalWrite(motor_R3, LOW);
    digitalWrite(motor_R4, LOW);
  }
  delay(100); // Uncalibrated
  // Debug
  Serial.print("Moving ");
  Serial.println(move_dir);
}

/**
   Short beep 50Ms at intersection point

*/
void short_beep() {
  // Short beep 50Ms at intersection point
  tone(buzzer, 3500, 50);
}
