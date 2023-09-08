SRC += $(USER_PATH)/spacerock.c \
        $(USER_PATH)/callbacks/callbacks.c \
        $(USER_PATH)/features/taps/taps.c \
        $(USER_PATH)/keyrecords/process_records.c

-include $(USER_PATH)/features/rules.mk
# ┌─────────────────────────────────────────────────┐
# │ c o n t r o l l e r   f e a t u r e s           │
# └─────────────────────────────────────────────────┘

# Ignore some warnings during the build, likely to be fixed before RP2040 PR is merged
ALLOW_WARNINGS   = yes
# LTO must be disabled for RP2040 builds
LTO_ENABLE       = no

# ┌─────────────────────────────────────────────────┐
# │ h a r d w a r e   f e a t u r e s               │
# └─────────────────────────────────────────────────┘


ENCODER_ENABLE     ?= no
ENCODER_MAP_ENABLE ?= no
MOUSEKEY_ENABLE    ?= no       # Mouse keys
NKRO_ENABLE        ?= yes
SPLIT_KEYBOARD     ?= yes
SWAP_HANDS_ENABLE  ?= no

BACKLIGHT_ENABLE      = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE       = no        # Enable keyboard RGB underglow
RGB_MATRIX_ENABLE    ?= yes     # do not use together with RGBLIGHT_ENABLE
RGB_MATRIX_DRIVER    ?= WS2812 # RGB matrix driver support
RGBLIGHT_ENABLE      ?= no      # Enable keyboard RGB underglow
RGB_MATRIX_SUPPORTED ?= yes

# ┌─────────────────────────────────────────────────┐
# │ s o f t w a r e   f e a t u r e s               │
# └─────────────────────────────────────────────────┘

CONSOLE_ENABLE      ?= no       # Console for debug
EXTRAKEY_ENABLE     ?= yes	# multi media keys
KEY_OVERRIDE_ENABLE ?= no
MOUSEKEY_ENABLE     ?= no       # Mouse keys
OS_DETECTION_ENABLE ?= yes

AUTO_SHIFT_ENABLE    ?= no
# https://docs.qmk.fm/#/feature_caps_word
CAPS_WORD_ENABLE     ?= yes

# ┌─────────────────────────────────────────────────┐
# │ u t i l i t y                                   │
# └─────────────────────────────────────────────────┘

BOOTMAGIC_ENABLE ?= yes      # Enable Bootmagic Lite
ifeq ($(strip $(BOOTMAGIC_ENABLE)), yes)
	SRC += util/bootmagic_better.c
endif

COMMAND_ENABLE = no

# ┌─────────────────────────────────────────────────┐
# │ s e c r e t s                                   │
# └─────────────────────────────────────────────────┘

# include $(USER_PATH)/../../../qmk_secrets/rules.mk
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
