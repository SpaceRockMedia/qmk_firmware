SRC += $(USER_PATH)/spacerock.c \
        $(USER_PATH)/callbacks.c \
        $(USER_PATH)/taps/taps.c

# ┌─────────────────────────────────────────────────┐
# │ f e a t u r e s                                 │
# └─────────────────────────────────────────────────┘

CALLUM_ENABLE ?= yes
ifeq ($(strip $(CALLUM_ENABLE)), yes)
	SRC += $(USER_PATH)/features/callum.c
	OPT_DEFS += -DCALLUM_ENABLE
endif

SWAPPER_ENABLE ?= yes
ifeq ($(strip $(SWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/swapper.c
	OPT_DEFS += -DSWAPPER_ENABLE
endif

SENTENCE_CASE_ENABLE ?= yes
ifeq ($(strip $(SENTENCE_CASE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/sentence_case.c
	OPT_DEFS += -DSENTENCE_CASE_ENABLE
endif

SRC += $(USER_PATH)/keyrecords/process_records.c

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

AUDIO_ENABLE       ?= no
MUSIC_ENABLE       ?= no
ENCODER_ENABLE     ?= no
ENCODER_MAP_ENABLE ?= no
MOUSEKEY_ENABLE    ?= no       # Mouse keys
NKRO_ENABLE        ?= yes
OLED_ENABLE        ?= yes
OLED_DRIVER        ?= SSD1306      # Enables the use of OLED displays
SPLIT_KEYBOARD     ?= yes
SWAP_HANDS_ENABLE  ?= no
WPM_ENABLE         ?= yes

ifeq ($(strip $(OLED_ENABLE)), yes)
	ifeq ($(strip $(WPM_ENABLE)), yes)
		WPM_SAMPLE_SECONDS = 15
	endif
	SRC += $(USER_PATH)/oled/oled.c
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

# ┌─────────────────────────────────────────────────┐
# │ s o f t w a r e   f e a t u r e s               │
# └─────────────────────────────────────────────────┘

CONSOLE_ENABLE      ?= no       # Console for debug
EXTRAKEY_ENABLE     ?= yes	# multi media keys
KEY_OVERRIDE_ENABLE ?= no
MOUSEKEY_ENABLE     ?= no       # Mouse keys
OS_DETECTION_ENABLE ?= yes

LEADER_ENABLE ?= yes
ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader.c
endif

REPEAT_KEY_ENABLE ?= yes
ifeq ($(strip $(REPEAT_KEY_ENABLE)), yes)
	SRC += $(USER_PATH)/keyrecords/repeat.c
endif

# tapping
TAP_DANCE_ENABLE            ?= yes
DYNAMIC_TAPPING_TERM_ENABLE ?= no
TAPPING_TERM_PER_KEY        ?= yes

AUTO_SHIFT_ENABLE    ?= no
# https://docs.qmk.fm/#/feature_caps_word
CAPS_WORD_ENABLE     ?= yes
COMBO_ENABLE         ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/combos/combos.c
	# SRC += $(USER_PATH)/keyrecords/combos.c
endif
DYNAMIC_MACRO_ENABLE ?= no

TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/taps/tap_dances.c
endif

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
