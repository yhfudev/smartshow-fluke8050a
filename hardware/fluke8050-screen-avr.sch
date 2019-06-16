EESchema Schematic File Version 2
LIBS:fluke8050-screen-rescue
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
LIBS:nodemcu
LIBS:arduino
LIBS:ssd1306
LIBS:mostek
LIBS:arduino_micro_shield
LIBS:maplemini
LIBS:dk_Logic-Buffers-Drivers-Receivers-Transceivers
EELAYER 25 0
EELAYER END
$Descr USLetter 11000 8500
encoding utf-8
Sheet 2 3
Title "Display and Data Log Mod for Fluke 8050a"
Date "2018-10-26"
Rev "1.0"
Comp "Yunhui Fu <yhfudev@gmail.com>"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L NodeMCU_0.9_Vraw U?
U 1 1 5BBBC88B
P 5650 1600
F 0 "U?" H 5650 2400 50  0000 C CNN
F 1 "NodeMCU_0.9_Vraw" H 5650 750 50  0000 C CNN
F 2 "" H 5900 1600 50  0000 C CNN
F 3 "" H 5900 1600 50  0000 C CNN
	1    5650 1600
	1    0    0    -1  
$EndComp
$Comp
L ARDUINO-NANO U?
U 1 1 5BBBC94B
P 2350 5900
F 0 "U?" H 2600 7200 70  0000 L BNN
F 1 "ARDUINO-NANO" H 2600 7050 70  0000 L BNN
F 2 "DIP30M6-ARDUINO-NANO" H 2600 6900 60  0001 L BNN
F 3 "" H 2350 5900 60  0000 C CNN
	1    2350 5900
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5BBBC9A0
P 7750 3600
F 0 "R?" V 7830 3600 50  0000 C CNN
F 1 "1k" V 7750 3600 50  0000 C CNN
F 2 "" V 7680 3600 50  0001 C CNN
F 3 "" H 7750 3600 50  0001 C CNN
	1    7750 3600
	0    1    1    0   
$EndComp
Text GLabel 1050 2500 0    60   Output ~ 0
Fa
Text GLabel 1050 2300 0    60   Output ~ 0
Fb
Text GLabel 1050 2400 0    60   Output ~ 0
Fc
Text GLabel 1050 2600 0    60   Output ~ 0
Fd
Text GLabel 1050 3200 0    60   Output ~ 0
ST4
Text GLabel 1050 3300 0    60   Output ~ 0
ST3
Text GLabel 1050 3400 0    60   Output ~ 0
ST2
Text GLabel 1050 3500 0    60   Output ~ 0
ST1
Text GLabel 1050 3600 0    60   Output ~ 0
ST0
Text GLabel 3350 1700 2    60   Output ~ 0
HV
Text GLabel 3350 1500 2    60   Output ~ 0
W
Text GLabel 3350 1400 2    60   Output ~ 0
X
Text GLabel 3350 1300 2    60   Output ~ 0
Y
Text GLabel 3350 1200 2    60   Output ~ 0
Z
Text GLabel 3350 1600 2    60   Output ~ 0
DP
Text GLabel 1050 2000 0    60   Output ~ 0
RNGa
Text GLabel 1050 2100 0    60   Output ~ 0
RNGb
Text GLabel 1050 2200 0    60   Output ~ 0
RNGc
Text GLabel 3200 6700 2    60   Input ~ 0
ST4
Text GLabel 1500 6100 0    60   Input ~ 0
ST3
Text GLabel 1500 5950 0    60   Input ~ 0
ST2
Text GLabel 1500 5800 0    60   Input ~ 0
ST1
Text GLabel 1500 5650 0    60   Input ~ 0
ST0
Text GLabel 1500 6550 0    60   Input ~ 0
HV
Text GLabel 3200 6100 2    60   Input ~ 0
W
Text GLabel 3200 6250 2    60   Input ~ 0
X
Text GLabel 3200 6400 2    60   Input ~ 0
Y
Text GLabel 3200 6550 2    60   Input ~ 0
Z
Text GLabel 750  6400 0    60   Input ~ 0
DP
Text GLabel 3200 6850 2    60   Input ~ 0
RNGa
Text GLabel 3200 5800 2    60   Input ~ 0
RNGb
$Comp
L R R?
U 1 1 5BBBF566
P 7950 3800
F 0 "R?" V 8030 3800 50  0000 C CNN
F 1 "2k" V 7950 3800 50  0000 C CNN
F 2 "" V 7880 3800 50  0001 C CNN
F 3 "" H 7950 3800 50  0001 C CNN
	1    7950 3800
	-1   0    0    1   
