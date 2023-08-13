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

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] =  LAYOUT_wrapper(
        KC_TAB,  _______________QUERTY__L_TOP_______________,    _______________QUERTY__R_TOP_______________,  KC_BSPC,
        CTL_ESC, _______________QUERTY__L_MID_______________,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,    KC_QUOT,
        QK_LEAD, _______________QUERTY__L_BOT_______________,    KC_N,    KC_M,    KC_COMM, KC_LEFT,  KC_DOWN, KC_RGHT,
                                LY_SYM, OSM(MOD_LSFT), MT(MOD_MEH,KC_SPACE), OSM(MOD_RCTL), LY_NAV
    ),

     [_GAME] =  LAYOUT_reviung41(
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,  KC_BSPC,
        CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,    KC_QUOT,
        QK_LEAD, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_LEFT,  KC_DOWN, KC_RGHT,
                                LY_SYM, OSM(MOD_LSFT), MT(MOD_MEH,KC_SPACE), OSM(MOD_RCTL), LY_NAV
    ),

    [_SYM] = LAYOUT_reviung41(
        DM_REC1, DM_REC2, _______, _______, _______, _______,   KC_7, KC_8, KC_9, KC_PLUS, KC_ASTR, SH_TOGG,
        DM_PLY1, DM_PLY2, OS_CMD,  OS_ALT, OS_CTRL, _______,    KC_4, KC_5, KC_6, KC_MINS, KC_SLSH, _______,
        DM_RSTP, _______, _______, _______, _______, _______,   KC_1, KC_2, KC_3, KC_DOT,  _______, _______,
                                            LY_DEF, _______, KC_ENT, KC_0, LY_FUN
    ),

     [_NAV] = LAYOUT_reviung41(
         SH_TOGG, KC_PGUP, M_LEFT,  KC_UP,   M_RIGHT, M_UP,     _______, _______, _______, _______, _______, _______,
         _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, M_DOWN,   _______, OS_CTRL, OS_ALT, OS_CMD, _______, _______,
         _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
                                            LY_DEF, _______, KC_ENT, _______, LY_FUN
     ),

    [_FUNC] = LAYOUT_reviung41(
        SH_TOGG, KC_F1, KC_F2,  KC_F3,  KC_F4,  _______,   _______, _______, _______, _______, _______, _______,
        _______, KC_F5, KC_F6,  KC_F7,  KC_F8,  _______,   _______, OS_CTRL, OS_ALT, OS_CMD, _______, _______,
        _______, KC_F9, KC_F10, KC_F11, KC_F12, _______,   _______, _______, _______, _______, _______,  _______,
                                      LY_DEF, _______, KC_ENT, _______, LY_ADJ
    ),

    [_ADJUST] = LAYOUT_reviung41(
        _______, RGB_TOG,  _______, _______, _______, OS_SWAP,   OS_SWAP, _______, _______, _______,  _______, TG_DEF,
        QK_BOOT, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,   _______, OS_CTRL, OS_ALT, OS_CMD,  _______, QK_BOOT,
        MAKE_H,  RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD,   AU_TOGG, DB_TOGG, HF_TOGG, _______, _______,  _______,
                                           LY_DEF, _______, KC_ENT, _______, LY_FUN
    )

 };
