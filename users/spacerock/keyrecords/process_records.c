
#include "spacerock.h"
#include "version.h"

#ifdef HAPTIC_ENABLE
#include "drivers/haptic/DRV2605L.h"
#endif //HAPTIC ENABLE

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

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘
        case LY_GAME:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_GAME);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
                layer_move(_GAME);
            }
            return false;
        case LY_COLE:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
                layer_move(_COLEMAK);
            }
            return false;
        case LY_DEF:
            if (record->event.pressed) {
                if (IS_LAYER_ON(_GAME)) {
                    layer_clear();
                    layer_move(_GAME);
                } else {
                    layer_clear();
                    layer_move(_COLEMAK);
                }
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
            }
            return false;
        // case LY_NAV:
        //     if (record->event.pressed) {
        //         layer_on(_NAV);
        //         // update_tri_layer(_NAV, _SYM, _ADJUST);
        //     } else {
        //         layer_off(_NAV);
        //         // update_tri_layer(_NAV, _SYM, _ADJUST);
        //     }
        //     return false;
        // case LY_SYM:
        //     if (record->event.pressed) {
        //         layer_on(_SYM);
        //         // update_tri_layer(_NAV, _SYM, _ADJUST);
        //     } else {
        //         layer_off(_SYM);
        //         // update_tri_layer(_NAV, _SYM, _ADJUST);
        //     }
        //     return false;
        // case LY_ADJ:
        //     if (record->event.pressed) {
        //         layer_on(_ADJUST);
        //     } else {
        //         layer_off(_ADJUST);
        //     }
        //     return false;

// ┌───────────────────────────────────────────────────────────┐
// │ q m k                                                     │
// └───────────────────────────────────────────────────────────┘

        case MAKE_H:
            if (record->event.pressed) {
                #ifdef KEYBOARD_klor_2040
                    SEND_STRING ("qmk compile -kb klor/2040 -km spacerock");
                    tap_code(KC_ENTER);
                #endif
                #ifdef KEYBOARD_splitkb_kyria_rev3
                    SEND_STRING ("qmk compile -kb splitkb/kyria/rev3 -km spacerock");
                    tap_code(KC_ENTER);
                #endif
                #ifdef KEYBOARD_splitkb_kyria_rev3
                    SEND_STRING ("qmk compile -kb hillside/52 -km spacerock");
                    tap_code(KC_ENTER);
                #endif
            }
            break;

// ┌───────────────────────────────────────────────────────────┐
// │ p r o d u c t i v i t y                                   │
// └───────────────────────────────────────────────────────────┘

        case OS_SWAP:
            if (record->event.pressed) {
                if (!keymap_config.swap_lctl_lgui) {
                  keymap_config.swap_lctl_lgui = true;  // ─── MAC
                //   #ifdef AUDIO_ENABLE
                //     PLAY_SONG(mac_song);
                //   #endif // AUDIO_ENABLE
                }
                else {
                  keymap_config.swap_lctl_lgui = false; // ─── WIN
                //   #ifdef AUDIO_ENABLE
                //     PLAY_SONG(winxp_song);
                //   #endif // AUDIO_ENABLE
                }
              #ifdef HAPTIC_ENABLE
                DRV_pulse(pulsing_strong);
              #endif // HAPTIC_ENABLE
            eeconfig_update_keymap(keymap_config.raw);
            clear_keyboard();  // ──── clear to prevent stuck keys
            return false;
        }

        case SNAP1:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    SEND_STRING(SS_LSFT(SS_LCMD("4")));           //MAC
                } else {
                    SEND_STRING(SS_LWIN(SS_TAP(X_PSCR)));         //WIN
                }
            }
            break;

        case SNAP2:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                SEND_STRING(SS_LSFT(SS_LCMD(SS_LCTL("4"))));  //MAC
                } else {
                SEND_STRING(SS_LSFT(SS_LWIN("S")));           //WIN
                }
            }
            break;

        case KC_MPLY:
            if (record->event.pressed) {
            #ifdef HAPTIC_ENABLE
                    DRV_pulse(sharp_click);
            #endif // HAPTIC_ENABL
            }
            break;
    }

    return true;
}

__attribute__((weak)) void post_process_record_keymap(uint16_t keycode, keyrecord_t *record) {}
void                       post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    post_process_record_keymap(keycode, record);
}
