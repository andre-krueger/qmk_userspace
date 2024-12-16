// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "features/achordion.h"

enum layers {
    _MAC = 0,
    _LW,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _ADJUST,
    _M_DE,
    _LW_DE,
};

enum custom_keycodes {
    M_DE_AE = SAFE_RANGE,
    M_DE_OE,
    M_DE_UE,
    DE_S,
    M_LOCK,
    LW_LOCK,
    LW_DE_AE,
    LW_DE_OE,
    LW_DE_UE,
    UPDIR,
    S_TAB,
};

#define ADJUST MO(_ADJUST)
#define SYM_R LT(_SYM, KC_R)
#define NAV_SPC LT(_NAV, KC_SPC)
#define NUM MO(_NUM)
#define FUN MO(_FUN)
#define MAC TO(_MAC)
#define LW TO(_LW) // Linux/Windows layer
#define M_DE OSL(_M_DE)
#define LW_DE OSL(_LW_DE)
#define BWD_DEL LALT(KC_BSPC)

// Left-hand home row mods base layer
#define HOME_S LCTL_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LGUI_T(KC_T)
#define HOME_H LSFT_T(KC_H)

// Right-hand home row mods base layer
#define HOME_A RSFT_T(KC_A)
#define HOME_E RGUI_T(KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_C RCTL_T(KC_C)

// Left-hand home row mods sym layer
#define HOME_EXLM LCTL_T(KC_EXLM)
#define HOME_BSLS LALT_T(KC_BSLS)
#define HOME_LPRN LGUI_T(KC_LPRN)
#define HOME_RPRN LSFT_T(KC_RPRN)

