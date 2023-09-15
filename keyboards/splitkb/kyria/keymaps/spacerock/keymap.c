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

#define __________UPPER__THUMB__________ KC_MEH, KC_HYPR, KC_HYPR, KC_MEH

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
      __LPT__, _______________COLEMAK_L_TOP_______________,                                   _______________COLEMAK_R_TOP_______________, __RPT__,
      __LPM__, _______________COLEMAK_L_MID_GASC__________,                                   _______________COLEMAK_R_MID_CSAG__________, __RPM__,
      __LPB__, _______________COLEMAK_L_BOT_______________, __________UPPER__THUMB__________, _______________COLEMAK_R_BOT_______________, __RPB__,
                                 QK_LEAD, ____________THUMB_LEFT____________, ____________THUMB_RIGHT___________, QK_LEAD
    ),

    [_GAME] = LAYOUT_wrapper(
      __LPT__, _______________QUERTY__L_TOP_______________,                                   _______________QUERTY__R_TOP_______________, __RPT__,
      __LPM__, _______________QUERTY__L_MID_GASC__________,                                   _______________QUERTY__R_MID_CSAG__________, __RPM__,
      __LPB__, _______________QUERTY__L_BOT_______________, __________UPPER__THUMB__________, _______________QUERTY__R_BOT_______________, __RPB__,
                                 QK_LEAD, ____________THUMB_LEFT____________, ____________THUMB_RIGHT___________, QK_LEAD
    ),

    [_NAV] = LAYOUT_wrapper(
      SH_TOGG, __________________NAV__LT__________________,                                      KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS, SH_TOGG,
      _______, __________________NAV__LM__________________,                                      KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
      SNAP1,   SNAP2,   _______, _______, _______, _______, _______, _______,  _______, _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                 _______, _______, LY_DEF, KC_UNDS, _______,   _______, _______, LY_DEF,   _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
      _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,                                      _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
      TG_DEF, RGB_TOG, xxxxxxx, xxxxxxx, xxxxxxx, OS_SWAP,                                      HF_TOGG, xxxxxxx, xxxxxxx, xxxxxxx, KC_MPLY, xxxxxxx,
      QK_BOOT, __________________RGB_INC__________________,                                     DB_TOGG, xxxxxxx, KC_MPRV, KC_MNXT, KC_VOLU, xxxxxxx,
      MAKE_H,  __________________RGB_DEC__________________, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, AU_TOGG, xxxxxxx, xxxxxxx, xxxxxxx, KC_VOLD, KC_MUTE,
                                 xxxxxxx, xxxxxxx, LY_DEF,  xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, LY_DEF,  xxxxxxx, xxxxxxx
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

// #if defined(ENCODER_MAP_ENABLE)
// const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
//     [_COLEMAK] = { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_GAME] =    { ENCODER_CCW_CW(KC_WH_U,  KC_WH_D),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_NAV] =     { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),   ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
//     [_SYM] =     { ENCODER_CCW_CW(RGB_HUI,  RGB_HUD),   ENCODER_CCW_CW(RGB_VAI, RGB_SAI) },
//     [_MEDIA] =   { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
//     [_ADJUST] =  { ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
// };
// #endif
