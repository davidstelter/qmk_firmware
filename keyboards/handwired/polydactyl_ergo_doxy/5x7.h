#pragma once

#include "dactyl_manuform.h"
#include "quantum.h"

#ifdef USE_I2C
#include <stddef.h>
#ifdef __AVR__
  #include <avr/io.h>
  #include <avr/interrupt.h>
#endif
#endif

#define LAYOUT_5x7( \
    L17, L16, L15, L14, L13, L12, L11,      \
    L27, L26, L25, L24, L23, L22, L21,      \
    L37, L36, L35, L34, L33, L32, L31,      \
    L47, L46, L45, L44, L43, L42,           \
    L57, L56, L55, L54,                     \
                        L53, L52,           \
                                  L62, L61, \
                                  L64, L63, \
                                            \
         R11, R12, R13, R14, R15, R16, R17, \
         R21, R22, R23, R24, R25, R26, R27, \
         R31, R32, R33, R34, R35, R36, R37, \
              R42, R43, R44, R45, R46, R47, \
                        R54, R55, R56, R57, \
              R52, R53,                     \
    R61, R62,                               \
    R63, R64                                \
  ) \
    \
  { \
    {   L11, L12,   L13, L14,   L15,   L16,   L17 }, \
    {   L21, L22,   L23, L24,   L25,   L26,   L27 }, \
    {   L31, L32,   L33, L34,   L35,   L36,   L37 }, \
    { KC_NO, L42,   L43, L44,   L45,   L46,   L47 }, \
    { KC_NO, L52,   L53, L54,   L55,   L56,   L57 }, \
    {   L61, L62,   L63, L64, KC_NO, KC_NO, KC_NO }, \
	                                                 \
    {   R11, R12,   R13, R14,   R15,   R16,   R17 }, \
    {   R21, R22,   R23, R24,   R25,   R26,   R27 }, \
    {   R31, R32,   R33, R34,   R35,   R36,   R37 }, \
    { KC_NO, R42,   R43, R44,   R45,   R46,   R47 }, \
    { KC_NO, R52,   R53, R54,   R55,   R56,   R57 }, \
    {   R61, R62,   R63, R64, KC_NO, KC_NO, KC_NO }  \
}

