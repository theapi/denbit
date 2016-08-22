# Knock

Knock Sensor
   This sketch reads a piezo element to detect a knocking sound.
   
   It reads an analog pin and compares the result to a set threshold.
   
   If the result is greater than the threshold, it writes
   "knock" to the serial port, and toggles the LED on pin 13.
   
   The circuit:
   
	 + connection of the piezo attached to analog in 0
	 
	 - connection of the piezo attached to ground
	 
	 -1-megohm resistor attached from analog in 0 to ground


![image](img/knock_bb.png)

### The Knock sketch
- `File -> Examples -> Denbit -> Sensors -> Knock`
- Compile the software: click the tick in the top left of the Arduino application... wait while it compiles...
- Upload the software: click the arrow in the top left of the Arduino application... wait while it uploads
