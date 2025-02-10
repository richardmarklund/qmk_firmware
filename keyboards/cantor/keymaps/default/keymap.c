// Copyright 2022 Diego Palacios (@diepala)
// SPDX-License-Identifier: GPL-2.0

#include QMK_KEYBOARD_H
#include "keymap_swedish.h"

    enum layers {
        _QWERTY = 0,
        _NUM,
        _SIGN,
    };
    const uint16_t PROGMEM one_shot_sign_combo[] = {KC_U, KC_I, COMBO_END};
    const uint16_t PROGMEM sign_combo[] = {KC_M, KC_COMM, COMBO_END};
    const uint16_t PROGMEM one_shot_num_combo[] = {KC_Y, KC_U, COMBO_END};
    const uint16_t PROGMEM num_combo[] = {KC_N, KC_M, COMBO_END};
    const uint16_t PROGMEM f1_combo[] = {KC_F, KC_G, COMBO_END};

        combo_t key_combos[] = {
            COMBO(one_shot_sign_combo, OSL(_SIGN)),
            COMBO(sign_combo, TG(_SIGN)),
            COMBO(one_shot_num_combo, OSL(_NUM)),
            COMBO(num_combo, TG(_NUM)),
            COMBO(f1_combo, TG(_SIGN)),
        };

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │ESC│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │ Å │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │SFT│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ O │ Ä │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ Z │ X │ C │ V │ B │       │ N │ M │ ,;│ .:│'* │ +?│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │TAB├───┐           ┌───┤F1 │
      *               └───┤BSP├───┐   ┌───┤Opt├───┘
      *                   |GUI|Ent│   │Spc│   |
      *                   └───┤   ├───┤   ├───┘
      *                       └───┘   └───┘
      */
    [_QWERTY] = LAYOUT_split_3x6_3(
        KC_ESC,         KC_Q,      KC_W,    KC_E,    KC_R,    KC_T,                                                      KC_Y,        KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC ,
        KC_LSFT,       KC_A,      KC_S,    KC_D,    KC_F,    KC_G,                                                      KC_H,        KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LCTL,        KC_Z,      KC_X,    KC_C,    KC_V,    KC_B,                                                      KC_N,        KC_M,    KC_COMM, KC_DOT,  KC_BSLS, KC_MINS,
                                            KC_TAB,  LGUI_T(KC_BSPC), KC_ENT,                                    KC_SPC, LALT_T(KC_NUM_LOCK),KC_F1
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ ! │ @ │ { │ } │ = │       │ = │ < │ > │ ~ │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ * │ " │ ( │ ) │ - │       │ ; │ / │ \ │ | │ & │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ctr│ % │ # │ [ │ ] │ _ │       │   │ M │,; │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │TAB├───┐           ┌───┤ F1│
      *               └───┤BSP├───┐   ┌───┤Opt├───┘
      *                   |GUI|Ent│   │Spc│   |
      *                   └───┤Num├───┤Sgn├───┘
      *                       └───┘   └───┘
      */
    [_SIGN] = LAYOUT_split_3x6_3(
        TO(0), KC_EXLM, SE_AT,   LALT(S(SE_8)), LALT(S(SE_9)), S(SE_0),                     S(SE_0),    KC_GRV,  KC_TILD,       SE_TILD,    KC_NO,   KC_NO,
        KC_NO, SE_ASTR, KC_AT,   KC_ASTR,       KC_LPRN,       SE_MINS,                     S(KC_COMM), S(SE_7), LALT(S(SE_7)), LALT(SE_7), SE_AMPR, KC_NO,
        KC_LCTL, KC_PERC, KC_HASH, LALT(SE_8),    LALT(SE_9),    SE_UNDS,                     KC_NO,    KC_M, KC_COMM,           KC_NO,      KC_NO,   KC_NO,
                                                KC_TAB, LGUI_T(KC_BSPC), KC_ENT,     KC_SPC,  KC_TAB, KC_F1
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ * │ 7 │ 8 │ 9 │ - │       │   │   │   │   │   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ / │ 4 │ 5 │ 6 │ + │       │Lft│Up │Dwn│Rgt│   │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │ctr│ 0 │ 1 │ 2 │ 3 │TAB│       │ N │ M │   │   │   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │TAB├───┐           ┌───┤ F1│
      *               └───┤BSP├───┐   ┌───┤Opt├───┘
      *                   |GUI|Ent│   │Spc│   |
      *                   └───┤Num├───┤Sgn├───┘
      *                       └───┘   └───┘
      */
    [_NUM] = LAYOUT_split_3x6_3(
        TO(0), KC_PIPE, KC_7,    KC_8,    KC_9,    SE_MINS,                      KC_NO,   KC_NO,   KC_NO, KC_NO,    KC_NO, KC_NO,
        KC_NO, S(SE_7), KC_4,    KC_5,    KC_6,    KC_MINS,                      KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_NO, KC_NO,
        KC_LCTL, KC_0,    KC_1,    KC_2,    KC_3,    KC_TAB,                       KC_N,    KC_M,    KC_NO, KC_NO,    KC_NO, KC_NO,
                                   KC_TAB, LGUI_T(KC_BSPC), KC_ENT,      KC_SPC, KC_NO, KC_F1
    )
};
