/*
Copyright 2012 Jun Wako <wakojun@gmail.com>
Copyright 2015 Jack Humbert

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID    0x444D
#define MANUFACTURER __dcbs
#define PRODUCT_ID   0x3537
#define DEVICE_VER   0x0003
#define PRODUCT      Polydactyl-ErgoDoxy (5x7)
#define DESCRIPTION  An ergo split board for those who wouldst live deliciously

/* mouse config */
#define MOUSEKEY_INTERVAL    20
#define MOUSEKEY_DELAY        0
#define MOUSEKEY_TIME_TO_MAX 60
#define MOUSEKEY_MAX_SPEED    7
#define MOUSEKEY_WHEEL_DELAY  0

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* serial.c configuration for split keyboard */
//#define SOFT_SERIAL_PIN D0
#define SOFT_SERIAL_PIN A10 // Proton C RX serial

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
// #define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
// #define LOCKING_RESYNC_ENABLE

/* Enables This makes it easier for fast typists to use dual-function keys */
#define PERMISSIVE_HOLD

/* key matrix size */
// Rows are doubled-up
#define MATRIX_ROWS 12
#define MATRIX_COLS 7

// wiring of each half
#define MATRIX_ROW_PINS { A0, B8, B13, B14, B15, B9 }
#define MATRIX_COL_PINS { B6, B5, B4, B3, B2, B1, B0 }

#define DIODE_DIRECTION COL2ROW

// WS2812 RGB LED strip input and number of LEDs
#define RGBLED_NUM 32 
//#define RGBLED_SPLIT { 8, 8 }
#define RGB_DI_PIN B7
#define RGBLIGHT_ANIMATIONS

// borrowed from planck/rev6
//#define DRIVER_LED_TOTAL RGBLED_NUM
//#define WS2812_PWM_DRIVER PWMD4
//#define WS2812_PWM_CHANNEL 1
//#define WS2812_PWM_PAL_MODE 2
//#define WS2812_DMA_STREAM STM32_DMA1_STREAM3
//#define WS2812_DMA_CHANNEL 3

