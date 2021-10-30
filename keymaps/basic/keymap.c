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
    _FN
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    CPY_PST,
};

// Tap Dance declarations
enum {
    TD_WIN_FN,
    TD_DOT_FN
};

#define TD_LWIN TD(TD_WIN_FN)
#define TD_DOT  TD(TD_DOT_FN)
#define LT_INS  LT(_FN, KC_INS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
    KC_ESC ,KC_PIPE,KC_AT  ,KC_HASH,KC_ASTR,KC_PERC,                KC_QUES,KC_LPRN,KC_LBRC,KC_LCBR,KC_LABK,KC_CAPS,
    KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,KC_EQL ,
    KC_BSPC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_SLSH,KC_RSFT,
                            KC_LALT,TD_LWIN,KC_LCTL,KC_LSFT,KC_ENT ,KC_SPC ,LT_INS ,KC_DEL ,
                            ALT_TAB,                CPY_PST,XXXXXXX,                XXXXXXX
    ),
    [_FN] = LAYOUT(
    KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
    _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                XXXXXXX,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,XXXXXXX,
    _______,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,XXXXXXX,
    _______,KC_0   ,KC_1   ,KC_2   ,KC_3   ,KC_CALC,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                            KC_EQL ,TD_DOT ,KC_0   ,KC_PENT,KC_RSFT,KC_RCTL,TG(_FN),KC_RALT,
                            _______,                _______,XXXXXXX,                XXXXXXX
    )
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

void keyboard_pre_init_user(void) {
    setPinOutput(TXLED);
    setPinOutput(RXLED);
    writePin(TXLED, LED_OFF);
    writePin(RXLED, LED_OFF);
}

void matrix_scan_user(void) {
    writePin(TXLED, IS_LAYER_OFF(_FN));
    writePin(RXLED, IS_LAYER_OFF(_FN));

    if (is_alt_tab_active) {
        if (timer_elapsed(alt_tab_timer) > 1000) {
            unregister_code(KC_LALT);
            is_alt_tab_active = false;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case ALT_TAB:
            if (record->event.pressed) {
                if (!is_alt_tab_active) {
                    is_alt_tab_active = true;
                    register_code(KC_LALT);
                }
                alt_tab_timer = timer_read();
                register_code(KC_TAB);
            } else {
                unregister_code(KC_TAB);
            }
            break;
        case CPY_PST:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("c"));
            } else {
                SEND_STRING(SS_LCTL("v"));
            }
            break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_ESC:
        clear_mods();
        alt_tab_timer = is_alt_tab_active ? timer_read() : 0;
        break;
    }
}

// Key Overrides
const key_override_t comma_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);
const key_override_t dot_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);
const key_override_t question_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);
const key_override_t pipe_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PIPE, KC_CIRCUMFLEX);
const key_override_t at_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_GRAVE);
const key_override_t hash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_TILDE);
const key_override_t asterisk_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_AMPERSAND);
const key_override_t percent_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_PERCENT, KC_DOLLAR);
const key_override_t left_angle_bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
const key_override_t left_paren_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
const key_override_t left_bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET);
const key_override_t left_curly_bracket_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t slash_key_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_BSLASH);

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &comma_key_override,
    &dot_key_override,
    &question_key_override,
    &pipe_key_override,
    &at_key_override,
    &hash_key_override,
    &asterisk_key_override,
    &percent_key_override,
    &left_angle_bracket_key_override,
    &left_paren_key_override,
    &left_bracket_key_override,
    &left_curly_bracket_key_override,
    &slash_key_override,
    NULL // Null terminate the array of overrides!
};

// Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_FN] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LWIN, _FN),
    [TD_DOT_FN] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_DOT , _FN)
};
