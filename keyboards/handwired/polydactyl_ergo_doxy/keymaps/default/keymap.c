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
//#define _NUMPAD 4

// Some basic macros
#define TAPPING_TOGGLE 3

// layer lighting!
// https://beta.docs.qmk.fm/using-qmk/hardware-features/lighting/feature_rgblight

const rgblight_segment_t PROGMEM my_qwerty_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    //{6, 4, HSV_GREEN},       // Light 4 LEDs, starting with LED 6
    //{12, 4, HSV_GREEN}       // Light 4 LEDs, starting with LED 12
    {0, 32, HSV_GREEN}
);
const rgblight_segment_t PROGMEM my_fn_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 32, HSV_CYAN}
);
const rgblight_segment_t PROGMEM my_emacs_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 32, HSV_PURPLE}
);
const rgblight_segment_t PROGMEM my_mouse_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 32, HSV_ORANGE}
);

// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_qwerty_layer,
    my_fn_layer,    // Overrides caps lock layer
    my_emacs_layer,     // Overrides other layers
	my_mouse_layer
);

void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(0, layer_state_cmp(state, 0));
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}

bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_5x7(
  // left hand
   KC_ESC,       KC_1,     KC_2,    KC_3,   KC_4,   KC_5,   KC_GRV,
   KC_TAB,       KC_Q,     KC_W,    KC_E,   KC_R,   KC_T,   KC_LBRC,
   KC_LCTL,      KC_A,     KC_S,    KC_D,   KC_F,   KC_G,   RSFT(KC_LBRC),
   KC_LSPO,      KC_Z,     KC_X,    KC_C,   KC_V,   KC_B,
   TT(_MOUSE),   TT(_FN),  KC_LEFT, KC_RGHT,
                                                 KC_BSPC,       LGUI_T(KC_DEL),
                                                 KC_LALT,       KC_LCTL,
                                                 LGUI(KC_RBRC), LGUI(KC_LBRC),
					  // right hand
                     KC_EQL,  KC_6,    KC_7,    KC_8,     KC_9,     KC_0,     KC_MINS,
                     KC_RBRC, KC_Y,    KC_U,    KC_I,     KC_O,     KC_P,     KC_BSLS,
                 LSFT(KC_RBRC), KC_H,    KC_J,    KC_K,     KC_L,     KC_SCLN,  KC_QUOT,
                              KC_N,    KC_M,    KC_COMM,  KC_DOT,   KC_SLSH,  KC_RSPC,
                                       KC_DOWN, KC_UP,    TT(_FN),  TT(_MOUSE),
              RGUI_T(KC_ENT), KC_SPC,
              KC_RCTL,        KC_RALT,
              SGUI(KC_LBRC),  SGUI(KC_RBRC)),

[_FN] = LAYOUT_5x7(
  // left hand
   RGB_MOD,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F11,
   RGB_HUI,  RGB_M_P,  RGB_M_B,  RGB_M_R,  RGB_M_SW, RGB_M_SN,  DEBUG,
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

//[_NUMPAD] = LAYOUT_5x7(
//  // left hand
//   _______,   _______,   _______,   _______,   _______,   _______,  _______,
//   _______,   _______,   _______,   _______,   _______,   _______,  _______,
//   _______,   _______,   _______,   _______,   _______,   _______,  _______,
//   _______,   _______,   _______,   _______,   _______,   _______,
//   _______,   _______,   _______,   _______,
//                               _______, _______,
//                               _______, _______,
//                               _______, _______,
//        // right hand
//                     _______,   _______,     KC_P7,     KC_P8,     KC_P9,     KC_PPLS,   _______,
//                     _______,   _______,     KC_P4,     KC_P5,     KC_P6,     _______,   _______,
//                     _______,   _______,     KC_P1,     KC_P2,     KC_P3,     KC_PAST,   _______,
//                                _______,   _______,     KC_P0,     KC_PDOT,   KC_PSLS,   _______,
//                                                        _______,   _______,   _______,   _______,
//        KC_PENT, _______,
//        _______, _______,
//        _______, _______),
};
