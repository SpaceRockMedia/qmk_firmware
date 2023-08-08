// Copyright 2021 Christopher Courtney, aka Drashna Jael're  (@drashna) <drashna@live.com>
// SPDX-License-Identifier: GPL-2.0-or-later

#include "spacerock.h"

#ifdef SENTENCE_CASE_ENABLED
void sentence_case_primed(bool primed) {
  // Change B0 to the pin for the LED to use.
  writePin(L21, primed);
}
#endif
