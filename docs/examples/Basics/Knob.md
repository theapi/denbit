# Knob

This example shows you how to monitor the value of a knob (potentiometer) by establishing serial communication 
between your Denbit and your computer over USB. 

![image](img/potentiometer_bb.png)

### Load the Knob sketch
- `File -> Examples -> Denbit -> Basics -> Knob`
- Compile the software: click the tick in the top left of the Arduino application... wait while it compiles...
- Upload the software: click the arrow in the top left of the Arduino application... wait while it uploads
 
### Open the serial monitor
Click the magnifiying class icon in the top right of the Arduino application.
  
The serial monitor needs to be listening at "115200 baud", 
so set the value in the baud selector to `115200 baud`.

If the wrong value is set, only gibberish will appear on the monitor. 

### Serial Plotter
Instead of using the serial monitor, you can see a graphical representation of the data by closing the serial monitor
and opening the serial plotter instead (Tools > Serial Plotter menu). 

The serial monitor & the serial plotter cannot both be used at the same time

### Why?
This demonstrates reading a variable voltage on the analog pin A0 and using that data.

