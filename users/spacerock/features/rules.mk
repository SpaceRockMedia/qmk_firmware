
FEATURE_CALLUM_ENABLE ?= no
ifeq ($(strip $(FEATURE_CALLUM_ENABLE)), yes)
	SRC += $(USER_PATH)/features/callum/callum.c
	OPT_DEFS += -DFEATURE_CALLUM_ENABLE
endif

FEATURE_SWAPPER_ENABLE ?= yes
ifeq ($(strip $(FEATURE_SWAPPER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/callum/swapper.c
	OPT_DEFS += -DFEATURE_SWAPPER_ENABLE
endif

FEATURE_REPEAT_KEY_ENABLE ?= yes
ifeq ($(strip $(FEATURE_REPEAT_KEY_ENABLE)), yes)
	SRC += $(USER_PATH)/features/repeat_key/callbacks.c
	SRC += $(USER_PATH)/features/repeat_key/repeat_key.c
	OPT_DEFS += -DFEATURE_REPEAT_KEY_ENABLE
endif

FEATURE_SENTENCE_CASE_ENABLE ?= yes
ifeq ($(strip $(FEATURE_SENTENCE_CASE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/sentence_case/sentence_case.c
	OPT_DEFS += -DFEATURE_SENTENCE_CASE_ENABLE
endif

LEADER_ENABLE ?= yes
ifeq ($(strip $(LEADER_ENABLE)), yes)
	SRC += $(USER_PATH)/features/leader/leader.c
endif

COMBO_ENABLE ?= yes
ifeq ($(strip $(COMBO_ENABLE)), yes)
	VPATH += keyboards/gboards
	INTROSPECTION_KEYMAP_C = $(USER_PATH)/features/combos/combos.c
endif

AUDIO_ENABLE ?= yes
ifeq ($(strip $(AUDIO_ENABLE)), yes)
	MUSIC_ENABLE ?= no
# 	SRC += $(USER_PATH)/features/audio/udio.c
endif

OLED_ENABLE        ?= yes
ifeq ($(strip $(OLED_ENABLE)), yes)
	OLED_DRIVER ?= SSD1306
	WPM_ENABLE ?= yes
	ifeq ($(strip $(WPM_ENABLE)), yes)
		WPM_SAMPLE_SECONDS = 15
	endif
	SRC += $(USER_PATH)/features/oled/oled.c
    # DEFERRED_EXEC_ENABLE = yes
endif

TAP_DANCE_ENABLE ?= yes
ifeq ($(strip $(TAP_DANCE_ENABLE)), yes)
	SRC += $(USER_PATH)/features/taps/tap_dances.c
endif

# tapping
DYNAMIC_TAPPING_TERM_ENABLE ?= no
TAPPING_TERM_PER_KEY        ?= yes
