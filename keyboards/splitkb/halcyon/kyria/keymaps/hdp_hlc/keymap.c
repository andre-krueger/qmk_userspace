// Copyright 2024 splitkb.com (support@splitkb.com)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap.h"
#include "keycodes.h"
#include "de_diacritics.h"
#include "xcase.h"
#include <ctype.h>
#include "g/keymap_combo.h"

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_MAC] = LAYOUT_split_3x6_5_hlc(
     KC_NO   , KC_F    , KC_P    , SFT_D   , DE_L    , KC_X    ,                                         KC_SCLN , FUN_U   , SFT_O   , KC_Y    , KC_B    , KC_Z    ,
     KC_BSPC , HOME_S  , HOME_N  , HOME_T  , HOME_H  , KC_K    ,                                         KC_COMM , HOME_A  , HOME_E  , HOME_I  , HOME_C  , KC_Q    ,
     KC_BSLS , KC_V    , KC_W    , KC_G    , KC_M    , KC_J    , KC_NO   , ADJUST  , LOCK    , KC_NO   , KC_MINS , KC_DOT  , KC_SLSH , KC_EQL  , KC_QUOT , KC_ENT  ,
                                   KC_NO   , KC_NO   , OSM_LSFT, KC_R    , KC_NO   , KC_UNDS , KC_SPC  , OSM_RSFT, KC_NO   , KC_NO   ,
     KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO   ,                                                             KC_MUTE , KC_NO   , KC_NO   , KC_NO   , KC_NO
    ),

    [_SYM] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_NO   , KC_AT   , KC_LABK , KC_RABK , KC_NO   ,                                         _______ , KC_LCBR, KC_RCBR  , KC_PIPE , KC_GRV  , KC_NO   ,
     _______ ,HOME_HASH,HOME_EXLM,HOME_PERC,HOME_ASTR, KC_NO   ,                                         _______ ,HOME_LPRN,HOME_RPRN,HOME_AMPR, HOME_DQT, KC_NO   ,
     _______ , KC_TILD , KC_PLUS , KC_LBRC , KC_RBRC , KC_NO   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                   _______ , _______ , _______ , KC_LGUI , KC_NO   , _______ , RGUI_SPC, _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

    [_NUM] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_PERC , KC_9    , KC_8    , KC_7    , _______ ,                                         _______ , KC_NO   , _______ , KC_NO   , _______ , KC_NO   ,
     _______ , KC_MINS , KC_3    , HOME_2  , KC_1    , KC_PLUS ,                                         _______ , KC_RGUI , _______ , KC_RCTL , KC_LALT , KC_NO   ,
     _______ , KC_SLSH , KC_6    , KC_5    , KC_4    , KC_ASTR , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                   _______ , _______ , _______ , KC_0    , QK_LLCK , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

    [_NAV] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_NO   , KC_NO   , KC_LSFT , KC_NO   , KC_NO   ,                                         KC_NO   , KC_PGUP , KC_UP   , KC_HOME , KC_NO   , KC_NO   ,
     _______ , KC_LALT , KC_LCTL , KC_NO   , KC_LGUI , KC_NO   ,                                         KC_NO   , KC_LEFT , KC_DOWN , KC_RGHT , KC_NO   , KC_DEL  ,
     _______ , KC_NO   , KC_NO   , KC_NO   , KC_LSFT , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_PGDN , KC_NO   , KC_END  , KC_APP  , _______ ,
                                   _______ , _______ , _______ , GUI_TAB , QK_LLCK , _______ , GUI_GRV , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

    [_FUN] = LAYOUT_split_3x6_5_hlc(
     _______ , KC_F12  , KC_F9   , KC_F8   , KC_F7   , KC_NO   ,                                         KC_NO   , KC_NO   , KC_RSFT , KC_NO   , KC_NO   , KC_NO   ,
     _______ , KC_F10  , KC_F3   , KC_F2   , KC_F1   , KC_NO   ,                                         KC_NO   , KC_RGUI , KC_NO   , KC_RCTL , KC_LALT , KC_NO   ,
     _______ , KC_F11  , KC_F6   , KC_F5   , KC_F4   , KC_NO   , _______ , _______ , _______ , _______ , KC_NO   , KC_NO   , KC_NO   , KC_NO   , KC_NO   , _______ ,
                                   _______ , _______ , _______ , _______ , QK_LLCK , _______ , KC_RGUI , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

    [_DE_DIA] = LAYOUT_split_3x6_5_hlc(
     _______ , GRV_ACC , _______ , DIAE    , _______ , _______ ,                                         _______ , DE_UE   , DE_OE   , _______ , _______ , _______ ,
     _______ , DE_S    , _______ , _______ , _______ , _______ ,                                         _______ , DE_AE   , ACU_ACC , _______ , CIRC    , _______ ,
     _______ , TILDE   , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

    [_ADJUST] = LAYOUT_split_3x6_5_hlc(
     _______ , _______ , _______ , _______ , _______ , TG_OS   ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , AS_UP   , AS_RPT  ,                                         RM_TOGG , RM_SATU , RM_HUEU , RM_VALU , RM_NEXT , _______ ,
     _______ , _______ , _______ , _______ , AS_DOWN , _______ , _______ , _______ , QK_BOOT , QK_RBT  , _______ , RM_SATD , RM_HUED , RM_VALD , RM_PREV , _______ ,
                                   _______ , _______ , _______ , _______ , _______ , EE_CLR  , _______ , _______ , _______ , _______ ,
     _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
    ),

// Halcyon Layer template
//
//     [_LAYERINDEX] = LAYOUT_split_3x6_5_hlc(
//      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ , _______ ,                                         _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//                                    _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ , _______ ,
//      _______ , _______ , _______ , _______ , _______ ,                                                             _______ , _______ , _______ , _______ , _______
//     ),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT(
      'L' , 'L' , 'L' , 'L' , 'L' , 'L' ,                         'R' , 'R' , 'R' , 'R' , 'R' , 'R' ,
      'L' , 'L' , 'L' , 'L' , 'L' , 'L' ,                         'R' , 'R' , 'R' , 'R' , 'R' , 'R' ,
      'L' , 'L' , 'L' , 'L' , 'L' , 'L' , '*' , '*' , '*' , '*' , 'R' , 'R' , 'R' , 'R' , 'R' , 'R' ,
                        '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*' , '*', '*'
     );

// clang-format on

uint8_t mod_state;
uint8_t one_shot_mod_state;

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    mod_state          = get_mods();
    one_shot_mod_state = get_oneshot_mods();

    const bool alt = mod_state & MOD_MASK_ALT;

    if (!process_de_diacritics(keycode, record)) {
        return false;
    }

    switch (keycode) {
        case TG_OS:
            if (record->event.pressed) {
                user_config.macos ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;
        case GUI_TAB:
            if (record->event.pressed) {
                tap_code16(user_config.macos ? RGUI(KC_TAB) : LALT(KC_TAB));
            }
            return false;
        case GUI_GRV:
            if (record->event.pressed) {
                tap_code16(user_config.macos ? RGUI(KC_GRV) : LALT(KC_GRV));
            }
            return false;
        case UNDO:
            if (record->event.pressed) {
                tap_code16(user_config.macos ? LGUI(KC_Z) : LCTL(KC_Z));
            }
            return false;
        case REDO:
            if (record->event.pressed) {
                tap_code16(user_config.macos ? LGUI(LSFT(KC_Z)) : LCTL(LSFT(KC_Z)));
            }
            return false;
        case XCASE:
            enable_xcase_with(KC_UNDS);
            return false;
        case CAPSWORD:
            enable_xcase_with(KC_UNDS);
            caps_word_on();
            return false;
        case LOCK:
            if (record->event.pressed) {
                if (user_config.macos) {
                    tap_code16(QK_LCTL | QK_LGUI | KC_Q);
                } else {
                    tap_code16(QK_LGUI | KC_L);
                }
            }
            break;
        case LARGE_RIGHT_ARROW:
            if (record->event.pressed) {
                del_mods(MOD_MASK_CSAG);
                del_oneshot_mods(MOD_MASK_CSAG);
                send_string((!alt) ? "=>" : "<=>");
                add_mods(mod_state);
                add_oneshot_mods(one_shot_mod_state);
            }
            break;
        case SMALL_RIGHT_ARROW:
            if (record->event.pressed) {
                del_mods(MOD_MASK_CSAG);
                del_oneshot_mods(MOD_MASK_CSAG);
                send_string((!alt) ? "->" : "<->");
                add_mods(mod_state);
                add_oneshot_mods(one_shot_mod_state);
            }
            break;
        case SMALL_LEFT_ARROW:
            if (record->event.pressed) {
                del_mods(MOD_MASK_CSAG);
                del_oneshot_mods(MOD_MASK_CSAG);
                send_string("<-");
                add_mods(mod_state);
                add_oneshot_mods(one_shot_mod_state);
            }
            break;
        case PIPE_TO:
            if (record->event.pressed) {
                send_string("|>");
            }
            break;
        case LESS_THAN:
            if (record->event.pressed) {
                del_mods(MOD_MASK_CSAG);
                del_oneshot_mods(MOD_MASK_CSAG);
                send_string("<=");
                add_mods(mod_state);
                add_oneshot_mods(one_shot_mod_state);
            }
            break;
        case GREATER_THAN:
            if (record->event.pressed) {
                del_mods(MOD_MASK_CSAG);
                del_oneshot_mods(MOD_MASK_CSAG);
                send_string(">=");
                add_mods(mod_state);
                add_oneshot_mods(one_shot_mod_state);
            }
            break;
        case HOME_HASH:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_HASH);
                return false;
            }
            break;
        case HOME_AMPR:
            if (record->tap.count && record->event.pressed) {
                tap_code16(KC_AMPR);
                return false;
            }
            break;
        case ELVIS_OPERATOR:
            if (record->event.pressed) {
                send_string("?:");
            }
            break;
    }

    return true;
};

