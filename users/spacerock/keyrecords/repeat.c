// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerock.h"

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);  // Was Shift held?
    bool controlled = (mods & MOD_MASK_CTRL);  // Was Ctrl held?

    switch (keycode) {
        case KC_Y:
            if (controlled) {
                return C(KC_Z);
            }
        case KC_Z:
            if (controlled) {
                return C(KC_Y);
            }
        case KC_TAB:
            if (shifted) {        // If the last key was Shift + Tab,
                return KC_TAB;    // ... the reverse is Tab.
            } else {              // Otherwise, the last key was Tab,
                return S(KC_TAB); // ... and the reverse is Shift + Tab.
            }
    }

    return KC_TRNS;  // Defer to default definitions.
}
