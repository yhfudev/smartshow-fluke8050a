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
Sheet 3 3
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
L MAPLE-MINI M?
U 1 1 5BD37AE6
P 3250 2400
F 0 "M?" H 2350 3600 45  0000 L BNN
F 1 "MAPLE-MINI" H 2350 3500 45  0000 L BNN
F 2 "DIP40M6-MAPLE-MINI" H 2350 3450 20  0001 L BNN
F 3 "" H 3250 2400 60  0000 C CNN
	1    3250 2400
	1    0    0    -1  
$EndComp
Text GLabel 4500 3300 2    60   Input ~ 0
ST4
Text GLabel 4500 3200 2    60   Input ~ 0
Fd
Text GLabel 4500 3100 2    60   Input ~ 0
DP
Text Notes 2200 3950 0    60   ~ 0
Pins are assigned according to:\nhttps://madnessinthedarkness.transsys.com/projects:fluke8050a:iopins
Text GLabel 4500 3000 2    60   Output ~ 0
LCD_SPI_DC
Text GLabel 4500 2900 2    60   Output ~ 0
LCD_SPI_MOSI
Text GLabel 4500 2800 2    60   Input ~ 0
LCD_SPI_MISO
Text GLabel 4500 2700 2    60   Output ~ 0
LCD_SPI_SCK
Text GLabel 4500 2600 2    60   Output ~ 0
LCD_SPI_CS
$Comp
L R R?
U 1 1 5BD38230
P 4650 2000
F 0 "R?" V 4730 2000 50  0000 C CNN
F 1 "22k" V 4650 2000 50  0000 C CNN
F 2 "" V 4580 2000 50  0001 C CNN
F 3 "" H 4650 2000 50  0001 C CNN
	1    4650 2000
	0    -1   -1   0   
$EndComp
Text GLabel 4950 2000 2    60   Input ~ 0
Fc
Wire Wire Line
	4950 2000 4800 2000
Wire Wire Line
	4500 2000 4350 2000
Wire Wire Line
	4500 2600 4350 2600
Wire Wire Line
	4350 2700 4500 2700
Wire Wire Line
	4500 2800 4350 2800
Wire Wire Line
	4350 2900 4500 2900
Wire Wire Line
	4500 3000 4350 3000
Wire Wire Line
	4350 3100 4500 3100
Wire Wire Line
	4500 3200 4350 3200
Wire Wire Line
	4350 3300 4500 3300
$Comp
L R R?
U 1 1 5BD38721
P 4650 1900
F 0 "R?" V 4730 1900 50  0000 C CNN
F 1 "22k" V 4650 1900 50  0000 C CNN
F 2 "" V 4580 1900 50  0001 C CNN
F 3 "" H 4650 1900 50  0001 C CNN
	1    4650 1900
	0    -1   -1   0   
$EndComp
Text GLabel 4950 1900 2    60   Input ~ 0
Fb
Wire Wire Line
	4950 1900 4800 1900
$Comp
L R R?
U 1 1 5BD3877E
P 4650 1800
F 0 "R?" V 4730 1800 50  0000 C CNN
F 1 "22k" V 4650 1800 50  0000 C CNN
F 2 "" V 4580 1800 50  0001 C CNN
F 3 "" H 4650 1800 50  0001 C CNN
	1    4650 1800
	0    -1   -1   0   
$EndComp
Text GLabel 4950 1800 2    60   Input ~ 0
Fa
Wire Wire Line
	4950 1800 4800 1800
Wire Wire Line
	4500 1800 4350 1800
Text GLabel 2000 1800 0    60   Input ~ 0
W
Text GLabel 2000 1900 0    60   Input ~ 0
X
Text GLabel 2000 2100 0    60   Input ~ 0
Y
Text GLabel 2000 2200 0    60   Input ~ 0
Z
Text GLabel 2000 2300 0    60   Input ~ 0
RNGa
Text GLabel 2000 2400 0    60   Input ~ 0
RNGb
Text GLabel 2000 2500 0    60   Input ~ 0
RNGc
Text GLabel 2000 3000 0    60   Input ~ 0
HV
Text GLabel 2000 3100 0    60   Input ~ 0
ST0
Text GLabel 2000 3200 0    60   Input ~ 0
ST1
Text GLabel 2000 3300 0    60   Input ~ 0
ST2
Text GLabel 2000 3400 0    60   Input ~ 0
ST3
Wire Wire Line
	2000 1800 2150 1800
Wire Wire Line
	2150 1900 2000 1900
Wire Wire Line
	2000 2100 2150 2100
Wire Wire Line
	2150 2200 2000 2200
Wire Wire Line
	2000 2300 2150 2300
Wire Wire Line
	2150 2400 2000 2400
Wire Wire Line
	2000 2500 2150 2500
Wire Wire Line
	2150 3000 2000 3000
Wire Wire Line
	2000 3100 2150 3100
Wire Wire Line
	2150 3200 2000 3200
Wire Wire Line
	2000 3300 2150 3300
Wire Wire Line
	2150 3400 2000 3400
Wire Wire Line
	4500 1900 4350 1900
