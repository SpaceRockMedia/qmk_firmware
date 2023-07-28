// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerock.h"

#ifdef I2C_SCANNER_ENABLE
void housekeeping_task_i2c_scanner(void);
void keyboard_post_init_i2c(void);
#endif

__attribute__((weak)) void keyboard_pre_init_keymap(void) {}
void                       keyboard_pre_init_user(void) {
    eeconfig_read_user_config(&userspace_config.raw);
    if (!userspace_config.check) {
        eeconfig_init_user();
    }
    keyboard_pre_init_keymap();
}

__attribute__((weak)) void keyboard_post_init_keymap(void) {}
void                       keyboard_post_init_user(void) {
    #if defined(CUSTOM_RGB_MATRIX)
        keyboard_post_init_rgb_matrix();
    #endif

    #if defined(SPLIT_KEYBOARD) && defined(SPLIT_TRANSACTION_IDS_USER)
        keyboard_post_init_transport_sync();
    #endif

    #if HAPTIC_ENABLE
        haptic_disable(); // disables per key haptic feedback by default
    #endif //HAPTIC ENABLE

    #if RGB_MATRIX_ENABLE
        rgblight_enable_noeeprom();
        //rgblight_sethsv_noeeprom(35, 255, 255); // set default RGB color to yellow
    #endif //RGB_MATRIX_ENABLE

    keyboard_post_init_keymap();
}

__attribute__((weak)) void suspend_power_down_keymap(void) {}

void suspend_power_down_user(void) {
    if (layer_state_is(_GAME)) {
        layer_off(_GAME);
    }
    if (layer_state_is(_NAV)) {
        layer_off(_NAV);
    }
    if (layer_state_is(_SYM)) {
        layer_off(_SYM);
    }
    if (layer_state_is(_ADJUST)) {
        layer_off(_ADJUST);
    }
#ifdef OLED_ENABLE
    oled_off();
#endif
    rgb_matrix_set_suspend_state(true);
    suspend_power_down_keymap();
}

__attribute__((weak)) void suspend_wakeup_init_keymap(void) {}
void                       suspend_wakeup_init_user(void) {
    rgb_matrix_set_suspend_state(false);
    suspend_wakeup_init_keymap();
}
