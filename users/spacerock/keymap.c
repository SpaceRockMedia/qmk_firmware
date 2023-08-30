#line 7 "keyrecords/process_records.h"
typedef enum userspace_custom_keycodes {
    LY_DEF = QK_USER,
    TG_DEF,
    LY_COLE,
    LY_GAME,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    SW_WIN,
    CTALDEL,
    SEARCH,
    OPN,
    MY_COPY,
    MY_CUT,
    MY_PAST,
    MY_UNDO,
    MY_REDO,
    MY_SAVE,
    CAPWORD,
    KC_TOGG,
    KC_QWER,
    KC_COLE,
    OS_SWAP,
    SNAP1,
    SNAP2,
    MAKE_H,
} CUSTOM_KEYCODES_T;
#line 6 "callbacks.h"
#include "quantum.h"

layer_state_t layer_state_set_keymap(layer_state_t state);
layer_state_t default_layer_state_set_keymap(layer_state_t state);
void          led_set_keymap(uint8_t usb_led);
#line 39 "spacerock.h"
typedef enum userspace_layers {
    _COLEMAK = 0,
    _GAME,
    _NAV,
    _FUNC,
    _MEDIA,
    _ADJUST,
} CUSTOM_LAYERS_T;
#line 18 "/mnt/c/Users/shawn/code/autoferrit/qmk_firmware/keyboards/splitkb/kyria/keymaps/spacerock/keymap.c"
#include "spacerock.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                                      KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_TRNS,
      CTL_T(KC_ESC), KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                                      KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT,
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V, QK_LEAD, KC_TRNS, KC_TRNS, QK_LEAD, KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                                 MOD_HYPR, KC_LGUI, TT(_SYM),        MEH_T(KC_SPC), SC_LSPO,  SC_RSPC, MEH_T(KC_ENT), TT(_NAV),        KC_RGUI, MOD_HYPR
    ),






    [_GAME] = LAYOUT(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_TRNS,
      CTL_T(KC_ESC), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT,
      KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B, QK_LEAD, KC_TRNS, KC_TRNS, QK_LEAD, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_LCTL,
                                 MOD_HYPR, KC_LGUI, TT(_SYM),        MEH_T(KC_SPC), SC_LSPO,    SC_RSPC, MEH_T(KC_ENT), TT(_NAV),        KC_RGUI, MOD_HYPR
    ),






    [_NAV] = LAYOUT(
      SH_TOGG, KC_PGUP, MEH(KC_LEFT),  KC_UP,   MEH(KC_RGHT), MEH(KC_UP),                                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, MEH(KC_DOWN),                                       KC_TRNS, OS_CMD, OS_ALT, OS_CTRL, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                                KC_TRNS, KC_TRNS,  LY_DEF,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(_FUNC),  KC_TRNS, KC_TRNS
    ),






    [_SYM] = LAYOUT(
      DM_REC1, DM_REC2, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                      KC_7,    KC_8,    KC_9, KC_MINS, KC_TRNS, SH_TOGG,
      DM_PLY1, DM_PLY2, OS_CMD, OS_ALT, OS_CTRL, KC_TRNS,                                      KC_4,    KC_5,    KC_6, KC_PLUS, KC_ASTR, KC_TRNS,
      DM_RSTP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_0,    KC_1,    KC_2,    KC_3, KC_DOT, KC_SLSH, KC_TRNS,
                                 KC_TRNS, KC_TRNS, LY_DEF,  KC_UNDS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(_FUNC),  KC_TRNS, KC_TRNS
    ),






    [_FUNC] = LAYOUT(
      SH_TOGG, KC_F1, KC_F2,  KC_F3,  KC_F4,  KC_TRNS,                                      KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_F5, KC_F6,  KC_F7,  KC_F8,  KC_TRNS,                                      KC_TRNS, OS_CMD, OS_ALT, OS_CTRL, KC_TRNS, KC_TRNS,
      KC_TRNS, KC_F9, KC_F10, KC_F11, KC_F12, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS,
                            KC_TRNS, KC_TRNS,  LY_DEF, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(_ADJUST),  KC_TRNS, KC_TRNS
    ),






    [_ADJUST] = LAYOUT(
      KC_TRNS, RGB_TOG,  KC_TRNS, KC_TRNS, KC_TRNS, OS_SWAP,                                      OS_SWAP, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, TG_DEF,
      QK_BOOT, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                                      KC_TRNS, OS_CMD, OS_ALT, OS_CTRL,  KC_TRNS, QK_BOOT,
      MAKE_H,  RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, AU_TOGG, DB_TOGG, HF_TOGG, KC_TRNS, KC_TRNS,  KC_TRNS,
                                  KC_TRNS, KC_TRNS, LY_DEF,  KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, TO(_SYM),  KC_TRNS, KC_TRNS
    ),
#line 83 "/mnt/c/Users/shawn/code/autoferrit/qmk_firmware/keyboards/splitkb/kyria/keymaps/spacerock/keymap.c"
};
