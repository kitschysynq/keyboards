#pragma once

#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
	#include <avr/io.h>
	#include <avr/interrupt.h>
#endif
#endif

#define LAYOUT( \
	          R00, R01, R02, R03, R04, \
	          R10, R11, R12, R13, R14, \
	          R20, R21, R22, R23, R24, \
	                    R32, R33,      \
                  R30, R31,                \
        R41, R40,                          \
        R43, R42                           \
	) \
	{ \
		{ R04, R03, R02, R01, R00 },    \
		{ R14, R13, R12, R11, R10 },    \
		{ R24, R23, R22, R21, R20 },    \
		{ KC_NO, R33, R32, R31, R30 },  \
		{ KC_NO, R43, R42, R41, R40 }  \
	}
