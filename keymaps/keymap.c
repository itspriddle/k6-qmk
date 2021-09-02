/*
Copyright 2020 Dimitris Mantzouranis

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
#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum layer_names {
    _MAC_BASE,
    _MAC_FN1,
    _MAC_FN2,
    _WIN_BASE,
    _WIN_FN1,
    _WIN_FN2,
};

// Custom keykodes
enum my_keycodes {
  MAC_EXPOSE = SAFE_RANGE,
  MAC_LAUNCHPAD
};

// https://beta.docs.qmk.fm/using-qmk/simple-keycodes/keycodes

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │ BKSPC │LGT│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │HOM│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │ ESC  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │PUP│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ LSHIFT │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │RSHIFT│UP │PDN│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│OPT │CMD │                        │CMD│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *
 * LGT - Cycle Lights
 * HOM - Home
 * PUP - Page Up
 * PDN - Page Down
 */
[_MAC_BASE] = {
  // 0,      1,       2,       3,     4,     5,     6,      7,     8,     9,       10,      11,           12,           13,        14,      15
  { KC_GRV,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,    KC_0,    KC_MINS,      KC_EQL,       KC_BSPC,   KC_NO,   RGB_MOD   },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,    KC_P,    KC_LBRC,      KC_RBRC,      KC_BSLASH, KC_NO,   KC_HOME   },
  { KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,   KC_J,  KC_K,  KC_L,    KC_SCLN, KC_QUOT,      KC_NO,        KC_ENT,    KC_NO,   KC_PGUP   },
  { KC_LSFT, KC_NO,   KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,  KC_SLSH,      KC_NO,        KC_RSFT,   KC_UP,   KC_PGDOWN },
  { KC_LCTL, KC_LALT, KC_LGUI, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO,   KC_RGUI, MO(_MAC_FN1), MO(_MAC_FN2), KC_LEFT,   KC_DOWN, KC_RGHT   }
},

/* F14 - Brightness up
 * F15 - Brightness down
 * MEX - Exposé (custom keycode)
 * F16 - Custom, map to Launchpad in Keyboard prefs
 * KBD - Keyboard Brightness Down
 * KBU - Keyboard Brightness Up
 * MPR - Music Previous
 * MPL - Music Play
 * MNX - Music Next
 * VMU - Volume Mute
 * VUP - Volume Up
 * VDO - Volume Down
 * LTO - RGB toggle on/off
 * VAI - Increase RGB brightness
 * VAD - Decrease RGB brightness
 * LBK - RGB style back
 * LFW - RGB style forward
 *
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│F14│F15│MEX│F16│KBD│KBU│MPR│MPL│MNX│VMU│VUP│VDO│       │LTO│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │ CAPS │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ LSHIFT │   │   │   │   │   │   │   │   │   │   │RSHIFT│VAI│   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│OPT │CMD │ RESET KB TO BOOTLOADER │   │   │FN2│LBK│VAD│LFW│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *
 * TODO: Is RGB_TOG okay since it writes to EEPROM?
 */
[_MAC_FN1] = {
  // 0,      1,       2,       3,          4,      5,       6,       7,       8,       9,       10,      11,      12,      13,       14,      15
  { KC_ESC,  KC_F14,  KC_F15,  MAC_EXPOSE, KC_F16, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU, KC_NO,    KC_NO,   RGB_TOG },
  { KC_NO,   KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_DEL,  KC_END,  KC_NO,    KC_NO,   KC_NO   },
  { KC_CAPS, KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    KC_NO,   KC_NO   },
  { KC_TRNS, KC_NO,   KC_NO,   KC_NO,      KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS,  RGB_VAI, KC_NO   },
  { KC_TRNS, KC_TRNS, KC_TRNS, KC_NO,      KC_NO,  KC_NO,   RESET,   KC_NO,   KC_NO,   KC_NO,   KC_TRNS, KC_NO,   KC_NO,   RGB_RMOD, RGB_VAD, RGB_MOD }
},

