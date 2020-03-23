/**
 * Copyright (c) 2018 panStamp <contact@panstamp.com>
 * 
 * This file is part of the panStamp project.
 * 
 * panStamp  is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * any later version.
 * 
 * panStamp is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with panStamp; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301 
 * USA
 * 
 * Author: Daniel Berenguer & George A. Popa
 * Creation date: 10/23/2018
 * For version A.5
 */

#ifndef _PINS_H
#define _PINS_H

#include <stdint.h>

#define __NRG_VERSION_2_0__  1

// Enable pseudo-pin interrupts on P3
#define __ENABLE_P3_PIN_INTERRUPTS__  1

// The board has no I2C thus don't keep those pins high
#define __NO_I2C__ 1

// UART
#define pinUARTmap()      P1MAP6 = PM_UCA0TXD; P1MAP5 = PM_UCA0RXD
#define pinUARTconfig()   P1SEL |= BIT6 | BIT5      // Set P1.6 and P1.5 to USCI Mode
// I2C
#define pinI2Cmap()       P1MAP4 = PM_UCB0SCL; P1MAP3 = PM_UCB0SDA
#define pinI2Cconfig()    P1SEL |= BIT3 | BIT4      // Set P1.4 and P1.3 to USCI function
// SPI
#define pinSPImap()       P1MAP0 = PM_UCB0SIMO; P1MAP1 = PM_UCB0SOMI; P1MAP2 = PM_UCB0CLK
#define pinSPIconfig()    P1SEL |= BIT0 | BIT1 | BIT2  // Set P1.0, P1.1 and P1.2 to USCI function
#define SCK   2
#define MISO  1
#define MOSI  0
#define SPISCK_SET_MODE (PORT_SELECTION0)
#define SPIMOSI_SET_MODE (PORT_SELECTION0)
#define SPIMISO_SET_MODE (PORT_SELECTION0)

#define NOT_A_PORT 0
#define NOT_A_PIN 0
#define NOT_ON_TIMER 0
#define NOT_ON_ADC 0xFF

// Ports
enum{
  P1 = 1,
  P2,
  P3,
  PJ
};

// Timers
enum{
  T0A0,
  T0A1,
  T0A2,
  T0A3,
  T0A4,
  T1A0,
  T1A1,
  T1A2
};

// ADC channels
static const uint8_t A0 = 8;
static const uint8_t A1 = 9;
static const uint8_t A2 = 10;
static const uint8_t A3 = 11;
static const uint8_t A4 = 12;
static const uint8_t A5 = 13;        // Connected to NTC
static const uint8_t A10 = 128 + 10; // special. This is the internal temp sensor
static const uint8_t A11 = 128 + 11; // special. This is (Vcc-Vss)/2
static const uint8_t A12 = 128 + 12; // special. This is VBAT

//Legend: {i} -interrupt(D0-15);  <PWM> -pulse width modulation/analog out pin; (A0)- analog in pin;
// On-board LED
#define ONBOARD_LED 23
#define LED_BUILTIN ONBOARD_LED
#define LED      ONBOARD_LED


#define PIN_TX     6//{i}
#define LED_GREEN  6 //{i}
#define LED_YELLOW 7 //{i}
#define LED_RED2   23
#define LED_RED1   12 // (A4) {i}
#define PIN_Flash_LED_1  3  // <PWM> {i}

#define BUTTON_TEST  14 //{i}
#define BUTTON_LEARN 15 //{i}

#define PIN_TDO  24
#define PIN_TCLK 25
#define PIN_TMS  26
#define PIN_TCK  27

