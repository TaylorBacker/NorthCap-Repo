/*
    Vibration Motor with Arduino
    For more details, visit: https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/
*/

int motor1 = 9;
int motor2 = 1;
int motor3 = 3;
int motor4 = 4; //motor transistor is connected to pin 3
int motor5 = 5;
int motor6 = 6;
int motor7 = 7;
int motor8 = 8; 
//int motorPin2 = 3;

int motor = 1;

void setup() {
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);
  pinMode(motor7, OUTPUT);
  pinMode(motor8, OUTPUT);
}

void loop() {

  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);  
  digitalWrite(motor4, HIGH);  
  digitalWrite(motor5, HIGH); 
  digitalWrite(motor6, HIGH);  
  digitalWrite(motor7, HIGH);  
  digitalWrite(motor8, HIGH);  

  if (motor == 1) {
    digitalWrite(motor1, LOW);  //vibrate
    motor = 2;
  } 
  else if (motor == 2 ){
    digitalWrite(motor2, LOW);  //vibrate
    motor = 3;
  } 
  else if (motor == 3 ){
    digitalWrite(motor3, LOW);  //vibrate
    motor = 4;
  } 
  else if (motor == 4 ){
    digitalWrite(motor4, LOW);  //vibrate
    motor = 5;
  } 
  else if (motor == 5 ){
    digitalWrite(motor5, LOW);  //vibrate
    motor = 6;
  } 
  else if (motor == 6 ){
    digitalWrite(motor6, LOW);  //vibrate
    motor = 7;
  } 
  else if (motor == 7 ){
    digitalWrite(motor7, LOW);  //vibrate
    motor = 8;
  } 
  else if (motor == 8 ){
    digitalWrite(motor8, LOW);  //vibrate
    motor = 1;
  } 

                                // digitalWrite(motorPin2, LOW); //stop vibrating
  delay(1000);                  //wait 50 seconds.
}