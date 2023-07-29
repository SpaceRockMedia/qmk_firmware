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

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

// clang-format on

// ┌───────────────────────────────────────────────────────────┐
// │ d e f i n e   l a y e r s                                 │
// └───────────────────────────────────────────────────────────┘

typedef enum userspace_layers {
    _COLEMAK = 0,
    _GAME,
    _NAV,
    _SYM,
    _FUNC,
    _ADJUST,
} CUSTOM_LAYERS_T;


