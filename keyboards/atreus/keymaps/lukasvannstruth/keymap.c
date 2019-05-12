// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TYPING 0
#define _NUMNAV 1
#define _FUNC 2

#define TAPPING_TOGGLE 2
// remember on my atreus the central column is upside down so alt is on the left and control is on the left
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_TYPING] = LAYOUT( /* Qwerty */
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P    ,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN ,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH ,
    KC_ESC, KC_TAB, KC_LGUI,  KC_LSFT, KC_BSPC,  KC_LALT, KC_LCTRL, KC_SPC,  MO(_NUMNAV), KC_MINS, KC_QUOT, KC_ENT
  ),
/*
  // old numnav layout
  /
   *  !       @     up     {    }        ||     pgup    7     8     9    *
   *  #     left   down  right  $        ||     pgdn    4     5     6    +
   *  [       ]      (     )    &        ||       `     1     2     3    \
   * lower  insert super shift bksp ctrl || alt space   num    .     0    =
   /
  */
  /*
   *  -      7     8     9     {         ||         }     home  pgdn  pgup end
   *  =      4     5     6     [         ||         ]     left  down  up   rght
   *  `      1     2     3     (         ||         )     \     psng  p\ps nsng
   *  func   0     lgui  shft  bspc ctrl || alt     spce  num   vold  musc volu
   */
  [_NUMNAV] = LAYOUT( /* [> RAISE <] */
    KC_MINS,   KC_7,   KC_8,    KC_9, KC_LCBR,                   KC_RCBR, KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_EQL,    KC_4,   KC_5,    KC_6, KC_LBRC,                   KC_RBRC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_GRV,    KC_1,   KC_2,    KC_3, KC_LPRN,                   KC_RPRN, KC_BSLS, KC_MPRV, KC_MPLY, KC_MNXT,
    MO(_FUNC), KC_0, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTRL, KC_SPC,  KC_TRNS, KC_VOLD, KC_MSEL, KC_VOLU),
  /* \ has to go on here somehwere
   * insert home   up  end   pgup       ||      up     F7    F8    F9   F10
   *  del   left  down right pgdn       ||     down    F4    F5    F6   F11
   *       volup             reset      ||             F1    F2    F3   F12
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_FUNC] = LAYOUT( /* [> LOWER <] */
    KC_INS,  KC_HOME, KC_UP,   KC_END,  KC_PGUP,                   KC_UP,   KC_F7,   KC_F8,   KC_F9,   KC_F10  ,
    KC_DELT, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN,                   KC_DOWN, KC_F4,   KC_F5,   KC_F6,   KC_F11  ,
    KC_NO,   KC_VOLU, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F12  ,
    KC_NO,   KC_VOLD, KC_LGUI, KC_LSFT, KC_BSPC, KC_LALT, KC_LCTRL, KC_SPC,  TO(_TYPING), KC_PSCR, KC_SLCK, KC_PAUS )
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt) {
  // MACRODOWN only works in this function
  switch(id) {
    case 0:
      if (record->event.pressed) {
        register_code(KC_RSFT);
      } else {
        unregister_code(KC_RSFT);
      }
    break;
  }
  return MACRO_NONE;
}
