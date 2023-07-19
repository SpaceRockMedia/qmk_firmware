// Copyright 2020 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "tap_dances.h"

// Associate our tap dance key with its functionality
tap_dance_action_t tap_dance_actions[] = {
    [HYP_NAV] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, HYP_NAV_finished, HYP_NAV_reset),
    [MEH_NUM] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, MEH_SYM_finished, MEH_SYM_reset)
};
