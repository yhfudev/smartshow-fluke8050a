EESchema Schematic File Version 2
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
LIBS:cpuz80
LIBS:mostek
LIBS:arduino_micro_shield
LIBS:maplemini
LIBS:dk_Logic-Buffers-Drivers-Receivers-Transceivers
LIBS:fluke8050-screen-cache
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
P 5850 2150
F 0 "U?" H 5850 2950 50  0000 C CNN
F 1 "NodeMCU_0.9_Vraw" H 5850 1300 50  0000 C CNN
F 2 "" H 6100 2150 50  0000 C CNN
F 3 "" H 6100 2150 50  0000 C CNN
	1    5850 2150
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
P 6850 4250
F 0 "R?" V 6930 4250 50  0000 C CNN
F 1 "1k" V 6850 4250 50  0000 C CNN
F 2 "" V 6780 4250 50  0001 C CNN
F 3 "" H 6850 4250 50  0001 C CNN
	1    6850 4250
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
P 7050 4450
F 0 "R?" V 7130 4450 50  0000 C CNN
F 1 "2k" V 7050 4450 50  0000 C CNN
F 2 "" V 6980 4450 50  0001 C CNN
F 3 "" H 7050 4450 50  0001 C CNN
	1    7050 4450
	-1   0    0    1   
$EndComp
Wire Wire Line
	7050 4250 7050 4300
$Comp
L GND #PWR?
U 1 1 5BBBF641
P 7050 4700
F 0 "#PWR?" H 7050 4450 50  0001 C CNN
F 1 "GND" H 7050 4550 50  0000 C CNN
F 2 "" H 7050 4700 50  0001 C CNN
F 3 "" H 7050 4700 50  0001 C CNN
	1    7050 4700
	1    0    0    -1  
$EndComp
Connection ~ 7050 4250
Text GLabel 6400 2350 2    60   Input ~ 0
ESP_RX
Text GLabel 6400 2450 2    60   Output ~ 0
ESP_TX
Wire Wire Line
	6400 1750 6300 1750
Text GLabel 3200 7000 2    60   Input ~ 0
ESP_TX_5V
Text GLabel 7100 4250 2    60   Output ~ 0
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
P 6350 3000
F 0 "#PWR?" H 6350 2750 50  0001 C CNN
F 1 "GND" H 6350 2850 50  0000 C CNN
F 2 "" H 6350 3000 50  0001 C CNN
F 3 "" H 6350 3000 50  0001 C CNN
	1    6350 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	6300 2750 6350 2750
Wire Wire Line
	6350 2050 6350 3000
$Comp
L +5V #PWR?
U 1 1 5BBCAFEF
P 5100 2850
F 0 "#PWR?" H 5100 2700 50  0001 C CNN
F 1 "+5V" H 5100 2990 50  0000 C CNN
F 2 "" H 5100 2850 50  0001 C CNN
F 3 "" H 5100 2850 50  0001 C CNN
	1    5100 2850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BBCB0BD
P 5350 3000
F 0 "#PWR?" H 5350 2750 50  0001 C CNN
F 1 "GND" H 5350 2850 50  0000 C CNN
F 2 "" H 5350 3000 50  0001 C CNN
F 3 "" H 5350 3000 50  0001 C CNN
	1    5350 3000
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 2750 5350 2750
Wire Wire Line
	5350 2350 5350 3000
Wire Wire Line
	5400 2350 5350 2350
Connection ~ 5350 2750
Wire Wire Line
	6300 2050 6350 2050
Connection ~ 6350 2750
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
Text GLabel 6400 1550 2    60   Output ~ 0
OLED_I2C_SCL
Text GLabel 6400 1650 2    60   BiDi ~ 0
OLED_I2C_SDA
Wire Wire Line
	6300 1550 6400 1550
Wire Wire Line
	6400 1650 6300 1650
Text GLabel 6400 2150 2    60   Output ~ 0
OLED_SPI_SCL
Text GLabel 6400 1850 2    60   Output ~ 0
OLED_SPI_SDA
Text GLabel 6400 1750 2    60   Output ~ 0
OLED_SPI_DC
Text GLabel 5150 2550 1    60   Output ~ 0
OLED_SPI_RST
Wire Wire Line
	5100 2850 5400 2850
