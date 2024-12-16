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
};

#define ADJUST MO(_ADJUST)
#define LGUI_R LGUI_T(KC_R)
#define RGUI_SPC RGUI_T(KC_SPC)
#define FUN_REP LT(_FUN, KC_0)
#define LCTL_M LCTL_T(KC_M)
#define RCTL_DOT RCTL_T(KC_DOT)
#define LCTL_RCBR LCTL_T(KC_RCBR)
#define RCTL_E RCTL_T(KC_E)
#define OSM_LSFT OSM(MOD_LSFT)
#define MAC TO(_MAC)
#define LW TO(_LW) // Linux/Windows layer
#define M_DE OSL(_M_DE)
#define LW_DE OSL(_LW_DE)

// Left-hand home row mods base layer
#define HOME_S LSFT_T(KC_S)
#define HOME_N LALT_T(KC_N)
#define HOME_T LT(_SYM, KC_T)
#define HOME_H LT(_NAV, KC_H)

// Right-hand home row mods base layer
#define HOME_A LT(_NUM, KC_A)
#define HOME_E LT(_SYM, KC_E)
#define HOME_I RALT_T(KC_I)
#define HOME_C RSFT_T(KC_C)

// Left-hand home row mods sym layer
#define HOME_EXLM LSFT_T(KC_EXLM)
#define HOME_BSLS LALT_T(KC_BSLS)
#define HOME_LPRN KC_LPRN
#define HOME_RPRN KC_RPRN

// Right-hand home row mods sym layer
#define HOME_SLSH KC_SLSH
#define HOME_DQUO KC_DQUO
#define HOME_UNDS RALT_T(KC_UNDS)
#define HOME_QUES RSFT_T(KC_QUES)