$EndComp
Wire Wire Line
	7950 3600 7950 3650
$Comp
L GND #PWR?
U 1 1 5BBBF641
P 7950 4050
F 0 "#PWR?" H 7950 3800 50  0001 C CNN
F 1 "GND" H 7950 3900 50  0000 C CNN
F 2 "" H 7950 4050 50  0001 C CNN
F 3 "" H 7950 4050 50  0001 C CNN
	1    7950 4050
	1    0    0    -1  
$EndComp
Connection ~ 7950 3600
Text GLabel 6200 1800 2    60   Input ~ 0
ESP_RX
Text GLabel 6200 1900 2    60   Output ~ 0
ESP_TX
Wire Wire Line
	6200 1200 6100 1200
Text GLabel 3200 7000 2    60   Input ~ 0
ESP_TX_5V
Text GLabel 8000 3600 2    60   Output ~ 0
ESP_RX
Wire Wire Line
	3200 6850 3050 6850
Wire Wire Line
	3050 6700 3200 6700
Wire Wire Line
	3200 6550 3050 6550
Wire Wire Line
	3200 6400 3050 6400
Wire Wire Line
	3050 6250 3200 6250
Wire Wire Line
	3200 6100 3050 6100
Wire Wire Line
	3200 5950 3050 5950
Wire Wire Line
	3050 5800 3200 5800
Wire Wire Line
	3200 7000 3050 7000
Wire Wire Line
	3050 7150 3200 7150
Wire Wire Line
	1500 6400 1650 6400
Wire Wire Line
	1500 5650 1650 5650
Wire Wire Line
	1650 5800 1500 5800
Wire Wire Line
	1500 5950 1650 5950
Wire Wire Line
	1650 6100 1500 6100
Wire Wire Line
	1500 6250 1650 6250
Wire Wire Line
	3350 1200 3200 1200
Wire Wire Line
	3200 1300 3350 1300
Wire Wire Line
	3350 1400 3200 1400
Wire Wire Line
	3200 1500 3350 1500
Wire Wire Line
	3350 1600 3200 1600
Wire Wire Line
	3200 1700 3350 1700
Wire Wire Line
	1200 2000 1050 2000
Wire Wire Line
	1050 2100 1200 2100
Wire Wire Line
	1200 2200 1050 2200
Wire Wire Line
	1050 2300 1200 2300
Wire Wire Line
	1200 2400 1050 2400
Wire Wire Line
	1050 2500 1200 2500
Wire Wire Line
	1050 3200 1200 3200
Wire Wire Line
	1200 3300 1050 3300
Wire Wire Line
	1050 3400 1200 3400
Wire Wire Line
	1200 3500 1050 3500
Wire Wire Line
	1050 3600 1200 3600
Wire Wire Line
	1050 2600 1200 2600
$Comp
L +5V #PWR?
U 1 1 5BBCAD3E
P 2350 4650
F 0 "#PWR?" H 2350 4500 50  0001 C CNN
F 1 "+5V" H 2350 4790 50  0000 C CNN
F 2 "" H 2350 4650 50  0001 C CNN
F 3 "" H 2350 4650 50  0001 C CNN
	1    2350 4650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BBCAD7D
P 2400 7600
F 0 "#PWR?" H 2400 7350 50  0001 C CNN
F 1 "GND" H 2400 7450 50  0000 C CNN
F 2 "" H 2400 7600 50  0001 C CNN
F 3 "" H 2400 7600 50  0001 C CNN
	1    2400 7600
	1    0    0    -1  
$EndComp
Wire Wire Line
	2400 7450 2400 7600
Wire Wire Line
	2250 7450 2250 7500
Wire Wire Line
	2250 7500 2400 7500
Connection ~ 2400 7500
Wire Wire Line
	2350 4650 2350 4750
$Comp
L +3.3V #PWR?
U 1 1 5BBCAEAF
P 2200 4650
F 0 "#PWR?" H 2200 4500 50  0001 C CNN
F 1 "+3.3V" H 2200 4790 50  0000 C CNN
F 2 "" H 2200 4650 50  0001 C CNN
F 3 "" H 2200 4650 50  0001 C CNN
	1    2200 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4650 2200 4750