Wire Wire Line
	6400 1850 6300 1850
Wire Wire Line
	6300 2350 6400 2350
Wire Wire Line
	6400 2150 6300 2150
Wire Wire Line
	6300 2450 6400 2450
Wire Wire Line
	7000 4250 7100 4250
Wire Wire Line
	7050 4600 7050 4700
Text Notes 3200 3500 0    60   ~ 0
Fluke 8050a U17
$Comp
L ARDUINO_MICRO_SHIELD U?
U 1 1 5BC8A9CF
P 9500 6200
F 0 "U?" H 11250 6600 60  0000 C CNN
F 1 "ARDUINO_MICRO_SHIELD" H 10350 6800 60  0000 C CNN
F 2 "" H 9900 6150 60  0000 C CNN
F 3 "" H 9900 6150 60  0000 C CNN
	1    9500 6200
	0    -1   -1   0   
$EndComp
Text GLabel 9800 5050 2    60   Input ~ 0
ST4
Text GLabel 9800 4950 2    60   Input ~ 0
ST3
Text GLabel 9800 4850 2    60   Input ~ 0
ST2
Text GLabel 9800 4750 2    60   Input ~ 0
ST1
Text GLabel 9800 4650 2    60   Input ~ 0
ST0
Text GLabel 8250 5350 0    60   Input ~ 0
HV
Text GLabel 8250 4850 0    60   Input ~ 0
W
Text GLabel 8250 4950 0    60   Input ~ 0
X
Text GLabel 8250 5050 0    60   Input ~ 0
Y
Text GLabel 8250 5150 0    60   Input ~ 0
Z
Text GLabel 9150 4250 2    60   Input ~ 0
DP
Text GLabel 9800 5250 2    60   Input ~ 0
Fa
Text GLabel 9800 5450 2    60   Input ~ 0
Fb
Text GLabel 8250 6050 0    60   Input ~ 0
Fc
Text GLabel 9800 5550 2    60   Input ~ 0
Fd
Text GLabel 8250 5250 0    60   Input ~ 0
BP
Text GLabel 9800 5350 2    60   Input ~ 0
RNGc
Text GLabel 9800 4550 2    60   Input ~ 0
RNGa
Text GLabel 9800 5150 2    60   Input ~ 0
RNGb
Wire Wire Line
	9800 4550 9700 4550
Wire Wire Line
	9700 4650 9800 4650
Wire Wire Line
	9800 4750 9700 4750
Wire Wire Line
	9700 4850 9800 4850
Wire Wire Line
	9800 4950 9700 4950
Wire Wire Line
	9700 5050 9800 5050
Wire Wire Line
	9800 5150 9700 5150
Wire Wire Line
	9800 5350 9700 5350
Wire Wire Line
	9700 5450 9800 5450
Wire Wire Line
	9800 5550 9700 5550
Wire Wire Line
	9700 5850 9800 5850
Wire Wire Line
	8350 4850 8250 4850
Wire Wire Line
	8250 4950 8350 4950
Wire Wire Line
	8350 5050 8250 5050
Wire Wire Line
	8250 5150 8350 5150
Wire Wire Line
	8350 5250 8250 5250
Wire Wire Line
	8250 5350 8350 5350
Text GLabel 8250 4550 0    60   Output ~ 0
LCD_SPI_DC
Text GLabel 9800 5750 2    60   Output ~ 0
LCD_SPI_RES
Text GLabel 8250 6150 0    60   Output ~ 0
LCD_SPI_SCL
Text GLabel 9800 6150 2    60   Output ~ 0
LCD_SPI_SDA
Text GLabel 9800 6050 2    60   Output ~ 0
LCD_SPI_CS
Wire Wire Line
	9700 6050 9800 6050
Wire Wire Line
	9800 6150 9700 6150
Wire Wire Line
	8350 6150 8250 6150
Wire Wire Line
	8250 4550 8350 4550
Wire Wire Line
	9700 5750 9800 5750