#define DOT_COMM LT(0, KC_DOT)
#define KC_0_UNDS LT(0, KC_0)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |   F  |   P  |   D  |   L  |   X  |                              |   ;  |   U  |   O  |   Y  |   B  |   Z    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ⌫   |LSft S|LAlt N| Sym T| Nav H|   K  |                              |   ,  | Num A| Sym E|RAlt I|RSft C|   Q    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  ____  |   V  |   W  |   G  |LCtl M|   J  | ____ |Adjust|  | Lock | ____ |   -  |RCtl .|   '  |   =  |  DE  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ | ____ | OSM  | LGui | ____ |  | ____ | RGui | Fun  | ____ | ____ |
 *                        |      |      |Shift | R    |      |  |      | Space| Rep  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_F    , KC_P    , KC_D    , KC_L    , KC_X    ,                                         KC_SCLN , KC_U    , KC_O    , KC_Y    , KC_B    , KC_Z    ,
     KC_BSPC , HOME_S  , HOME_N  , HOME_T  , HOME_H  , KC_K    ,                                         KC_COMM , HOME_A  , HOME_E  , HOME_I  , HOME_C  , KC_Q    ,
     KC_NO   , KC_V    , KC_W    , KC_G    , LCTL_M  , KC_J    , KC_NO   , ADJUST  , M_LOCK  , KC_NO   , KC_MINS , RCTL_DOT, KC_QUOT , KC_EQL  , M_DE    , KC_ENT  ,
                                   KC_NO   , KC_NO   , OSM_LSFT, LGUI_R  , KC_NO   , KC_NO   , RGUI_SPC, FUN_REP , KC_NO   , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                             KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Base Layer: Linux/Windows
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |   Tab  |   F  |   P  |   D  |   L  |   X  |                              |   ;  |   U  |   O  |   Y  |   B  |   Z    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |    ⌫   |LSft S|LAlt N| Sym T| Nav H|   K  |                              |   ,  | Num A| Sym E|RAlt I|RSft C|   Q    |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |  ____  |   V  |   W  |   G  |LCtl M|   J  | ____ |Adjust|  | Lock | ____ |   -  |RCtl .|   '  |   =  |  DE  | Enter  |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ | ____ | OSM  | LGui | ____ |  | ARep | RGui | Fun  | ____ | ____ |
 *                        |      |      |Shift | R    |      |  |      | Space| Rep  |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_LW] = LAYOUT_split_3x6_5_hlc(
     KC_TAB  , KC_F    , KC_P    , KC_D    , KC_L    , KC_X    ,                                         KC_SCLN , KC_U    , KC_O    , KC_Y    , KC_B    , KC_Z    ,
     KC_BSPC , HOME_S  , HOME_N  , HOME_T  , HOME_H  , KC_K    ,                                         KC_COMM , HOME_A  , HOME_E  , HOME_I  , HOME_C  , KC_Q    ,
     KC_NO   , KC_V    , KC_W    , KC_G    , LCTL_M  , KC_J    , KC_NO   , ADJUST  , LW_LOCK , KC_NO   , KC_MINS , RCTL_DOT, KC_QUOT , KC_EQL  , LW_DE   , KC_ENT  ,
                                   KC_NO   , KC_NO   , OSM_LSFT, LGUI_R  , KC_NO   , QK_AREP , RGUI_SPC, FUN_REP , KC_NO   , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                             KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Sym
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    ^   |   #  |   *  |   [  |   ]  |   &  |                              |   ;  |   <  |   >  |   @  |   ~  |    `   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |LSft !|LAlt \|   (  |   )  |   :  |                              |   ,  |   /  |   "  |RAlt _|RSft ?|  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   %  |   $  |   {  |LCtl }|   |  |      |      |  |      |      |   -  |RCtl .|   '  |   =  |   +  |        |
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
     _______ ,HOME_EXLM,HOME_BSLS,HOME_LPRN,HOME_RPRN, KC_COLN ,                                         KC_COMM ,HOME_SLSH,HOME_DQUO,HOME_UNDS,HOME_QUES, KC_NO   ,
     _______ , KC_PERC , KC_DLR  , KC_LCBR ,LCTL_RCBR, KC_PIPE , _______ , _______ , _______ , _______ , KC_MINS ,RCTL_DOT , KC_QUOT , KC_EQL  , KC_PLUS , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        | ____ | ____ | ____ | ____ | ____ |                              | PgUp | Home |   ↑  |  End | ____ |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LSft | LAlt | LCtl | ____ | ____ |                              | PgDn |  ←   |   ↓  |   →  |   ⌦  |  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      | ____ | Tab  | ____ |  App | ____ |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      | LLck |  |      | Esc  |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_PGUP , KC_HOME , KC_UP   , KC_END  , KC_NO   , KC_NO   ,
     _______ , KC_LSFT , KC_LALT , KC_LCTL , KC_NO   , KC_NO   ,                                         KC_PGDN , KC_LEFT , KC_DOWN , KC_RGHT , KC_DEL  , KC_NO   ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_TAB  , KC_NO   , KC_APP  , KC_NO   , _______ ,
                                   _______ , _______ , _______ , _______ , QK_LLCK , _______ , KC_ESC  , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Num
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |   %  |   6  |   5  |   4  |   X  |                              | ____ | ____ | ____ | ____ | ____ |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   -  |   3  |   2  |   1  |   +  |                              | ____ | ____ |RCtl E| RAlt | RSft |  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   /  |   9  |   8  |   7  |   *  |      |      |  |      |      | ____ | ____ | ____ |   =  | ____ |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |   ,  |   _  | LLck |  |      |      |      |      |      |
 *                        |      |      |   .  |   0  |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NUM] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_PERC , KC_6    , KC_5    , KC_4    , _______ ,                                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     _______ , KC_MINS , KC_3    , KC_2    , KC_1    , KC_PLUS ,                                         KC_NO   , KC_NO   , RCTL_E  , KC_RALT , KC_RSFT , KC_NO   ,
     _______ , KC_SLSH , KC_9    , KC_8    , KC_7    , KC_ASTR , _______ , _______ , _______ , _______ , KC_NO   , KC_NO   , KC_NO   , _______ , KC_NO   , _______ ,
                                   _______ , _______ , DOT_COMM,KC_0_UNDS, QK_LLCK , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * Fun
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |  F10 |  F6  |  F5  |  F4  | ____ |                              | ____ | ____ | ____ | ____ | ____ |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |  F11 |  F3  |  F2  |  F1  | ____ |                              | ____ | ____ | RCtl | RAlt | RSft |  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |  F12 |  F9  |  F8  |  F7  | ____ |      |      |  |      |      | ____ | ____ | ____ | ____ | ____ |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      | ARep |      | LLck |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUN] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_F10  , KC_F6   , KC_F5   , KC_F4   , KC_NO   ,                                         KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,
     _______ , KC_F11  , KC_F3   , KC_F2   , KC_F1   , KC_NO   ,                                         KC_NO   , KC_NO   , KC_RCTL , KC_RALT , KC_RSFT , KC_NO   ,
     _______ , KC_F12  , KC_F9   , KC_F8   , KC_F7   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
                                   _______ , _______ , QK_AREP , _______ , QK_LLCK , _______ , _______ , _______ , _______ , _______ ,
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
 * |        |      |      |      |      |      |      |      |  |QkBoot|Reset |      |  SAD |  HUD |  VAD | RMOD |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  | Clear|      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , MAC     ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ , LW      ,                                         RGB_TOG , RGB_SAI , RGB_HUI , RGB_VAI , RGB_MOD , _______ ,
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , QK_BOOT , QK_RBT  , _______ , RGB_SAD , RGB_HUD , RGB_VAD ,RGB_RMOD , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , EE_CLR  , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

