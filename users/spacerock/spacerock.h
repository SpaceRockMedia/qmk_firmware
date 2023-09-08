// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#ifdef OS_DETECTION_ENABLE
#    include "os_detection.h"
#endif

#include "keyrecords/wrappers.h"
#include "keyrecords/process_records.h"
#include "callbacks/callbacks.h"
#include "features/features.h"

typedef enum userspace_layers {
    _COLEMAK = 0,
    _GAME,
    _NAV,
    _MEDIA,
    _ADJUST,
} CUSTOM_LAYERS_T;
