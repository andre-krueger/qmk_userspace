#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _MAC = 0,
    _SYM,
    _NUM,
    _NAV,
    _FUN,
    _DE_DIA,
    _ADJUST,
};

enum custom_keycodes {
    DE_AE = QK_USER,
    TG_OS,
    GUI_TAB,
    GUI_GRV,
    XCASE,
    CAPSWORD,
    DE_OE,
    DE_UE,
    DE_S,
    ACU_ACC,
    GRV_ACC,
    TILDE,
    DIAE,
    CIRC,
    LOCK,
    LARGE_RIGHT_ARROW,
    SMALL_RIGHT_ARROW,
    SMALL_LEFT_ARROW,
    PIPE_TO,
    LESS_THAN,
    GREATER_THAN,
    UNDO,
    COPY_CUT,
    PASTE_PASTE_SPECIAL,
    REDO,
    ELVIS_OPERATOR,
};

#define ADJUST MO(_ADJUST)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_RSFT OSM(MOD_RSFT)
#define SYM_ESC LT(_SYM, KC_ESC)
#define SYM_COLN LT(_SYM, KC_COLN)
#define RGUI_SPC RGUI_T(KC_SPC)
#define DE_L LT(_DE_DIA, KC_L)
#define FUN_U LT(_FUN, KC_U)

#define SFT_D LSFT_T(KC_D)
#define SFT_O RSFT_T(KC_O)

// Left-hand home row mods base layer
#define HOME_S LALT_T(KC_S)
#define HOME_N LCTL_T(KC_N)
#define HOME_T LT(_NAV, KC_T)
#define HOME_H LGUI_T(KC_H)

// Right-hand home row mods base layer
#define HOME_A RGUI_T(KC_A)
#define HOME_E LT(_NUM, KC_E)
#define HOME_I RCTL_T(KC_I)
#define HOME_C LALT_T(KC_C)

// Left-hand home row mods num layer
#define HOME_2 LT(_NAV, KC_2)

// Left-hand home row mods sym layer
#define HOME_HASH LALT_T(KC_HASH)
#define HOME_EXLM LCTL_T(KC_EXLM)
#define HOME_PERC KC_PERC
#define HOME_ASTR KC_ASTR

// Right-hand home row mods sym layer
#define HOME_LPRN KC_LPRN
#define HOME_RPRN KC_RPRN
#define HOME_AMPR RCTL_T(KC_AMPR)
#define HOME_DQT LALT_T(KC_DQT)
