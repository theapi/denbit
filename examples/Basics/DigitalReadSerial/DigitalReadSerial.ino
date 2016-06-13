/*
  DigitalReadSerial
  Reads a digital input on pin 2, prints the result to the serial monitor.
  
  To see the serial monitor, click the magnifiying class icon in the top right.
  The serial monitor needs to be listening at "115200 baud", 
  so set the value in the bottom left to 115200 baud.
  If the wrong value is set, only gibberish will appear on the monitor. 
  
  Pin 2 to is attached to the left button on the Denbit.
 */

// Assign the pin number a name:
int leftButton = 2;

/**
 * The setup function runs once when you press reset.
 */
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
  
  // make the leftButton's pin an input that is a 1 (HIGH) when not pressed.
  pinMode(leftButton, INPUT_PULLUP);
}

/**
 * The loop function runs over and over again forever.
 */
void loop() {
  // read the input pin:
  int buttonState = digitalRead(leftButton);
  
  // print out the state of the button:
  Serial.println(buttonState);
  
  // delay in between reads for stability
  delay(100);        
}

