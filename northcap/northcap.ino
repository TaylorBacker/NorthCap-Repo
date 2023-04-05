
// libraries
#include <Wire.h>
#include <HMC5883L.h>
HMC5883L compass;

// setting motor variables to their pin number
int motor1 = 12;
int motor2 = 2;
int motor3 = 3;
int motor4 = 4; 
int motor5 = 5;
int motor6 = 6;
int motor7 = 7;
int motor8 = 8; 

// motor variable (refers to the motor that should be on)
int motor = 3;

// setup code 
void setup() {
  Serial.begin(9600); 

  // pin setup
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  pinMode(motor3, OUTPUT);
  pinMode(motor4, OUTPUT);
  pinMode(motor5, OUTPUT);
  pinMode(motor6, OUTPUT);
  pinMode(motor7, OUTPUT);
  pinMode(motor8, OUTPUT);

  // compass setup
  Serial.println("Initialize HMC5883L"); // Initialize HMC5883L
  while (!compass.begin())
  {
    Serial.println("Could not find a valid HMC5883L sensor, check wiring!");
    delay(500);
  }
  compass.setRange(HMC5883L_RANGE_1_3GA); // Set measurement range
  compass.setMeasurementMode(HMC5883L_CONTINOUS); // Set measurement mode
  compass.setDataRate(HMC5883L_DATARATE_30HZ); // Set data rate
  compass.setSamples(HMC5883L_SAMPLES_8); // Set number of samples averaged
  compass.setOffset(201, -106); // Set calibration offset. See HMC5883L_calibration.ino

}

void loop() {

  // heading calculation (from tutorial)
  Vector norm = compass.readNormalize();

  float heading = atan2(norm.YAxis, norm.XAxis); // Calculate heading

  // Set declination angle on your locatio from http://magnetic-declination.com/
  // (+) Positive or (-) for negative
  // For Claremont,CA declination angle is 11'30E (positive)
  // Formula: (deg + (min / 60.0)) / (180 / M_PI);
  float declinationAngle = (11.0 + (30.0 / 60.0)) / (180 / M_PI);

  // fixing heading based on angle
  heading -= declinationAngle;

  // Correct for heading < 0deg and heading > 360deg
  if (heading < 0)
  {
    heading += 2 * PI;
  }
  if (heading > 2 * PI)
  {
    heading -= 2 * PI;
  }
  
  // Convert to degrees
  float headingDegrees = heading * 180/M_PI; 


  // turn all motors off
  digitalWrite(motor1, HIGH); 
  digitalWrite(motor2, HIGH);
  digitalWrite(motor3, HIGH);  
  digitalWrite(motor4, HIGH);  
  digitalWrite(motor5, HIGH); 
  digitalWrite(motor6, HIGH);  
  digitalWrite(motor7, HIGH);  
  digitalWrite(motor8, HIGH);  

  Serial.println();
  Serial.print(headingDegrees);

  // determining correct motor
  if ((0 < headingDegrees) && (headingDegrees < 45))
  {
    // motor1 on
    Serial.print("motor1 on"); 
    motor = 1;
    
  }
  else if ((45 < headingDegrees) && (headingDegrees < 90))
  {
    // motor2 on
    Serial.print("motor2 on"); 
    motor = 2;
  } 
  else if ((90 < headingDegrees) && (headingDegrees < 135))
  {
    //motor3 on
    Serial.print("motor3 on"); 
    motor = 3;
  }
  else if ((135 < headingDegrees) && (headingDegrees < 180))
  {
    //motor4 on
    Serial.print("motor4 on"); 
    motor = 4;
  }
  else if ((180 < headingDegrees) && (headingDegrees < 225))
  {
    //motor5 on
    Serial.print("motor5 on"); 
    motor = 5;
  }
  else if ((225 < headingDegrees) && (headingDegrees < 270))
  {
    //motor6 on
    Serial.print("motor6 on"); 
    motor = 6;
  }
  else if ((270 < headingDegrees) && (headingDegrees < 315))
  {
    //motor7 on
    Serial.print("motor7 on"); 
    motor = 7;
  }
  else if ((315 < headingDegrees) && (headingDegrees < 360))
  {
    //motor8 on
    Serial.print("motor8 on"); 
    motor = 8;
  }

  // turn correct motor on 
  if (motor == 1) {
    digitalWrite(motor8, LOW);  //vibrate
  } 
  else if (motor == 2 ){
    digitalWrite(motor1, LOW);  //vibrate
  } 
  else if (motor == 3 ){
    digitalWrite(motor2, LOW);  //vibrate
  } 
  else if (motor == 4 ){
    digitalWrite(motor3, LOW);  //vibrate
  } 
  else if (motor == 5 ){
    digitalWrite(motor4, LOW);  //vibrate
  } 
  else if (motor == 6 ){
    digitalWrite(motor5, LOW);  //vibrate
  } 
  else if (motor == 7 ){
    digitalWrite(motor6, LOW);  //vibrate
  } 
  else if (motor == 8 ){
    digitalWrite(motor7, LOW);  //vibrate
  } 

  delay(100);                 
}