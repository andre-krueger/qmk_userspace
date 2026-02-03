#pragma once

#include QMK_KEYBOARD_H

void handle_mac_umlaut(void);
bool process_de_diacritics(uint16_t keycode, keyrecord_t *record);
