
/** 
  Servo Sweep
*/


#include <Servo.h>

// Include the Denbit library.
#include <Denbit.h>
// Initialize the denbit.
Denbit denbit;


Servo myservo;  // create servo object to control a servo
// more than one servo objects can be created

int pos = 0;    // variable to store the servo position

void setup() {
  myservo.attach(4);  // attaches the servo to the output pin
}

void loop() {
  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