#define PIN_check_vib1	   18// <PWM>
#define PIN_check_vib2 	   17
#define PIN_ac_power_onoff 16
#define PIN_V1_onoff 	   20
#define PIN_V1_ret		   9 // 21 (A1) {i}
#define PIN_V1_ret_GND     21
#define PIN_V2_onoff       2 // <PWM> {i}
#define PIN_V2_ret 		   8 // 19 (A0) <19 is PWM> {8 is i}
#define PIN_V2_ret_GND 	   19
#define PIN_AC_power 	   22
#define PIN_Flash_LED_2    22
#define PIN_dc_vib1 	   5 // {i}
#define PIN_RX             5//{i}
#define PIN_dc_str1        0 // {i}
#define PIN_VIB_2 		   1 // <PWM> {i}
#define PIN_ADC2 		   10// (A2) {i}
#define PIN_ADC3 	       11// (A3) {i}
#define PIN_BAT_VAU 	   4 // 13 (13 is A5) <PWM> {i}
#define PIN_BAT_VAU_GND    13 


#define INIT_ONBOARD_LED()    PJDIR |= BIT3; PJOUT &= ~BIT3
// Preferred analog pin to measure battery voltage
#define BATT_VOLT_PIN   A5
// NTC(Thermistor) ADC pin
#define NTC_PIN    A10
// ADC resolution
#define ADC_RESOLUTION  0xFFF

// LD-BOARD definitions
//#define CC1190_AVAILABLE 1
#define HGM     26
#define LNA_EN  25
#define PA_EN   24


//                                     PINOUT
//
//                         +--------------------------+
//                   GND  1|            ||||          |30  P3.5 (D21)
//            (D20) P3.4  2|        	   			  |29  P3.6 (D22)
//      <PWM> (D19) P3.3  3|           				  |28  P3.7 (D23) /ONBOARD_LED
//      <PWM> (D18) P3.2  4|          			      |27  P1.0 (D0)(SPI_MOSI) 
//            (D17) P3.1  5|            			  |26  P1.1 (D1)(SPI_MISO) <PWM>
//            (D16) P3.0  6|         			      |25  P1.2 (D2)(SPI_SCK)  <PWM>
//            (D15) P2.7  7|            			  |24  P1.3 (D3)(I2C_SDA)  <PWM>
//            (D14) P2.6  8|         			      |23  P1.4 (D4) (I2C_SCL) <PWM>
//         (A5/D13) P2.5  9|         			      |22  P1.5 (D5) (RXD) 
//         (A4/D12) P2.4 10|        			      |21  P1.6 (D6) (TXD)
//         (A3/D11) P2.3 11|     	  			      |20  P1.7 (D7) 
//         (A2/D10) P2.2 12|        			      |19  (RESET)
//          (A1/D9) P2.1 13|         			      |18  (TEST)
//          (A0/D8) P2.0 14|          			      |17  GND
//                   GND 15|        			      |16  VCC
//                          +-------------------------+
//
//                      ONBOARD_LED(pan)/TCK -- PJ.3 (D27)
//                      CC1190 HGM/TMS       -- PJ.2 (D26)
//                      CC1190 LNA_EN/TCLK   -- PJ.1 (D25)
//                      CC1190 PA_EN/TDO     -- PJ.0 (D24)


const uint16_t digital_pin_to_pmap[] = {
	(uint16_t) &P1MAP0, 
	(uint16_t) &P1MAP1,
  (uint16_t) &P1MAP2,
  (uint16_t) &P1MAP3,
  (uint16_t) &P1MAP4,
  (uint16_t) &P1MAP5,
  (uint16_t) &P1MAP6,
  (uint16_t) &P1MAP7,
	(uint16_t) &P2MAP0,
  (uint16_t) &P2MAP1,
  (uint16_t) &P2MAP2,
  (uint16_t) &P2MAP3,
  (uint16_t) &P2MAP4,
  (uint16_t) &P2MAP5,
  (uint16_t) &P2MAP6,
  (uint16_t) &P2MAP7,
	(uint16_t) &P3MAP0,
  (uint16_t) &P3MAP1,
  (uint16_t) &P3MAP2,
  (uint16_t) &P3MAP3,
  (uint16_t) &P3MAP4,
  (uint16_t) &P3MAP5,
  (uint16_t) &P3MAP6,
  (uint16_t) &P3MAP7,
  NOT_A_PORT,  // No PJMAP0
  NOT_A_PORT,  // No PJMAP1
  NOT_A_PORT,  // No PJMAP2
  NOT_A_PORT   // No PJMAP3
};

