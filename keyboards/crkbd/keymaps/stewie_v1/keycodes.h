#pragma once

enum layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _FUNCT
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)

#define AUT_GEN A(KC_INS) //alt + insert autogenerado intellij
#define HOT_SW C(KC_F9)   //ctrl + f9 hot-swap intellij

#define CH_LAN A(KC_LSFT) //alt + shift cambio idioma windows
