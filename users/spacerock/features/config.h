// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Tapping
#include "features/taps/config.h"

#ifdef SPLIT_KEYBOARD
#    include "features/split/config.h"
#endif

#ifdef FEATURE_LEADER_ENABLE
#    include "features/leader/config.h"
#endif

#ifdef AUDIO_ENABLE
#    include "features/audio/config.h"
#endif // AUDIO_ENABLE

#ifdef COMBO_ENABLE
#    include "features/combos/config.h"
#endif

#ifdef AUDIO_ENABLE
#    include "features/audio/config.h"
#endif

#ifdef OLED_ENABLE
#    include "features/oled/config.h"
#endif

#ifdef RGB_MATRIX_ENABLE
#    include "features/rgb/config.h"
#endif
