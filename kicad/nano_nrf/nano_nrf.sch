EESchema Schematic File Version 2
LIBS:nano_nrf-rescue
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:nano_nrf-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "jeu. 02 avril 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L CONN_15 P1
U 1 1 551D9496
P 9625 2000
F 0 "P1" V 9595 2050 60  0000 C CNN
F 1 "Digital" V 9705 2050 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x15" H 9625 2050 60  0001 C CNN
F 3 "" H 9625 2050 60  0000 C CNN
	1    9625 2000
	1    0    0    -1  
$EndComp
$Comp
L CONN_15 P2
U 1 1 551D94EF
P 10000 2000
F 0 "P2" V 9970 2050 60  0000 C CNN
F 1 "Analog" V 10080 2050 60  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x15" H 10000 2050 60  0001 C CNN
F 3 "" H 10000 2050 60  0000 C CNN
	1    10000 2000
	-1   0    0    -1  
$EndComp
Text Label 8575 1300 0    60   ~ 0
1(Tx)
Text Label 8575 1400 0    60   ~ 0
0(Rx)
Text Label 8575 1500 0    60   ~ 0
Reset
Text Label 8575 1700 0    60   ~ 0
2
Text Label 8575 1800 0    60   ~ 0
3(**)
Text Label 8575 1900 0    60   ~ 0
4
Text Label 8575 2000 0    60   ~ 0
5(**)
Text Label 8575 2100 0    60   ~ 0
6(**)
Text Label 8550 2200 0    60   ~ 0
7
Text Label 8550 2300 0    60   ~ 0
8
Text Label 8575 2400 0    60   ~ 0
9(**)
Text Label 8575 2500 0    60   ~ 0
10(**/SS)
Text Label 7800 3675 0    60   ~ 0
11(MISO)
Text Label 8550 2700 0    60   ~ 0
12(MOSI)
Text Label 10775 2700 0    60   ~ 0
13(SCK)
Text Label 10750 2400 0    60   ~ 0
A0
Text Label 10750 2300 0    60   ~ 0
A1
Text Label 10750 2200 0    60   ~ 0
A2
Text Label 10750 2100 0    60   ~ 0
A3
Text Label 10750 2000 0    60   ~ 0
A4
Text Label 10750 1900 0    60   ~ 0
A5
Text Label 10750 1800 0    60   ~ 0
A6
Text Label 10750 1700 0    60   ~ 0
A7
$Comp
L +3.3V-RESCUE-nano_nrf #PWR01
U 1 1 551D9E93
P 10675 1125
F 0 "#PWR01" H 10675 1085 30  0001 C CNN
F 1 "+3.3V" H 10675 1235 30  0000 C CNN
F 2 "" H 10675 1125 60  0000 C CNN
F 3 "" H 10675 1125 60  0000 C CNN
	1    10675 1125
	1    0    0    -1  
$EndComp
Text Label 10750 2500 0    60   ~ 0
AREF
$Comp
L +5V #PWR02
U 1 1 551D9FBD
P 10550 1125
F 0 "#PWR02" H 10550 1215 20  0001 C CNN
F 1 "+5V" H 10550 1215 30  0000 C CNN
F 2 "" H 10550 1125 60  0000 C CNN
F 3 "" H 10550 1125 60  0000 C CNN
	1    10550 1125
	1    0    0    -1  
$EndComp
Text Label 10750 1500 0    60   ~ 0
Reset
Text Notes 8500 575  0    60   ~ 0
Shield for Arduino Nano
Wire Wire Line
	8550 2700 9275 2700
Wire Wire Line
	8550 2600 9275 2600
Wire Wire Line
	8550 2500 9275 2500
Wire Wire Line
	8550 2400 9275 2400
Wire Wire Line
	8550 2300 9275 2300
Wire Wire Line
	8550 2200 9275 2200
Wire Wire Line
	8550 2100 9275 2100
Wire Wire Line
	8550 2000 9275 2000
Wire Wire Line
	8550 1900 9275 1900
Wire Wire Line
	8550 1800 9275 1800
