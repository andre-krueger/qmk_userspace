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
#define RGUI_SPC RGUI_T(KC_SPC)
#define DE_L LT(_DE_DIA, KC_L)
#define FUN_U LT(_FUN, KC_U)

#define HOME_T LT(_NAV, KC_T)
#define HOME_H LT(_SYM, KC_H)

#define HOME_A LT(_SYM, KC_A)
#define HOME_E LT(_NUM, KC_E)

// Left-hand bottom row mods
#define BTM_V LALT_T(KC_V)
#define BTM_W LCTL_T(KC_W)
#define BTM_G LSFT_T(KC_G)
#define BTM_M LGUI_T(KC_M)

// Right-hand bottom row mods
#define BTM_DOT RGUI_T(KC_DOT)
#define BTM_SLSH RSFT_T(KC_SLSH)
#define BTM_EQL RCTL_T(KC_EQL)
#define BTM_QUOT LALT_T(KC_QUOT)

// Left-hand home row mods num layer
#define HOME_2 LT(_NAV, KC_2)

// Left-hand home row mods sym layer
#define HOME_HASH LALT_T(KC_HASH)
#define HOME_EXLM LCTL_T(KC_EXLM)
#define HOME_PERC LT(_NAV, KC_PERC)

// Right-hand home row mods sym layer
#define HOME_AMPR RCTL_T(KC_AMPR)
#define HOME_DQT LALT_T(KC_O)
#define HOME_RPRN LT(_NUM, KC_RPRN)