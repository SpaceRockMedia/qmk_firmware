#include QMK_KEYBOARD_H
#include "spacerockmedia.h"
#include "features/callum/process_records.h"
#include "features/callum/callum.h"
#include "features/callum/swapper.h"
#include "os_detection.h"

bool sw_win_active = false;
bool sw_lang_active = false;
oneshot_state os_shft_state = os_up_unqueued;
oneshot_state os_ctrl_state = os_up_unqueued;
oneshot_state os_alt_state = os_up_unqueued;
oneshot_state os_cmd_state = os_up_unqueued;

bool process_record_features_callum(uint16_t keycode, keyrecord_t *record) {

    switch (detected_host_os()) {
        case OS_MACOS:
            //
            // Callum's Swapper
            update_swapper(
                &sw_win_active, KC_LGUI, KC_TAB, SW_WIN,
                keycode, record
            );

            break;
        default:
            //
            // Callum's Swapper
            update_swapper(
                &sw_win_active, KC_LALT, KC_TAB, SW_WIN,
                keycode, record
            );
            break;
    }

    return true;
}
