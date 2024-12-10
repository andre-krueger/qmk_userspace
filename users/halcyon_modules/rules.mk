CURRENT_DIR := $(dir $(realpath $(lastword $(MAKEFILE_LIST))))

SRC += halcyon.c

LTO_ENABLE ?= yes

# May need to be changed when adding more pointing devices
POINTING_DEVICE_ENABLE = yes
POINTING_DEVICE_DRIVER = cirque_pinnacle_spi

# May need to be changed when adding more displays
QUANTUM_PAINTER_ENABLE = yes
QUANTUM_PAINTER_DRIVERS += st7789_spi surface

BACKLIGHT_ENABLE = yes
BACKLIGHT_DRIVER = pwm

ifdef HLC_ENCODER
  include $(CURRENT_DIR)/hlc_encoder/rules.mk
endif

ifdef HLC_TFT_DISPLAY
  include $(CURRENT_DIR)/hlc_tft_display/rules.mk
endif

ifdef HLC_CIRQUE_TRACKPAD
  include $(CURRENT_DIR)/hlc_cirque_trackpad/rules.mk
endif

HLC_OPTIONS := $(HLC_NONE) $(HLC_CIRQUE_TRACKPAD) $(HLC_ENCODER) $(HLC_TFT_DISPLAY)

ifeq ($(filter 1, $(HLC_OPTIONS)), )
$(error Wrong or no module specified. Please specify one of the following: HLC_NONE, HLC_CIRQUE_TRACKPAD, HLC_ENCODER or HLC_TFT_DISPLAY.)
endif
