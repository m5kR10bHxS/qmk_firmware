#include QMK_KEYBOARD_H

uint16_t copy_paste_timer

#define WORKMAN = 0,
#define LOWER 1,
#define RAISE 2,
#define ADJUST 16

enum custom_keycodes {
  KC_CCCV = SAFE_RANGE,
//  QWERTY,
//  LOWER,
//  RAISE,
//  ADJUST,
};

//#define CALTDEL LCTL(LALT(KC_DEL))
//#define TSKMGR LCTL(LSFT(KC_ESC))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [WORKMAN] = LAYOUT(
  //,--------+--------+--------+--------+--------+------------------+-------------------. ,--------------------+-----------------+--------+-----------+--------+--------+--------.
     KC_ESC,  KC_Q,    KC_D,    KC_R,    KC_W,    KC_B,              KC_MINS,              KC_EQL,              KC_J,             KC_F,    KC_U,       KC_P,    KC_SCLN, KC_PIPE,
  //|--------+--------+--------+--------+--------+------------------+-------------------| |--------------------+-----------------+--------+-----------+--------+--------+--------|
     KC_TAB,  KC_A,    KC_S,    KC_H,    KC_T,    KC_G,              KC_LBRC,              KC_RBRC,             KC_Y,             KC_N,    KC_E,       KC_O,    KC_I,    KC_QUOT,
  //|--------+--------+--------+--------+--------+------------------+-------------------| |--------------------+-----------------+--------+-----------+--------+--------+--------|
     KC_LCTL, KC_Z,    KC_X,    KC_M,    KC_C,    KC_V,              KC_CCCV,              KC_LEAD,             KC_K,             KC_L,    KC_COMM,    KC_DOT,  KC_SLSH, KC_RCTL,
  //|--------+--------+--------+--------+--------+------------------+-------------------| |--------------------+-----------------+--------+-----------+--------+--------+--------|
     _______, KC_LGUI, KC_LALT, MO(NAV),          LT(LOWER,KC_BSPC), MT(MOD_LSFT,KC_DEL),  MT(MOD_RSFT,KC_ENT), LT(RAISE,KC_SPC),          MO(ADJUST), KC_RALT, KC_MPLY, _______
  //`--------+--------+--------+--------+--------+------------------+-------------------/  \-------------------+-----------------+--------+-----------+--------+--------+--------'
  ),

  [_LOWER] = LAYOUT(
 
     KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,    _______,               _______,   _______,   KC_7,    KC_8,    KC_9,    KC_SLSH, KC_MINS,
     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______,               _______,   _______,   KC_4,    KC_5,    KC_6,    KC_ASTR, KC_PLUS,
     _______, _______, _______, _______, _______, _______,  _______,               _______,   KC_0,      KC_1,    KC_2,    KC_3,    KC_COMM, KC_DOT,
     _______, _______, _______, _______,          _______,  _______,               _______,   _______,            _______, _______, _______, _______
  ),

  [_RAISE] = LAYOUT(
     KC_TILD, KC_EXLM,  KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_HOME,               KC_PGUP,     KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_DEL,
     _______, KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_END ,               KC_PGDN,     KC_F6,   KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_BSLS,
     _______, KC_F7,    KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_BSPC,               KC_BSPC,     KC_F12,  _______, _______, KC_MUTE, _______, KC_PIPE,
     _______, _______,  _______, _______,          KC_BSPC, _______,               KC_BSPC,     _______,          KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
  ),

  [_NAV] = LAYOUT(
     _______, _______,  KC_INS,  KC_HOME, KC_PGUP, KC_SYSREQ, _______,              _______,  _______, _______, _______, _______, _______,  _______,
     KC_CAPS, _______,  KC_DEL,  KC_END,  KC_PGDN, KC_PAUS,   _______,              _______,  _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______,
     _______, _______,  _______, _______, KC_PSCR, KC_BRK,    _______,              _______,  _______, _______, _______, _______, _______,  _______,
     _______, _______,  _______, _______,          _______,   _______,              _______,  _______,          _______, _______, _______,  _______
  ),

  [_ADJUST] = LAYOUT(
     _______, _______,  KC_MNXT, KC_VOLU, KC_MUTE, _______, _______,              _______,  _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, _______,
     _______, _______,  KC_MPRV, KC_VOLD, KC_MPLY, _______, _______,              _______,  _______, RGB_MOD, RGB_SAD, RGB_HUD, RGB_VAD, _______,
     _______, _______,  _______, _______, _______, _______, _______,              _______,  _______, _______, _______, _______, _______, _______,
     _______, _______,  _______, _______,          _______, _______,              _______,  _______,          _______, _______, _______, _______
  ),

};






/*
*bool process_record_user(uint16_t keycode, keyrecord_t *record) {
*  switch (keycode) {
*    case QWERTY:
*      if (record->event.pressed) {
*        #ifdef AUDIO_ENABLE
*          PLAY_SONG(tone_qwerty);
*        #endif
*        set_single_persistent_default_layer(_QWERTY);
*      }
*      return false;
*      break;
*    case LOWER:
*      if (record->event.pressed) {
*        layer_on(_LOWER);
*        update_tri_layer(_LOWER, _RAISE, _ADJUST);
*      } else {
*        layer_off(_LOWER);
*        update_tri_layer(_LOWER, _RAISE, _ADJUST);
*      }
*      return false;
*      break;
*    case RAISE:
*      if (record->event.pressed) {
*        layer_on(_RAISE);
*        update_tri_layer(_LOWER, _RAISE, _ADJUST);
*      } else {
*        layer_off(_RAISE);
*        update_tri_layer(_LOWER, _RAISE, _ADJUST);
*      }
*      return false;
*      break;
*    case ADJUST:
*      if (record->event.pressed) {
*        layer_on(_ADJUST);
*      } else {
*        layer_off(_ADJUST);
*      }
*      return false;
*      break;
*  }
*  return true;
*}
*/
