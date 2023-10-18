/* Copyright 2021 @Ciutadellla
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


#include QMK_KEYBOARD_H
#define KEYMAP_DISPLAY
#include "spacerock.h"

#undef LAYOUT_wrapper
#define LAYOUT_wrapper(...)   LAYOUT_reviung41(__VA_ARGS__)
#define ___THUMB_REVIUNG___ LY_NAV, MEH_T(KC_SPC), KC_LSFT, MEH_T(KC_ENT), LY_NAV

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] =  LAYOUT_wrapper(
        __LPT__, _______________QUERTY__L_TOP_______________,    _______________QUERTY__R_TOP_______________, __RPT__,
        __LPM__, _______________COLEMAK_L_MID_GASC__________,    _______________COLEMAK_R_MID_CSAG__________, __RPM__,
        __LPB__, _______________QUERTY__L_BOT_______________,    _______________QUERTY__R_BOT_______________, __RPB__,
                                                     ___THUMB_REVIUNG___
    ),

    [_GAME] =  LAYOUT_wrapper(
        __LPT__, _______________QUERTY__L_TOP_______________,    _______________QUERTY__R_TOP_______________, __RPT__,
        __LPM__, _______________QUERTY__L_MID_GASC__________,    _______________QUERTY__R_MID_CSAG__________, __RPM__,
        __LPB__, _______________QUERTY__L_BOT_______________,    _______________QUERTY__R_BOT_______________, __RPB__,
                                                     ___THUMB_REVIUNG___
    ),

    [_NAV] = LAYOUT_wrapper(
        SH_TOGG, __________________NAV__LT__________________,   KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS, SH_TOGG,
        _______, __________________NAV__LM__________________,   KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        SNAP1,   SNAP2,   _______, _______, _______, _______,   KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
                                         LY_DEF, _______, _______, _______, LY_DEF
     ),

    [_MEDIA] = LAYOUT_wrapper(
        DM_REC1, DM_REC2, _______, _______, _______, _______,   _______, _______, _______, _______, KC_MPLY, _______,
        DM_PLY1, DM_PLY2, _______, _______, _______, _______,   _______, _______, KC_MPRV, KC_MNXT, KC_VOLU, _______,
        DM_RSTP, _______, _______, _______, _______, _______,   _______, _______, _______, _______, KC_VOLD, KC_MUTE,
                                         LY_DEF, _______, _______, _______, LY_DEF
    ),

    [_ADJUST] = LAYOUT_wrapper(
        TG_DEF,  RGB_TOG,  _______, _______, _______, OS_SWAP,   HF_TOGG, _______, _______, _______, KC_MPLY, _______,
        QK_BOOT, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,   DB_TOGG, _______, KC_MPRV, KC_MNXT, KC_VOLU, _______,
        MAKE_H,  RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,   AU_TOGG, _______, _______, _______, KC_VOLD, KC_MUTE,
                                          LY_DEF, _______, _______, _______, LY_DEF
    )

 };
