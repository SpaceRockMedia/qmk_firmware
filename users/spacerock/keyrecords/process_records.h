// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include "spacerock.h"

typedef enum userspace_custom_keycodes {
    CTALDEL = QK_USER,
    CTALESC,
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
    LY_DEF,
    LY_GAME,
    LY_COLE,
} CUSTOM_KEYCODES_T;

bool process_record_secrets(uint16_t keycode, keyrecord_t *record);
bool process_record_keymap(uint16_t keycode, keyrecord_t *record);
void post_process_record_keymap(uint16_t keycode, keyrecord_t *record);

#define xxxxxxx KC_NO
#define _______ KC_TRNS

//
// Layers
//
#define LY_NAV MO(_NAV)
#define LY_SYM TO(_SYM)
#define LY_ADJ TO(_ADJUST)

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

#define KHYP HYPR_T(KC_LPRN)
#define KMEH MEH_T(KC_RPRN)
#define H_UP HYPR_T(KC_UP)
#define H_DOWN HYPR_T(KC_DOWN)
#define H_LEFT HYPR_T(KC_LEFT)
#define H_RIGHT HYPR_T(KC_RGHT)


// (For OS X, you'll want to change these editing keys to LGUI(KC_Z) etc.)

//
// Some windows shortcuts
//

// Everything
#define CTALDEL LCTL(LALT(KC_DEL))
// Task Manager
#define CTALESC LCTL(LALT(KC_ESC))
#define CTL_ESC CTL_T(KC_ESC)

//
// COMBOS
//
enum combo_keycodes {
    CB_BSPC = 0,
    CB_DEL,

    COMBO_LENGTH,
};
#undef COMBO_LEN
// uint16_t COMBO_LEN = COMBO_LENGTH;
combo_t key_combos[COMBO_LENGTH];
