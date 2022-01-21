/* Copyright 2020 Adam Honse <calcprogrammer1@gmail.com>
 * Copyright 2020 Dimitris Mantzouranis <d3xter93@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include "config_common.h"
#include "config_led.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x05ac
#define PRODUCT_ID      0x024f
#define DEVICE_VER      0x0001

#define MANUFACTURER    Keychron
#define PRODUCT         K6
#define DESCRIPTION     K6 RGB ANSI

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 16

#define DIODE_DIRECTION COL2ROW

#define MATRIX_COL_PINS { A8, A9, A10, A11, A12, A13, A14, A15, B0, B1, B2, B3, B4, B5, B6, B7 }
#define MATRIX_ROW_PINS { D11, D10, D9, D8, D7 }

// Connects each switch in the dip switch to the GPIO pin of the MCU
#define DIP_SWITCH_PINS { D5, D6 }

/* LED Status indicators */
#define LED_CAPS_LOCK_PIN B9
#define LED_PIN_ON_STATE  1

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 10

/*#define FORCE_NKRO*/

//    0,     1,     2,     3,     4,     5,     6,     7,     8,     9,     10,    11,    12,    13,    14,    15
#define LAYOUT( \
      K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,          K0F, \
      K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,          K1F, \
      K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,          K2D,          K2F, \
      K30,          K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,          K3D,   K3E,   K3F, \
      K40,   K41,   K42,                        K46,                        K4A,   K4B,   K4C,   K4D,   K4E,   K4F  \
) \
{ \
    { K00,   K01,   K02,   K03,   K04,   K05,   K06,   K07,   K08,   K09,   K0A,   K0B,   K0C,   K0D,   KC_NO, K0F }, \
    { K10,   K11,   K12,   K13,   K14,   K15,   K16,   K17,   K18,   K19,   K1A,   K1B,   K1C,   K1D,   KC_NO, K1F }, \
    { K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28,   K29,   K2A,   K2B,   KC_NO, K2D,   KC_NO, K2F }, \
    { K30,   KC_NO, K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K3A,   K3B,   KC_NO, K3D,   K3E,   K3F }, \
    { K40,   K41,   K42,   KC_NO, KC_NO, KC_NO, K46,   KC_NO, KC_NO, KC_NO, K4A,   K4B,   K4C,   K4D,   K4E,   K4F }, \
}
