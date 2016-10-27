# Denbit
Training wheels for the NodeMCU
-------------------------------------------------------------
![image](https://raw.githubusercontent.com/theapi/denbit/master/kicad/basic/denbit_front.png)

##Installation



- Download and install the [Aduino IDE](https://www.arduino.cc/en/Main/Software) plus any drivers it asks too. 
 You can use the free version with the `JUST DOWNLOAD` link. No need to donate money.

- Install the NodeMCU "board" into the Arduino IDE:
 - Start Arduino and open Preferences window.
 - Enter http://arduino.esp8266.com/stable/package_esp8266com_index.json into Additional Board Manager URLs field and click `Ok`:
 
 ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/prefs.png )

 - Open the Boards Manager `Tools > Board > Boards Manager...`:
 
 ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/board_manager_select.png)

 - Scroll down to `esp8266 by ESP8266 Community`, click `More info` and select version 2.2.0 then click install:
 
 ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/board_manager.png)

 - Click `Close` once it installed

 - Select the NodeMCU 1.0 board from `Tools > Board menu` and select `NodeMCU 1.0 (ESP-12E Module)`:
 
 ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/board_selected.png)

- Install the denbit library 
 - [Download the latest release of this repo](https://github.com/theapi/denbit/archive/v1.0.9.zip)
 - `Sketch -> Include Library -> Add .ZIP Library...` then select the file downloaded in the step above.
 
- Rename ~/Documents/Arduino/libraries/denbit/src/default_config.h to config.h
and edit its content to have the wifi access details and your denbit's name.

- Mac users, if programming with a usb cable, install the driver from [www.silabs.com][1] ([direct link][2]).

## Make it do something...
- Connect the denbit to the usb port of the computer.
- Select the `Port` the usb is connected to
 - On a Mac it will be `/dev/cu.SLAB_USBtoUART` 
 - On Windows it will be `COMM` and a number so something like `COMM4`
- Load the Blink "sketch"
 - `File -> Examples -> Denbit -> Basics -> Blink`
 - Compile (verify) the software: click the tick in the top left of the Arduino application... 
 
  ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/compile.png)

 - wait while it compiles...
 
  ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/compiling.png) 
 
 - Upload the software: click the arrow in the top left of the Arduino application:
 
  ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/upload.png)

 - wait while it uploads...
 
  ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/uploading.png)

  - The center light will be blue while it uploads. 

  ![](https://raw.githubusercontent.com/theapi/denbit/master/docs/img/done_uploading.png) 

  - When the Arduino window says *"Done uploading"* the green light will blink on & off
 - Change the Blink sketch so that `delay(1000)` is `delay(500)`, then compile & upload again. The green LED will now blink twice as fast
 
 
## Play with the Denbit Basic examples
- [Fade](docs/examples/Basics/Fade.md)
- [DigitalReadSerial](docs/examples/Basics/DigitalReadSerial.md)
- [AnalogReadSerial](docs/examples/Basics/AnalogReadSerial.md)
- [Denbit](docs/examples/Basics/Denbit.md)
- [Knob](docs/examples/Basics/Knob.md)

## Play with servos
- [ServoSweep](docs/examples/Servo/ServoSweep.md)
- [ServoKnob](docs/examples/Servo/ServoKnob.md)

## Then use some sensors
- [Temperature](docs/examples/Sensors/Temperature.md)
- [Knock](docs/examples/Sensors/Knock.md)

[1]:https://www.silabs.com/products/mcu/Pages/USBtoUARTBridgeVCPDrivers.aspx
[2]:https://www.silabs.com/Support%20Documents/Software/Mac_OSX_VCP_Driver.zip
