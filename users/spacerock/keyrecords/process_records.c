
#include "spacerock.h"
#include "version.h"
#include "features/callum.h"
#include "features/swapper.h"
#include "os_detection.h"

#ifdef SENTENCE_CASE_ENABLE
    #include "features/sentence_case.h"
#endif

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

#ifdef CALLUM_ENABLE
    bool sw_win_active = false;
    bool sw_lang_active = false;

    oneshot_state os_shft_state = os_up_unqueued;
    oneshot_state os_ctrl_state = os_up_unqueued;
    oneshot_state os_alt_state = os_up_unqueued;
    oneshot_state os_cmd_state = os_up_unqueued;
#endif

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
// ┌───────────────────────────────────────────────────────────┐
// │ f e a t u r e s                                           │
// └───────────────────────────────────────────────────────────┘

    #ifdef CALLUM_ENABLE
        switch (detected_host_os()) {
            case OS_MACOS:
                update_swapper(
                    &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
                    keycode, record
                );
                break;
            default:
                update_swapper(
                    &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
                    keycode, record
                );
                break;
        }

        // update_swapper(
        //     &sw_lang_active, KC_LCTL, KC_SPC, SW_LANG,
        //     keycode, record
        // );

        update_oneshot(
            &os_shft_state, KC_LSFT, OS_SHFT,
            keycode, record
        );
        update_oneshot(
            &os_ctrl_state, KC_LCTL, OS_CTRL,
            keycode, record
        );
        update_oneshot(
            &os_alt_state, KC_LALT, OS_ALT,
            keycode, record
        );
        update_oneshot(
            &os_cmd_state, KC_LCMD, OS_CMD,
            keycode, record
        );
    #endif

    #ifdef SENTENCE_CASE_ENABLE
        if (!process_sentence_case(keycode, record)) { return false; }
    #endif

    // if (get_highest_layer(layer_state | default_layer_state) == _NAV) {
    //     switch (keycode) {
    //         case KC_PGUP:
    //         case KC_PGDN:
    //         case KC_LEFT:
    //         case KC_RIGHT:
    //         case KC_DOWN:
    //         case KC_UP:
    //         case M_LEFT:
    //         case M_RIGHT:
    //         case M_DOWN:
    //         case M_UP:
    //             return true;

    //         case LY_DEF:
    //         case TG_DEF:
    //         case KC_TRNS:
    //         default:
    //             layer_off(_NAV);
    //             return true;
    //     }
    // }

    switch (keycode) {

// ┌───────────────────────────────────────────────────────────┐
// │ l a y e r                                                 │
// └───────────────────────────────────────────────────────────┘
        case TG_DEF:
            if (record->event.pressed) {
                layer_clear();
                if (IS_LAYER_ON(_GAME)) {
                    set_single_persistent_default_layer(_COLEMAK);
                    layer_move(_COLEMAK);
                } else {
                    set_single_persistent_default_layer(_GAME);
                    layer_move(_GAME);
                }
                #ifdef HAPTIC_ENABLE
                  DRV_pulse(transition_hum);
                #endif // HAPTIC_ENABLE
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
            return false;

// ┌───────────────────────────────────────────────────────────┐
// │ o s  s h o r t c u t                                      │
// └───────────────────────────────────────────────────────────┘

        case OS_COPY:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("c"));
                } else {
                    SEND_STRING(SS_LCTL("c"));
                }
            }
            return true;

        case OS_CUT:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("x"));
                } else {
                    SEND_STRING(SS_LCTL("x"));
                }
            }
            return true;

        case OS_PASTE:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("v"));
                } else {
                    SEND_STRING(SS_LCTL("v"));
                }
            }
            return true;

        case OS_UNDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("z"));
                } else {
                    SEND_STRING(SS_LCTL("z"));
                }
            }
            return true;

        case OS_REDO:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD(SS_LSFT("z")));
                } else {
                    SEND_STRING(SS_LCTL(SS_LSFT("z")));
                }
            }
            return true;

        case OS_SAVE:
            if (record->event.pressed) {
                if (detected_host_os() == OS_MACOS) {
                    SEND_STRING(SS_LCMD("s"));
                } else {
                    SEND_STRING(SS_LCTL("s"));
                }
            }
            return true;


// ┌───────────────────────────────────────────────────────────┐
// │ c o d i n g                                               │
// └───────────────────────────────────────────────────────────┘

        case LALT(KC_W):
        case MEH_T(KC_W):
            if (record->event.pressed) {
                set_oneshot_layer(_NAV, ONESHOT_START);
            } else {
                clear_oneshot_layer_state(ONESHOT_PRESSED);
            }
            return true;

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
