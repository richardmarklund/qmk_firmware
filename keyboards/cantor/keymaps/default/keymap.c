// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

enum layers {
    _QWERTY = 0,
    _NUM,
    _SIGN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ESC│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ Å │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ O │ Ä │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ ,;│ .:│'* │ +?│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Opt│
      *               └───┤Tab├───┐   ┌───┤Bsp├───┘
      *                   └───┤Ent│   │Spc├───┘
      *                       │Num├───┤Sgn│
      *                       └───┘   └───┘
      */                        
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                               KC_Y,            KC_U,     KC_I,    KC_O,    KC_P,    KC_LBRC ,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                               KC_H,            KC_J,     KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,                               KC_N,            KC_M,     KC_COMM, KC_DOT,  KC_BSLS, KC_MINS,
                                            KC_TAB,  KC_LGUI, LT(_NUM,KC_ENT),        LT(_SIGN,KC_SPC),KC_BSPC, KC_LEFT_ALT 
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ * │ ! │ @ │ { │ } │ = │       │   │ < │ > │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │ " │ ( │ ) │ - │       │ | │ & │ ; │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ % │ # │ [ │ ] │ _ │       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤ = │
      *               └───┤Bsp├───┐   ┌───┤TAB├───┘
      *                   └───┤Ent│   │   ├───┘
      *                       └───┘   └───┘
      */
    [_SIGN] = LAYOUT_split_3x6_3(
        SE_ASTR, KC_EXLM, SE_AT,   LALT(S(SE_8)), LALT(S(SE_9)), S(SE_0),                     KC_NO,  KC_GRV,     KC_TILD, KC_NO,    KC_NO, KC_NO,
        KC_NO,   KC_NO,   KC_AT,   KC_ASTR,       KC_LPRN,       SE_MINS,                     KC_LEFT,  KC_DOWN,  KC_UP,   KC_RIGHT, KC_NO, KC_NO,
        KC_NO,   KC_PERC, KC_HASH, LALT(SE_8),    LALT(SE_9),    SE_UNDS,                     KC_NO,  LALT(SE_7), SE_AMPR,  KC_SCLN,  KC_NO, KC_NO,
                                                  KC_LGUI,       KC_BSPC, KC_ENT,     KC_NO,  KC_TAB, S(SE_0)
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ * │ 7 │ 8 │ 9 │ - │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ / │ 4 │ 5 │ 6 │ + │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ 0 │ 1 │ 2 │ 3 │TAB│       │   │   │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │Bsp├───┐           ┌───┤   │
      *               └───┤Ent├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NUM] = LAYOUT_split_3x6_3(
        KC_NO, KC_PIPE, KC_7,    KC_8,    KC_9,    SE_MINS,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, S(SE_7), KC_4,    KC_5,    KC_6,    KC_MINS,                      KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
        KC_NO, KC_0,    KC_1,    KC_2,    KC_3,    KC_TAB,                       KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,
                                            KC_BSPC, KC_ENT, KC_NO ,      KC_NO, KC_NO, KC_NO 
    )
};