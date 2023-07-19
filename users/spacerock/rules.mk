SRC += $(USER_PATH)/spacerock.c \
        $(USER_PATH)/callbacks.c \
        $(USER_PATH)/keyrecords/process_records.c \
        $(USER_PATH)/keyrecords/tapping.c

# ┌─────────────────────────────────────────────────┐
# │ c o n t r o l l e r   f e a t u r e s           │
# └─────────────────────────────────────────────────┘

# I generally use rp2040 for everything
CONVERT_TO       = promicro_rp2040
# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS   = yes
# LTO must be disabled for RP2040 builds
LTO_ENABLE       = no
BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite

# ┌─────────────────────────────────────────────────┐
# │ h a r d w a r e   f e a t u r e s               │
# └─────────────────────────────────────────────────┘

ENCODER_ENABLE     ?= yes
ENCODER_MAP_ENABLE ?= yes
MOUSEKEY_ENABLE    ?= no       # Mouse keys
NKRO_ENABLE        ?= yes
OLED_ENABLE        ?= yes
OLED_DRIVER        ?= SSD1306      # Enables the use of OLED displays
SPLIT_KEYBOARD     ?= yes
SWAP_HANDS_ENABLE  ?= yes

ifeq ($(strip $(OLED_ENABLE)), yes)
	SRC += $(USER_PATH)/oled/oled_stuff.c
    # DEFERRED_EXEC_ENABLE = yes
endif

BACKLIGHT_ENABLE      = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE       = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE    ?= yes     # do not use together with RGBLIGHT_ENABLE
RGB_MATRIX_DRIVER    ?= WS2812 # RGB matrix driver support
RGBLIGHT_ENABLE      ?= no      # Enable keyboard RGB underglow
RGB_MATRIX_SUPPORTED ?= yes

ifeq ($(strip $(RGB_MATRIX_ENABLE)), yes)
	SRC += $(USER_PATH)/rgb/rgb_matrix_stuff.c
	OPT_DEFS += -DCUSTOM_RGB_MATRIX
endif

ifdef KEYBOARD_klor
	HAPTIC_DRIVER = DRV2605L
endif

# ┌─────────────────────────────────────────────────┐
# │ s o f t w a r e   f e a t u r e s               │
# └─────────────────────────────────────────────────┘

CONSOLE_ENABLE      ?= yes       # Console for debug
EXTRAKEY_ENABLE     ?= yes	# multi media keys
KEY_OVERRIDE_ENABLE ?= yes
MOUSEKEY_ENABLE     ?= no       # Mouse keys
OS_DETECTION_ENABLE ?= yes

# AUTO_SHIFT_ENABLE = yes
CAPS_WORD_ENABLE     ?= yes
COMBO_ENABLE         ?= yes
DYNAMIC_MACRO_ENABLE ?= yes

TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/keyrecords/tap_dances.c
endif

ifeq ($(strip $(OLED_ENABLE)), yes)
	WPM_ENABLE         = yes
	WPM_SAMPLE_SECONDS = 15
endif

# ┌─────────────────────────────────────────────────┐
# │ s e c r e t s                                   │
# └─────────────────────────────────────────────────┘

include $(USER_PATH)/../../../qmk_secrets/rules.mk
# ifneq ($(strip $(NO_SECRETS)), yes)
#     ifneq ("$(wildcard $(USER_PATH)/../../../qmk_secrets/secrets.c)","")
#         SRC += $(USER_PATH)/../../../qmk_secrets/secrets.c
#         $(shell touch $(USER_PATH)/../../../qmk_secrets/secrets.c)
#         SECURE_ENABLE = yes
#     endif
#     ifeq ($(strip $(NO_SECRETS)), lite)
#         OPT_DEFS += -DNO_SECRETS
#     endif
# endif
