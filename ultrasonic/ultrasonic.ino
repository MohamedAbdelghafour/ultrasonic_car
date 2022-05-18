
#include <NewPing.h>
#include <Servo.h> 

#define TRIG_PIN A1 
#define ECHO_PIN A0 
#define MAX_DISTANCE 200 
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 
Servo myservo;   

boolean goesForward=false;
int distance = 100;
int speedSet = 0;

//Motor A
int PWMR = 11;
int motorPin1  = 12;  // Forward
int motorPin2  =11;  // Reverse

//Motor B
int PWML = 12;
int motorPin3  = 3;  //
int motorPin4  = 2;  //


void setup() {

  myservo.attach(8);  
  myservo.write(115); 
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(PWMR, OUTPUT);
  pinMode(PWML, OUTPUT);
}

void loop() {
  analogWrite(PWMR,200);
  analogWrite(PWML,100) ; 
 int distanceR = 0;
 int distanceL =  0;
 delay(40);
 
 if(distance<=20)
 {
//  moveStop();
  //delay(100);
  //moveBackward();
  //delay(300);
  moveStop();
  delay(200);
  distanceR = lookRight();
  delay(200);
  distanceL = lookLeft();
  delay(200);

  if(distanceR>=distanceL)
  {
    turnRight();
    //moveStop();
  }else
  {
    turnLeft();
    //moveStop();
  }
 }else
 {
  moveForward();
 }
 distance = readPing();
}

int lookRight()
{
    myservo.write(50); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
}

int lookLeft()
{
    myservo.write(170); 
    delay(500);
    int distance = readPing();
    delay(100);
    myservo.write(115); 
    return distance;
    delay(100);
}

int readPing() { 
  delay(70);
  int cm = sonar.ping_cm();
  if(cm==0)
  {
    cm = 250;
  }
  return cm;
}

void moveStop() {
  analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 0);
  } 
  
void moveForward() {


    analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
    analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);  
  
}

void moveBackward() {
    
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);
    analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);   
  
}  

void turnRight() {
 analogWrite(motorPin1, 180);
    analogWrite(motorPin2, 0);
  analogWrite(motorPin3, 0);
    analogWrite(motorPin4, 180);    
  delay(300);
 moveForward();      
  
} 
 
void turnLeft() {
  analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 180);   
 analogWrite(motorPin3, 180);
    analogWrite(motorPin4, 0);     
  delay(300);
   moveForward();
}  