bool caps_word_press_user(uint16_t keycode) {
    switch (keycode) {
        // Keycodes that continue Caps Word, with shift applied.
        case KC_A ... KC_Z:
        case KC_MINS:
            add_weak_mods(MOD_BIT(KC_LSFT)); // Apply shift to next key.
            return true;

            // Keycodes that continue Caps Word, without shifting.
        case KC_1 ... KC_0:
        case KC_BSPC:
        case KC_DEL:
        case KC_UNDS:
        case DE_AE:
        case DE_UE:
        case DE_OE:
            return true;

        default:
            return false; // Deactivate Caps Word.
    }
}

bool use_default_xcase_separator(uint16_t keycode, const keyrecord_t* record) {
    switch (keycode) {
        case KC_A ... KC_Z:
        case KC_1 ... KC_0:
            return true;
    }
    return false;
}

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
    switch (tap_hold_keycode) {
        case HOME_T:
            if (other_keycode == KC_M) {
                return true;
            }
            break;

        case HOME_E:
            if (other_keycode == KC_DOT) {
                return true;
            }
            break;

        case DE_L:
            if (other_keycode == SFT_D || other_keycode == KC_F || other_keycode == HOME_S ||
                other_keycode == KC_V) {
                return true;
            }
            break;
    }
    return get_chordal_hold_default(tap_hold_record, other_record);
}

bool get_speculative_hold(uint16_t keycode, keyrecord_t* record) {
    return true;
}

// clang-format off

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_VOLD, KC_VOLU),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN),  ENCODER_CCW_CW(KC_PGUP, KC_PGDN)  },
    [1] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [2] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [3] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [4] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [5] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
    [6] = { ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______),  ENCODER_CCW_CW(_______, _______)  },
};
#endif
