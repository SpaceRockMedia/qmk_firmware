// Copyright 2022 Michael McCoyd (@mmccoyd)
// SPDX-License-Identifier: GPL-2.0-or-later

// #include QMK_KEYBOARD_H
#define KEYMAP_DISPLAY
#include "spacerock.h"

// #undef LAYOUT_wrapper
// #define LAYOUT_wrapper(...)   LAYOUT(__VA_ARGS__)
// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_COLEMAK] = LAYOUT_wrapper(
        KC_TAB,  _______________COLEMAK_L_TOP_______________,                                          _______________COLEMAK_R_TOP_______________, LY_MED,
        CTL_ESC, _______________COLEMAK_L_MID_______________,                                          _______________COLEMAK_R_MID_______________, CTL_QUO,
        KC_LGUI, _______________COLEMAK_L_BOT_______________,    QK_LEAD,                     QK_LEAD, _______________COLEMAK_R_BOT_______________, KC_LGUI,
        KC_MUTE, KC_HYPR, _______,          ____________THUMB_LEFT____________,     ____________THUMB_RIGHT___________,          _______, KC_HYPR, KC_VOLD
    ),

    [_GAME] = LAYOUT_wrapper(
        KC_TAB,  _______________QUERTY__L_TOP_______________,                                          _______________QUERTY__R_TOP_______________, LY_MED,
        CTL_ESC, _______________QUERTY__L_MID_______________,                                          _______________QUERTY__R_MID_______________, CTL_QUO,
        KC_LGUI, _______________QUERTY__L_BOT_______________,    QK_LEAD,                     QK_LEAD, _______________QUERTY__R_BOT_______________, KC_LGUI,
        KC_MUTE, KC_HYPR, _______,          ____________THUMB_LEFT____________,    ____________THUMB_RIGHT___________,          _______, KC_HYPR, KC_VOLD
    ),

    [_NAV] = LAYOUT_wrapper(
        SH_TOGG, KC_PGUP, M_LEFT,  KC_UP,   M_RIGHT, M_UP,                                          KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS, SH_TOGG,
        _______, KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, M_DOWN,                                        KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        _______, _______, _______, _______, _______, _______, _______,                     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        _______, _______, _______,          _______, LY_DEF,  KC_UNDS, _______,   _______, _______, LY_SYM,  _______,          _______, _______, _______
    ),

    [_SYM] = LAYOUT_wrapper(
        DM_REC1, DM_REC2, _______, _______, _______, _______,                                       KC_ASTR, KC_7,    KC_8,    KC_9,    KC_PLUS, SH_TOGG,
        DM_PLY1, DM_PLY2, _______, _______, _______, _______,                                       KC_SLSH, KC_4,    KC_5,    KC_6,    KC_MINS, _______,
        DM_RSTP, _______, _______, _______, _______, _______, _______,                     _______, KC_0,    KC_1,    KC_2,    KC_3,    KC_DOT,  _______,
        xxxxxxx, xxxxxxx, _______,          _______, LY_DEF,  KC_UNDS, _______,   _______, _______, LY_ADJ,  _______,          _______, _______, _______
    ),

    [_MEDIA] = LAYOUT_wrapper(
        DM_REC1, DM_REC2, _______, _______, _______, _______,                                       _______, _______, _______, _______, KC_MPLY, _______,
        DM_PLY1, DM_PLY2, _______, _______, _______, _______,                                       _______, _______, KC_MPRV, KC_MNXT, KC_VOLU, _______,
        DM_RSTP, _______, _______, _______, _______, _______,  _______,                    _______, _______, _______, _______, _______, KC_VOLD, KC_MUTE,
        xxxxxxx, xxxxxxx, _______,          _______, LY_DEF,  _______, _______,   _______, _______, TO(_SYM),_______,          _______, KC_MUTE, _______
    ),

    [_ADJUST] = LAYOUT_wrapper(
        xxxxxxx, RGB_TOG, xxxxxxx, xxxxxxx, xxxxxxx, OS_SWAP,                                       OS_SWAP, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, TG_DEF,
        QK_BOOT, RGB_MOD,  RGB_SPI, RGB_HUI, RGB_SAI, RGB_VAI,                                      xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, xxxxxxx, QK_BOOT,
        MAKE_H,  RGB_RMOD, RGB_SPD, RGB_HUD, RGB_SAD, RGB_VAD, xxxxxxx,                    xxxxxxx, AU_TOGG, DB_TOGG, HF_TOGG, xxxxxxx, xxxxxxx, xxxxxxx,
        xxxxxxx, xxxxxxx, xxxxxxx,          xxxxxxx, LY_DEF,  xxxxxxx, xxxxxxx,   xxxxxxx, xxxxxxx, TO(_SYM),xxxxxxx,          xxxxxxx, xxxxxxx, xxxxxxx
    ),

};

//  Template:
//    [_INDEX] = LAYOUT_wrapper(
//      _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______,                                       _______, _______, _______, _______, _______, _______,
//      _______, _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, _______,
//      _______, _______, _______,          _______, _______, _______, _______,   _______, _______, _______, _______,          _______, _______, _______
//    ),

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][2] = {
    [_COLEMAK] = { ENCODER_CCW_CW(KC_WH_D,  KC_WH_U),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_GAME] =    { ENCODER_CCW_CW(KC_WH_D,  KC_WH_U),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_NAV] =     { ENCODER_CCW_CW(KC_RIGHT, KC_LEFT),   ENCODER_CCW_CW(KC_MNXT, KC_MPRV) },
    [_SYM] =     { ENCODER_CCW_CW(RGB_HUI,  RGB_HUD),   ENCODER_CCW_CW(RGB_VAI, RGB_SAI) },
    [_MEDIA] =   { ENCODER_CCW_CW(KC_MPRV,  KC_MNXT),   ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [_ADJUST] =  { ENCODER_CCW_CW(RGB_MOD,  RGB_RMOD),  ENCODER_CCW_CW(RGB_SPI, RGB_SPD) },
};
#endif


// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//     switch (keycode) {
//         case LY_GAME:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_GAME);
//                 layer_move(_GAME);
//             }
//             return false;
//         case LY_COLE:
//             if (record->event.pressed) {
//                 set_single_persistent_default_layer(_COLEMAK);
//                 layer_move(_COLEMAK);
//             }
//             return false;
//         case LY_DEF:
//             if (record->event.pressed) {
//                 if (IS_LAYER_ON(_GAME)) {
//                     layer_move(_GAME);
//                 } else {
//                     layer_move(_COLEMAK);
//                 }
//             }
//     }
//     return true;
// }
