# Denbit
Training wheels for the nodemcu
-------------------------------------------------------------
![image](https://raw.githubusercontent.com/theapi/denbit/master/kicad/basic/basic.png)

##Installation
- Mac users need to install the driver from [www.silabs.com][1] ([direct link][2]).

- Download and install the [Aduino IDE](https://www.arduino.cc/en/Main/Software)

- Install the NodeMCU "board" into the Arduino IDE:
 - Install Arduino 1.6.9 from the Arduino website.
 - Start Arduino and open Preferences window.
 - Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field. You can add multiple URLs, separating them with commas.
 - Open Boards Manager from Tools > Board menu and install esp8266 platform (and don't forget to select your ESP8266 board from Tools > Board menu after installation).
 - Install the denbit library 
  - [Download the latest release of this repo from](https://github.com/theapi/denbit/releases)
  - Sketch -> Include Library -> Add .ZIP Library... then select the file downloaded in the step above.
 - Connect the denbit to the usb port of the computer.
 - Load the test "sketch"
  - File -> Examples -> Denbit -> SmokeTest
 - Compile the software: click the tick in the top left of the Arduino application... wait while it compiles...
 - Upload the software: click the arrow in the top left of the Arduino application... wait while it uploads
  - The led will be blue while it uploads. 

[1]:https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx
[2]:https://www.silabs.com/Support%20Documents/Software/Mac_OSX_VCP_Driver.zip
