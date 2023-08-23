#include QMK_KEYBOARD_H
#include "features/leader.h"

#ifdef AUDIO_ENABLE
float leader_start_song[][2] = SONG(ONE_UP_SOUND);
float leader_succeed_song[][2] = SONG(ALL_STAR);
float leader_fail_song[][2] = SONG(RICK_ROLL);
#endif

__attribute__((weak))
bool leader_start_keymap(void) {
    return true;
}

void leader_start_user(void) {
    #ifdef AUDIO_ENABLE
        PLAY_SONG(leader_start_song);
    #endif
    // Do something when the leader key is pressed

    leader_start_keymap();
}

__attribute__((weak))
bool leader_end_keymap(void) {
    return true;
}

void leader_end_user(void) {
    bool did_leader_succeed = false;

    if (leader_sequence_one_key(KC_F)) {
        // Leader, f => Types the below string
        SEND_STRING("QMK is awesome.");
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(KC_D, KC_D)) {
        // Leader, d, d => Ctrl+A, Ctrl+C
        SEND_STRING(SS_LCTL("a") SS_LCTL("c"));
        did_leader_succeed = true;
    } else if (leader_sequence_three_keys(KC_D, KC_D, KC_S)) {
        // Leader, d, d, s => Types the below string
        SEND_STRING("https://start.duckduckgo.com\n");
        did_leader_succeed = true;
    } else if (leader_sequence_two_keys(KC_A, KC_S)) {
        // Leader, a, s => GUI+S
        tap_code16(LGUI(KC_S));
        did_leader_succeed = true;
    }

    leader_end_keymap();

    #ifdef AUDIO_ENABLE
        if (did_leader_succeed) {
            PLAY_SONG(leader_succeed_song);
        } else {
            PLAY_SONG(leader_fail_song);
        }
    #endif
}
