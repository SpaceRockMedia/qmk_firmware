#pragma once

// Plug USB into the left half of the keyboard
// see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
// #define MASTER_LEFT
#undef SPLIT_HAND_MATRIX_GRID
// #define EE_HANDS

#ifdef RGB_MATRIX_ENABLE

#define RGB_DI_PIN 25
#define RGB_DISABLE_WHEN_USB_SUSPENDED     // turn off effects when suspended
#define RGB_MATRIX_TIMEOUT 300000          // timeout in ms, 5 min
#define SPLIT_TRANSPORT_MIRROR             // If LED_MATRIX_KEYPRESSES or LED_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR
#define RGB_MATRIX_MAXIMUM_BRIGHTNESS 100  // limits maximum brightness of LEDs (max 255). Higher may cause the controller to crash.
#define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_TYPING_HEATMAP

// Animations
// Uncomment any that you want to try. Limited by
// space on the microcontroller. The defines below mirror
// the order they animations will cycle through.

// These modes don’t require any additional defines
#define ENABLE_RGB_MATRIX_ALPHAS_MODS

// These modes require the RGB_MATRIX_FRAMEBUFFER_EFFECTS define
#define RGB_MATRIX_FRAMEBUFFER_EFFECTS
#define ENABLE_RGB_MATRIX_TYPING_HEATMAP
// #define ENABLE_RGB_MATRIX_DIGITAL_RAIN

#endif