const uint16_t port_to_input[] = {
	NOT_A_PORT,
	(uint16_t) &P1IN,
	(uint16_t) &P2IN,
	(uint16_t) &P3IN,
	(uint16_t) &PJIN
};

const uint16_t port_to_output[] = {
	NOT_A_PORT,
	(uint16_t) &P1OUT,
	(uint16_t) &P2OUT,
	(uint16_t) &P3OUT,
	(uint16_t) &PJOUT
};

const uint16_t port_to_dir[] = {
	NOT_A_PORT,
	(uint16_t) &P1DIR,
	(uint16_t) &P2DIR,
	(uint16_t) &P3DIR,
	(uint16_t) &PJDIR
};

const uint16_t port_to_ren[] = {
	NOT_A_PORT,
	(uint16_t) &P1REN,
	(uint16_t) &P2REN,
	(uint16_t) &P3REN,
	(uint16_t) NOT_A_PORT  //No PJREN
};

const uint16_t port_to_sel[] = {
	NOT_A_PORT,
	(uint16_t) &P1SEL,
	(uint16_t) &P2SEL,
	(uint16_t) &P3SEL,
	(uint16_t) NOT_A_PORT  // No PJSEL,
};

const uint16_t port_to_pmap[] = {
	NOT_A_PORT,	/* PMAP starts at port P1 */
	(uint16_t) &P1MAP0,
	(uint16_t) &P2MAP0,
	(uint16_t) &P3MAP0,
	NOT_A_PORT  // No PJMAP0
};

const uint8_t digital_pin_to_timer[] = {
	T0A0,         /* P1.0 - note: A0 output cannot be used with analogWrite */
	T0A1,         /* P1.1 */
	T0A2,         /* P1.2 */
	T0A3,         /* P1.3 */
	T0A4,         /* P1.4 */
	NOT_ON_TIMER, /* P1.5 */
	NOT_ON_TIMER, /* P1.6 */
	NOT_ON_TIMER, /* P1.7 */
	NOT_ON_TIMER, /* P2.0 */
	NOT_ON_TIMER, /* P2.1 */
	NOT_ON_TIMER, /* P2.2 */
	NOT_ON_TIMER, /* P2.3 */
	NOT_ON_TIMER, /* P2.4 */
	NOT_ON_TIMER, /* P2.5 */
	NOT_ON_TIMER, /* P2.6 */
	NOT_ON_TIMER, /* P2.7 */
  NOT_ON_TIMER, /* P3.0 */
	T1A0,         /* P3.1 - note: A0 output cannot be used with analogWrite */
	T1A1,         /* P3.2 */
	T1A2,         /* P3.3 */
  NOT_ON_TIMER, /* P3.4 */
  NOT_ON_TIMER, /* P3.5 */
  NOT_ON_TIMER, /* P3.6 */
	NOT_ON_TIMER, /* P3.7 */
	NOT_ON_TIMER, /* PJ.0 -> CC1190 PA_EN  */
	NOT_ON_TIMER, /* PJ.1 -> CC1190 LNA_EN */
	NOT_ON_TIMER, /* PJ.2 -> CC1190 HGM    */
	NOT_ON_TIMER  /* PJ.3 -> ONBOARD_LED   */
};

