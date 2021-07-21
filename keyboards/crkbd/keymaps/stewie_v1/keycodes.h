#pragma once

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCT
};

enum tapDance {
    TD_FLT,
    TD_SCL
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)

#define AUT_GEN A(KC_INS) //alt + insert autogenerado intellij
#define HOT_SW C(KC_F9)   //ctrl + f9 hot-swap intellij
#define RST_SRV S(KC_F9)  //shif + f9 start or restart debug intellij

#define CH_LAN A(KC_LSFT) //alt + shift cambio idioma windows

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_FLT] = ACTION_TAP_DANCE_DOUBLE(KC_F13, KC_LALT),  // one tap f13, two taps alt
    [TD_SCL] = ACTION_TAP_DANCE_DOUBLE(KC_LSFT, KC_CAPS)  // one tap sift, two taps caps lock
};
