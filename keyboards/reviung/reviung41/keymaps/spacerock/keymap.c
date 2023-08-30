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
#define ___THUMB_REVIUNG___ OSM(MOD_LSFT), MEH_T(KC_SPC), LY_NAV, MEH_T(KC_ENT), OSM(MOD_RCTL)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] =  LAYOUT_wrapper(
        KC_TAB,        _______________QUERTY__L_TOP_______________,    _______________QUERTY__R_TOP_______________, LY_MED,
        OSM(MOD_LALT), _______________QUERTY__L_MID_______________,    _______________QUERTY__R_MID_______________, OSM(KC_LALT),
        OSM(MOD_LGUI), _______________QUERTY__L_BOT_______________,    _______________QUERTY__R_BOT_______________, OSM(MOD_RGUI),
                                                           ___THUMB_REVIUNG___
    ),

    [_GAME] =  LAYOUT_wrapper(
        KC_TAB,        _______________QUERTY__L_TOP_______________,    _______________QUERTY__R_TOP_______________, KC_BSPC,
        OSM(MOD_LALT), _______________QUERTY__L_MID_______________,    _______________QUERTY__R_MID_______________, OSM(MOD_LALT),
        OSM(MOD_LGUI), _______________QUERTY__L_BOT_______________,    _______________QUERTY__R_BOT_______________, OSM(MOD_RGUI),
                                                           ___THUMB_REVIUNG___
    ),

    [_NAV] = LAYOUT_wrapper(
         SH_TOGG, KC_PGUP, M_LEFT,  KC_UP,   M_RIGHT, M_UP,     _______, _______, _______, _______, _______, _______,
         _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, M_DOWN,   _______, _______, _______, _______, _______, _______,
         _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                                          _______, _______, LY_ADJ, _______, _______
     ),

    [_MEDIA] = LAYOUT_wrapper(
        DM_REC1, DM_REC2, _______, _______, _______, _______,  _______, _______, _______, _______, KC_MPLY, _______,
        DM_PLY1, DM_PLY2, _______, _______, _______, _______,  _______, _______, KC_MPRV, KC_MNXT, KC_VOLU, _______,
        DM_RSTP, _______, _______, _______, _______, _______,  _______, _______, _______, _______, KC_VOLD, KC_MUTE,
                                         _______, _______, _______, _______, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        _______, RGB_TOG,  _______, _______, _______, OS_SWAP,  OS_SWAP, _______, _______, _______,  _______, TG_DEF,
        QK_BOOT, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,  _______, OS_CTRL, OS_ALT, OS_CMD,  _______, QK_BOOT,
        MAKE_H,  RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,  AU_TOGG, DB_TOGG, HF_TOGG, _______, _______,  _______,
                                         _______, _______, LY_DEF, _______, _______
    )

 };
