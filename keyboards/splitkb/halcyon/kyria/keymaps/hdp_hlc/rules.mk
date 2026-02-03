ENCODER_MAP_ENABLE = yes
CAPS_WORD_ENABLE = yes
LAYER_LOCK_ENABLE = yes
COMBO_ENABLE = yes
AUTO_SHIFT_ENABLE = yes

VPATH += keyboards/gboards

SRC += autoshift.c
SRC += de_diacritics.c

# This adds module functionality to your keyboard (files found in users/halcyon_modules)
USER_NAME := halcyon_modules
