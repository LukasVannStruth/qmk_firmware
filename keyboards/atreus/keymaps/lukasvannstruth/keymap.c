// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _TYPING 0
#define _NUMNAV 1
#define _MISC 2

LEADER_EXTERNS();

// custom keycodes
#define NUMNAV MO(_NUMNAV)
#define MISC MO(_MISC)
#define CTL_ENT MT(MOD_LCTL, KC_ENT)
#define ALT_ESC MT(MOD_LALT, KC_ESC)
#define BRACE TD(TD_BRACE)
#define SQ_BRKT TD(TD_SQ_BRKT)
#define PARENTH TD(TD_PARA)
#define MULDIV TD(TD_MULDIV)
#define EQLPLS TD(TD_EQLPLS)
#define DOTENT TD(TD_DOTENT)

// tap dance keycodes
enum {
    TD_BRACE = 0,
    TD_SQ_BRKT = 1,
    TD_PARA = 2,
    TD_MULDIV = 3,
    TD_EQLPLS = 4,
    TD_DOTENT = 5
};

enum custom_keycodes {
    CTRL_AND_ENTER = SAFE_RANGE,
    ALT_AND_ESC = SAFE_RANGE
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_BRACE] = ACTION_TAP_DANCE_DOUBLE(KC_LCBR, KC_RCBR),
    [TD_SQ_BRKT] = ACTION_TAP_DANCE_DOUBLE(KC_LBRC, KC_RBRC),
    [TD_PARA] = ACTION_TAP_DANCE_DOUBLE(KC_LPRN, KC_RPRN),
    [TD_MULDIV] = ACTION_TAP_DANCE_DOUBLE(KC_PAST, KC_PSLS),
    [TD_EQLPLS] = ACTION_TAP_DANCE_DOUBLE(KC_PEQL, KC_PPLS),
    [TD_DOTENT] = ACTION_TAP_DANCE_DOUBLE(KC_PDOT, KC_PENT)
};

// remember on my atreus the central column is upside down so alt is on the left and control is on the left
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_TYPING] = LAYOUT( 
    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                      KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
    MISC,    KC_TAB,  KC_LGUI, KC_LSFT, KC_BSPC, ALT_ESC, CTL_ENT, KC_SPC,  NUMNAV,  KC_MINS, KC_QUOT, KC_LEAD
  ),
  /* shit be out of date fam
   *  -      7     8     9     {         ||         }     home  pgdn  pgup end
   *  =      4     5     6     [         ||         ]     left  down  up   rght
   *  `      1     2     3     (         ||         )     \     psng  p\ps nsng
   *  func   0     lgui  shft  bspc ctrl || alt     spce  num   vold  musc volu
   */
  [_NUMNAV] = LAYOUT( 
    KC_MINS,   KC_7,   KC_8,    KC_9,    EQLPLS,                    BRACE,   KC_HOME, KC_PGDN, KC_PGUP, KC_END,
    KC_EQL,    KC_4,   KC_5,    KC_6,    MULDIV,                    SQ_BRKT, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
    KC_GRV,    KC_1,   KC_2,    KC_3,    DOTENT,                    PARENTH, KC_BSLS, KC_MPRV, KC_MPLY, KC_MNXT,
    KC_TRNS,   KC_0,   KC_LGUI, KC_LSFT, KC_BSPC, ALT_ESC, CTL_ENT, KC_SPC,  KC_TRNS, KC_VOLD, KC_MSEL, KC_VOLU
   ),
  /*  
   * insert home   up  end   pgup       ||      up     F9    F10   F11  F12
   *  del   left  down right pgdn       ||     down    F5    F6    F7   F8
   *       volup             reset      ||             F1    F2    F3   F4
   *       voldn  super shift bksp ctrl || alt space   L0  prtsc scroll pause
   */
  [_MISC] = LAYOUT( 
    KC_NO,   KC_NO, KC_NO,   KC_NO,   KC_PGUP,                   KC_UP,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_DELT, KC_NO, KC_NO,   KC_NO,   KC_NO,                   KC_DOWN, KC_F5,   KC_F6,   KC_F7,   KC_F8,
    KC_NO,   KC_NO, KC_NO,   KC_NO,   RESET,                     KC_NO,   KC_F1,   KC_F2,   KC_F3,   KC_F4,
    KC_TRNS, KC_NO, KC_LGUI, KC_LSFT, KC_BSPC, ALT_ESC, CTL_ENT, KC_SPC,  KC_NO,   KC_PSCR, KC_SLCK, KC_PAUS
   )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch(keycode) {
        
    }
    return true;
}

void matrix_scan_user(void) {
    LEADER_DICTIONARY() {
        leading = false;
        leader_end();
        
        // excel paste values 
        SEQ_THREE_KEYS(KC_E, KC_S, KC_V) { SEND_STRING(SS_LALT("esv")"\n"); }     
        // excel paste formats
        SEQ_THREE_KEYS(KC_E, KC_S, KC_T) { SEND_STRING(SS_LALT("est")"\n"); }
        // excel paste formulas
        SEQ_THREE_KEYS(KC_E, KC_S, KC_T) { SEND_STRING(SS_LALT("esf")"\n"); }
        
        // excel hide rows
        SEQ_THREE_KEYS(KC_E, KC_F, KC_R) { SEND_STRING(SS_LALT("hour")); }
        // excel hide columns
        SEQ_THREE_KEYS(KC_E, KC_F, KC_C) { SEND_STRING(SS_LALT("houc")); }
        // excel unhide rows
        SEQ_THREE_KEYS(KC_E, KC_F, KC_T) { SEND_STRING(SS_LALT("houo")); }
        // excel unhide columns
        SEQ_THREE_KEYS(KC_E, KC_F, KC_V) { SEND_STRING(SS_LALT("houl")); }
         
        // excel insert row
        SEQ_THREE_KEYS(KC_E, KC_D, KC_R) { SEND_STRING(SS_LSFT(" "SS_LCTRL("+"))); }
        // excel insert column
        SEQ_THREE_KEYS(KC_E, KC_D, KC_C) { SEND_STRING(SS_LCTRL(" "SS_LSFT("+"))); }

        // excel autofit row
        SEQ_THREE_KEYS(KC_E, KC_D, KC_A) { SEND_STRING(SS_LALT("hoa")); }
        // excel autofit column
        SEQ_THREE_KEYS(KC_E, KC_D, KC_S) { SEND_STRING(SS_LALT("hoi")); }

        // excel toggle word wrap
        SEQ_FOUR_KEYS(KC_E, KC_F, KC_W, KC_W) { SEND_STRING(SS_LALT("hw")"\n"); }
    }
    


}
