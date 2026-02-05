#include QMK_KEYBOARD_H
#include "keycodes.h"
#include "keymap.h"

bool get_custom_auto_shifted_key(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_UNDS:
        case BTM_DOT:
        case KC_COLN:
        case HOME_DQT:
        case BTM_QUOT:
        case BTM_EQL:
        case HOME_AMPR:
        case KC_PIPE:
        case KC_GRV:
        case KC_LABK:
        case KC_RABK:
        case KC_0:
        case KC_BSLS:
        case BTM_SLSH:
        case HOME_EXLM:
        case HOME_HASH:
        case COPY_CUT:
        case PASTE_PASTE_SPECIAL:
        case DE_AE:
        case DE_UE:
        case DE_OE:
        case KC_EQL:
        case KC_QUES:
            return true;
        default:
            return false;
    }
}

void autoshift_press_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        case KC_UNDS:
            if (!shifted) {
                tap_code16(KC_UNDS);
            } else {
                send_string("__");
            }
            break;
        case KC_COLN:
            if (!shifted) {
                tap_code16(KC_COLN);
            } else {
                send_string("::");
            }
            break;
        case HOME_DQT:
            if (!shifted) {
                tap_code16(KC_DQT);
            } else {
                send_string("\"\"\"");
            }
            break;
        case HOME_EXLM:
            if (!shifted) {
                tap_code16(KC_EXLM);
            } else {
                send_string("!=");
            }
            break;
        case BTM_QUOT:
            if (!shifted) {
                tap_code16(KC_QUOT);
            } else {
                send_string("'''");
            }
            break;
        case KC_GRV:
            if (!shifted) {
                tap_code16(KC_GRV);
            } else {
                send_string("```");
            }
            break;
        case KC_EQL:
            if (!shifted) {
                tap_code(KC_EQL);
            } else {
                send_string("==");
            }
            break;
        case KC_LABK:
            if (!shifted) {
                tap_code16(KC_LABK);
            } else {
                send_string("<<");
            }
            break;
        case KC_RABK:
            if (!shifted) {
                tap_code16(KC_RABK);
            } else {
                send_string(">>");
            }
            break;
        case KC_BSLS:
            if (!shifted) {
                tap_code16(KC_BSLS);
            } else {
                send_string("\\");
            }
            break;
        case BTM_SLSH:
            if (!shifted) {
                tap_code16(KC_SLSH);
            } else {
                send_string("//");
            }
            break;
        case HOME_HASH:
            if (!shifted) {
                tap_code16(KC_HASH);
            } else {
                send_string("##");
            }
            break;
        case KC_QUES:
            if (!shifted) {
                tap_code16(KC_QUES);
            } else {
                send_string("??");
            }
            break;
        case BTM_EQL:
            if (!shifted) {
                tap_code16(KC_EQL);
            } else {
                send_string("==");
            }
            break;
        case HOME_AMPR:
            if (!shifted) {
                tap_code16(KC_AMPR);
            } else {
                send_string("&&");
            }
            break;
        case KC_PIPE:
            if (!shifted) {
                tap_code16(KC_PIPE);
            } else {
                send_string("||");
            }
            break;
        case KC_0:
            if (!shifted) {
                tap_code16(KC_0);
            } else {
                send_string("000");
            }
            break;
        case BTM_DOT:
            if (!shifted) {
                tap_code16(KC_DOT);
            } else {
                send_string("...");
            }
            break;
        case COPY_CUT:
            if (user_config.macos) {
                tap_code16((!shifted) ? G(KC_C) : G(KC_X));
            } else {
                tap_code16((!shifted) ? C(KC_C) : C(KC_X));
            }
            break;
        case PASTE_PASTE_SPECIAL:
            if (user_config.macos) {
                tap_code16((!shifted) ? G(KC_V) : S(G(A(KC_V))));
            } else {
                tap_code16((!shifted) ? C(KC_V) : S(C(KC_V)));
            }
            break;
        default:
            if (shifted) {
                add_weak_mods(MOD_BIT(KC_LSFT));
            }
            register_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}

void autoshift_release_user(uint16_t keycode, bool shifted, keyrecord_t *record) {
    switch (keycode) {
        default:
            unregister_code16((IS_RETRO(keycode)) ? keycode & 0xFF : keycode);
    }
}
