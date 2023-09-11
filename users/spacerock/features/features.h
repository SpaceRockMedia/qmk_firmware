// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once
#include QMK_KEYBOARD_H

#include "keycodes/keycodes.h"
#include "features/callbacks.h"
#include "features/process_records.h"

#ifdef LEADER_ENABLE
#    include "features/callum/callum.h"
#    include "features/callum/swapper.h"
#endif

#ifdef LEADER_ENABLE
#    include "features/leader/leader.h"
#endif

#ifdef FEATURE_REPEAT_KEY_ENABLE
#    include "features/repeat_key/repeat_key.h"
#endif

#ifdef FEATURE_SENTENCE_CASE_ENABLE
#    include "features/sentence_case/sentence_case.h"
#endif

#ifdef TAP_DANCE_ENABLE
#    include "features/taps/tap_dances.h"
#endif

#ifdef OLED_ENABLE
#    include "features/oled/oled.h"
#endif
