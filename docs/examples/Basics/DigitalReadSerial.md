# DigitalReadSerial

This example shows you how to monitor the state of the left switch by establishing serial communication 
between your Denbit and your computer over USB. 


### Load the DigitalReadSerial sketch
- `File -> Examples -> Denbit -> Basics -> DigitalReadSerial`
- Compile the software: click the tick in the top left of the Arduino application... wait while it compiles...
- Upload the software: click the arrow in the top left of the Arduino application... wait while it uploads
 
### Open the serial monitor
Click the magnifiying class icon in the top right of the Arduino application.
  
The serial monitor needs to be listening at "115200 baud", 
so set the value in the baud selector to `115200 baud`.

If the wrong value is set, only gibberish will appear on the monitor. 

### Click the left button on the Denbit 
- while watching the 1's change to 0's on the serial monitor

### Why?
This demonstrates a basic way to communicate to other systems. Handy for many things like:
- Debugging
- Graphing
- Sending commands
- etc

Further info is here [https://www.arduino.cc/en/Tutorial/DigitalReadSerial]
