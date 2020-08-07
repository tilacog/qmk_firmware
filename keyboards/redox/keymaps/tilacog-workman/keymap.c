#include QMK_KEYBOARD_H

#define _WORKMAN 0
#define _SYMB 1
#define _MOUSE 2

// Shortcut to make keymap more readable
#define KC_TABOS LGUI_T(KC_TAB)      // Tap: Tab        , hold: Super
#define KC_BMSL LT(_MOUSE, KC_BSPC)  // Tap: Backspace  , hold: Mouse layer
#define KC_BSSL LT(_SYMB, KC_BSPC)   // Tap: Backspace  , hold: Symbol layer
#define KC_DLSL LT(_SYMB, KC_DEL)    // Tap: Delete     , hold: Symbol layer
#define KC_LASP LALT_T(KC_SPC)       // Tap: Space      , hold: Left Alt
#define KC_RASP RALT_T(KC_SPC)       // Tap: Space      , hold: Right Alt
#define KC_PUSL LT(_SYMB, KC_PGUP)   // Tap: Page Up    , hold: Symbol layer
#define KC_PDSL LT(_SYMB, KC_PGDN)   // Tap: Page Down  , hold: Symbol layer
#define KC_TBSL LT(_SYMB, KC_TAB)    // Tap: Tab        , hold: Symbol layer
#define KC_UNSL LT(_SYMB, KC_UNDS)   // Tap: Underscore , hold: Symbol layer

// One Shots
#define DEAD_LA OSM(MOD_LALT)
#define DEAD_LG OSM(MOD_LGUI)
#define DEAD_LC OSM(MOD_LCTL)
#define DEAD_LS OSM(MOD_LSFT)
#define DEAD_SG OSM(MOD_LSFT | MOD_LGUI)
#define OS_SYMB OSL(_SYMB)

// Tap Dance
enum {
    TD_HOME_END,
};

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
};

#define TD_HE TD(TD_HOME_END)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {  // clang-format off

  [_WORKMAN] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     KC_GESC ,KC_1    ,KC_2    ,KC_3    ,KC_4    ,KC_5    ,                                            KC_6    ,KC_7    ,KC_8    ,KC_9    ,KC_0    ,KC_MINS ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_TABOS,KC_Q    ,KC_D    ,KC_R    ,KC_W    ,KC_B    ,KC_LBRC ,                          KC_RBRC ,KC_J    ,KC_F    ,KC_U    ,KC_P    ,KC_SCLN ,KC_EQL  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_BMSL ,KC_A    ,KC_S    ,KC_H    ,KC_T    ,KC_G    ,KC_DLSL ,                          KC_BSSL ,KC_Y    ,KC_N    ,KC_E    ,KC_O    ,KC_I    ,KC_QUOT ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     DEAD_LS ,KC_Z    ,KC_X    ,KC_M    ,KC_C    ,KC_V    ,KC_PUSL ,KC_PDSL ,        KC_TBSL ,KC_UNSL ,KC_K    ,KC_L    ,KC_COMM ,KC_DOT  ,KC_SLSH ,KC_BSLS ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     TD_HE   ,DEAD_SG ,DEAD_LG ,DEAD_LA ,     KC_LASP ,    DEAD_LC ,KC_ENT  ,        KC_ENT  ,OS_SYMB ,    KC_RASP ,     KC_UP   ,KC_DOWN ,KC_LEFT ,KC_RGHT
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
),

  [_SYMB] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     _______ ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5   ,                                            KC_F6   ,KC_F7   ,KC_F8   ,KC_F9   ,KC_F10  ,KC_F11  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,KC_PIPE ,KC_HOME ,                          KC_PGUP ,KC_PSLS ,KC_P7   ,KC_P8   ,KC_P9   ,KC_PMNS ,KC_F12  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     KC_CAPS ,KC_HASH ,KC_DLR  ,KC_LBRC ,KC_RBRC ,KC_GRV  ,KC_END  ,                          KC_PGDN ,KC_PAST ,KC_P4   ,KC_P5   ,KC_P6   ,KC_PPLS ,KC_TAB  ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     _______ ,KC_PAST ,KC_CIRC ,KC_LPRN ,KC_RPRN ,KC_TILD ,_______ ,_______ ,        _______ ,_______ ,XXXXXXX ,KC_P1   ,KC_P2   ,KC_P3   ,KC_PENT ,KC_NLCK ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     _______ ,_______ ,_______ ,_______ ,     KC_ESC  ,    _______ ,_______ ,        _______ ,_______ ,    KC_P0   ,     KC_P0   ,KC_PDOT ,KC_PENT ,KC_PSCR
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
),

  [_MOUSE] = LAYOUT(
  //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
     XXXXXXX ,_______ ,_______ ,_______ ,_______ ,_______ ,                                            _______ ,_______ ,_______ ,_______ ,_______ ,KC_MUTE ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_LCTL ,KC_MS_U ,XXXXXXX ,KC_WH_U ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,XXXXXXX ,KC_UP   ,XXXXXXX ,KC_VOLD ,KC_VOLU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,KC_MS_L ,KC_MS_D ,KC_MS_R ,KC_WH_D ,XXXXXXX ,_______ ,                          _______ ,XXXXXXX ,KC_LEFT ,KC_DOWN ,KC_RGHT ,KC_BRID ,KC_BRIU ,
  //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,_______ ,_______ ,        _______ ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,XXXXXXX ,
  //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
     XXXXXXX ,XXXXXXX, XXXXXXX ,KC_BTN3 ,     KC_BTN1 ,    KC_BTN2 ,XXXXXXX ,        _______ ,_______ ,    XXXXXXX ,     XXXXXXX ,XXXXXXX ,XXXXXXX ,RESET
  //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
)

};  // clang-format on
