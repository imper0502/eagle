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

enum layer_names {
    _BS, _FN
};

enum tap_dance_names {
    ALT_TABLE,
    COPY_PASTE_SCREENSHOT
};

// Alias of keycodes
#define ALT_TAB TD(ALT_TABLE)
#define CPY_PST TD(COPY_PASTE_SCREENSHOT)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
    KC_ESC ,KC_BSLS,KC_AT  ,KC_ASTR,KC_AMPR,KC_SLSH,                KC_GRV ,KC_LPRN,KC_LBRC,KC_LCBR,KC_LABK,KC_BSPC,
    KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,KC_EQL ,
    KC_LWIN,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUES,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_QUOT,KC_RSFT,
                            KC_LALT,KC_LCTL,KC_LSFT,KC_BSPC,KC_ENT ,KC_SPC ,MO(_FN),KC_DEL ,
                        ALT_TAB,                    CPY_PST,KC_INS ,                    KC_CAPS
    ),
    [_FN] = LAYOUT(
    KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
    _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                XXXXXXX,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,KC_INS ,
    _______,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                XXXXXXX,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_DEL ,
    _______,KC_0   ,KC_1   ,KC_2   ,KC_3   ,KC_CALC,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                            KC_EQL ,KC_DOT ,KC_0   ,_______,_______,KC_RSFT,KC_RCTL,KC_RALT,
                        _______,                    _______,_______,                    _______
    )
};

void keyboard_pre_init_user(void) {
    setPinOutput(TXLED);
    setPinOutput(RXLED);
    writePin(TXLED, LED_OFF);
    writePin(RXLED, LED_OFF);
}

void matrix_scan_user(void) {
    writePin(TXLED, IS_LAYER_OFF(_FN));
    writePin(RXLED, IS_LAYER_OFF(_FN));
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(ALT_TAB):
            return TAPPING_TERM + 500;
        default:
            return TAPPING_TERM;
    }
}

// Key Overrides
const key_override_t at_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CIRCUMFLEX);           // @^
const key_override_t astersk_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_HASH);      // *#
const key_override_t ampersand_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_DOLLAR); // &$
const key_override_t slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT);        // /%
const key_override_t left_paren_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
const key_override_t left_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET);
const key_override_t left_curly_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t left_angle_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
const key_override_t question_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);  // ?!
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);         // ,;
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);              // .:

// This globally defines all key overrides to be used
const key_override_t **key_overrides = (const key_override_t *[]){
    &at_override,
    &astersk_override,
    &ampersand_override,
    &slash_override,
    &left_paren_override,
    &left_bracket_override,
    &left_curly_bracket_override,
    &left_angle_bracket_override,
    &question_override,
    &comma_override,
    &dot_override,
    NULL // Null terminate the array of overrides!
};

/*
 * Tap Dance */
typedef enum {
    SINGLE_TAP, SINGLE_HOLD,
    DUAL_TAP, OTHERWISE
} td_state_t; // Define a type containing as many tapdance states

static td_state_t td_state; // Create a global instance of the tapdance state type

uint8_t current_dance(qk_tap_dance_state_t *state);
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data);
void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data);
void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [COPY_PASTE_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_copy_paste_finished, td_copy_paste_reset),
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL)
};

uint8_t current_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:  return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
        case 2:  return DUAL_TAP;
        default: return OTHERWISE;
    }
}

void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case SINGLE_TAP:  register_code16(C(KC_V));   break;
        case SINGLE_HOLD: tap_code16(C(KC_C));        break;
        case DUAL_TAP:  register_code16(LSG(KC_S)); break;
        default:          layer_on(_FN);             return;
    }
}

void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:  unregister_code16(C(KC_V));   break;
        case SINGLE_HOLD: tap_code16(C(KC_V));          break;
        case DUAL_TAP:  unregister_code16(LSG(KC_S)); break;
        default:                                       return;
    }
    td_state = OTHERWISE;
}

void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: add_mods(MOD_BIT(KC_LALT));
        default:          tap_code(KC_TAB);
    }
}

void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
    del_mods(MOD_BIT(KC_LALT));
}
