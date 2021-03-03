#include QMK_KEYBOARD_H


#define _BASE 0
#define _LEFT 1
#define _NMBR 2
#define _PNCT 3

// Fillers to make layering more clear

#define ____ KC_TRNS

#define GUI_ESC  GUI_T(KC_ESC)
#define CTL_SPC  CTL_T(KC_SPC)
#define ALT_ENT  ALT_T(KC_ENT)

#define LEFT  MO(_LEFT)
#define NMBR  MO(_NMBR)
#define PNCT  MO(_PNCT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Base (qwerty - right)
 *               ,----------------------------------,
 *               |   y  |   u  |   i  |   o  |   p  |
 *               |-------------+------+------+------|
 *               |   h  |   j  |   k  |   l  |   ;  |
 *               |------|------+------+------+------|
 *               |   n  |   m  |   ,  |   .  |   '  |
 *               ,-------------+------+------+------,
 *                             |   -  |   =  |
 *               '-------------'------+------'
 *               | SPACE|ENTER |
 *               |  +   |  +   |
 *               | CTL  | ALT  |
 *               '------+------'
 * '------+------'
 * | Pnct | Left |
 * '------+------'
 * | GUI  | Nmbr |
 * |  +   |      |
 * | ESC  |      |
 * '------+------'
 */

[_BASE] = LAYOUT( \
                     KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    \
                     KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, \
                     KC_N, KC_M,    KC_COMM, KC_DOT, KC_QUOT, \
                           KC_MINS, KC_EQL,                   \
   CTL_SPC, ALT_ENT,                                          \
   PNCT,    LEFT,                                             \
   GUI_ESC, NMBR
),

/* Left (qwerty)
 *               ,----------------------------------,
 *               |   t  |   r  |   e  |   w  |   q  |
 *               |-------------+------+------+------|
 *               |   g  |   f  |   d  |   s  |   a  |
 *               |------|------+------+------+------|
 *               |   b  |   v  |   c  |   x  |   z  |
 *               ,-------------+------+------+------,
 *                             |   [  |   ]  |
 *               '-------------'------+------'
 *               |      |      |
 *               |      |      |
 *               |      |      |
 *               '------+------'
 * '------+------'
 * |      |      |
 * '------+------'
 * |      |      |
 * '------+------'
 */

[_LEFT] = LAYOUT( \
                     KC_T, KC_R,    KC_E,    KC_W,   KC_Q,    \
                     KC_G, KC_F,    KC_D,    KC_S,   KC_A,    \
                     KC_B, KC_V,    KC_C,    KC_X,   KC_Z,    \
                           KC_LBRC, KC_RBRC,                  \
  ____, ____,                                                 \
  ____, ____,                                                 \
  ____, ____                                                  \
),

/* Number
 *               ,----------------------------------,
 *               |  6   |  7   |  8   |  9   |  0   |
 *               |-------------+------+------+------|
 *               |  1   |  2   |  3   |  4   |  5   |
 *               |------|------+------+------+------|
 *               | HOME | PGDN | PGUP | END  |  BS  |
 *               ,-------------+------+------+------,
 *                             |  -   |  =   |
 *               '-------------'------+------'
 *               |      |      |
 *               |      |      |
 *               |      |      |
 *               '------+------'
 * '------+------'
 * |      |      |
 * '------+------'
 * |      |      |
 * '------+------'
 */

[_NMBR] = LAYOUT( \
              KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    \
              KC_1,    KC_2,     KC_3,    KC_4,    KC_5,    \
              KC_HOME, KC_PGDN,  KC_PGUP, KC_END,  KC_BSPC, \
                                 ____,    ____,             \
  ____, ____,                                               \
  ____, ____,                                               \
  ____, ____                                                \
),

/* Punctuation
 *               ,----------------------------------,
 *               |      |      |      |      | RST  |
 *               |-------------+------+------+------|
 *               |      |  `   |  \   |  /   |      |
 *               |------|------+------+------+------|
 *               |      |      |      |      |      |
 *               ,-------------+------+------+------,
 *                             |      |      |
 *               '-------------'------+------'
 *               |      |      |
 *               |      |      |
 *               |      |      |
 *               '------+------'
 * '------+------'
 * |      |      |
 * '------+------'
 * |      |      |
 * '------+------'
 */

[_PNCT] = LAYOUT( \
              ____,    ____,     ____,    ____,    RESET,   \
              ____,    KC_GRV,   KC_BSLS, KC_SLSH, ____,    \
              ____,    ____,     ____,    ____,    ____,    \
                                 ____,    ____,             \
  ____, ____,                                               \
  ____, ____,                                               \
  ____, ____                                                \
)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}
