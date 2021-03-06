/* Copyright 2021 imper0502
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

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BS,
    FN1,
    FN2,
    FN3
};

#define LT_MINS LT(FN1, KC_MINS)
#define SFT_SPC RSFT_T(KC_SPC)
#define CTL_ENT RCTL_T(KC_ENT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // GRAVE_ESC
    // GRAVE_ESC_ALT_OVERRIDE   -> Always send Escape if Alt is pressed     -> x -> alt + esc
    // GRAVE_ESC_GUI_OVERRIDE   -> Always send Escape if GUI is pressed     -> x -> win + ` = `
    // GRAVE_ESC_SHIFT_OVERRIDE -> Always send Escape if Shift is pressed   -> x -> sft + ` = ~
    // GRAVE_ESC_CTRL_OVERRIDE  -> Always send Escape if Control is pressed -> o -> ctl + esc
    [_BS] = LAYOUT( // without key overrides
        KC_GESC,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
        KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
        KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
        KC_LBRC,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                KC_N   ,KC_M   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RBRC,
                                KC_LALT,KC_LWIN,KC_LSFT,KC_LCTL,CTL_ENT,SFT_SPC,LT_MINS,KC_EQL ,
                                XXXXXXX,                XXXXXXX,XXXXXXX,                XXXXXXX
    ),
    [FN1] = LAYOUT(
        KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,KC_INS ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_DEL ,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                _______,_______,_______,_______,KC_RCTL,KC_RSFT,XXXXXXX,KC_RALT,
                                XXXXXXX,                XXXXXXX,XXXXXXX,                XXXXXXX
    ),
    [FN2] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,_______,_______,_______,_______,_______,
                                _______,                _______,_______,                _______
    ),
    [FN3] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
                                _______,_______,_______,_______,_______,_______,_______,_______,
                                _______,                _______,_______,                _______
    ),
};
