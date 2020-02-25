// Clueboard

#include QMK_KEYBOARD_H

uint16_t copy_paste_timer;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
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

/* Base Layer: QWERTY (Default Layer)
 *
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+        
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  - _  |  = +  |    Bk Spc     |       | PgUp  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |  Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  [ {  |  ] }  |     \ |       |       | PgDn  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |     Cps Lk    |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |  ; :  |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------+-------+
 * |     Shift     |   Z  |   X  |   V  |   V  |   B  |   N  |   M  |  , < |  . > |  /  ? |         Shift         |   Up  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------+-------+-------+
 * |  Ctrl  | Menu |  Alt |                         Space                         | LOWER |  Ctrl |WORKMAN| Left  |  Down | Right |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

[QWERTY] = LAYOUT_66_ansi(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_BSPC,          KC_PGUP,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,       KC_P,    KC_LBRC, KC_RBRC, KC_BSLS,          KC_PGDN,
  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,       KC_SCLN, KC_QUOT, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT,                   KC_UP,
  KC_LCTL, KC_LGUI, KC_LALT,                            KC_SPC,                    MO(_LOWER), KC_RCTL, TG(_WORKMAN),     KC_LEFT, KC_DOWN, KC_RGHT
),

/* Base Layer: WORKMAN: Alternate Base Layer)
 *
 *  --------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+        
 * |  Esc   |   1  |   2  |   3  |   4  |   5  |  6   |   7  |   8  |   9  |   0  |  - _  |  = +  |     | \       |       | PgUp  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |  Tab   |   Q  |   D  |   R  |   W  |   B  |   J  |   F  |   U  |   P  | ;  : |  [ {  |  ] }  |    Bk Spc     |       | PgDn  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+------+--------+       +-------+
 * |      Ctrl     |   A  |   S  |   H  |   T  |   G  |   Y  |   N  |   E  |   O  |   I   |  ' "  |    Enter      |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+---------------+-------+
 * |     Shift     |   Z  |   X  |   M  |   C  |   V  |   K  |   L  |  , < |  . > |  /  ? |         Shift         |   Up  |
 * |--------+------+------+------+------+------+------+------+------+------+------+-------+-------+-------+-------+-------+-------+
 * |  CCCV  | Menu |  Alt |                     Space FN (NAV)                    | LOWER | LEADER| QWERTY| Left  |  Down | Right |
 *  --------+------+------+-------------------------------------------------------+-------+-------+-------+-------+-------+-------+    
 */

[WORKMAN] = LAYOUT_66_ansi(
  KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,       KC_0,    KC_MINS, KC_EQL,  KC_BSLS,           KC_PGUP,
  KC_TAB,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,    KC_J,    KC_F,    KC_U,    KC_P,       KC_SCLN, KC_LBRC, KC_RBRC, KC_BSPC,           KC_PGDN,
  KC_LCTL, KC_A,    KC_S,    KC_H,    KC_T,    KC_G,    KC_Y,    KC_N,    KC_E,    KC_O,       KC_I,    KC_QUOT, KC_ENT,
  KC_LSFT, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,    KC_K,    KC_L,    KC_COMM, KC_DOT,     KC_SLSH, KC_RSFT,                    KC_UP,
  KC_CCCV, KC_LGUI, KC_LALT,                            LT(_NAV,KC_SPC),           MO(_LOWER), KC_LEAD, _______,           KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Keymap LOWER: Function layer
 */
[LOWER] = LAYOUT_66_ansi(
  _______,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_F11,  KC_F12, _______,           KC_PGUP,
  _______,  _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______,           KC_PGDN,
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
  _______,  _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,                    KC_UP,
  _______,  _______, _______,                            _______,                   _______, _______, _______,           KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Keymap NAV: Navigation Layer
 */
[NAV] = LAYOUT_66_ansi(
  _______, _______, KC_INS,  KC_HOME, KC_PGUP, KC_SYSREQ, _______, _______, _______, _______, _______,  _______, _______, _______,          KC_PGUP,
  _______, _______, KC_DEL,  KC_END,  KC_PGDN, KC_PAUS,   _______, _______, _______, _______, _______,  _______, _______, _______,          KC_PGDN,
  KC_CAPS, _______, _______, _______, _______, KC_BRK,    _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, _______,
  _______, _______, _______, _______, _______, _______,   _______, KC_PGDN, KC_PGUP, _______, _______,  _______,                   KC_UP,
  _______, _______, _______,                              _______,                   _______, _______,  _______,          KC_LEFT, KC_DOWN, KC_RIGHT
),

/* Keymap ADJUST: Adjust Layer
 */
[ADJUST] = LAYOUT_66_ansi(
  _______,  _______, KC_MNXT, KC_VOLU, KC_MUTE, _______,   _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, _______, _______, _______,           KC_VOLU,
  _______,  _______, KC_MPRV, KC_VOLD, KC_MPLY, _______,   _______, RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD, _______, _______, _______,           KC_VOLD,
  KC_ASON,  KC_ASUP, KC_ASRP, _______, _______, _______,   _______, _______, _______, _______, _______, _______, _______,
  KC_ASOFF, KC_ASDN, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,                    KC_UP,
  RESET,    _______, _______,                              _______,                   _______, _______, _______,           KC_LEFT, KC_DOWN, KC_RIGHT
),
};

layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _LOWER, _NAV, _ADJUST);
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
                send_unicode_hex_string("2328"); 
            }
        return false; 
            break;
        case KC_TMRK:
            if (record->event.pressed) {
                send_unicode_hex_string("2122"); 
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

