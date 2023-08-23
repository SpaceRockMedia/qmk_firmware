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
#define KEYMAP_DISPLAY
#include "spacerock.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
      KC_TAB,  _______________COLEMAK_L_TOP_______________,                                     _______________COLEMAK_R_TOP_______________, LY_MED,
      CTL_ESC, _______________COLEMAK_L_MID_______________,                                     _______________COLEMAK_R_MID_______________,
      QK_LEAD, _______________COLEMAK_L_BOT_______________, QK_LEAD, _______, _______, QK_LEAD, _______________COLEMAK_R_BOT_______________, QK_LEAD,
                                 KC_HYPR, ____________THUMB_LEFT____________,  ____________THUMB_RIGHT___________, KC_HYPR
    ),

    [_GAME] = LAYOUT_wrapper(
      KC_TAB,  _______________QUERTY__L_TOP_______________,                                     _______________QUERTY__R_TOP_______________, LY_MED,
      CTL_ESC, _______________QUERTY__L_MID_______________,                                     _______________QUERTY__R_MID_______________, KC_QUOT,
      QK_LEAD, _______________QUERTY__L_BOT_______________, QK_LEAD, _______, _______, QK_LEAD, _______________QUERTY__R_BOT_______________, QK_LEAD,
                                 KC_HYPR, ____________THUMB_LEFT____________,    ____________THUMB_RIGHT___________, KC_HYPR
    ),

    [_NAV] = LAYOUT_wrapper(
      SH_TOGG, KC_PGUP, M_LEFT,  KC_UP,   M_RIGHT, M_UP,                                         _______, _______, _______, _______, _______, _______,
      _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, M_DOWN,                                       _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______,  _______,
                                _______, _______,  LY_DEF,  _______, _______,  _______, _______, LY_SYM,  _______, _______
    ),

    [_SYM] = LAYOUT_wrapper(
      DM_REC1, DM_REC2, _______, _______, _______, _______,                                      KC_ASTR, KC_7, KC_8, KC_9, KC_PLUS, SH_TOGG,
      DM_PLY1, DM_PLY2, _______, _______, _______, _______,                                      KC_SLSH, KC_4, KC_5, KC_6, KC_MINS, _______,
      DM_RSTP, _______, _______, _______, _______, _______, _______, _______,  _______, _______, KC_0,    KC_1, KC_2, KC_3, KC_DOT,  _______,
                                 _______, _______, LY_DEF,  KC_UNDS, _______,  _______, _______, LY_ADJ,  _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, KC_MPLY, _______,
      _______, _______, _______, _______, _______, _______,                                      _______, _______, KC_MPRV, KC_MNXT, KC_VOLU, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE,
                                 _______, _______,  LY_DEF, _______, _______,  _______, _______, _______, _______, KC_MUTE
    ),

    [_ADJUST] = LAYOUT_wrapper(
      _______, RGB_TOG,  _______, _______, _______, OS_SWAP,                                      OS_SWAP, _______, _______, _______,  _______, TG_DEF,
      QK_BOOT, __________________RGB_INC___________________,                                      _______, _______, _______, _______, _______, QK_BOOT,
      MAKE_H,  __________________RGB_DEC___________________, _______, _______,  _______, _______, AU_TOGG, DB_TOGG, HF_TOGG, _______, _______,  _______,
                                  _______, _______, LY_DEF,  _______, _______,  _______, _______, TO(_SYM),  _______, _______
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
    [_COLEMAK] = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAME] =    { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV] =     { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),   ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_SYM] =     { ENCODER_CCW_CW(RGB_HUI,  RGB_HUD),   ENCODER_CCW_CW(RGB_VAI, RGB_SAI) },
    [_MEDIA] =   { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_ADJUST] =  { ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
};
#endif
