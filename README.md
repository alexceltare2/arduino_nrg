# Universal CC430 for Arduino (unicc)
Universal MSP430 for Arduino

This project aims to make panStamp a universal CC430 chip capable to be programmed using internal or external clocks, switchable carrier frequencies and many other tunnable features.
The default behaviour of the CC430 chipset is to operate with minimal external hardware requirements, meaning that only 1 XTAL clock is required for the RF modulation and the other clocks (Auxiliary Clock, Master Clock and Subsystem master Clock) will be sourced internally with minimal power consumption.


# Specifications

* MCU: CC430F5137 (MSP430 core + CC1101 radio SOC)
* Speed: Programmable speed between 8MHz and 24MHz (Default is 12Mhz)
* Clock: 5 sources programmable through UCS
* Timers: 4 sources
* Flash: 32KB
* RAM: 4KB
* Info memory/EEPROM: 512 bytes
* 6 x 12-bit ADC inputs
* 30 x GPIO supporting I2C, SPI, IrDA & UART through USCI
* Interrupts via Pins, RF & Timer
* Unique MAC address
* Voltage range: from 2VDC to 3.6VDC
* Rx current: 14 mA (high gain mode disabled) / 18 mA (high gain mode enabled)
* Tx current: 36 mA max (high gain mode disabled) / 300 mA (high gain mode enabled)
* Sleep current: 2.5 uA (powered from BAT pin)
* Maximum Tx power: over +20 dBm
* RF bands: 433/868/905/915/918 MHz ISM bands
* Communication distance: Over 1Km at 4800 bps with high gain mode disabled and over 5Km wigh HGM enabled
(Under good LoS conditions)
* 128-bit AES Hardware Security Encryption
* Support for FHSS (Frequency-Hopping Spread Spectrum)
* Programmable via SBW, serial BSL and wirelessly (SWAP)
* Hardware RTC
* Internal Temperature and Voltage sensor
* Password protection for program memory


# Programming

We recommend Arduino IDE as your development environment and serial protocol as your programming method. The programmer of choice should be a regular 3.3V USB-to-UART(RS232) serial programmer (WCH, FTDI, Silabs or other brands) with DTR & RTS pins. To connect from Arduino IDE to the board you should connect the pins as they follow:

...............|VCC --> VCC|................|

...............|GND --> GND|..............|

UART...|RTS --> TEST|..CC430..|

...............|DTR --> Reset|..............|

...............|RX  --> TX|.....................|

...............|TX  --> RX|......................|


# Pin mapping
![Pin Definitions](https://github.com/alexceltare2/arduino_nrg/blob/master/resources/cc430-pins.png)


# Info memory
CC430 processors do not include EEPROM space. Instead, they provide a special region in Flash to store configurations. This region is called info memory and is 512 bytes long in the CC430F5137 MCU. The panStamp library provides the necessary functions to use this info space as any other EEPROM-based region. The detailed structure of the CC430 memory is listed bellow:
![Memory](https://github.com/alexceltare2/arduino_nrg/blob/master/resources/cc430-mem.png)

# Serial monitor
To save programming resources, Arduino IDE doesn't load the HardwareSerial API by default, that is, you can't use "Serial.begin()" or "Serial.print()" unless you include "#include<HardwareSerial.h>" to your code.
With regards to Serial Monitor, some USB-to-UART adapters like FTDI come prebuilt with the right capacitor configuration and pins while others like CH340G need the DTR pin to be diconeected to trigger the Serial Monitor write(TX), and disconnect RTS to reset the MCU. A fix should be on the way.

# Radio Frequency
To change frequencies from 868Mhz to 443Mhz for example, you would traditionally call "panstamp.init();" to your code. That is not the case anymore as the new API doesn't allow this behaviour and frequencies can only be changed by editing "DEFAULT_CARRIER_FREQ" from "panstamp_nrg\hardware\msp430\1.1.0\cores\panstamp\panstamp.h". Other cool things can be changed from both the .h and .cpp file like FHSS hops and timer settings.

# Interrupts
To interrupt the MCU from sleeping or doing its infinite loop, the CC430 employs external interrupts. These interrupts can originate from the RF (packet received), the Timer or through its external pins (pins P1.x to P2.x / D0 to D15). 

# Timers
Used in a variety of implementations like signal triggers and timed events, these timers are organised as it follows:
- Watchdog timer : Used by delay(), resets the MCU after a specified event
- Timer1_A3/TA0 with 5 comparators: Used by writeAnalog() (PWM output). Also used by "modem" to detect time-outs between serial transmissions (Timer1A0 library)
- Timer0_A5/TA1 with 3 comparators: Used by writeAnalog() (PWM output)
- RTC timer : Used by cc430rtc.cpp (panstamp.sleepSec())
