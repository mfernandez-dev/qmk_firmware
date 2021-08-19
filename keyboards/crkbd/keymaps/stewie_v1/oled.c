#pragma once

#include "split_util.h"

extern uint8_t is_master;



void render_status(void) {

    static const char PROGMEM mayus_logo[] = {0xb5, 0xb6, 0};
    static const char PROGMEM scroll_loc_logo[] = {0xd5, 0xd6, 0};

    static const char PROGMEM normal_layer[] = {0x97, 0x98, 0x99, 0x9a, 0};
    static const char PROGMEM num_layer[] = {0x9b, 0x9c, 0x9d, 0};
    static const char PROGMEM funct_layer[] = {0xb7, 0xb8, 0xb9, 0xba, 0};
    static const char PROGMEM symb_layer[] = {0xd7, 0xd8, 0xd9, 0xda, 0};

    static const char PROGMEM indicator[] = {0xbb, 0};

    oled_write_P(indicator, false);

    switch (get_highest_layer(layer_state))
    {
    case _QWERTY:
        oled_write_P(normal_layer, false);
        break;

    case _LOWER:
        oled_write_P(num_layer, false);
        oled_write_P(PSTR(" "), false);
        break;
    case _RAISE:
        oled_write_P(symb_layer, false);
        break;
    case _FUNCT:
        oled_write_P(funct_layer, false);
        break;
    default:
        oled_write_P(PSTR("UNDEF"), false);

    }
    // Host Keyboard LED Status
    oled_write_P(indicator, false);

    led_t led_state = host_keyboard_led_state();
    oled_write_P(led_state.caps_lock ? mayus_logo : PSTR("  "), false);
    oled_write_P(PSTR(""),false);
    oled_write_P(led_state.scroll_lock ? scroll_loc_logo : PSTR("  "), false);

}

oled_rotation_t oled_init_user (oled_rotation_t rotation) {
    // return OLED_ROTATION_180;
    return OLED_ROTATION_270;
}

static void eva_logo(void) {

    static const char PROGMEM eva_logo[] = {
      0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94, 0x80,
      0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4, 0xa0,
      0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4, 0xc0, 0xc0,
      0};

    oled_write_P(eva_logo, false);
}

static void nerv_logo(void) {
    static const char PROGMEM nerv_logo[] = {
         0x81, 0x82, 0x83, 0x84, 0x85,
         0xa1, 0xa2, 0xa3, 0xa4, 0xa5,
         0xc1, 0xc2, 0xc3, 0xc4, 0xc5,
         0};

    oled_write_P(nerv_logo, false);
}


void oled_task_user(void) {
    if (is_master) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        oled_write_ln_P(PSTR(" "),false);
        nerv_logo();
    } else {
        eva_logo();  // Renders a static logo
    }
}