$Comp
L GND #PWR?
U 1 1 5BBCAF50
P 6150 2450
F 0 "#PWR?" H 6150 2200 50  0001 C CNN
F 1 "GND" H 6150 2300 50  0000 C CNN
F 2 "" H 6150 2450 50  0001 C CNN
F 3 "" H 6150 2450 50  0001 C CNN
	1    6150 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 2200 6150 2200
Wire Wire Line
	6150 1500 6150 2450
$Comp
L +5V #PWR?
U 1 1 5BBCAFEF
P 4900 2300
F 0 "#PWR?" H 4900 2150 50  0001 C CNN
F 1 "+5V" H 4900 2440 50  0000 C CNN
F 2 "" H 4900 2300 50  0001 C CNN
F 3 "" H 4900 2300 50  0001 C CNN
	1    4900 2300
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BBCB0BD
P 5150 2450
F 0 "#PWR?" H 5150 2200 50  0001 C CNN
F 1 "GND" H 5150 2300 50  0000 C CNN
F 2 "" H 5150 2450 50  0001 C CNN
F 3 "" H 5150 2450 50  0001 C CNN
	1    5150 2450
	1    0    0    -1  
$EndComp
Wire Wire Line
	5200 2200 5150 2200
Wire Wire Line
	5150 1800 5150 2450
Wire Wire Line
	5200 1800 5150 1800
Connection ~ 5150 2200
Wire Wire Line
	6100 1500 6150 1500
Connection ~ 6150 2200
Text GLabel 3600 5200 2    60   Output ~ 0
LCD_SPI_SCL
Text GLabel 3600 5800 2    60   Output ~ 0
LCD_SPI_DC
Text GLabel 3600 5500 2    60   Output ~ 0
LCD_SPI_SDA
Text GLabel 3600 5650 2    60   Output ~ 0
LCD_SPI_CS
Wire Wire Line
	3050 5200 3200 5200
Wire Wire Line
	3200 5350 3050 5350
Wire Wire Line
	3050 5500 3200 5500
Wire Wire Line
	3200 5650 3050 5650
Text GLabel 1500 7000 0    60   Output ~ 0
LCD_SPI_RES
Text GLabel 6200 1000 2    60   Output ~ 0
OLED_I2C_SCL
Text GLabel 6200 1100 2    60   BiDi ~ 0
OLED_I2C_SDA
Wire Wire Line
	6100 1000 6200 1000
Wire Wire Line
	6200 1100 6100 1100
Text GLabel 6200 1600 2    60   Output ~ 0
OLED_SPI_SCL
Text GLabel 6200 1300 2    60   Output ~ 0
OLED_SPI_SDA
Text GLabel 6200 1200 2    60   Output ~ 0
OLED_SPI_DC
Text GLabel 4950 2000 1    60   Output ~ 0
OLED_SPI_RST
Wire Wire Line
	4900 2300 5200 2300
Wire Wire Line
	6200 1300 6100 1300
Wire Wire Line
	6100 1800 6200 1800
Wire Wire Line
	6200 1600 6100 1600
Wire Wire Line
	6100 1900 6200 1900
Wire Wire Line
	7900 3600 8000 3600
Wire Wire Line
	7950 3950 7950 4050
Text Notes 3200 3500 0    60   ~ 0
Fluke 8050a U17
$Comp
L ARDUINO_MICRO_SHIELD U?
U 1 1 5BC8A9CF
P 7200 6100
F 0 "U?" H 8950 6500 60  0000 C CNN
F 1 "ARDUINO_MICRO_SHIELD" H 8050 6700 60  0000 C CNN
F 2 "" H 7600 6050 60  0000 C CNN
F 3 "" H 7600 6050 60  0000 C CNN
	1    7200 6100
	0    -1   -1   0   
$EndComp
Text GLabel 7500 4950 2    60   Input ~ 0
ST4
Text GLabel 7500 4850 2    60   Input ~ 0
ST3
Text GLabel 7500 4750 2    60   Input ~ 0
ST2
Text GLabel 7500 4650 2    60   Input ~ 0
ST1
Text GLabel 7500 4550 2    60   Input ~ 0
ST0
Text GLabel 5950 5250 0    60   Input ~ 0
HV
Text GLabel 5950 4750 0    60   Input ~ 0
W
Text GLabel 5950 4850 0    60   Input ~ 0
X
Text GLabel 5950 4950 0    60   Input ~ 0
Y
Text GLabel 5950 5050 0    60   Input ~ 0
Z
Text GLabel 7000 6200 2    60   Input ~ 0
DP
Text GLabel 7500 5150 2    60   Input ~ 0
Fa
Text GLabel 7500 5350 2    60   Input ~ 0
Fb
Text GLabel 5950 5950 0    60   Input ~ 0
Fc
Text GLabel 7500 5450 2    60   Input ~ 0
Fd
Text GLabel 5950 5150 0    60   Input ~ 0
BP
Text GLabel 7500 5250 2    60   Input ~ 0
RNGc
Text GLabel 7500 4450 2    60   Input ~ 0
RNGa
Text GLabel 7500 5050 2    60   Input ~ 0
RNGb
Wire Wire Line
	7500 4450 7400 4450
