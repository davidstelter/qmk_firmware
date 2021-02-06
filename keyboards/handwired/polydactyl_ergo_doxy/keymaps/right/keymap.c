//#include QMK_KEYBOARD_H
#include "5x7.h"


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _FN     1
#define _EMACS  2
#define _MOUSE  3

#define TAPPING_TOGGLE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_5x7(
  // left hand
   KC_ESC,       KC_1,     KC_2,    KC_3,   KC_4,   KC_5,   KC_GRV,
   KC_TAB,       KC_Q,     KC_W,    KC_E,   KC_R,   KC_T,   KC_HOME,
   KC_LCTL,      KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   KC_END,
   KC_LSPO,      KC_Z,     KC_X,    KC_C,   KC_V,   KC_B,
   KC_GRV,       KC_EQL,   KC_LEFT, KC_RGHT,
                                                 KC_BSPC,       LGUI_T(KC_DEL),
                                                 KC_LALT,       KC_LCTL,
                                                 TT(_FN),       TT(_MOUSE),
					  // right hand
                      KC_EQL, KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                     KC_PGDN, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                     KC_PGUP, KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                              KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSFT,
                                       KC_DOWN, KC_UP,    KC_LBRC,  KC_RBRC,
              RGUI_T(KC_ENT), KC_SPC,
              KC_RCTL,        KC_RALT,
              TT(_MOUSE),     TT(_FN)),

[_FN] = LAYOUT_5x7(
  // left hand
   RGB_MOD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,
   RGB_HUI,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN, DEBUG,
   RGB_SAI,  RGB_M_K,  RGB_M_X,  RGB_M_G,  RGB_M_T,  _______,  RESET,
   RGB_VAI,  _______,  _______,  _______,  _______,  _______,
   _______,  _______,  _______,  _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     KC_F12,    KC_F6,   KC_F7,    KC_F8,    KC_F9,    KC_F10,   RGB_TOG,
                     _______,  _______,  _______,  _______,  _______,  _______,  RGB_MOD,
                     _______,  _______,  _______,  _______,  _______,  _______,  _______,
                               _______,  _______,  _______,  _______,  _______,  _______,
                                                   _______,  _______,  _______,  _______,
        _______, _______,
        _______, _______,
        _______, _______),

[_EMACS] = LAYOUT_5x7(
  // left hand
   _______,   _______,   _______,   KC_END,   _______,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,  _______,
   _______,   KC_HOME,   _______,   KC_DEL,    KC_RGHT,   _______,  _______,
   _______,   _______,   _______,   _______,   _______,   _______,
   _______,   _______,   _______,   _______,
                               _______, _______,
                               _______, _______,
                               _______, _______,
        // right hand
                     _______,   _______,   _______,     _______,   _______,   _______,   _______,
                     _______,   _______,   _______,     _______,   _______,   _______,   _______,
                     _______,   KC_BSPC,   _______,     _______,   _______,   _______,   _______,
                                _______,   _______,     _______,   _______,   _______,   _______,
                                                        _______,   _______,   _______,   _______,
        _______, _______,
        _______, _______,
        _______, _______),

[_MOUSE] = LAYOUT_5x7(
  // left hand
   CK_TOGG,   _______,   _______,   _______,  _______,  _______,  _______,
   _______,   _______,   _______,   _______,  _______,  _______,  _______,
   _______,   _______,   _______,   _______,  _______,  _______,  _______,
   _______,   _______,   _______,   _______,  _______,  _______,
   _______,   _______,   _______,   _______,
                                                         KC_BTN1, KC_BTN2,
                                                         XXXXXXX, KC_BTN3,
                                                         KC_BTN4, KC_BTN5,
        // right hand
                     KC_ACL0,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   _______,
                     KC_ACL1,  XXXXXXX,  XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,   _______,
                     KC_ACL2,  KC_MS_L,  KC_MS_D,  KC_MS_U,  KC_MS_R,   XXXXXXX,   _______,
                               KC_WH_L,  KC_WH_D,  KC_WH_U,  KC_WH_R,   XXXXXXX,   _______,
                                                   XXXXXXX,  XXXXXXX,   _______,   _______,
                     KC_BTN2, KC_BTN1,
                     KC_BTN3, XXXXXXX,
					 KC_BTN4, KC_BTN5),
};