Text GLabel 9800 5850 2    60   Input ~ 0
ESP_TX_5V
Text GLabel 9800 5950 2    60   Output ~ 0
ESP_RX_5V
Text GLabel 3350 1800 2    60   Output ~ 0
BP
Wire Wire Line
	3200 1800 3350 1800
Text GLabel 9000 4250 0    60   Input ~ 0
PIND5_LED
Wire Wire Line
	9000 4250 9150 4250
Wire Wire Line
	8350 6050 8250 6050
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
P 9550 3050
F 0 "U?" H 11300 3450 60  0000 C CNN
F 1 "ARDUINO_MICRO_SHIELD" H 10400 3650 60  0000 C CNN
F 2 "" H 9950 3000 60  0000 C CNN
F 3 "" H 9950 3000 60  0000 C CNN
	1    9550 3050
	0    -1   -1   0   
$EndComp
Text GLabel 9850 1900 2    60   Input ~ 0
ST4
Text GLabel 9850 2300 2    60   Input ~ 0
ST3
Text GLabel 9850 2400 2    60   Input ~ 0
ST2
Text GLabel 9850 2700 2    60   Input ~ 0
ST1
Text GLabel 9850 2800 2    60   Input ~ 0
ST0
Text GLabel 8300 2200 0    60   Input ~ 0
HV
Text GLabel 8300 1700 0    60   Input ~ 0
W
Text GLabel 8300 1800 0    60   Input ~ 0
X
Text GLabel 8300 1900 0    60   Input ~ 0
Y
Text GLabel 8300 2000 0    60   Input ~ 0
Z
Text GLabel 8300 2100 0    60   Input ~ 0
DP
Text GLabel 9850 1400 2    60   Input ~ 0
Fa
Text GLabel 9850 2200 2    60   Input ~ 0
Fb
Text GLabel 9850 2000 2    60   Input ~ 0
Fc
Text GLabel 9200 1100 2    60   Input ~ 0
Fd
Text GLabel 9850 1500 2    60   Input ~ 0
BP
Text GLabel 9850 1800 2    60   Input ~ 0
RNGc
Text GLabel 9850 1600 2    60   Input ~ 0
RNGa
Text GLabel 9850 1700 2    60   Input ~ 0
RNGb
Wire Wire Line
	9850 1400 9750 1400
Wire Wire Line
	9750 1500 9850 1500
Wire Wire Line
	9850 1600 9750 1600
Wire Wire Line
	9750 1700 9850 1700
Wire Wire Line
	9850 1800 9750 1800
Wire Wire Line
	9750 1900 9850 1900
Wire Wire Line
	9850 2000 9750 2000
Wire Wire Line
	9850 2200 9750 2200
Wire Wire Line
	9750 2300 9850 2300
Wire Wire Line
	9850 2400 9750 2400
Wire Wire Line
	9750 2700 9850 2700
Wire Wire Line
	9850 2800 9750 2800
Wire Wire Line
	8400 1700 8300 1700
Wire Wire Line
	8300 1800 8400 1800
Wire Wire Line
	8400 1900 8300 1900
Wire Wire Line
	8300 2000 8400 2000
Wire Wire Line
	8400 2100 8300 2100
Wire Wire Line
	8300 2200 8400 2200
Text GLabel 8300 1400 0    60   Output ~ 0
LCD_SPI_DC
Text GLabel 9850 2600 2    60   Output ~ 0
LCD_SPI_RES
Text GLabel 8300 3000 0    60   Output ~ 0
LCD_SPI_SCL
Text GLabel 9850 3000 2    60   Output ~ 0
LCD_SPI_SDA
Text GLabel 9850 2900 2    60   Output ~ 0
LCD_SPI_CS
Wire Wire Line
	9750 2900 9850 2900
Wire Wire Line
	9850 3000 9750 3000
Wire Wire Line
	8400 3000 8300 3000
Wire Wire Line
	8300 1400 8400 1400
Wire Wire Line
	9750 2600 9850 2600
Text GLabel 9050 1100 0    60   Input ~ 0
PIND5_LED
Wire Wire Line
	9050 1100 9200 1100