Wire Wire Line
	7400 4550 7500 4550
Wire Wire Line
	7500 4650 7400 4650
Wire Wire Line
	7400 4750 7500 4750
Wire Wire Line
	7500 4850 7400 4850
Wire Wire Line
	7400 4950 7500 4950
Wire Wire Line
	7500 5050 7400 5050
Wire Wire Line
	7500 5250 7400 5250
Wire Wire Line
	7400 5350 7500 5350
Wire Wire Line
	7500 5450 7400 5450
Wire Wire Line
	7400 5750 7500 5750
Wire Wire Line
	6050 4750 5950 4750
Wire Wire Line
	5950 4850 6050 4850
Wire Wire Line
	6050 4950 5950 4950
Wire Wire Line
	5950 5050 6050 5050
Wire Wire Line
	6050 5150 5950 5150
Wire Wire Line
	5950 5250 6050 5250
Text GLabel 5950 4450 0    60   Output ~ 0
LCD_SPI_DC
Text GLabel 7500 5650 2    60   Output ~ 0
LCD_SPI_RES
Text GLabel 5950 6050 0    60   Output ~ 0
LCD_SPI_SCL
Text GLabel 7500 6050 2    60   Output ~ 0
LCD_SPI_SDA
Text GLabel 7500 5950 2    60   Output ~ 0
LCD_SPI_CS
Wire Wire Line
	7400 5950 7500 5950
Wire Wire Line
	7500 6050 7400 6050
Wire Wire Line
	6050 6050 5950 6050
Wire Wire Line
	5950 4450 6050 4450
Wire Wire Line
	7400 5650 7500 5650
Text GLabel 7500 5750 2    60   Input ~ 0
ESP_TX_5V
Text GLabel 7500 5850 2    60   Output ~ 0
ESP_RX_5V
Text GLabel 3350 1800 2    60   Output ~ 0
BP
Wire Wire Line
	3200 1800 3350 1800
Text GLabel 6850 6200 0    60   Input ~ 0
PIND5_LED
Wire Wire Line
	6050 5950 5950 5950
Text GLabel 3200 5350 2    60   Input ~ 0
Fa
Text GLabel 3200 5650 2    60   Input ~ 0
Fb
Text GLabel 3200 5200 2    60   Input ~ 0
Fc
Text GLabel 3200 5500 2    60   Input ~ 0
Fd
$Comp
L ARDUINO_MICRO_SHIELD U?
U 1 1 5BCA403A
P 9350 2500
F 0 "U?" H 11100 2900 60  0000 C CNN
F 1 "ARDUINO_MICRO_SHIELD" H 10200 3100 60  0000 C CNN
F 2 "" H 9750 2450 60  0000 C CNN
F 3 "" H 9750 2450 60  0000 C CNN
	1    9350 2500
	0    -1   -1   0   
$EndComp
Text GLabel 9650 1350 2    60   Input ~ 0
ST4
Text GLabel 9650 1750 2    60   Input ~ 0
ST3
Text GLabel 9650 1850 2    60   Input ~ 0
ST2
Text GLabel 9650 2150 2    60   Input ~ 0
ST1
Text GLabel 9650 2250 2    60   Input ~ 0
ST0
Text GLabel 8100 1650 0    60   Input ~ 0
HV
Text GLabel 8100 1150 0    60   Input ~ 0
W
Text GLabel 8100 1250 0    60   Input ~ 0
X
Text GLabel 8100 1350 0    60   Input ~ 0
Y
Text GLabel 8100 1450 0    60   Input ~ 0
Z
Text GLabel 8100 1550 0    60   Input ~ 0
DP
Text GLabel 9650 850  2    60   Input ~ 0
Fa
Text GLabel 9650 1650 2    60   Input ~ 0
Fb
Text GLabel 9650 1450 2    60   Input ~ 0
Fc
Text GLabel 9150 2600 2    60   Input ~ 0
Fd
Text GLabel 9650 950  2    60   Input ~ 0
BP
Text GLabel 9650 1250 2    60   Input ~ 0
RNGc
Text GLabel 9650 1050 2    60   Input ~ 0
RNGa
Text GLabel 9650 1150 2    60   Input ~ 0
RNGb
Wire Wire Line
	9650 850  9550 850 
