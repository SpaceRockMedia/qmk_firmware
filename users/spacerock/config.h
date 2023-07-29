// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Use custom magic number so that when switching branches, EEPROM always gets reset
// #define EECONFIG_MAGIC_NUMBER (uint16_t)0x1339

// Will probably only have 16 or less layers.
// #define LAYER_STATE_16BIT

#if defined(SPLIT_KEYBOARD)
#    include "split/split_config.h"
#endif

#if defined(COMBO_ENABLE)
#    include "combos/combos_config.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "rgb/rgb_matrix_config.h"
#endif // RGB_MATRIX_ENABLE

#ifdef OLED_ENABLE
#    include "oled/oled_config.h"
#endif

#ifdef AUDIO_ENABLE
#    include "audio_config.h"
#endif // AUDIO_ENABLE

#if defined(WPM_ENABLE)
// #    define WPM_LAUNCH_CONTROL
// #    define WPM_UNFILTERED
#    define WPM_ALLOW_COUNT_REGRESSION
#    define WPM_SAMPLE_SECONDS 10
#    define WPM_SAMPLE_PERIODS 50
#    define WPM_ESTIMATED_WORD_SIZE 5
#endif

#if defined(TAP_DANCE_ENABLE)
#    define PERMISSIVE_HOLD_PER_KEY
#    define QUICK_TAP_TERM_PER_KEY
#    define HOLD_ON_OTHER_KEY
#    define RETRO_TAPPING_PER_KEY
#    define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#    define TAPPING_TERM_PER_KEY
     // Lets you roll mod-tap keys
#    define TAPPING_TERM 225
#else
#    undef PERMISSIVE_HOLD
#endif

#ifndef TAPPING_TOGGLE
#    define TAPPING_TOGGLE 1
#endif

#define TAP_CODE_DELAY 5

#define ENABLE_COMPILE_KEYCODE

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
