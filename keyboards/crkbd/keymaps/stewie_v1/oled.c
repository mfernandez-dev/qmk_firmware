#pragma once

#include "split_util.h"

extern uint8_t is_master;

void render_status(void) {

    oled_write_P(PSTR("LAYER\n"), false);

    switch (get_highest_layer(layer_state))
    {
    case _QWERTY:
        oled_write_P(PSTR("NORM\n\n"), false);
        break;

    case _LOWER:
        oled_write_P(PSTR("LOWER\n"), false);
        break;
    case _RAISE:
        oled_write_P(PSTR("RAISE\n"), false);
        break;
    case _FUNCT:
        oled_write_P(PSTR("FUNCT\n"), false);
        break;
    default:
        oled_write_ln_P(PSTR("UNDEF"), false);

    }
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? PSTR("CAP\n") : PSTR("   \n"), false);
    oled_write_P(led_state.scroll_lock ? PSTR("SCR\n ") : PSTR("   \n"), false);
}

oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    // return OLED_ROTATION_180;
    return OLED_ROTATION_270;
}

static void eva_logo(void) {

    static const char PROGMEM eva_logo[] = {
      0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
      0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
      0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
      0
      };

    oled_write_P(eva_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        render_my_logo();  // Renders a static logo
    }
}