Wire Wire Line
	9550 950  9650 950 
Wire Wire Line
	9650 1050 9550 1050
Wire Wire Line
	9550 1150 9650 1150
Wire Wire Line
	9650 1250 9550 1250
Wire Wire Line
	9550 1350 9650 1350
Wire Wire Line
	9650 1450 9550 1450
Wire Wire Line
	9650 1650 9550 1650
Wire Wire Line
	9550 1750 9650 1750
Wire Wire Line
	9650 1850 9550 1850
Wire Wire Line
	9550 2150 9650 2150
Wire Wire Line
	9650 2250 9550 2250
Wire Wire Line
	8200 1150 8100 1150
Wire Wire Line
	8100 1250 8200 1250
Wire Wire Line
	8200 1350 8100 1350
Wire Wire Line
	8100 1450 8200 1450
Wire Wire Line
	8200 1550 8100 1550
Wire Wire Line
	8100 1650 8200 1650
Text GLabel 8100 850  0    60   Output ~ 0
LCD_SPI_DC
Text GLabel 9650 2050 2    60   Output ~ 0
LCD_SPI_RES
Text GLabel 8100 2450 0    60   Output ~ 0
LCD_SPI_SCL
Text GLabel 9650 2450 2    60   Output ~ 0
LCD_SPI_SDA
Text GLabel 9650 2350 2    60   Output ~ 0
LCD_SPI_CS
Wire Wire Line
	9550 2350 9650 2350
Wire Wire Line
	9650 2450 9550 2450
Wire Wire Line
	8200 2450 8100 2450
Wire Wire Line
	8100 850  8200 850 
Wire Wire Line
	9550 2050 9650 2050
Text GLabel 9000 2600 0    60   Input ~ 0
PIND5_LED
Wire Wire Line
	9000 2600 9150 2600
Text Notes 7850 2900 0    60   ~ 0
Original Fluke 8050a LCD Hack\nhttp://vondervotteimittiss.com/belfry/?p=180
Text Notes 5550 6500 0    60   ~ 0
Fluke 8050a LCD with New INT handler\nhttps://github.com/yhfudev/smartshow-fluke8050a.git
Text Notes 4850 2950 0    60   ~ 0
ESP8266 UART Bridge (UART Swap mode)\nhttps://github.com/jeelabs/esp-link.git
Text Notes 600  7900 0    60   ~ 0
ATMega328p Headless\nhttps://github.com/yhfudev/smartshow-fluke8050a.git
Text GLabel 3350 2800 2    60   Input ~ 0
~OL
Text GLabel 1050 2900 0    60   Input ~ 0
~P.O.R
Text GLabel 3350 2500 2    60   Input ~ 0
AZ+INT-LO+HOLD
Text GLabel 3350 2600 2    60   Input ~ 0
AZ+INT-~LO
Text GLabel 3350 2300 2    60   Input ~ 0
DE(+R)
Text GLabel 3350 2700 2    60   Input ~ 0
AZ+DE(+R)+HOLD
Text GLabel 3350 2400 2    60   Input ~ 0
DE(-R)
Text GLabel 3350 2100 2    60   Input ~ 0
AZ
Text GLabel 1050 3100 0    60   Input ~ 0
AC*100
Text GLabel 1050 3000 0    60   Input ~ 0
AC*1
Text GLabel 1050 2700 0    60   Input ~ 0
T&H
Text GLabel 3350 2200 2    60   Input ~ 0
INT
Wire Wire Line
	1050 2700 1200 2700
Wire Wire Line
	1200 2900 1050 2900
Wire Wire Line
	1050 3000 1200 3000
Wire Wire Line
	1200 3100 1050 3100
Wire Wire Line
	3350 2100 3200 2100
Wire Wire Line
	3200 2200 3350 2200
Wire Wire Line
	3350 2300 3200 2300
Wire Wire Line
	3200 2400 3350 2400
Wire Wire Line
	3350 2500 3200 2500
Wire Wire Line
	3200 2600 3350 2600
Wire Wire Line
	3350 2700 3200 2700
Wire Wire Line
	3200 2800 3350 2800