/* F1-F12 - Standard F keys
 * HUI - RGB hue increase
 * HUI - RGB hue decrease
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │F13│F14│F15│F16│F17│F18│F19│F20│F21│F22│F23│F24│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │   │   │   │   │      │VAI│   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │ RESET KB TO BOOTLOADER │   │   │   │HUD│VAD│HUI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
[_MAC_FN2] = {
  // 0,    1,      2,      3,      4,      5,      6,      7,      8,      9,      10,     11,     12,     13,      14,      15
  { KC_NO, KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12, KC_NO,   KC_NO,   KC_NO      },
  { KC_NO, KC_F13, KC_F14, KC_F15, KC_F16, KC_F17, KC_F18, KC_F19, KC_F20, KC_F21, KC_F22, KC_F23, KC_F24, KC_NO,   KC_NO,   SGUI(KC_4) },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO      },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,   RGB_VAI, KC_NO      },
  { KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RESET,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  RGB_HUD, RGB_VAD, RGB_HUI    }
},

/*
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ + │ BKSPC │LGT│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │ TAB │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │ \   │HOM│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │ ESC  │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ ENTER  │PUP│
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │ LSHIFT │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ - │RSHIFT│UP │PDN│
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │CTRL│WIN │ALT │                        │MAC│FN1│FN2│LFT│DWN│RGT│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 *
 * LGT - Cycle Lights
 * HOM - Home
 * PUP - Page Up
 * PDN - Page Down
 */
[_WIN_BASE] = {
  // 0,      1,       2,       3,     4,     5,     6,      7,     8,     9,       10,       11,           12,           13,        14,      15
  { KC_ESC,  KC_1,    KC_2,    KC_3,  KC_4,  KC_5,  KC_6,   KC_7,  KC_8,  KC_9,    KC_0,     KC_MINS,      KC_EQL,       KC_BSPC,   KC_NO,   RGB_MOD   },
  { KC_TAB,  KC_Q,    KC_W,    KC_E,  KC_R,  KC_T,  KC_Y,   KC_U,  KC_I,  KC_O,    KC_P,     KC_LBRC,      KC_RBRC,      KC_BSLASH, KC_NO,   KC_HOME   },
  { KC_ESC,  KC_A,    KC_S,    KC_D,  KC_F,  KC_G,  KC_H,   KC_J,  KC_K,  KC_L,    KC_SCLN,  KC_QUOT,      KC_NO,        KC_ENT,    KC_NO,   KC_PGUP   },
  { KC_LSFT, KC_NO,   KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,   KC_N,  KC_M,  KC_COMM, KC_DOT,   KC_SLSH,      KC_NO,        KC_RSFT,   KC_UP,   KC_PGDOWN },
  { KC_LCTL, KC_LGUI, KC_LALT, KC_NO, KC_NO, KC_NO, KC_SPC, KC_NO, KC_NO, KC_NO,   KC_RCTRL, MO(_WIN_FN1), MO(_WIN_FN2), KC_LEFT,   KC_DOWN, KC_RGHT   }
},

