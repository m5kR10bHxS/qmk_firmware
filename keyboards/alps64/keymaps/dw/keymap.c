// Alps64

/*
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

uint16_t copy_paste_timer;

#define _QWERTY  0
#define _WORKMAN 1
#define _LOWER   2
#define _NAV     3
#define _ADJUST  4

enum custom_keycodes {
    KC_CCCV = SAFE_RANGE,
    KC_KEEB,
    KC_TMRK
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base Layer: QWERTY
 *
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------        
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |  | \ |  ` ~   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [ {  |  ] }  |    Bk Spc     |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|
 * |     Cps Lk    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; :  |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------|
 * |     Shift     |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |  , < |  . > |  /  ? |    Shift      |WORKMAN|
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|
 * |  Ctrl  | GUI  |  Alt |                         Space                         |  Alt  |  GUI  | LOWER |  Ctrl |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------'
 */

  [_QWERTY] = LAYOUT_infinity( \
      KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_BSLS, KC_GRV, \
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,    KC_BSPC,         \
      KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,                      \
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, TG(_WORKMAN),                \
      KC_LCTL, KC_LGUI, KC_LALT,                   KC_SPC,                                      KC_RALT, KC_RGUI, MO(_LOWER), KC_RCTL          \
  ),

/* Base Layer: WORKMAN
 *
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------        
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |  | \ |  ` ~   |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|
 * |  Tab   |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  | ;  : |  [ {  |  ] }  |    Bk Spc     |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------|
 * |      Ctrl     |   A  |   S  |  H   |   T  |   G  |   Y  |   N  |   E  |   O  |   I   |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------|
 * |      Shift    |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |  , < |  . > |  /  ? |     Shift     | QWERTY|
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------|
 * |  CCCV  | Menu |  Alt |                     Space Fn(NAV)                     |  Alt  | LEADER| LOWER |  Ctrl |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------'
 */

  [_WORKMAN] = LAYOUT_infinity( \
      KC_ESC,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,     KC_BSLS, KC_GRV, \
      KC_TAB,   KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,     KC_J,    KC_F,    KC_U,    KC_P,    KC_SCLN, KC_LBRC, KC_RBRC,    KC_BSPC,         \
      KC_LCTL,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,     KC_Y,    KC_N,    KC_E,    KC_O,    KC_I,    KC_QUOT, KC_ENT,                      \
      KC_LSFT,  KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,     KC_K,    KC_L,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, _______,                     \
      KC_CCCV,  KC_LGUI, KC_LALT,                   LT(_NAV,KC_SPC),                              KC_RALT, KC_LEAD, MO(_LOWER), KC_RCTL          \
  ),

  [_LOWER] = LAYOUT_infinity( \
      _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,    KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  _______,  _______, \
      _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,           \
      _______,  _______, _______, _______, _______, _______,  _______, KC_KEEB, KC_TMRK, _______, _______, _______, _______,                    \
      _______,  _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,                    \
      _______,  _______, _______,                   _______,                                      _______, _______, _______, _______            \
  ),

  [_NAV] = LAYOUT_infinity( \
      _______,  _______, KC_INS,  KC_HOME, KC_PGUP, KC_SYSREQ, _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
      _______,  _______, KC_DEL,  KC_END,  KC_PGDN, KC_PAUS,   _______, _______, _______, _______, _______,  _______, _______, _______,          \
      KC_CAPS,  _______, _______, _______, _______, KC_BRK,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,                   \
      _______,  _______, _______, _______, _______, _______,   _______, KC_PGUP, KC_PGDN, _______, _______,  _______, _______,                   \
      _______,  _______, _______,                   _______,                                       _______,  _______, _______, _______           \
  ),

[_ADJUST] = LAYOUT_infinity( \
      _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,  _______, _______, _______, _______, \
      _______,  _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______,  _______, _______, _______,          \
      KC_ASON,  KC_ASUP, KC_ASRP, _______, _______, _______,   _______, _______, _______, _______, _______,  _______, _______,                   \
      KC_ASOFF, KC_ASDN, _______, _______, _______, _______,   _______, _______, _______, _______, _______,  _______, _______,                   \
      RESET,    _______, _______,                   _______,                                       _______,  _______, _______, _______           \
  ),
};

// Change to _ADJUST layer, if both _LOWER and _NAV layers are held
layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _NAV, _ADJUST);
}

// Automate the auto shift feature: off w/ _QWERTY, but on w/ _WORKMAN
layer_state_t default_layer_state_set_user(layer_state_t state) {
    if (layer_state_cmp(state, _WORKMAN)) {
        autoshift_enable();
    } else {
        autoshift_disable();
    }
    return state;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_CCCV:  // One key copy/paste
            if (record->event.pressed) {
                copy_paste_timer = timer_read();
            } else {
                if (timer_elapsed(copy_paste_timer) > TAPPING_TERM) {  // Hold to copy
                    tap_code16(LCTL(KC_C));
                } else { // Tap to paste
                    tap_code16(LCTL(KC_V));
                }
            }
            break;
        case KC_KEEB:
            if (record->event.pressed) {
                send_unicode_hex_string("0x2328"); 
            }
        return false; 
            break;
        case KC_TMRK:
            if (record->event.pressed) {
                send_unicode_hex_string("0x2122"); 
            }
        return false; 
            break;
    }
    return true;
}

LEADER_EXTERNS();

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();

        SEQ_ONE_KEY(KC_N) { // Undo closed browser window
            SEND_STRING(SS_LCTL(SS_LALT("n")));
        }
        SEQ_ONE_KEY(KC_P) { // New private browser window
            SEND_STRING(SS_LCTL(SS_LSFT("p")));
        }
        SEQ_ONE_KEY(KC_R) { // Toggle browser reader mode
            SEND_STRING(SS_LCTL(SS_LSFT("r")));
        }
        SEQ_ONE_KEY(KC_T) { // Undo closed browser tab
            SEND_STRING(SS_LCTL(SS_LSFT("t")));
        }
    }
}

