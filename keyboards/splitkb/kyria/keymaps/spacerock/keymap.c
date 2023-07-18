/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
// #include QMK_KEYBOARD_H
#include "spacerock.h"



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
    KC_TAB,  _______________COLEMAK_L_TOP_______________,                                       _______________COLEMAK_R_TOP_______________, LY_GAME,
    CTL_ESC,  _______________COLEMAK_L_MID_______________,                                       _______________COLEMAK_R_MID_______________,
    KC_LCTL, _______________COLEMAK_L_BOT_______________,   KHYP,    KC_LGUI,  KC_RGUI, KMEH,   _______________COLEMAK_R_BOT_______________, KC_VOLD,
                                 _______, _____________MOD_LEFT_____________,  _____________MOD_RIGHT____________, _______
    ),

    [_GAME] = LAYOUT_wrapper(
     KC_TAB,  _______________QUERTY__L_TOP_______________,                                       _______________QUERTY__R_TOP_______________, LY_COLE,
     CTL_ESC,  _______________QUERTY__L_MID_______________,                                       _______________QUERTY__R_MID_______________,
     KC_LCTL, _______________QUERTY__L_BOT_______________,   KHYP,   KC_LGUI,  KC_MPLY, KMEH,    _______________QUERTY__R_BOT_______________, KC_VOLD,
                                 _______, _____________MOD_LEFT_____________,  _____________MOD_RIGHT____________, _______
    ),

    [_NAV] = LAYOUT(
      _______, KC_PGUP, H_LEFT,  KC_UP,   H_RIGHT, H_UP,                                         _______, _______, _______, _______,  _______, _______,
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, H_DOWN,                                      _______, KC_LALT, KC_LGUI, KC_LCTL,  _______, _______,
      _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   _______,  _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12, _______,
                                _______, _______,  LY_DEF,  CW_TOGG, _______,  _______, _______, LY_SYM,  _______, _______
    ),

    [_SYM] = LAYOUT(
      DM_REC1, DM_REC2, _______, _______, _______, _______,                                      KC_SLSH, KC_7,    KC_8,    KC_9, KC_MINS, _______,
      DM_PLY1, DM_PLY2, KC_LCTL, KC_LGUI, KC_LALT, _______,                                      KC_ASTR, KC_4,    KC_5,    KC_6, KC_PLUS, _______,
      DM_RSTP, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_0,    KC_1,    KC_2,    KC_3, KC_DOT, _______,
                                 _______, _______, LY_DEF,  KC_UNDS, _______,  _______, _______, LY_ADJ,  _______, _______
    ),

    [_ADJUST] = LAYOUT(
      _______, _______, _______,  _______, _______, _______,                                     _______, _______, _______, _______,  _______, _______,
      RGB_TOG, RGB_MOD, RGB_SPI,  RGB_HUI, RGB_SAI, RGB_VAI,                                     _______, _______, _______, _______,  _______, _______,
      _______, RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,
                                  _______, _______, LY_DEF,  _______, _______,  _______, _______, LY_DEF,  _______, _______
    ),

// /*
//  * Layer template
//  *aa
//  *, -------------------------------------------.,                              -------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.,  -------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT(
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______, _______,
//       _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
//                                  _______, _______, LY_DEF,  _______, _______, _______, _______, _______, _______, _______
//     ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_WH_D,  KC_WH_U),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_GAME] =    { ENCODER_CCW_CW(KC_WH_D,  KC_WH_U),   ENCODER_CCW_CW(KC_VOLU, KC_VOLD) },
    [_NAV] =     { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),   ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_SYM] =     { ENCODER_CCW_CW(RGB_HUI,  RGB_HUD),   ENCODER_CCW_CW(RGB_VAI, RGB_SAI) },
    [_ADJUST] =  { ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
};
#endif

//
// TAP dance
//

// Determine the current tap dance state
td_state_t cur_dance(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (!state->pressed) return TD_SINGLE_TAP;
        else return TD_SINGLE_HOLD;
    } else if (state->count == 2) return TD_DOUBLE_TAP;
    else return TD_UNKNOWN;
}

// Initialize tap structure associated with example tap dance key
static td_tap_t ql_tap_state = {
    .is_press_action = true,
    .state = TD_NONE
};

// Functions that control what our tap dance key does
void HYP_NAV_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_NAV)) {
                // If already set, then switch it off
                layer_off(_NAV);
            } else {
                // If not already set, then switch the layer on
                layer_on(_NAV);
            }
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_HYPR);
            break;
        default:
            break;
    }
}

void HYP_NAV_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        unregister_code16(_NAV);
    }
    ql_tap_state.state = TD_NONE;
}

// Functions that control what our tap dance key does
void MEH_SYM_finished(tap_dance_state_t *state, void *user_data) {
    ql_tap_state.state = cur_dance(state);
    switch (ql_tap_state.state) {
        case TD_SINGLE_TAP:
            // Check to see if the layer is already set
            if (layer_state_is(_SYM)) {
                // If already set, then switch it off
                layer_off(_SYM);
            } else {
                // If not already set, then switch the layer on
                layer_on(_SYM);
            }
            break;
        case TD_SINGLE_HOLD:
            register_code16(KC_MEH);
            break;
        default:
            break;
    }
}

void MEH_SYM_reset(tap_dance_state_t *state, void *user_data) {
    // If the key was held down and now is released then switch off the layer
    if (ql_tap_state.state == TD_SINGLE_HOLD) {
        unregister_code16(KC_MEH);
    }
    ql_tap_state.state = TD_NONE;
}

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [HYP_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, HYP_NAV_finished, HYP_NAV_reset),
    [MEH_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, MEH_SYM_finished, MEH_SYM_reset)
};

// Set a long-ish tapping term for tap-dance keys
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QK_TAP_DANCE ... QK_TAP_DANCE_MAX:
            return 275;
        default:
            return TAPPING_TERM;
    }
}