// Right-hand home row mods sym layer
#define HOME_SLSH RSFT_T(KC_SLSH)
#define HOME_UNDS RGUI_T(KC_UNDS)
#define HOME_EQL RALT_T(KC_EQL)
#define HOME_QUES LCTL_T(KC_QUES)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   F  |   P  |   D  |   L  |   X  |                              |   ;  |   U  |   O  |   Y  |   B  |   Z    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  BSpc  |LCtl S|LAlt N|LGui T|LSft H|   K  |                              |   ,  |RSft A|RGui E|RAlt I|RCtl C|   Q    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  \     |   V  |   W  |   G  |   M  |   J  | ____ |Adjust|  | Lock | ____ |   -  |   .  |   '  |   =  |  DE  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ | ____ | Num  | Sym  | ____ |  | ____ | Nav  | Fun  | ____ | ____ |
 *                        |      |      |      | R    |      |  |      | Space|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_F    , KC_P    , KC_D    , KC_L    , KC_X    ,                                         KC_SCLN , KC_U    , KC_O    , KC_Y    , KC_B    , KC_Z    ,
     KC_BSPC , HOME_S  , HOME_N  , HOME_T  , HOME_H  , KC_K    ,                                         KC_COMM , HOME_A  , HOME_E  , HOME_I  , HOME_C  , KC_Q    ,
     KC_BSLS , KC_V    , KC_W    , KC_G    , KC_M    , KC_J    , KC_NO   , ADJUST  , M_LOCK  , KC_NO   , KC_MINS , KC_DOT  , KC_QUOT , KC_EQL  , M_DE    , KC_ENT  ,
                                   KC_NO   , KC_NO   , NUM     , SYM_R   , KC_NO   , KC_NO   , NAV_SPC , FUN     , KC_NO   , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                             KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Base Layer: Linux/Windows
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  Tab   |   F  |   P  |   D  |   L  |   X  |                              |   ;  |   U  |   O  |   Y  |   B  |   Z    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |  BSpc  |LCtl S|LAlt N|LGui T|LSft H|   K  |                              |   ,  |RSft A|RGui E|RAlt I|RCtl C|   Q    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  \     |   V  |   W  |   G  |   M  |   J  | ____ |Adjust|  | Lock | ____ |   -  |   .  |   '  |   =  |  DE  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ | ____ | Num  | Sym  | ____ |  | ____ | Nav  | Fun  | ____ | ____ |
 *                        |      |      |      | R    |      |  |      | Space|      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_LW] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_F    , KC_P    , KC_D    , KC_L    , KC_X    ,                                         KC_SCLN , KC_U    , KC_O    , KC_Y    , KC_B    , KC_Z    ,
     KC_BSPC , HOME_S  , HOME_N  , HOME_T  , HOME_H  , KC_K    ,                                         KC_COMM , HOME_A  , HOME_E  , HOME_I  , HOME_C  , KC_Q    ,
     KC_BSLS , KC_V    , KC_W    , KC_G    , KC_M    , KC_J    , KC_NO   , ADJUST  , LW_LOCK , KC_NO   , KC_MINS , KC_DOT  , KC_QUOT , KC_EQL  , LW_DE   , KC_ENT  ,
                                   KC_NO   , KC_NO   , NUM     , SYM_R   , KC_NO   , KC_NO   , NAV_SPC , FUN     , KC_NO   , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                             KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Sym
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ^   |   #  |   *  |   [  |   ]  |   &  |                              |   ;  |   <  |   >  |   @  |   ~  |    `   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |LCtl !|LAlt \|LGui (|LSft )|   :  |                              |   ,  |RSft /|RGui _|RAlt =|RCtl ?|  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   %  |   $  |   {  |   }  |   |  |      |      |  |      |      |   -  |   .  |   '  |   "  |   +  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
     KC_CIRC , KC_HASH , KC_ASTR , KC_LBRC , KC_RBRC , KC_AMPR ,                                         KC_SCLN , KC_LABK , KC_RABK , KC_AT   , KC_TILD , KC_GRV  ,
     _______ ,HOME_EXLM,HOME_BSLS,HOME_LPRN,HOME_RPRN, KC_COLN ,                                         KC_COMM ,HOME_SLSH,HOME_UNDS ,HOME_EQL,HOME_QUES, KC_NO   ,
     _______ , KC_PERC , KC_DLR  , KC_LCBR , KC_RCBR , KC_PIPE , _______ , _______ , _______ , _______ , KC_MINS , KC_DOT  , KC_QUOT , KC_DQUO , KC_PLUS , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  | ____ | ____ | ____ | ____ | ____ |                              | ____ | ____ |   ↑  | ____ | ____ |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |Bwd Del | LCtl | LAlt | LGui | LSft | ____ |                              | STab |  ←   |   ↓  |   →  | Tab  | Delete |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      | ____ | ____ | ____ | ____ | ____ |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      | Esc  | LLck |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_NO   , KC_NO   , KC_UP   , KC_NO   , KC_NO   , KC_NO   ,
     BWD_DEL , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_NO   ,                                         S_TAB   , KC_LEFT , KC_DOWN , KC_RGHT , KC_TAB  , KC_DEL  ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
                                   _______ , _______ , _______ , KC_ESC  , QK_LLCK , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Num
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  | ____ | ____ | ____ | ____ | ____ |                              |   /  |   4  |   5  |   6  |   +  |    *   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCtl | LAlt | LGui | LSft | ____ |                              |   :  |   1  |   2  |   3  |   -  |    =   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      |   ,  |   7  |   8  |   9  |   .  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | LLck |  0   |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUM] = LAYOUT_split_3x6_5_hlc(
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_PSLS , KC_P4   , KC_P5   , KC_P6   , KC_PPLS , KC_PAST ,
     _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_NO   ,                                         KC_COLN , KC_P1   , KC_P2   , KC_P3   , KC_PMNS , KC_PEQL ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_COMM , KC_P7   , KC_P8   , KC_P9   , KC_PDOT , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , QK_LLCK , KC_P0   , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Fun
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  | ____ | ____ | ____ | ____ | ____ |                              | ____ |  F4  |  F5  |  F6  |  F10 |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCtl | LAlt | LGui | LSft | ____ |                              | ____ |  F1  |  F2  |  F3  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      | ____ |  F7  |  F8  |  F9  |  F12 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | LLck |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUN] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_NO   , KC_F4   , KC_F5   , KC_F6   , KC_F10  , KC_NO   ,
     _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_NO   ,                                         KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F11  , _______ ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_F7   , KC_F8   , KC_F9   , KC_F12  , _______ ,
                                   _______ , _______ , _______ , _______ , QK_LLCK , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Adjust
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |  Mac |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |  LW  |                              |  TOG |  SAI |  HUI |  VAI |  MOD |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |QkBoot|      |      |  SAD |  HUD |  VAD | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , MAC     ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , LW      ,                                         RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT , _______ , _______ , RGB_SAD , RGB_HUD , RGB_VAD ,RGB_RMOD , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * German Layer: Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   Ü  |   Ö  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   ß  |      |      |LShift|      |                              |      |   Ä  |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |     |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_M_DE] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , M_DE_UE , M_DE_OE , _______ , _______ , _______ ,
     _______ , DE_S    , _______ , _______ , KC_LSFT , _______ ,                                         _______ , M_DE_AE , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * German Layer: Linux/Windows
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   Ü  |   Ö  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   ß  |      |      |LShift|      |                              |      |   Ä  |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |     |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_LW_DE] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ ,LW_DE_UE ,LW_DE_OE , _______ , _______ , _______ ,
     _______ , DE_S    , _______ , _______ , KC_LSFT , _______ ,                                         _______ ,LW_DE_AE , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