const uint8_t digital_pin_to_port[] = {
	P1,           /* P1.0 */
	P1,           /* P1.1 */
	P1,           /* P1.2 */
	P1,           /* P1.3 */
	P1,           /* P1.4 */
	P1,           /* P1.5 */
	P1,           /* P1.6 */
	P1,           /* P1.7 */
	P2,           /* P2.0 */
	P2,           /* P2.1 */
	P2,           /* P2.2 */
	P2,           /* P2.3 */
	P2,           /* P2.4 */
	P2,           /* P2.5 */
	P2,           /* P2.6 */
	P2,           /* P2.7 */
	P3,           /* P3.0 */
	P3,           /* P3.1 */
	P3,           /* P3.2 */
  P3,           /* P3.3 */
  P3,           /* P3.4 */
  P3,           /* P3.5 */
  P3,           /* P3.6 */  
	P3,           /* P3.7 */
	PJ,           /* PJ.0 -> CC1190 PA_EN  */
	PJ,           /* PJ.1 -> CC1190 LNA_EN */
	PJ,           /* PJ.2 -> CC1190 HGM    */
	PJ            /* PJ.3 -> ONBOARD_LED   */
};

const uint8_t digital_pin_to_bit_mask[] = {
	BIT0,        /* P1.0 */
	BIT1,        /* P1.1 */
	BIT2,        /* P1.2 */
	BIT3,        /* P1.3 */
	BIT4,        /* P1.4 */
	BIT5,        /* P1.5 */
	BIT6,        /* P1.6 */
	BIT7,        /* P1.7 */
	BIT0,        /* P2.0 */
	BIT1,        /* P2.1 */
	BIT2,        /* P2.2 */
	BIT3,        /* P2.3 */
	BIT4,        /* P2.4 */
	BIT5,        /* P2.5 */
	BIT6,        /* P2.6 */
	BIT7,        /* P2.7 */
	BIT0,        /* P3.0 */
	BIT1,        /* P3.1 */
	BIT2,        /* P3.2 */
  BIT3,        /* P3.3 */
  BIT4,        /* P3.4 */
  BIT5,        /* P3.5 */
  BIT6,        /* P3.6 */
	BIT7,        /* P3.7 */
	BIT0,        /* PJ.0 -> CC1190 PA_EN  */
	BIT1,        /* PJ.1 -> CC1190 LNA_EN */
	BIT2,        /* PJ.2 -> CC1190 HGM    */
	BIT3         /* PJ.3 -> ONBOARD_LED   */
};

const uint16_t digital_pin_to_analog_in[] = {
	NOT_ON_ADC,   /* P1.0 */
	NOT_ON_ADC,   /* P1.1 */
	NOT_ON_ADC,   /* P1.2 */
	NOT_ON_ADC,   /* P1.3 */
	NOT_ON_ADC,   /* P1.4 */
	NOT_ON_ADC,   /* P1.5 */
	NOT_ON_ADC,   /* P1.6 */
	NOT_ON_ADC,   /* P1.7 */
	0,            /* P2.0 */
	1,            /* P2.1 */
	2,            /* P2.2 */
	3,            /* P2.3 */
	4,            /* P2.4 */
	5,            /* P2.5 */
	NOT_ON_ADC,   /* P2.6 */
	NOT_ON_ADC,   /* P2.7 */
	NOT_ON_ADC,   /* P3.0 */
	NOT_ON_ADC,   /* P3.1 */
	NOT_ON_ADC,   /* P3.2 */
	NOT_ON_ADC,   /* P3.3 */
  NOT_ON_ADC,   /* P3.4 */
  NOT_ON_ADC,   /* P3.5 */
	NOT_ON_ADC,   /* P3.6 */
	NOT_ON_ADC,   /* P3.7 */
	NOT_ON_ADC,   /* PJ.0 -> CC1190 PA_EN  */
	NOT_ON_ADC,   /* PJ.1 -> CC1190 LNA_EN */
	NOT_ON_ADC,   /* PJ.2 -> CC1190 HGM    */
	NOT_ON_ADC    /* PJ.3 -> ONBOARD_LED   */
};

#endif
