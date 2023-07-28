// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerock.h"
#include <stdio.h>
#include <ctype.h>

 userspace_config_t userspace_config;

#if defined(AUTOCORRECT_ENABLE)
#    if defined(AUDIO_ENABLE)
#        ifdef USER_SONG_LIST
float autocorrect_song[][2] = SONG(MARIO_GAMEOVER);
#        else
float autocorrect_song[][2] = SONG(PLOVER_GOODBYE_SOUND);
#        endif
#    endif

bool apply_autocorrect(uint8_t backspaces, const char *str) {
    if (layer_state_is(_GAMEPAD)) {
        return false;
    }
    // TO-DO use unicode stuff for this.  Will probably have to reverse engineer
    // send string to get working properly, to send char string.

#    if defined(AUDIO_ENABLE)
    PLAY_SONG(autocorrect_song);
#    endif
    return true;
}
#endif

const char *get_layer_name_string(layer_state_t state, bool alt_name) {
    switch (get_highest_layer(state)) {
        case _GAME:
            return alt_name ? "Num Pad" : "QWERTY";
        case _COLEMAK:
            return "Colemak-DH";
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
