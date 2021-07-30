#include "split_util.h"

#ifdef OLED_DRIVER_ENABLE

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
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }

    return rotation;
}

void oled_task_user(void) {
    if (is_keyboard_master()) {
        render_status();  // Renders the current keyboard state (layer, lock, caps, scroll, etc)
    } else {
        // render_logo();  // Renders a static logo
        oled_scroll_left();  // Turns on scrolling
    }
}


#endif
