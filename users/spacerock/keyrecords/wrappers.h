// Copyright 2023 Shawn McElroy, aka Autoferrit  (@autoferrit)
// Copyright 2023 @autoferrit
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerock.h"
/*
Since our quirky block definitions are basically a list of comma separated
arguments, we need a wrapper in order for these definitions to be
expanded before being used as arguments to the LAYOUT_xxx macro.
*/

/*
Blocks for each of the four major keyboard layouts
Organized so we can quickly adapt and modify all of them
at once, rather than for each keyboard, one at a time.
And this allows for much cleaner blocks in the keymaps.
For instance Tap/Hold for Control on all of the layouts

NOTE: These are all the same length.  If you do a search/replace
  then you need to add/remove underscores to keep the
  lengths consistent.
*/

#define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)

// clang-format off
#define _______________COLEMAK_L_TOP_______________ KC_Q,    KC_W,    KC_F,    KC_P,    KC_B
#define _______________COLEMAK_L_MID_______________ KC_A,    KC_R,    KC_S,    KC_T,    KC_G
#define _______________COLEMAK_L_BOT_______________ KC_Z,    KC_X,    KC_C,    KC_D,    KC_V

#define _______________COLEMAK_R_TOP_______________ KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN
#define _______________COLEMAK_R_MID_______________ KC_M,    KC_N,    KC_E,    KC_I,    KC_O,  KC_QUOT
#define _______________COLEMAK_R_BOT_______________ KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH

#define _______________QUERTY__L_TOP_______________ KC_Q,    KC_W,    KC_E,    KC_R,    KC_T
#define _______________QUERTY__L_MID_______________ KC_A,    KC_S,    KC_D,    KC_F,    KC_G
#define _______________QUERTY__L_BOT_______________ KC_Z,    KC_X,    KC_C,    KC_V,    KC_B

#define _______________QUERTY__R_TOP_______________ KC_Y,    KC_U,    KC_I,    KC_O,    KC_P
#define _______________QUERTY__R_MID_______________ KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,  KC_QUOT
#define _______________QUERTY__R_BOT_______________ KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH

#define ____________THUMB_LEFT____________ KC_LGUI, LY_NAV,         LALT_T(KC_SPC), SC_LSPO
#define ____________THUMB_RIGHT___________ SC_RSPC, RALT_T(KC_ENT), LY_SYM,         KC_RGUI

#define __________________RGB_INC___________________ RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI
#define __________________RGB_DEC___________________ RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD
