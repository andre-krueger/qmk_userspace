// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

enum layers {
    _MAC = 0,
    _LW,
    _SYM,
    _NAV,
    _NUM,
    _FUN,
    _ADJUST,
};

enum custom_keycodes {
    MAC_DE_AE = SAFE_RANGE,
    MAC_DE_OE,
    MAC_DE_UE,
    DE_S,
    MAC_LOCK,
    LW_DE_AE,
    LW_DE_OE,
    LW_DE_UE,
};

#define ADJUST MO(_ADJUST)
#define NAV_BSPC LT(_NAV, KC_BSPC)
#define NUM_TAB LT(_NUM, KC_TAB)
#define SYM_SPC LT(_SYM, KC_SPC)
#define FUN_ENT LT(_FUN, KC_ENT)
#define MAC TO(_MAC)
#define LW TO(_LW) // Linux/Windows layer

// Left-hand home row mods base layer
#define HOME_C LCTL_T(KC_C)
#define HOME_S LALT_T(KC_S)
#define HOME_I LGUI_T(KC_I)
#define HOME_E LSFT_T(KC_E)

// Right-hand home row mods base layer
#define HOME_T RSFT_T(KC_T)
#define HOME_N RGUI_T(KC_N)
#define HOME_R RALT_T(KC_R)
#define HOME_H RCTL_T(KC_H)

// Left-hand home row mods sym layer
#define HOME_MINS LCTL_T(KC_MINS)
#define HOME_UNDS LALT_T(KC_UNDS)
#define HOME_LPRN LGUI_T(KC_LPRN)
#define HOME_RPRN LSFT_T(KC_RPRN)

// Right-hand home row mods sym layer
#define HOME_RCBR RSFT_T(KC_RCBR)
#define HOME_LCBR RGUI_T(KC_LCBR)
#define HOME_SLSH RALT_T(KC_SLSH)
#define HOME_COLN RCTL_T(KC_COLN)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * Base Layer: Mac
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    J   |   Y  |   Z  |   U  |   A  |   Q  |                              |   P  |   B  |   M  |   L  |   F  |   ß    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |LCtl/C|LAlt/S|LGui/I|LSft/E|   O  |                              |   D  |RSft/T|RGui/N|RAlt/R|RCtl/H|  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   V  |   X  |   Ü  |   Ä  |   Ö  | ____ | ____ |  | LOCK | ____ |   W  |   G  | ,  < | .  > |   K  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ |Adjust| Nav/ | Num/ | ____ |  | ____ | Fun/ | Sym/ |Adjust| ____ |
 *                        |      |      | Bkspc| Tab  |      |  |      | Enter| Space|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_J    , KC_Y    , KC_Z    , KC_U    , KC_A    , KC_Q    ,                                         KC_P    , KC_B    , KC_M    , KC_L    , KC_F    , DE_S    ,
     KC_ESC  , HOME_C  , HOME_S  , HOME_I  , HOME_E  , KC_O    ,                                         KC_D    , HOME_T  , HOME_N  , HOME_R  , HOME_H  , KC_NO   ,
     KC_LSFT , KC_V    , KC_X    ,MAC_DE_UE,MAC_DE_AE,MAC_DE_OE, KC_NO   , KC_NO   ,MAC_LOCK , KC_NO   , KC_W    , KC_G    , KC_COMM , KC_DOT  , KC_K    , KC_RSFT ,
                                   KC_NO   , ADJUST  ,NAV_BSPC , NUM_TAB , KC_LCTL , KC_RCTL , FUN_ENT , SYM_SPC , ADJUST  , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                   KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Base Layer: Linux/Windows
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |    J   |   Y  |   Z  |   U  |   A  |   Q  |                              |   P  |   B  |   M  |   L  |   F  |   ß    |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |   Esc  |LCtl/C|LAlt/S|LGui/I|LSft/E|   O  |                              |   D  |RSft/T|RGui/N|RAlt/R|RCtl/H|  ____  |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * | LShift |   V  |   X  |   Ü  |   Ä  |   Ö  | ____ | ____ |  | ____ | ____ |   W  |   G  | ,  < | .  > |   K  | RShift |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        | ____ |Adjust| Nav/ | Num/ | ____ |  | ____ | Fun/ | Sym/ |Adjust| ____ |
 *                        |      |      | Bkspc| Tab  |      |  |      | Enter| Space|      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * | MUTE | ____ | _____ | ____ | ____ |                                              | MUTE | ____ | _____ | ____ | ____ |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_LW] = LAYOUT_split_3x6_5_hlc(
     KC_J    , KC_Y    , KC_Z    , KC_U    , KC_A    , KC_Q    ,                                         KC_P    , KC_B    , KC_M    , KC_L    , KC_F    , DE_S    ,
     KC_ESC  , HOME_C  , HOME_S  , HOME_I  , HOME_E  , KC_O    ,                                         KC_D    , HOME_T  , HOME_N  , HOME_R  , HOME_H  , KC_NO   ,
     KC_LSFT , KC_V    , KC_X    ,LW_DE_UE ,LW_DE_AE ,LW_DE_OE , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_W    , KC_G    , KC_COMM , KC_DOT  , KC_K    , KC_RSFT ,
                                   KC_NO   , ADJUST  ,NAV_BSPC , NUM_TAB , KC_LCTL , KC_RCTL , FUN_ENT , SYM_SPC , ADJUST  , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                   KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

/*
 * Sym
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  |   @  |   +  |   [  |   ]  |   %  |                              |   ~  |   \  |   "  |   *  |   '  |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |LCtl/-|LAlt/_|LGui/(|LSft/)|   &  |                              |   |  |RSft/}|RGui/{|RAlt//|RCtl/:|        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |   ^  |   $  |   <  |   >  |   #  |      |      |  |      |      |   `  |   =  |   ?  |   !  |   ;  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_SYM] = LAYOUT_split_3x6_5_hlc(
     KC_NO   , KC_AT   , KC_PPLS , KC_LBRC , KC_RBRC , KC_PERC ,                                         KC_TILD , KC_BSLS , KC_DQUO , KC_ASTR , KC_QUOT , KC_NO   ,
     _______ ,HOME_MINS,HOME_UNDS,HOME_LPRN,HOME_RPRN, KC_AMPR ,                                         KC_PIPE ,HOME_RCBR,HOME_LCBR,HOME_SLSH,HOME_COLN, _______ ,
     _______ , KC_CIRC , KC_DLR  , KC_LABK , KC_RABK , KC_HASH , _______ , _______ , _______ , _______ , KC_GRV  , KC_EQL  , KC_QUES , KC_EXLM , KC_SCLN , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

/*
 * Nav
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  | ____ | ____ | ____ | ____ | ____ |                              | ____ | PgUp |   ↑  | PgDn | ____ |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCtl | LAlt | LGui | LSft | ____ |                              | Home |  ←   |   ↓  |   →  |  End |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      | ____ | ____ | ____ | ____ | ____ |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_NAV] = LAYOUT_split_3x6_5_hlc(
     KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_NO   , KC_PGUP , KC_UP   , KC_PGDN , KC_NO   , KC_NO   ,
     _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_NO   ,                                         KC_HOME , KC_LEFT , KC_DOWN , KC_RGHT , KC_END  , _______ ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

/*
 * Num
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |  ____  | ____ | ____ | ____ | ____ | ____ |                              |   /  |   4  |   5  |   6  |   +  |    *   |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCtl | LAlt | LGui |LShift| ____ |                              |   :  |   1  |   2  |   3  |   -  |    =   |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      |   ,  |   7  |   8  |   9  |   .  |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |   0  |      |      |
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
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , KC_P0   , _______  , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

/*
 * Fun
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * | QK_BOOT| ____ | ____ | ____ | ____ | ____ |                              | ____ |  F4  |  F5  |  F6  |  F10 |  ____  |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        | LCtl | LAlt | LGui |LShift| ____ |                              | ____ |  F1  |  F2  |  F3  |  F11 |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        | ____ | ____ | ____ | ____ | ____ |      |      |  |      |      | ____ |  F7  |  F8  |  F9  |  F12 |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 * ,-----------------------------------.                                              ,-----------------------------------.
 * |      |      |       |      |      |                                              |      |      |       |      |      |
 * `-----------------------------------'                                              `-----------------------------------'
 */
    [_FUN] = LAYOUT_split_3x6_5_hlc(
     QK_BOOT , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                         KC_NO   , KC_F4   , KC_F5   , KC_F6   , KC_F10  , KC_NO   ,
     _______ , KC_LCTL , KC_LALT , KC_LGUI , KC_LSFT , KC_NO   ,                                         KC_NO   , KC_F1   , KC_F2   , KC_F3   , KC_F11  , _______ ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_F7   , KC_F8   , KC_F9   , KC_F12  , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
    ),

/*
 * Adjust
 *
 * ,-------------------------------------------.                              ,-------------------------------------------.
 * |        |      |      |      |      |  Mac |                              |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|                              |------+------+------+------+------+--------|
 * |        |      |      |      |      |  LW  |                              |  TOG |  SAI |  HUI |  VAI |  MOD |        |
 * |--------+------+------+------+------+------+-------------.  ,-------------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |  SAD |  HUD |  VAD | RMOD |        |
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
     _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , RGB_SAD , RGB_HUD , RGB_VAD ,RGB_RMOD , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
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
//      _______ , _______ , _______ , _______ , _______ ,                                                   _______ , _______ , _______ , _______ , _______
//     ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LCTL_T(KC_MINS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_MINS);
                return false;
            }
            break;
        case LALT_T(KC_UNDS):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_UNDS);
                return false;
            }
            break;
        case LGUI_T(KC_LPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LPRN);
                return false;
            }
            break;
        case LSFT_T(KC_RPRN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RPRN);
                return false;
            }
            break;
        case RSFT_T(KC_RCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_RCBR);
                return false;
            }
            break;
        case RGUI_T(KC_LCBR):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_LCBR);
                return false;
            }
            break;
        case RCTL_T(KC_COLN):
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_COLN);
                return false;
            }
            break;
        case MAC_DE_AE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("u") "a");
            }
            break;
        case MAC_DE_OE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("u") "o");
            }
            break;
        case MAC_DE_UE:
            if (record->event.pressed) {
                SEND_STRING(SS_LALT("u") "u");
            }
            break;
        case DE_S:
            if (record->event.pressed) {
                tap_code16(QK_LALT | KC_S);
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
        case MAC_LOCK:
            if (record->event.pressed) {
                tap_code16(QK_LCTL | QK_LGUI | KC_Q);
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
