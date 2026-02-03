#include "de_diacritics.h"
#include "keycodes.h"
#include "keymap.h"

void handle_mac_umlaut() {
    mod_state          = get_mods();
    one_shot_mod_state = get_oneshot_mods();

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

bool process_de_diacritics(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case DE_S:
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_S);
                return false;
            } else if (record->event.pressed) {
                tap_code16(QK_RALT | KC_S);
                return false;
            }
        case ACU_ACC: {
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_E);
                return false;
            }
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_QUOT);
                return false;
            }
        }
        case GRV_ACC: {
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_GRAVE);
                return false;
            }
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_GRAVE);
                return false;
            }
        }
        case CIRC: {
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_I);
                return false;
            }
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_6);
                return false;
            }
        }
        case TILDE: {
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_N);
                return false;
            }
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_TILD);
                return false;
            }
        }
        case DIAE: {
            if (record->event.pressed && user_config.macos) {
                tap_code16(QK_RALT | KC_U);
                return false;
            }
            if (record->event.pressed) {
                tap_code16(QK_RALT | KC_DQT);
                return false;
            }
        }
        case DE_AE:
            if (record->event.pressed) {
                if (user_config.macos) {
                    handle_mac_umlaut();
                    tap_code(KC_A);
                } else {
                    if (is_caps_word_on()) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                    }
                    tap_code16(QK_RALT | KC_A);
                }
                return false;
            }
        case DE_OE:
            if (record->event.pressed) {
                if (user_config.macos) {
                    handle_mac_umlaut();
                    tap_code(KC_O);
                } else {
                    if (is_caps_word_on()) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                    }
                    tap_code16(QK_RALT | KC_O);
                }
                return false;
            }
        case DE_UE:
            if (record->event.pressed) {
                if (user_config.macos) {
                    handle_mac_umlaut();
                    tap_code(KC_U);
                } else {
                    if (is_caps_word_on()) {
                        add_weak_mods(MOD_BIT(KC_LSFT));
                    }
                    tap_code16(QK_RALT | KC_U);
                }
                return false;
            }
    }

    return true;
}