/* BRU - Brightness up
 * BRD - Brightness down
 * KBD - Keyboard Brightness Down
 * KBU - Keyboard Brightness Up
 * MPR - Music Previous
 * MPL - Music Play
 * MNX - Music Next
 * VMU - Volume Mute
 * VUP - Volume Up
 * VDO - Volume Down
 * LOF - Keyboard Lights Off
 * VAI
 * VAD
 * LBK - Light style back
 * LFW - light style forward
 *
 *
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ESC│BRD│BRU│   │   │KBD│KBU│MPR│MPL│MNX│VMU│VUP│VDO│       │LOF│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │INS│DEL│END│     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │   │   │   │   │      │VAI│   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │ RESET KB TO BOOTLOADER │   │   │FN2│LBK│VAD│LFW│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
[_WIN_FN1] = {
  // 0,      1,       2,       3,     4,     5,       6,       7,       8,       9,       10,      11,      12,            13,       14,      15
  { KC_GRV,  KC_BRID, KC_BRIU, KC_NO, KC_NO, RGB_VAD, RGB_VAI, KC_MPRV, KC_MPLY, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,       KC_NO,    KC_NO,   RGB_TOG },
  { KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_INS,  KC_DEL,  KC_END,        KC_NO,    KC_NO,   KC_NO   },
  { KC_CAPS, KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,    KC_NO,   KC_NO   },
  { KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,         KC_NO,    RGB_VAI, KC_NO   },
  { KC_NO,   KC_NO,   KC_NO,   KC_NO, KC_NO, KC_NO,   RESET,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   DF(_MAC_BASE), RGB_RMOD, RGB_VAD, RGB_MOD }
},

/* F1-F12 - Standard F keys
 *
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │   │F1 │F2 │F3 │F4 │F5 │F6 │F7 │F8 │F9 │F10│F11│F12│       │   │
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │     │   │   │   │   │   │   │   │   │   │   │   │   │     │   │
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴─────┼───┤    
 * │      │   │   │   │   │   │   │   │   │   │   │   │        │   │
 * ├──────┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴────┬───┼───┤
 * │        │   │   │   │   │   │   │   │   │   │   │      │VAI│   │
 * ├────┬───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴──┬┴──┬┴──┬───┼───┼───┤
 * │    │    │    │ RESET KB TO BOOTLOADER │   │   │   │HUD│VAD│HUI│
 * └────┴────┴────┴────────────────────────┴───┴───┴───┴───┴───┴───┘
 */
[_WIN_FN2] = {
  // 0,    1,     2,     3,     4,     5,     6,     7,     8,     9,     10,     11,     12,     13,      14,      15
  { KC_NO, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_NO,   KC_NO,   KC_NO   },
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO   },
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   KC_NO,   KC_NO   },
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  KC_NO,   RGB_VAI, KC_NO   },
  { KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, RESET, KC_NO, KC_NO, KC_NO, KC_NO,  KC_NO,  KC_NO,  RGB_HUD, RGB_VAD, RGB_HUI }
}
};

// This does not fire :(
void dip_switch_update_user(uint8_t index, bool active) {
  switch (index) {
    case 0:
      if (active) {
        // BT mode
      } else {
        // Cable mode
      }
      break;
    case 1:
      if (active) {
        // Win/Android mode
      } else {
        // Mac/iOS mode
      }
      break;
  }
}

/* void dip_switch_update_kb(uint8_t index, bool active) { */
/*   if (index == 1) { */
/*     default_layer_set(1UL << (active ? 3 : 0)); */
/*   } */
/* } */

// Disable RGB at boot
void matrix_init_user(void) {
  rgblight_disable_noeeprom();
}

void keyboard_post_init_user(void) {
  // Customise these values to desired behaviour
  //debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
}

uint8_t mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  mod_state = get_mods();

  switch (keycode) {
    // FN1 + 3:        Exposé all apps' windows (via Ctrl-Up)
    // FN1 + CTRL + 3: Exposé current apps' windows (via Ctrl-Down)
    // FN1 + CMD + 3:  Show Desktop (via F11)
    case MAC_EXPOSE:
      if (mod_state & MOD_MASK_GUI) {
        if (record->event.pressed) {
          clear_mods();
          register_code(KC_F11);
          set_mods(mod_state);
        } else {
          unregister_code(KC_F11);
          set_mods(mod_state);
        }
      } else if (mod_state & MOD_MASK_CTRL) {
        if (record->event.pressed) {
          clear_mods();
          set_mods(MOD_MASK_CTRL);
          register_code(KC_DOWN);
          set_mods(mod_state);
        } else {
          unregister_code(KC_DOWN);
          set_mods(mod_state);
        }
      } else {
        if (record->event.pressed) {
          clear_mods();
          set_mods(MOD_MASK_CTRL);
          register_code(KC_UP);
          set_mods(mod_state);
        } else {
          unregister_code(KC_UP);
          set_mods(mod_state);
        }
      }
      return false;
      break;
    // FN + 4: Show Launchpad (via F16, needs to be manually set in Mac OS
    //         keyboard prefs)
    case MAC_LAUNCHPAD:
      if (record->event.pressed) {
        register_code(KC_F16);
      } else {
        unregister_code(KC_F16);
      }
      return false;
      break;
  }
  return true;
}
