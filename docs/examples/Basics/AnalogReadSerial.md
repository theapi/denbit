# AnalogReadSerial

This example shows you how to monitor the value of the analog pin A0, by establishing serial communication 
between your Denbit and your computer over USB. 

Just put a wire into the connector marked A0 as this is the analog input:
![image](img/analog_read_bb.png)

### Load the AnalogReadSerial sketch
- `File -> Examples -> Denbit -> Basics -> AnalogReadSerial`
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

### Touch
Touch & relaease the wire and see how the numbers/graph changes. 

### Why?
This demonstrates reading voltage on the analog pin A0 and seeing that data.

Further info is here [https://www.arduino.cc/en/Tutorial/AnalogReadSerial](https://www.arduino.cc/en/Tutorial/AnalogReadSerial)
