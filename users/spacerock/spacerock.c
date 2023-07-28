// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerock.h"
#include <stdio.h>
#include <ctype.h>

const char *get_layer_name_string(layer_state_t state, bool alt_name) {
    switch (get_highest_layer(state)) {
        case _GAME:
            return alt_name ? "Num Pad" : "QWERTY";
        case _COLEMAK:
            return "Colemak";
        case _SYM:
            return "Symbol";
        case _NAV:
            return "Nav";
        case _FUNC:
            return "Func";
        case _ADJUST:
            return "Adjust";
        default:
            return "Unknown";
    }
}
