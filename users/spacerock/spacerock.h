// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#include "eeprom.h"

// ┌───────────────────────────────────────────────────────────┐
// │ l o a d   c o n f i g s                                   │
// └───────────────────────────────────────────────────────────┘

#include "keyrecords/wrappers.h"
#include "keyrecords/process_records.h"
#include "callbacks.h"

#ifdef TAP_DANCE_ENABLE
#    include "keyrecords/tap_dances.h"
#endif // TAP_DANCE_ENABLE

#if defined(RGB_MATRIX_ENABLE)
#    include "rgb/rgb_matrix_stuff.h"
#endif

#if defined(OLED_ENABLE)
#    include "oled/oled_stuff.h"
#endif

#ifdef SPLIT_KEYBOARD
#    include "split/transport_sync.h"
#endif

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

typedef union {
    uint32_t raw;
    struct {
        bool     rgb_layer_change     :1;
        bool     is_overwatch         :1;
        bool     nuke_switch          :1;
        bool     swapped_numbers      :1;
        bool     rgb_matrix_idle_anim :1;
        bool     mouse_jiggler        :1;
        uint8_t  align_reserved       :2;
        uint8_t  oled_brightness      :8;
        uint32_t reserved             :15;
        bool     check                :1;
    };
} userspace_config_t;
// clang-format on

_Static_assert(sizeof(userspace_config_t) == sizeof(uint32_t), "Userspace EECONFIG out of spec.");

extern userspace_config_t userspace_config;

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

typedef enum userspace_layers {
    _COLEMAK = 0,
    _GAME,
    _NAV,
    _SYM,
    _ADJUST,
} CUSTOM_LAYERS_T;


