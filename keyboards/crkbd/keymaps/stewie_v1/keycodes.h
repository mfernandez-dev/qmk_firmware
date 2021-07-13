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

