

#include QMK_KEYBOARD_H
#include "spacerock.h"
#include "features/caps_word/process_records.h"

bool process_record_features_caps_word(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_SPACE:
            if (record->event.pressed) {
                if (is_caps_word_on()) {
                    register_code16(KC_UNDS);
                }
            } else {
                if (is_caps_word_on()) {
                    unregister_code16(KC_UNDS);
                }
            }
            return true;
        default:
            return true;

    }
    return true;
}
