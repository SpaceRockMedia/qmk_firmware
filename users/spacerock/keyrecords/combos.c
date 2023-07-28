
#include QMK_KEYBOARD_H

#include "spacerock.h"

const uint16_t PROGMEM cb_bspc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cb_del[] = {KC_E, KC_R, COMBO_END};
combo_t key_combos[] = {
    [CB_BSPC] = COMBO(cb_bspc, KC_BSPC),
    [CB_DEL] = COMBO(cb_del, KC_DEL), // keycodes with modifiers are possible too!
};
