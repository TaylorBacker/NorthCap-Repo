/*
    Vibration Motor with Arduino
    For more details, visit: https://techzeero.com/arduino-tutorials/vibration-motor-with-arduino/
*/

int motor1 = 1;
int motor2 = 2;
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

  digitalWrite(motor1, LOW); 
  digitalWrite(motor2, LOW);
  digitalWrite(motor3, LOW);  
  digitalWrite(motor4, LOW);  
  digitalWrite(motor5, LOW); 
  digitalWrite(motor6, LOW);  
  digitalWrite(motor7, LOW);  
  digitalWrite(motor8, LOW);  
                                // digitalWrite(motorPin2, LOW); //stop vibrating
  delay(1000);                  //wait 50 seconds.
}