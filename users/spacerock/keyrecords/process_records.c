
#include "spacerock.h"
#include "version.h"
#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

/**
 * @brief Keycode handler for keymaps
 *
 * This handles the keycodes at the keymap level, useful for keyboard specific customization
 */
__attribute__((weak)) bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    return true;
}
__attribute__((weak)) bool process_record_secrets(uint16_t keycode, keyrecord_t *record) {
    return true;
}

/**
 * @brief Main user keycode handler
 *
 * This handles all of the keycodes for the user, including calling feature handlers.
 *
 * @param keycode Keycode from matrix
 * @param record keyrecord_t data structure
 * @return true Continue processing keycode and send to host
 * @return false Stop process keycode and do not send to host
 */
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LY_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
                layer_move(_GAME);
            }
            return false;
        case LY_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                layer_move(_COLEMAK);
            }
            return false;
        case LY_DEF:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_GAME)) {
                    layer_clear();
                    // layer_move(_GAME);
                } else {
                    layer_clear();
                    // layer_move(_COLEMAK);
                }
            }
    }
    return true;
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}


const uint16_t PROGMEM cb_bspc[] = {KC_W, KC_E, COMBO_END};
const uint16_t PROGMEM cb_del[] = {KC_E, KC_R, COMBO_END};
combo_t key_combos[] = {
    [CB_BSPC] = COMBO(cb_bspc, KC_BSPC),
    [CB_DEL] = COMBO(cb_del, KC_DEL), // keycodes with modifiers are possible too!
};