NoConn ~ 3200 1900
NoConn ~ 1200 1800
NoConn ~ 1200 1500
Wire Wire Line
	7400 5150 7500 5150
Text GLabel 1500 6700 0    60   Input ~ 0
BP
NoConn ~ 3600 5200
NoConn ~ 3600 5800
NoConn ~ 3600 5500
NoConn ~ 3600 5650
NoConn ~ 1500 7000
$Comp
L Crystal_Small Y?
U 1 1 5BCA6B81
P 950 1200
F 0 "Y?" H 950 1300 50  0000 C CNN
F 1 "Crystal_Small" H 950 1100 50  0000 C CNN
F 2 "" H 950 1200 50  0001 C CNN
F 3 "" H 950 1200 50  0001 C CNN
	1    950  1200
	-1   0    0    1   
$EndComp
$Comp
L C_Small C?
U 1 1 5BCA6BEC
P 950 1600
F 0 "C?" H 960 1670 50  0000 L CNN
F 1 "10/16v" H 960 1520 50  0000 L CNN
F 2 "" H 950 1600 50  0001 C CNN
F 3 "" H 950 1600 50  0001 C CNN
	1    950  1600
	0    1    1    0   
$EndComp
Wire Wire Line
	1050 1200 1200 1200
Wire Wire Line
	1200 1600 1050 1600
Wire Wire Line
	850  1200 800  1200
Wire Wire Line
	800  1200 800  1300
Wire Wire Line
	800  1300 1200 1300
$Comp
L MK3870 U?
U 1 1 5BCA6C3A
P 2200 2400
F 0 "U?" H 2200 2550 50  0000 C CNN
F 1 "MK3870" H 2200 2300 50  0000 C CNN
F 2 "" H 2200 2400 50  0001 C CNN
F 3 "" H 2200 2400 50  0001 C CNN
	1    2200 2400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BCA6DF4
P 2200 4050
F 0 "#PWR?" H 2200 3800 50  0001 C CNN
F 1 "GND" H 2200 3900 50  0000 C CNN
F 2 "" H 2200 4050 50  0001 C CNN
F 3 "" H 2200 4050 50  0001 C CNN
	1    2200 4050
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR?
U 1 1 5BCA6E62
P 2200 700
F 0 "#PWR?" H 2200 550 50  0001 C CNN
F 1 "+5V" H 2200 840 50  0000 C CNN
F 2 "" H 2200 700 50  0001 C CNN
F 3 "" H 2200 700 50  0001 C CNN
	1    2200 700 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 4050 2200 4000
$Comp
L +5V #PWR?
U 1 1 5BCA7727
P 7900 1950
F 0 "#PWR?" H 7900 1800 50  0001 C CNN
F 1 "+5V" H 7900 2090 50  0000 C CNN
F 2 "" H 7900 1950 50  0001 C CNN
F 3 "" H 7900 1950 50  0001 C CNN
	1    7900 1950
	1    0    0    -1  
$EndComp
Wire Wire Line
	7900 1950 8200 1950
$Comp
L +5V #PWR?
U 1 1 5BCA7772
P 5750 5550
F 0 "#PWR?" H 5750 5400 50  0001 C CNN
F 1 "+5V" H 5750 5690 50  0000 C CNN
F 2 "" H 5750 5550 50  0001 C CNN
F 3 "" H 5750 5550 50  0001 C CNN
	1    5750 5550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5750 5550 6050 5550
$Comp
L GND #PWR?
U 1 1 5BCA7912
P 700 1650
F 0 "#PWR?" H 700 1400 50  0001 C CNN
F 1 "GND" H 700 1500 50  0000 C CNN
F 2 "" H 700 1650 50  0001 C CNN
F 3 "" H 700 1650 50  0001 C CNN
	1    700  1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4950 2000 4950 2100
Wire Wire Line
	4950 2100 5200 2100
Text GLabel 3200 5950 2    60   Input ~ 0
RNGc
Wire Wire Line
	1500 6700 1650 6700
Wire Wire Line
	1650 6550 1500 6550
Text GLabel 1500 6400 0    60   Output ~ 0
OLED_I2C_SCL
Text GLabel 1500 6250 0    60   BiDi ~ 0
OLED_I2C_SDA
NoConn ~ 750  6400
Text GLabel 6200 2100 2    60   Output ~ 0
ESP_RESET
Text GLabel 1500 7150 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	1500 7150 1650 7150
Text GLabel 6200 2000 2    60   Output ~ 0
ESP_ISP_FLASH
Wire Wire Line
	6100 2000 6200 2000
