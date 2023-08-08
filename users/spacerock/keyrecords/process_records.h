// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerock.h"

typedef enum userspace_custom_keycodes {
    LY_DEF = QK_USER,
    TG_DEF,
    LY_COLE,
    LY_GAME,
    OS_SHFT,
    OS_CTRL,
    OS_ALT,
    OS_CMD,
    SW_WIN,
    CTALDEL,
    SEARCH,
    OPN,
    MY_COPY,
    MY_CUT,
    MY_PAST,
    MY_UNDO,
    MY_REDO,
    MY_SAVE,
    CAPWORD,
    KC_TOGG,
    KC_QWER,
    KC_COLE,
    OS_SWAP,
    SNAP1,
    SNAP2,
    MAKE_H,
} CUSTOM_KEYCODES_T;

#define xxxxxxx KC_NO
#define _______ KC_TRNS

//
// Layers
//
#define LY_NAV TT(_NAV)
#define LY_SYM TT(_SYM)
#define LY_ADJ TO(_ADJUST)
#define LY_FUN TO(_FUNC)

//
// One Shot Mods
//
#define ALT_GR OSM(MOD_RALT)
#define O_LSFT OSM(MOD_LSFT)
#define O_RSFT OSM(MOD_RSFT)

//
// Abbreviations
//
#define PPLAY KC_MEDIA_PLAY_PAUSE

#define UNDO LCTL(KC_Z)
#define CUT  LCTL(KC_X)
#define COPY LCTL(KC_C)
#define PASTE LCTL(KC_V)
#define REDO LCTL(KC_Y)

#define KHYP MOD_HYPR
#define KMEH MOD_MEH
#define M_UP MEH(KC_UP)
#define M_DOWN MEH(KC_DOWN)
#define M_LEFT MEH(KC_LEFT)
#define M_RIGHT MEH(KC_RGHT)
#define M_PGUP MEH(KC_PGUP)
#define M_PGDN MEH(KC_PGDN)

#define MT_PGUP MT(KC_PGUP, KC_PGDN)


// (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)

//
// Some windows shortcuts
//

// Everything
#define CTALDEL HYPR_T(KC_SPACE)
// Task Manager
#define CTALESC LCTL(LALT(KC_ESC))
#define CTL_ESC CTL_T(KC_ESC)