$Comp
L SN74LVC1G125DBVR U?
U 1 1 5BD79422
P 9000 4400
F 0 "U?" H 8802 4614 60  0000 L CNN
F 1 "SN74AHCT1G125" H 9059 4178 60  0000 L CNN
F 2 "digikey-footprints:SOT-753" H 9200 4600 60  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g125.pdf" H 9200 4700 60  0001 L CNN
F 4 "296-11603-1-ND" H 9200 4800 60  0001 L CNN "Digi-Key_PN"
F 5 "SN74LVC1G125DBVR" H 9200 4900 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9200 5000 60  0001 L CNN "Category"
F 7 "Logic - Buffers, Drivers, Receivers, Transceivers" H 9200 5100 60  0001 L CNN "Family"
F 8 "http://www.ti.com/lit/ds/symlink/sn74lvc1g125.pdf" H 9200 5200 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/texas-instruments/SN74LVC1G125DBVR/296-11603-1-ND/385742" H 9200 5300 60  0001 L CNN "DK_Detail_Page"
F 10 "IC BUF NON-INVERT 5.5V SOT23-5" H 9200 5400 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 9200 5500 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9200 5600 60  0001 L CNN "Status"
	1    9000 4400
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 5BD79423
P 9000 4800
F 0 "#PWR?" H 9000 4550 50  0001 C CNN
F 1 "GND" H 9000 4650 50  0000 C CNN
F 2 "" H 9000 4800 50  0001 C CNN
F 3 "" H 9000 4800 50  0001 C CNN
	1    9000 4800
	1    0    0    -1  
$EndComp
Wire Wire Line
	8600 4500 8700 4500
Wire Wire Line
	9200 4400 9300 4400
Wire Wire Line
	8700 4300 8650 4300
Wire Wire Line
	8650 4300 8650 4750
Wire Wire Line
	8650 4750 9000 4750
Wire Wire Line
	9000 4700 9000 4800
Connection ~ 9000 4750
Wire Wire Line
	9000 4000 9000 4100
Text GLabel 9300 4400 2    60   Output ~ 0
ESP_TX_5V
Text GLabel 8600 4500 0    60   Input ~ 0
ESP_TX
Text Notes 8200 4450 0    60   ~ 0
Max 3v3
Text Notes 9350 4300 0    60   ~ 0
Out < 5v
$Comp
L +5V #PWR?
U 1 1 5BD79424
P 9000 4000
F 0 "#PWR?" H 9000 3850 50  0001 C CNN
F 1 "+5V" H 9000 4140 50  0000 C CNN
F 2 "" H 9000 4000 50  0001 C CNN
F 3 "" H 9000 4000 50  0001 C CNN
	1    9000 4000
	1    0    0    -1  
$EndComp
$Comp
L SN74LVC1G125DCKR U?
U 1 1 5BD79425
P 9000 5650
F 0 "U?" H 9250 5900 60  0000 R CNN
F 1 "SN74LVC1G125DCKR" H 7950 5900 60  0000 L CNN
F 2 "digikey-footprints:SOT-353" H 9200 5850 60  0001 L CNN
F 3 "http://www.ti.com/lit/ds/symlink/sn74lvc1g125.pdf" H 9200 5950 60  0001 L CNN
F 4 "296-11604-1-ND" H 9200 6050 60  0001 L CNN "Digi-Key_PN"
F 5 "SN74LVC1G125DCKR" H 9200 6150 60  0001 L CNN "MPN"
F 6 "Integrated Circuits (ICs)" H 9200 6250 60  0001 L CNN "Category"
F 7 "Logic - Buffers, Drivers, Receivers, Transceivers" H 9200 6350 60  0001 L CNN "Family"
F 8 "http://www.ti.com/lit/ds/symlink/sn74lvc1g125.pdf" H 9200 6450 60  0001 L CNN "DK_Datasheet_Link"
F 9 "/product-detail/en/texas-instruments/SN74LVC1G125DCKR/296-11604-1-ND/385743" H 9200 6550 60  0001 L CNN "DK_Detail_Page"
F 10 "IC BUF NON-INVERT 5.5V SC70-5" H 9200 6650 60  0001 L CNN "Description"
F 11 "Texas Instruments" H 9200 6750 60  0001 L CNN "Manufacturer"
F 12 "Active" H 9200 6850 60  0001 L CNN "Status"
	1    9000 5650
	1    0    0    -1  
$EndComp
Text GLabel 8600 5750 0    60   Input ~ 0
ESP_RX_5V
Text GLabel 9300 5750 2    60   Output ~ 0
ESP_RX
Wire Wire Line
	9300 5750 9200 5750
Wire Wire Line
	8700 5750 8600 5750
$Comp
L GND #PWR?
U 1 1 5BD79426
P 9000 6050
F 0 "#PWR?" H 9000 5800 50  0001 C CNN
F 1 "GND" H 9000 5900 50  0000 C CNN
F 2 "" H 9000 6050 50  0001 C CNN
F 3 "" H 9000 6050 50  0001 C CNN
	1    9000 6050
	1    0    0    -1  
$EndComp
Wire Wire Line
	8700 5550 8650 5550
Wire Wire Line
	8650 5550 8650 6000
Wire Wire Line
	8650 6000 9000 6000
Wire Wire Line
	9000 5950 9000 6050
Connection ~ 9000 6000
$Comp
L +3V3 #PWR?
U 1 1 5BD79427
P 9000 5250
F 0 "#PWR?" H 9000 5100 50  0001 C CNN
F 1 "+3V3" H 9000 5390 50  0000 C CNN
F 2 "" H 9000 5250 50  0001 C CNN
F 3 "" H 9000 5250 50  0001 C CNN
	1    9000 5250
	1    0    0    -1  
$EndComp
Wire Wire Line
	9000 5250 9000 5350
$EndSCHEMATC
