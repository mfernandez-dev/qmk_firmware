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

#define ALT_A MT(MOD_RALT, KC_A) //funcion como alt cuando se mantiene pulsado y como TAB al pulsar una vez

#define AUT_GEN A(KC_INS) //alt + insert autogenerado intellij
#define HOT_SW C(KC_F9)   //ctrl + f9 hot-swap intellij
#define RST_SRV S(KC_F9)  //shif + f9 start or restart debug intellij

#define CH_LAN A(KC_LSFT) //alt + shift cambio idioma windows