Wire Wire Line
	6200 2100 6100 2100
Text GLabel 5950 5650 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	5950 5650 6050 5650
$Comp
L LM393 U?
U 1 1 5BD66041
P 9500 3700
F 0 "U?" H 9650 3850 50  0000 C CNN
F 1 "LM393" H 9750 3550 50  0000 C CNN
F 2 "" H 9500 3700 50  0001 C CNN
F 3 "" H 9500 3700 50  0001 C CNN
	1    9500 3700
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5BD66043
P 8950 3850
F 0 "R?" V 9030 3850 50  0000 C CNN
F 1 "200k" V 8950 3850 50  0000 C CNN
F 2 "" V 8880 3850 50  0001 C CNN
F 3 "" H 8950 3850 50  0001 C CNN
	1    8950 3850
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5BD66044
P 8950 4250
F 0 "R?" V 9030 4250 50  0000 C CNN
F 1 "50k" V 8950 4250 50  0000 C CNN
F 2 "" V 8880 4250 50  0001 C CNN
F 3 "" H 8950 4250 50  0001 C CNN
	1    8950 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BD66045
P 8950 4500
F 0 "#PWR?" H 8950 4250 50  0001 C CNN
F 1 "GND" H 8950 4350 50  0000 C CNN
F 2 "" H 8950 4500 50  0001 C CNN
F 3 "" H 8950 4500 50  0001 C CNN
	1    8950 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8950 4000 8950 4100
Wire Wire Line
	9200 3800 9150 3800
Wire Wire Line
	9150 3800 9150 4050
Wire Wire Line
	9150 4050 8950 4050
Connection ~ 8950 4050
Wire Wire Line
	8950 4400 8950 4500
Wire Wire Line
	9400 4000 9400 4450
Wire Wire Line
	9400 4450 8950 4450
Connection ~ 8950 4450
$Comp
L +5V #PWR?
U 1 1 5BD66046
P 9400 3250
F 0 "#PWR?" H 9400 3100 50  0001 C CNN
F 1 "+5V" H 9400 3390 50  0000 C CNN
F 2 "" H 9400 3250 50  0001 C CNN
F 3 "" H 9400 3250 50  0001 C CNN
	1    9400 3250
	1    0    0    -1  
$EndComp
Text Notes 8750 4100 0    60   ~ 0
1v
Text GLabel 8900 3600 0    60   Input ~ 0
ESP_TX
Text Notes 8500 3550 0    60   ~ 0
MAX 3v3
Text GLabel 9950 3700 2    60   Output ~ 0
ESP_TX_5V
Wire Wire Line
	9800 3700 9950 3700
$Comp
L R R?
U 1 1 5BD6604B
P 9850 3500
F 0 "R?" V 9930 3500 50  0000 C CNN
F 1 "20k" V 9850 3500 50  0000 C CNN
F 2 "" V 9780 3500 50  0001 C CNN
F 3 "" H 9850 3500 50  0001 C CNN
	1    9850 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	9850 3650 9850 3700
Connection ~ 9850 3700
Wire Wire Line
	9400 3250 9400 3400
Wire Wire Line
	9850 3300 9850 3350
Wire Wire Line
	8950 3300 9850 3300
Connection ~ 9400 3300
Wire Wire Line
	8950 3700 8950 3300
Text Notes 10050 3600 0    60   ~ 0
Out < 5v
Wire Wire Line
	8900 3600 9200 3600
$Comp
L LM393 U?
U 2 1 5BD64FB0
P 10000 4300
F 0 "U?" H 10150 4450 50  0000 C CNN
F 1 "LM393" H 10250 4150 50  0000 C CNN
F 2 "" H 10000 4300 50  0001 C CNN
F 3 "" H 10000 4300 50  0001 C CNN
	2    10000 4300
	1    0    0    -1  
$EndComp
Text GLabel 3200 7150 2    60   Output ~ 0
ESP_RX_5V
Text GLabel 7500 3600 0    60   Input ~ 0
ESP_RX_5V
Wire Wire Line
	7600 3600 7500 3600
Wire Wire Line
	7500 5850 7400 5850
$Comp
L C_Small C?
U 1 1 5BD74DF6
P 2000 750
F 0 "C?" H 2010 820 50  0000 L CNN
F 1 "10/16v" H 2010 670 50  0000 L CNN
F 2 "" H 2000 750 50  0001 C CNN
F 3 "" H 2000 750 50  0001 C CNN
	1    2000 750 
	0    1    1    0   
