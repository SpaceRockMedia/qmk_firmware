// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define TAPPING_TERM 350
#define BILATERAL_COMBINATIONS

/* Miryoku */
// https://github.com/manna-harbour/qmk_firmware/pull/56
#define BILATERAL_COMBINATIONS_LIMIT_CHORD_TO_N_KEYS 4 /* GUI, Alt, Ctrl, Shift */
#define BILATERAL_COMBINATIONS_DELAY_MODS_THAT_MATCH MOD_MASK_GUI
#define BILATERAL_COMBINATIONS_DELAY_MATCHED_MODS_BY 100  /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_CROSSOVER_AFTER 80   /* ms */
#define BILATERAL_COMBINATIONS_ALLOW_SAMESIDED_AFTER 500 /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_TIMEOUT 175  /* ms */
#define BILATERAL_COMBINATIONS_TYPING_STREAK_MODMASK (~MOD_MASK_SHIFT)
// #define TAPPING_TERM_PER_KEY

// https://docs.qmk.fm/#/tap_hold?id=tap-or-hold-decision-modes
// The PERMISSIVE_HOLD option is not noticeable if you also enable
// HOLD_ON_OTHER_KEY_PRESS because the latter option considers both the “nested
// tap” and “rolling press” sequences like shown above as a hold action, not the
// tap action. HOLD_ON_OTHER_KEY_PRESS makes the Tap-Or-Hold decision earlier in
// the chain of key events, thus taking a precedence over PERMISSIVE_HOLD.
// define PERMISSIVE_HOLD
// define PERMISSIVE_HOLD_PER_KEY

// https://docs.qmk.fm/#/tap_hold?id=hold-on-other-key-press
// #define HOLD_ON_OTHER_KEY_PRESS
// #define HOLD_ON_OTHER_KEY_PRESS_PER_KEY

// #ifndef TAPPING_TOGGLE
// #    define TAPPING_TOGGLE 1
// #endif

// #define TAP_CODE_DELAY 5

// #define RETRO_TAPPING
// #define RETRO_TAPPING_PER_KEY
