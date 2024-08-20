/* Copyright 2023 Brian Low
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H
#include "keymap_french.h"
#include "utils/tap_hold.c"

tap_dance_action_t tap_dance_actions[] = {
    // Tap once for Escape, twice for Caps Lock
    [TD_LOCK] = ACTION_TAP_DANCE_DOUBLE(KC_LCMD, LCA(FR_L)), /* windows key or ctrl+alt+L */
    [TD_COLN] = ACTION_TAP_HOLD(FR_COLN, FR_SCLN), /* : or ;*/
    [TD_COMM] = ACTION_TAP_HOLD(FR_COMM, FR_LABK), /* , or < */
    [TD_DOT] = ACTION_TAP_HOLD(FR_DOT, FR_RABK), /* . or > */
    [TD_MEDIA] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MNXT) /* Play or Next*/
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * TODO update the visual layout
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  Mute |    | Pause |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LCTL | LGUI | LCMD | LALT | /Enter  /       \Space \  | RALT | RCMD | RGUI | RCTL |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

/*
 LAYOUT(
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                         _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______,       _______, _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,                _______, _______, _______, _______, _______, _______,
)

 * */


[0] = LAYOUT(
    KC_ESC,   FR_1,   FR_2,    FR_3,    FR_4,    FR_5,                       FR_6,     FR_7,    FR_8,    FR_9,    FR_0,    KC_DEL,
    KC_TAB,   FR_Q,   FR_W,    FR_F,    FR_P,    FR_B,                       FR_J,     FR_L,    FR_O,    FR_Y,    TD(TD_COLN), FR_EQL,
    KC_LSFT,  MT(MOD_LCTL, FR_A),   MT(MOD_LALT, KC_R),MT(MOD_RALT, KC_S),MT(MOD_LSFT, KC_T),KC_G,                       FR_M,    MT(MOD_RSFT, KC_N),MT(MOD_RALT, KC_E),MT(MOD_LALT, KC_I),    MT(MOD_RCTL, FR_U), KC_QUOT,
    FR_DLR,   FR_Z,   FR_X,    FR_C,    FR_V,    FR_D,    KC_BTN1,           KC_BTN2,  FR_K,    FR_H,    TD(TD_COMM), TD(TD_DOT),  FR_EXLM, KC_CAPS,
                KC_LEFT, KC_RIGHT, TD(TD_LOCK), KC_SPC, KC_BSPC,                    TT(1),    KC_ENT,   TT(2),  KC_UP, KC_DOWN
    ),

[1] = LAYOUT(
       QK_LOCK,   KC_F1, KC_F2,   KC_F3,   KC_F4,   KC_F5,                           KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
       FR_SUP2, FR_AMPR, FR_EACU, FR_DQUO, FR_QUOT, DM_REC1,                         FR_MINS, FR_EGRV, FR_UNDS, FR_CCED, FR_AGRV, KC_F12,
       FR_SLSH, FR_BSLS, FR_TILD, FR_CIRC, FR_HASH, DM_PLY1,                         FR_AT,   FR_ASTR, FR_GRV,  FR_DIAE, KC_UP,   FR_UGRV,
       FR_LCBR, FR_RCBR, FR_LBRC, FR_RBRC, FR_LPRN, FR_RPRN, TG(3),      XXXXXXX,    FR_PERC, FR_PLUS, FR_PIPE, KC_LEFT, KC_DOWN, KC_RIGHT,
            _______, _______, _______, _______, _______,                                  _______, _______, _______, _______, _______
    ),


[2] =  LAYOUT(
    QK_BOOT, KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,                          XXXXXXX, FR_EQL,  FR_7,    FR_8,    FR_9,    FR_ASTR,
    XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, KC_F18,                          FR_LABK, FR_RABK, FR_4,    FR_5,    FR_6,    FR_PLUS,
    XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, KC_F19,                          KC_HOME, KC_END,  FR_1,    FR_2,    FR_3,    FR_MINS,
    KC_PSCR, KC_F24,  KC_F23,  KC_F22,  KC_F21,  KC_F20, KC_KB_MUTE,TD(TD_MEDIA), KC_PGUP, KC_PGDN, FR_COMM, FR_0,    FR_DOT,  FR_SLSH,
        _______, _______, _______, _______, _______,                                  _______, _______, _______, _______, _______
),




[3] = LAYOUT(
    KC_ESC,   FR_1,   FR_2,    FR_3,    FR_4,    FR_5,                       FR_6,     FR_7,     FR_8,    FR_9,    FR_0,    KC_DEL,
    KC_TAB,   FR_Q,   FR_W,    FR_F,    FR_P,    FR_B,                       FR_J,     FR_L,     FR_O,    FR_Y,    FR_COLN, KC_BSPC,
    KC_LSFT,  FR_A,   KC_R,    KC_S,    KC_T,    KC_G,                       FR_M,     KC_N,     KC_E,    KC_I,    FR_U,    KC_QUOT,
    KC_LCTL,  FR_Z,   FR_X,    FR_C,    FR_V,    FR_D,    TG(3),           KC_BTN2,FR_K,     FR_H,     FR_COMM, FR_DOT,  FR_EXLM, KC_RSFT,
                      KC_F2,   KC_F3,   KC_F4,   KC_SPC,  KC_F5,    KC_LALT, KC_ENT,  KC_RCMD,  KC_UP, KC_DOWN

    ),

};
/* This part is for the 2 encoders */
/*
#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    { ENCODER_CCW_CW(KC_VOLD, KC_VOLU), ENCODER_CCW_CW(KC_MPRV, KC_MNXT) },
};
#endif
*/

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN), ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT) },
    [1] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN), ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT) },
    [2] = { ENCODER_CCW_CW(KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN), ENCODER_CCW_CW(KC_BRIGHTNESS_UP, KC_BRIGHTNESS_DOWN)},
    [3] = { ENCODER_CCW_CW(KC_MS_UP, KC_MS_DOWN), ENCODER_CCW_CW(KC_MS_LEFT, KC_MS_RIGHT) },
};
#endif




//layer lighting
bool rgb_matrix_indicators_advanced_user(uint8_t led_min, uint8_t led_max) {
    HSV hsv = {0, 255, 255};
    switch(get_highest_layer(layer_state|default_layer_state)) {
        case 3:
            hsv = (HSV){180, 255, 255};
            break;
        case 2:
            hsv = (HSV){130, 255, 255};
            break;
        case 1:
            hsv = (HSV){30, 255, 255};
            break;
        default:
            hsv = (HSV){200, 255, 255};
            break;
    }

    if (hsv.v > rgb_matrix_get_val()) {
        hsv.v = rgb_matrix_get_val();
    }
    RGB rgb = hsv_to_rgb(hsv);

    for (uint8_t i = led_min; i < led_max; i++) {
        rgb_matrix_set_color(i, rgb.r, rgb.g, rgb.b);
    }
    return false;
}