/*
 * German Layer: Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |      |                              |      |   Ü  |   Ö  |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |   ß  |      |      |      |      |                              |      |   Ä  |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_M_DE] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , M_DE_UE , M_DE_OE , _______ , _______ , _______ ,
     _______ , DE_S    , _______ , _______ , _______ , _______ ,                                         _______ , M_DE_AE , _______ , _______ , _______ , _______ ,
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
 * |        |   ß  |      |      |      |      |                              |      |   Ä  |      |      |      |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_LW_DE] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ ,LW_DE_UE ,LW_DE_OE , _______ , _______ , _______ ,
     _______ , DE_S    , _______ , _______ , _______ , _______ ,                                         _______ ,LW_DE_AE , _______ , _______ , _______ , _______ ,
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

bool remember_last_key_user(uint16_t keycode, keyrecord_t* record, uint8_t* remembered_mods) {
    if (keycode == FUN_REP) {
        return false;
    }
    return true;
}

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t* record) {
    switch (keycode) {
        case LGUI_R:
            return true;
        default:
            return false;
    }
}

void housekeeping_task_user(void) {
    achordion_task();
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
    bool shifted = (mods & MOD_MASK_SHIFT);
    switch (keycode) {
        case RCTL_DOT:
            if (!shifted) {
                return UPDIR;
            }
    }

    return KC_TRNS;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
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

static bool process_tap_or_long_press_key(keyrecord_t* record, uint16_t long_press_keycode) {
    if (record->tap.count == 0) {
        if (record->event.pressed) {
            tap_code16(long_press_keycode);
        }
        return false;
    }
    return true;
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (!process_achordion(keycode, record)) {
        return false;
    }

    mod_state          = get_mods();
    one_shot_mod_state = get_oneshot_mods();

    switch (keycode) {
        case DOT_COMM:
            return process_tap_or_long_press_key(record, KC_COMM);
        case KC_0_UNDS:
            return process_tap_or_long_press_key(record, KC_UNDS);
        case FUN_REP:
            if (record->tap.count) {
                repeat_key_invoke(&record->event);
                return false;
            }
            return true;
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
        case LCTL_RCBR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            break;
        case HOME_UNDS:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
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
