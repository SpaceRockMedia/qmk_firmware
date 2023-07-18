// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#include "eeprom.h"
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

// Enabling this option changes the startup behavior to listen for an
// active USB communication to delegate which part is master and which
// is slave. With this option enabled and theres's USB communication,
// then that half assumes it is the master, otherwise it assumes it
// is the slave.
//
// I've found this helps with some ProMicros where the slave does not boot
#define SPLIT_USB_DETECT
#define SPLIT_LAYER_STATE_ENABLE

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

// enum layers {
typedef enum userspace_layers {
    _COLEMAK = 0,
    _GAME,
    _NAV,
    _SYM,
    _ADJUST,
} CUSTOM_LAYERS_T;


