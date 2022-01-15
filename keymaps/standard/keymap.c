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
    _BS, _QW, NUM,
    _FN, MY_COMMAND
};

enum tap_dance_names {
    IME_CAPSLOCK,
    ALT_TABLE,
    COPY_PASTE_FNLOCK_SCREENSHOT,
};

/* Key Override */
const key_override_t at_override = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CIRCUMFLEX);             // @^
const key_override_t hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_DOLLAR);             // #$
const key_override_t astersk_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_AMPERSAND);   // *&
const key_override_t ampersand_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_ASTERISK); // &*
const key_override_t slash_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT);          // /%
const key_override_t left_paren_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
const key_override_t left_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET);
const key_override_t left_curly_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t left_angle_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
const key_override_t question_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);  // ?!
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);         // ,;
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);              // .:

const key_override_t **key_overrides = (const key_override_t *[]) {
    &at_override,
    &hash_override,
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

#define TD_IME  TD(IME_CAPSLOCK)
#define ALT_TAB TD(ALT_TABLE)
#define CPY_PST TD(COPY_PASTE_FNLOCK_SCREENSHOT)
#define FN_SPC  LT(_FN, KC_SPC)
#define FN_ALT  LM(_FN, MOD_RALT)

/* Keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
        ALT_TAB,KC_GRV ,KC_AT  ,KC_HASH,KC_AMPR,KC_SLSH,                KC_BSLS,KC_LPRN,KC_LBRC,KC_LCBR,KC_LABK,KC_BTN4,
        KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,KC_EQL ,
        KC_LWIN,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUES,
        KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_QUOT,KC_RSFT,
                                KC_LALT,KC_LCTL,KC_RSFT,KC_BSPC,KC_ENT ,FN_SPC ,KC_DEL ,FN_ALT ,
                            KC_ESC ,                    CPY_PST,KC_INS ,                    TD_IME
    ),
    [_QW] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_QUES,
        _______,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_MINS,KC_EQL ,
        _______,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                KC_N   ,KC_M   ,_______,_______,_______,_______,
                                _______,_______,_______,_______,_______,_______,_______,_______,
                            _______,                    _______,_______,                    _______
    ),
    [NUM] = LAYOUT(
        _______,_______,_______,_______,_______,_______,                _______,_______,_______,_______,_______,_______,
        _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,_______,
        KC_CALC,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,KC_CALC,
        _______,KC_PERC,KC_1   ,KC_2   ,KC_3   ,KC_EQL ,                KC_PERC,KC_1   ,KC_2   ,KC_3   ,KC_EQL ,_______,
                                KC_0   ,KC_DOT ,_______,_______,_______,_______,KC_0   ,KC_DOT ,
                            _______,                    _______,_______,                    _______
    ),
    [_FN] = LAYOUT(
        KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
        _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                KC_BRIU,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,KC_INS ,
        KC_CALC,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                KC_BRID,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_DEL ,
        _______,KC_PERC,KC_1   ,KC_2   ,KC_3   ,KC_EQL ,                KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,
                                KC_0   ,KC_DOT ,_______,_______,_______,_______,KC_RCTL,KC_RALT,
                            _______,                    _______,_______,                    KC_CAPS
    ),
    [MY_COMMAND] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,TG(_QW),CG_NORM,TG(_FN),KC_PSCR,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX, RESET ,KC_SLCK,CG_TOGG,XXXXXXX,                CG_SWAP,KC_NLCK,EEP_RST,EEP_RST,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,KC_CAPS,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                            XXXXXXX,                    XXXXXXX,XXXXXXX,                    XXXXXXX
    )
};

/* Behavior */
void keyboard_pre_init_user(void) {
    setPinOutput(TXLED);
    setPinOutput(RXLED);

    writePin(TXLED, LED_OFF);
    writePin(RXLED, LED_OFF);
}

void matrix_scan_user(void) {
    writePin(TXLED, IS_LAYER_OFF(_FN));
    writePin(RXLED, IS_LAYER_OFF(_FN));

   get_mods() == MOD_MASK_SHIFT ? layer_on(MY_COMMAND) : layer_off(MY_COMMAND);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case TD(ALT_TABLE):
            return TAPPING_TERM + 500;
        default:
            return TAPPING_TERM;
    }
}

/* Tap Dance */
typedef enum {
    SINGLE_TAP, SINGLE_HOLD,
    DOUBLE_TAP, OTHERWISE
} td_state_t;

td_state_t current_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:  return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
        case 2:  return DOUBLE_TAP;
        default: return OTHERWISE;
    }
}

void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data);
void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [IME_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(G(KC_SPC) , KC_CAPS),
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL),
    [COPY_PASTE_FNLOCK_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_copy_paste_finished, td_copy_paste_reset),
};

void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data) {
    switch (state->count) {
        case 1: add_mods(MOD_BIT(KC_LALT));
        default:          tap_code(KC_TAB);
    }
}

void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data) {
    del_mods(MOD_BIT(KC_LALT));
}

static td_state_t td_state;

void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case SINGLE_TAP:  register_code16(C(KC_V));    break;
        case SINGLE_HOLD: tap_code16(C(KC_C));         break;
        case DOUBLE_TAP:  layer_invert(NUM);           break;
        default:          register_code16(LSG(KC_S)); return;
    }
}

void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:  unregister_code16(C(KC_V));    break;
        case SINGLE_HOLD: tap_code16(C(KC_V));           break;
        case DOUBLE_TAP:  /* This line is necessary. */  break;
        default:          unregister_code16(LSG(KC_S)); return;
    }
}

/* Retry Encoders */
uint8_t mod_state;
bool encoder_update_user(uint8_t index, bool clockwise) {
    mod_state = get_mods();
    switch (index) {
    case 0:
        if (IS_LAYER_ON(_FN)) {
            if (mod_state & MOD_MASK_CS) {
                clockwise ? tap_code(KC_BRIU) : tap_code(KC_BRID);
            } else {
                clockwise ? tap_code(KC_VOLU) : tap_code(KC_VOLD);
            }
        } else {
            if (mod_state == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT)) ||
                mod_state == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_RSFT)) ||
                mod_state == (MOD_BIT(KC_RCTL) | MOD_BIT(KC_LSFT)) ||
                mod_state == (MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT))) {
                del_mods(MOD_MASK_CS);
                clockwise ? tap_code(KC_PGDN) : tap_code(KC_PGUP);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_ALT) {
                del_mods(MOD_MASK_ALT);
                clockwise ? tap_code(KC_BTN5) : tap_code(KC_BTN4);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_SG) {
                clockwise ? tap_code16(C(KC_RGHT)) : tap_code16(C(KC_LEFT));            
            } else if (mod_state & MOD_MASK_CTRL) {
                clockwise ? tap_code(KC_Y) : tap_code(KC_Z);
            } else {
                clockwise ? tap_code(KC_WH_D) : tap_code(KC_WH_U);
            }
        }
        break;
    }
    return false;
}