// /*
//  * Halcyon Layer template
//  *
//  * ,-------------------------------------------.                              ,-------------------------------------------.
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |                              |      |      |      |      |      |        |
//  * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
//  * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
//  * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        |      |      |      |      |      |  |      |      |      |      |      |
//  *                        `----------------------------------'  `----------------------------------'
//  * ,-----------------------------------.                                              ,-----------------------------------.
//  * |      |      |       |      |      |                                              |      |      |       |      |      |
//  * `-----------------------------------'                                              `-----------------------------------'
//  */
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//                                    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
//     ),
};
// clang-format on

void housekeeping_task_user(void) {
    achordion_task();
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);
    switch (keycode) {
        case KC_DOT:
            if (!shifted) {
                return UPDIR;
            }
    }

    return KC_TRNS;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case NAV_SPC:
        case SYM_R:
            return true;
            break;
    }

    if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 3) {
        return true;
    }

    return achordion_opposite_hands(tap_hold_record, other_record);
}

uint8_t mod_state;
uint8_t one_shot_mod_state;

void handle_mac_umlaut(void);

void handle_mac_umlaut() {
    if (mod_state & MOD_MASK_SHIFT) {
        del_mods(MOD_MASK_SHIFT);
    }
    if (one_shot_mod_state & MOD_MASK_SHIFT) {
        del_oneshot_mods(MOD_MASK_SHIFT);
    }
    register_code(KC_LALT);
    tap_code(KC_U);
    unregister_code(KC_LALT);
    set_mods(mod_state);
    set_oneshot_mods(one_shot_mod_state);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    mod_state          = get_mods();
    one_shot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case HOME_EXLM:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EXLM);
                return false;
            }
            break;
        case HOME_BSLS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_BSLS);
                return false;
            }
            break;
        case HOME_LPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case HOME_RPRN:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case HOME_SLSH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_SLSH);
                return false;
            }
            break;
        case HOME_UNDS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case HOME_EQL:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_EQL);
                return false;
            }
            break;
        case HOME_QUES:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_QUES);
                return false;
            }
            break;
        case M_DE_AE:
            if (record->event.pressed) {
                handle_mac_umlaut();
                if (is_caps_word_on()) {
                    register_code(KC_LSFT);
                    tap_code(KC_A);
                    unregister_code(KC_LSFT);
                } else {
                    tap_code(KC_A);
                }
                return false;
            }
            break;
        case M_DE_OE:
            if (record->event.pressed) {
                handle_mac_umlaut();
                if (is_caps_word_on()) {
                    register_code(KC_LSFT);
                    tap_code(KC_O);
                    unregister_code(KC_LSFT);
                } else {
                    tap_code(KC_O);
                }
                return false;
            }
            break;
        case M_DE_UE:
            if (record->event.pressed) {
                handle_mac_umlaut();
                if (is_caps_word_on()) {
                    register_code(KC_LSFT);
                    tap_code(KC_U);
                    unregister_code(KC_LSFT);
                } else {
                    tap_code(KC_U);
                }
                return false;
            }
            break;
        case DE_S:
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_S);
            }
            break;
        case LW_DE_AE:
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_Q);
            }
            break;
        case LW_DE_OE:
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_P);
            }
            break;
        case LW_DE_UE:
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_Y);
            }
            break;
        case M_LOCK:
            if (record->event.pressed) {
                tap_code16(QK_LCTL | QK_LGUI | KC_Q);
            }
            break;
        case LW_LOCK:
            if (record->event.pressed) {
                tap_code16(QK_LGUI | KC_L);
            }
            break;
        case S_TAB:
            if (record->event.pressed) {
                tap_code16(QK_LSFT | KC_TAB);
            }
            break;
        case UPDIR:
            if (record->event.pressed) {
                SEND_STRING("./");
            }
            break;
    }
    return true;
};

#ifdef ENCODER_ENABLE
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        // Volume control
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 2) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    } else if (index == 3) {
        // Page up/Page down
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return false;
}
#endif
