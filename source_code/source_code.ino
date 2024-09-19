#include <Servo.h>

#define THRESHOLD 150 //state of the hand (opened/closed)
#define EMGPIN 3      //Muscle Sensor V3 Board
#define LITTLEPIN  2  //Little servo
#define RINGPIN    3  //Ring servo
#define MIDDLEPIN  4  //Middle servo
#define INDEXPIN   5  //Index servo
#define THUMBPIN   6  //Thumb servo

#define LITTLE 1 
#define RING   2
#define MIDDLE 3
#define INDEX  4
#define THUMB  5

Servo servoLittleFinger;         
Servo servoRingFinger;         
Servo servoMiddleFinger;        
Servo servoIndexFinger;         
Servo servoThumbFinger;         

int finger;


// Motion routines for handopen and handclose
void openhand()
{
  for(finger = 1; finger < 6; finger++)
  {
    openFinger(finger);
  }
}

void closehand()
{
  for(finger = 1; finger < 6 ; finger++)
  {
    closeFinger(finger);
  }
}


// open and close the fingers 
void openFinger(int finger)
{

  if(finger==LITTLE)
  {
    servoLittleFinger.write(0);
  } 
  else if(finger==RING)
  {
    servoRingFinger.write(170);
  }
  else if(finger==MIDDLE)
  {
    servoMiddleFinger.write(170);
  }
  else if(finger==INDEX)
  {
    servoIndexFinger.write(170);
  }
  else if(finger==THUMB)
  {
    servoThumbFinger.write(0);
  }

}


void closeFinger(int finger)
{
  if(finger==LITTLE)
  {
    servoLittleFinger.write(170);
  } 
  else if(finger==RING)
  {
    servoRingFinger.write(0);
  }
  else if(finger==MIDDLE)
  {
    servoMiddleFinger.write(0);
  }
  else if(finger==INDEX)
  {
    servoIndexFinger.write(0);
  }
  else if(finger==THUMB)
  {
    servoThumbFinger.write(170);
  }
}


void setup()
{
  Serial.begin(115200); 

  servoLittleFinger.attach(LITTLEPIN); 
  servoRingFinger.attach(RINGPIN); 
  servoMiddleFinger.attach(MIDDLEPIN);  
  servoIndexFinger.attach(INDEXPIN); 
  servoThumbFinger.attach(THUMBPIN);  
}


void loop() 
{
  int value = analogRead(EMGPIN); 

  if(value>THRESHOLD)
  {
    closehand();
  }
  else 
  {
    openhand();
  }

  Serial.println(value); 
}