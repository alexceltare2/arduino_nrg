# Universal CC430duino
Universal MSP430 for Arduino

This project aims to make panStamp a universal CC430 chip capable to be programmed using internal or external clocks, switchable carrier frequencies and many other tunnable features.
The default behaviour of the CC430 chipset is to operate with minimal external hardware requirements, meaning that only 1 XTAL clock is required for the RF modulation and the other clocks (Auxiliary Clock, Master Clock and Subsystem master Clock) will be sourced internally with minimal power consumption.


# Specifications

* MCU: CC430F5137 (MSP430 core + CC11XX radio SOC)
* Speed: Programmable speed between 8MHz and 24MHz
* Flash: 32KB
* RAM: 4KB
* Info memory/EEPROM: 512 bytes
* Six 12-bit ADC inputs
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
* Support for [FHSS (Frequency-Hopping Spread Spectrum)](FHSS)
* Programmable via SBW, serial BSL and wirelessly (SWAP)


# Programming

We recommend Arduino IDE as your development environment and serial protocol as your programming method. The programmer of choice should be a regular 3,3V USB-to-UART(RS232) serial programmer (WCH, FTDI, Silabs or other brands) with . the pins to connectfrom Arduino IDE to the board are as they follow:

...............|VCC --> VCC|..............

...............|GND --> GND|...........

UART...|RTS --> TEST|..CC430..

...............|DTR --> Reset|.........

...............|RX  --> TX|.................

...............|TX  --> RX|.................


# Pin mapping
TBA


# Info memory

CC430 processors do not include EEPROM space. Instead, they provide a special region in Flash to store configurations. This region is called info memory and is 512 bytes long in the CC430F5137 MCU. The panStamp library provides the necessary functions to use this info space as any other EEPROM-based region.