Wire Wire Line
	8550 1700 9275 1700
Wire Wire Line
	8550 1500 9275 1500
Wire Wire Line
	8550 1400 9275 1400
Wire Wire Line
	8550 1300 9275 1300
Wire Wire Line
	9200 1600 9200 2875
Wire Wire Line
	9200 1600 9275 1600
Text Label 10425 1125 1    60   ~ 0
Vin
Wire Wire Line
	10425 1125 10425 1300
Wire Wire Line
	10425 1300 10350 1300
Wire Wire Line
	10350 2600 10675 2600
Wire Wire Line
	10350 1600 10550 1600
Wire Wire Line
	10550 1600 10550 1125
Wire Wire Line
	10675 2600 10675 1125
Wire Wire Line
	10425 1400 10425 2875
Wire Notes Line
	11225 3100 8525 3100
Wire Wire Line
	10350 1500 11125 1500
Wire Wire Line
	10350 1700 11125 1700
Wire Wire Line
	10350 1800 11125 1800
Wire Wire Line
	10350 1900 11125 1900
Wire Wire Line
	10350 2000 11125 2000
Wire Wire Line
	10350 2100 11125 2100
Wire Wire Line
	10350 2200 11125 2200
Wire Wire Line
	10350 2300 11125 2300
Wire Wire Line
	10350 2400 11125 2400
Wire Wire Line
	10350 2500 11125 2500
Wire Wire Line
	10350 2700 10775 2700
Wire Notes Line
	8475 475  8475 3100
Wire Notes Line
	8475 650  9675 650 
Wire Notes Line
	9675 650  9675 475 
$Comp
L CONN_02X04 P3
U 1 1 571623F2
P 7350 3825
F 0 "P3" H 7350 4075 50  0000 C CNN
F 1 "CONN_02X04" H 7350 3575 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_2x04" H 7350 2625 50  0001 C CNN
F 3 "" H 7350 2625 50  0000 C CNN
	1    7350 3825
	-1   0    0    1   
$EndComp
$Comp
L GND #PWR03
U 1 1 571625F5
P 10425 2875
F 0 "#PWR03" H 10425 2625 50  0001 C CNN
F 1 "GND" H 10425 2725 50  0000 C CNN
F 2 "" H 10425 2875 50  0000 C CNN
F 3 "" H 10425 2875 50  0000 C CNN
	1    10425 2875
	1    0    0    -1  
$EndComp
Wire Wire Line
	10350 1400 10425 1400
$Comp
L GND #PWR04
U 1 1 57162899
P 9200 2875
F 0 "#PWR04" H 9200 2625 50  0001 C CNN
F 1 "GND" H 9200 2725 50  0000 C CNN
F 2 "" H 9200 2875 50  0000 C CNN
F 3 "" H 9200 2875 50  0000 C CNN
	1    9200 2875
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 57162953
P 7600 3975
F 0 "#PWR05" H 7600 3725 50  0001 C CNN
F 1 "GND" H 7600 3825 50  0000 C CNN
F 2 "" H 7600 3975 50  0000 C CNN
F 3 "" H 7600 3975 50  0000 C CNN
	1    7600 3975
	1    0    0    -1  
$EndComp
Text Label 10675 1350 0    60   ~ 0
3V3
Wire Wire Line
	6625 3975 7100 3975
Wire Wire Line
	7600 3675 7800 3675
NoConn ~ 7100 3675
Text Label 7800 3775 0    60   ~ 0
13(SCK)
Text Label 8550 2600 0    60   ~ 0
11(MISO)
Text Label 6625 3775 0    60   ~ 0
12(MOSI)
Text Label 6625 3875 0    60   ~ 0
8
Text Label 6625 3975 0    60   ~ 0
3V3
Text Label 7800 3875 0    60   ~ 0
7
Wire Wire Line
	7100 3775 6625 3775
Wire Wire Line
	7100 3875 6625 3875
Wire Wire Line
	7600 3775 7800 3775
Wire Wire Line
	7600 3875 7800 3875
$EndSCHEMATC