Text Notes 8050 3350 0    60   ~ 0
Original Fluke 8050a LCD Hack\nhttp://vondervotteimittiss.com/belfry/?p=180
Text Notes 8050 6650 0    60   ~ 0
Fluke 8050a LCD with New INT handler\nhttps://github.com/yhfudev/smartshow-fluke8050a.git
Text Notes 5050 3500 0    60   ~ 0
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
	9700 5250 9800 5250
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
P 8100 2500
F 0 "#PWR?" H 8100 2350 50  0001 C CNN
F 1 "+5V" H 8100 2640 50  0000 C CNN
F 2 "" H 8100 2500 50  0001 C CNN
F 3 "" H 8100 2500 50  0001 C CNN
	1    8100 2500
	1    0    0    -1  
$EndComp
Wire Wire Line
	8100 2500 8400 2500
$Comp
L +5V #PWR?
U 1 1 5BCA7772
P 8050 5650
F 0 "#PWR?" H 8050 5500 50  0001 C CNN
F 1 "+5V" H 8050 5790 50  0000 C CNN
F 2 "" H 8050 5650 50  0001 C CNN
F 3 "" H 8050 5650 50  0001 C CNN
	1    8050 5650
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 5650 8350 5650
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
	5150 2550 5150 2650
Wire Wire Line
	5150 2650 5400 2650
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
Text GLabel 6400 2650 2    60   Output ~ 0
ESP_RESET
Text GLabel 1500 7150 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	1500 7150 1650 7150
Text GLabel 6400 2550 2    60   Output ~ 0
ESP_ISP_FLASH
Wire Wire Line
	6300 2550 6400 2550
Wire Wire Line
	6400 2650 6300 2650
Text GLabel 8250 5750 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	8250 5750 8350 5750
$Comp
L LM393 U?
U 1 1 5BD66041
P 5400 4450
F 0 "U?" H 5550 4600 50  0000 C CNN
F 1 "LM393" H 5650 4300 50  0000 C CNN
F 2 "" H 5400 4450 50  0001 C CNN
F 3 "" H 5400 4450 50  0001 C CNN
	1    5400 4450
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5BD66043
P 4850 4600
F 0 "R?" V 4930 4600 50  0000 C CNN
F 1 "200k" V 4850 4600 50  0000 C CNN
F 2 "" V 4780 4600 50  0001 C CNN
F 3 "" H 4850 4600 50  0001 C CNN
	1    4850 4600
	1    0    0    -1  
$EndComp
$Comp
L R R?
U 1 1 5BD66044
P 4850 5000
F 0 "R?" V 4930 5000 50  0000 C CNN
F 1 "50k" V 4850 5000 50  0000 C CNN
F 2 "" V 4780 5000 50  0001 C CNN
F 3 "" H 4850 5000 50  0001 C CNN
	1    4850 5000
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BD66045
P 4850 5250
F 0 "#PWR?" H 4850 5000 50  0001 C CNN
F 1 "GND" H 4850 5100 50  0000 C CNN
F 2 "" H 4850 5250 50  0001 C CNN
F 3 "" H 4850 5250 50  0001 C CNN
	1    4850 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	4850 4750 4850 4850
Wire Wire Line
	5100 4550 5050 4550
Wire Wire Line
	5050 4550 5050 4800
Wire Wire Line
	5050 4800 4850 4800
Connection ~ 4850 4800
Wire Wire Line
	4850 5150 4850 5250
Wire Wire Line
	5300 4750 5300 5200
Wire Wire Line
	5300 5200 4850 5200
Connection ~ 4850 5200
$Comp
L +5V #PWR?
U 1 1 5BD66046
P 5300 4000
F 0 "#PWR?" H 5300 3850 50  0001 C CNN
F 1 "+5V" H 5300 4140 50  0000 C CNN
F 2 "" H 5300 4000 50  0001 C CNN
F 3 "" H 5300 4000 50  0001 C CNN
	1    5300 4000
	1    0    0    -1  
$EndComp
Text Notes 4650 4850 0    60   ~ 0
1v
Text GLabel 4800 4350 0    60   Input ~ 0
ESP_TX
Text Notes 4400 4300 0    60   ~ 0
MAX 3v3
Text GLabel 5850 4450 2    60   Output ~ 0
ESP_TX_5V
Wire Wire Line
	5700 4450 5850 4450
