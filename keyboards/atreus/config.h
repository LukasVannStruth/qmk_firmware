/*
Copyright 2012 Jun Wako <wakojun@gmail.com>

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

#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */

#define VENDOR_ID       0x1209
#define PRODUCT_ID      0xA1E5
#define DEVICE_VER      0x0008
#define MANUFACTURER    Technomancy
#define PRODUCT         Atreus
#define DESCRIPTION     q.m.k. keyboard firmware for Atreus


#define CATERINA_BOOTLOADER

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 11

// Change this to how you wired your keyboard
// COLS: Left to right, ROWS: Top to bottom
// normal matrix rows and not pcbdown
// new cols: {qtqtuqtiwus
#if defined(ATREUS_ASTAR)
#   define MATRIX_ROW_PINS { D3, D2, D0, D1 }
#if defined(PCBDOWN)
#   define MATRIX_COL_PINS { B7, D6, F7, F6, B6, D4, E6, B4, B5, C6, D7 }
#else
//#   define MATRIX_COL_PINS {D4, C6, D7, E6, B4, F1, B3, B1, F7, F6, F5 }
#   define MATRIX_COL_PINS {B3, B1, F7, F6, F5, F1, D4, C6, D7, E6, B4 }
#endif
#   define UNUSED_PINS
#elif defined(ATREUS_TEENSY2)
#   define MATRIX_ROW_PINS { D0, D1, D2, D3 }
#   define MATRIX_COL_PINS { F6, F5, F4, B7, B6, B5, B4, B3, B2, B1, B0 }
#   define UNUSED_PINS
#endif

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
//#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCING_DELAY 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif
