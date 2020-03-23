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
 * Creation date: 02/21/2013
 */

#ifndef _TIMER0A5_H
#define _TIMER0A5_H

#include "Arduino.h"

#ifdef __MSP430_HAS_T0A5__

/**
 * Class: TIMER0
 */
class TIMER0A5
{
  public:
    /**
     * Class constructor
     */
    TIMER0A5(void);

    /**
     * TA5 overflow callback function
     */
    void (*timer0a5overflow)(void);

    /**
     * start
     *
     * Start T0A5 timer
     *
     * @param millis Milliseconds to be timed. Up to 2000 ms
     */
    void start(unsigned int millis);
	
    /**
     * start2
     *
     * Start T0A5 timer using ACLK ticks
     *
     * @param ticks ACLK clock cycles to be timed. Up to 2000 ms
     */
    void start2(unsigned int ticks);

    /**
     * halt
     *
     * Stop T0A5 timer
     */
    void halt(void);
	
    /**
     * resume
     *
     * Continue T0A5 timer
     */
    void resume(void);
	
    /**
     * reset
     *
     * Resets T0A5 timer
     */
    void reset(void);
	
    /**
     * overflow
     *
     * Overflow/timeout T0A5 timer
     */
    bool overflow(void);

    /**
     * attachInterrupt
     * 
     * Declare custom ISR, to be called whenever the timer overflows
     * 
     * @param funct pointer to the custom function
     */
     inline void attachInterrupt(void (*funct)(void))
     {
       timer0a5overflow = funct;
     }
};

extern TIMER0A5 timer0a5;

#endif  // __MSP430_HAS_T0A5__
#endif
