/**
 * Copyright (c) 2013 panStamp <contact@panstamp.com>
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
 * Author: Daniel Berenguer
 * Creation date: 02/21/2014
 */

#include "timer0a5.h"
#ifdef __MSP430_HAS_T0A5__

/**
 * TIMER0_A5_ISR
 * 
 * TimerA 1 ISR function
 */
__attribute__((interrupt(TIMER0_A0_VECTOR)))
void TIMER0_A5_ISR(void)
{
  if (timer0a5.timer0a5overflow != NULL)
    timer0a5.timer0a5overflow();            // Call user function
}

/**
 * Class constructor
 */
TIMER0A5::TIMER0A5(void)
{
  timer0a5overflow = NULL;
}

/**
 * start
 *
 * Start T0A5 timer
 *
 * @param millis Milliseconds to be timed. Up to 2000 ms
 */
void TIMER0A5::start(unsigned int millis)
{
  TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
  TA0CCR0 = /*previously 32.767 as ACLK was XT1, now VLO*/ 10.000 * millis;                // Max count
  TA0CTL = TASSEL_1 + MC_1 + TACLR;         // ACLK, upmode, clear TAR
}

/**
 * start2
 *
 * Start T0A5 timer using ACLK ticks
 *
 * @param ticks ACLK clock cycles to be timed. Up to 2000 ms
 */
void TIMER0A5::start2(unsigned int ticks)
{
  TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
  TA0CCR0 = ticks;                // Max count
  TA0CTL = TASSEL_1 + MC_1 + TACLR;         // ACLK, upmode, clear TAR
}

/**
 * stop/halt
 *
 * Stop T0A5 timer
 */
void TIMER0A5::halt(void)
{
  TA0CTL = MC_0;                            // Halt timer
}

/**
 * reset
 *
 * Restart T0A5 timer
 */
void TIMER0A5::reset(void)
{
  TA0CTL |= TACLR;                            // Reset timer
}

/**
 * overflow
 *
 * Overflow/timeout T0A5 timer
 */
bool TIMER0A5::overflow(void)
{
   return (TA0R == TA0CCR0);				  // Returns overflow condition
}

/**
 * resume
 *
 * Continue timing the T0A5 timer
 */
void TIMER0A5::resume(void)
{
   TA0CTL = TASSEL_1 + MC_1;				  // Continue counter from halt
}

TIMER0A5 timer0a5;
#endif // __MSP430_HAS_T0A5__