$EndComp
$Comp
L GND #PWR?
U 1 1 5BD74EA1
P 1750 800
F 0 "#PWR?" H 1750 550 50  0001 C CNN
F 1 "GND" H 1750 650 50  0000 C CNN
F 2 "" H 1750 800 50  0001 C CNN
F 3 "" H 1750 800 50  0001 C CNN
	1    1750 800 
	1    0    0    -1  
$EndComp
Wire Wire Line
	2200 700  2200 800 
Wire Wire Line
	2100 750  2200 750 
Connection ~ 2200 750 
Wire Wire Line
	850  1600 700  1600
Wire Wire Line
	700  1600 700  1650
Wire Wire Line
	1900 750  1750 750 
Wire Wire Line
	1750 750  1750 800 
$Comp
L Conn_01x12 J?
U 1 1 5BD761D4
P 5950 7300
AR Path="/5BD761D4" Ref="J?"  Part="1" 
AR Path="/5BD37954/5BD761D4" Ref="J?"  Part="1" 
F 0 "J?" H 5950 7950 50  0000 C CNN
F 1 "CONN_01X12" V 6050 7300 50  0000 C CNN
F 2 "" H 5950 7300 50  0001 C CNN
F 3 "" H 5950 7300 50  0001 C CNN
	1    5950 7300
	1    0    0    -1  
$EndComp
Text GLabel 5650 7000 0    60   Input ~ 0
GND
Text GLabel 5650 6900 0    60   Input ~ 0
ESP_TX
Text GLabel 5650 6800 0    60   Input ~ 0
ESP_RX
Text GLabel 5650 7200 0    60   Input ~ 0
+5V
Text GLabel 5650 7300 0    60   Input ~ 0
+5V
Text GLabel 5650 7400 0    60   Input ~ 0
LCD_SPI_RST
Text GLabel 5650 7500 0    60   Input ~ 0
LCD_SPI_SDA
Text GLabel 5650 7600 0    60   Input ~ 0
LCD_SPI_SCL
Text GLabel 5650 7700 0    60   Input ~ 0
LCD_SPI_CS
Text GLabel 5650 7800 0    60   Input ~ 0
LCD_SPI_DC
Text GLabel 5650 7900 0    60   Input ~ 0
GND
Wire Wire Line
	5650 6800 5750 6800
Wire Wire Line
	5750 6900 5650 6900
Wire Wire Line
	5650 7000 5750 7000
Wire Wire Line
	5750 7100 5650 7100
Wire Wire Line
	5750 7300 5650 7300
Wire Wire Line
	5750 7500 5650 7500
Wire Wire Line
	5650 7600 5750 7600
Wire Wire Line
	5750 7700 5650 7700
Wire Wire Line
	5650 7800 5750 7800
Wire Wire Line
	5650 7900 5750 7900
Wire Wire Line
	5750 7400 5650 7400
Text GLabel 5650 7100 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	5650 7200 5750 7200
Wire Notes Line
	5000 7000 4950 7000
Text Notes 4350 7050 0    60   ~ 0
To ESP\n3v3 tolerent
Wire Notes Line
	5050 6750 5000 6750
Wire Notes Line
	5000 6750 5000 7250
Wire Notes Line
	5000 7250 5050 7250
Text Notes 2350 4200 0    60   Italic 12
connected to -5V of Fluke8050a!
Text Notes 2300 600  0    60   Italic 12
connected to GND of Fluke8050a!
Text Notes 7800 5500 0    63   ~ 0
PD6 - D12\nPB7 - D11\nPB6 - D10\nPB5 - D9\nPB4 - D8\nPE6 - D7\nPD7 - D6\nPC6 - D5\nPD4 - D4\nPD0 - D3\nPD1 - D2
Text Notes 8150 6100 0    63   ~ 0
PD2 - D0 - RX\nPD3 - D1 - TX\nPB0 - D17 - SS - RX_LED\nPB2 - D16 - MOSI
Text Notes 5300 6100 2    60   ~ 0
MISO - D14 - PB3\nSCK - D15 - PB1
Text Notes 5250 5300 0    63   ~ 0
A0 - PF7\nA1 - PF6\nA2 - PF5\nA3 - PF4\nA4 - PF1\nA5 - PF0
Text Notes 5400 4400 0    63   ~ 0
D13 - PC7
Wire Wire Line
	6850 6200 7000 6200
$EndSCHEMATC
