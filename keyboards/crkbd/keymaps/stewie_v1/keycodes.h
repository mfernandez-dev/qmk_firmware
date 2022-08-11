#pragma once

enum layers {
    _QWERTY,    
    _QWERT2,
    _LOWER,
    _RAISE,
    _FUNCT

};

enum tapDance {
    TD_FLT,
    TD_SCL,
    TD_GLA
};
// Activate layer while keystroke
#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define FUNCT MO(_FUNCT)

// Change de base layout
#define DISC  TO(_QWERT2)
#define QWERT TO(_QWERTY)

#define AUT_GEN A(KC_INS) //alt + insert autogenerado intellij
#define HOT_SW C(KC_F9)   //ctrl + f9 hot-swap intellij
#define RST_SRV S(KC_F9)  //shif + f9 start or restart debug intellij

#define CH_LAN A(KC_LSFT) //alt + shift cambio idioma windows

// POWER TOYS
#define WN_LCK G(C(KC_T)) //win + shift + T Bloquear ventana al frente
#define PK_CLR G(S(KC_C)) //win + shift + C Selector de color

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_FLT] = ACTION_TAP_DANCE_DOUBLE(KC_F13, KC_LALT),   // one tap f13, two taps alt
    [TD_GLA] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_LALT)   // one tap win, tow taps alt
};