$Comp
L R R?
U 1 1 5BD6604B
P 5750 4250
F 0 "R?" V 5830 4250 50  0000 C CNN
F 1 "20k" V 5750 4250 50  0000 C CNN
F 2 "" V 5680 4250 50  0001 C CNN
F 3 "" H 5750 4250 50  0001 C CNN
	1    5750 4250
	-1   0    0    1   
$EndComp
Wire Wire Line
	5750 4400 5750 4450
Connection ~ 5750 4450
Wire Wire Line
	5300 4000 5300 4150
Wire Wire Line
	5750 4050 5750 4100
Wire Wire Line
	4850 4050 5750 4050
Connection ~ 5300 4050
Wire Wire Line
	4850 4450 4850 4050
Text Notes 5950 4350 0    60   ~ 0
Out < 5v
Wire Wire Line
	4800 4350 5100 4350
$Comp
L LM393 U?
U 2 1 5BD64FB0
P 6100 5050
F 0 "U?" H 6250 5200 50  0000 C CNN
F 1 "LM393" H 6350 4900 50  0000 C CNN
F 2 "" H 6100 5050 50  0001 C CNN
F 3 "" H 6100 5050 50  0001 C CNN
	2    6100 5050
	1    0    0    -1  
$EndComp
Text GLabel 3200 7150 2    60   Input ~ 0
ESP_RX_5V
Text GLabel 6600 4300 3    60   Input ~ 0
ESP_RX_5V
Wire Wire Line
	6700 4250 6600 4250
Wire Wire Line
	6600 4250 6600 4300
Wire Wire Line
	9800 5950 9700 5950
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
L CONN_01X12 J?
U 1 1 5BD761D4
P 5950 7300
F 0 "J?" H 5950 7950 50  0000 C CNN
F 1 "CONN_01X12" V 6050 7300 50  0000 C CNN
F 2 "" H 5950 7300 50  0001 C CNN
F 3 "" H 5950 7300 50  0001 C CNN
	1    5950 7300
	1    0    0    -1  
$EndComp
Text GLabel 5650 6950 0    60   Input ~ 0
GND
Text GLabel 5650 6750 0    60   Input ~ 0
ESP_TX
Text GLabel 5650 6850 0    60   Input ~ 0
ESP_RX
Text GLabel 5650 7150 0    60   Input ~ 0
+5V
Text GLabel 5650 7250 0    60   Input ~ 0
+5V
Text GLabel 5650 7350 0    60   Input ~ 0
LCD_SPI_RST
Text GLabel 5650 7450 0    60   Input ~ 0
LCD_SPI_SDA
Text GLabel 5650 7550 0    60   Input ~ 0
LCD_SPI_SCL
Text GLabel 5650 7650 0    60   Input ~ 0
LCD_SPI_CS
Text GLabel 5650 7750 0    60   Input ~ 0
LCD_SPI_DC
Text GLabel 5650 7850 0    60   Input ~ 0
GND
Wire Wire Line
	5650 6750 5750 6750
Wire Wire Line
	5750 6850 5650 6850
Wire Wire Line
	5650 6950 5750 6950
Wire Wire Line
	5750 7050 5650 7050
Wire Wire Line
	5750 7250 5650 7250
Wire Wire Line
	5750 7450 5650 7450
Wire Wire Line
	5650 7550 5750 7550
Wire Wire Line
	5750 7650 5650 7650
Wire Wire Line
	5650 7750 5750 7750
Wire Wire Line
	5650 7850 5750 7850
Wire Wire Line
	5750 7350 5650 7350
Text GLabel 5650 7050 0    60   Input ~ 0
ESP_RESET
Wire Wire Line
	5650 7150 5750 7150
Wire Notes Line
	5000 6950 4950 6950
Text Notes 4350 7000 0    60   ~ 0
To ESP\n3v3 tolerent
Wire Notes Line
	5050 6700 5000 6700
Wire Notes Line
	5000 6700 5000 7200
Wire Notes Line
	5000 7200 5050 7200
$EndSCHEMATC
