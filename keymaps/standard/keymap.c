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
    QWT,
    _FN,
    COMMAND
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    ALT_TAB = SAFE_RANGE,
    BTN_2_1
};

// Tap Dance declarations
enum tap_dance_names {
    WIN_FNLOCK,
    IME_CAPSLOCK,
    INSERT_SCREENSHOT,
    COPY_PASTE,
};

#define TD_LWIN TD(WIN_FNLOCK)
#define TD_IME  TD(IME_CAPSLOCK)
#define TD_INS  TD(INSERT_SCREENSHOT)
#define CTL_ENT RCTL_T(KC_ENT)
#define SFT_SPC RSFT_T(KC_SPC)
#define LT_INS  LT(_FN, KC_INS)
#define LT_MINS LT(_FN, KC_MINS)
#define CPY_PST TD(COPY_PASTE)

// To disable key overrides
#define CT_LBRC RCTL_T(KC_LBRC)
#define CT_RBRC RCTL_T(KC_RBRC)
#define CT_SLSH RCTL_T(KC_SLSH)
#define CT_DOT  RCTL_T(KC_DOT)
#define CT_COMM RCTL_T(KC_COMM)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
        KC_BTN4,KC_BSLS,KC_AT  ,KC_ASTR,KC_AMPR,KC_SLSH,                KC_GRV ,KC_LPRN,KC_LBRC,KC_LCBR,KC_LABK,ALT_TAB,
        KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,KC_EQL ,
        KC_BSPC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUES,
        KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                KC_K   ,KC_H   ,KC_COMM,KC_DOT ,KC_QUOT,KC_RSFT,
                                KC_LALT,TD_LWIN,KC_LSFT,KC_LCTL,CTL_ENT,SFT_SPC,MO(_FN),KC_DEL ,
                            KC_ESC ,                    CPY_PST,TD_INS ,                    TD_IME
    ),
    [QWT] = LAYOUT(
        KC_ESC ,KC_1   ,KC_2   ,KC_3   ,KC_4   ,KC_5   ,                KC_6   ,KC_7   ,KC_8   ,KC_9   ,KC_0   ,KC_BSPC,
        KC_TAB ,KC_Q   ,KC_W   ,KC_E   ,KC_R   ,KC_T   ,                KC_Y   ,KC_U   ,KC_I   ,KC_O   ,KC_P   ,KC_BSLS,
        KC_CAPS,KC_A   ,KC_S   ,KC_D   ,KC_F   ,KC_G   ,                KC_H   ,KC_J   ,KC_K   ,KC_L   ,KC_SCLN,KC_QUOT,
        KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_V   ,KC_B   ,                KC_N   ,KC_M   ,CT_COMM,CT_DOT ,CT_SLSH,KC_RSFT,
                                KC_LALT,KC_LWIN,KC_LSFT,KC_LCTL,_______,_______,_______,KC_GRV ,
                            CT_LBRC,                    KC_MINS,KC_EQL ,                    CT_RBRC
    ),
    [_FN] = LAYOUT(
        KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
        KC_TAB ,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                DM_REC1,KC_HOME,KC_UP  ,KC_END ,KC_PGUP,KC_INS ,
        KC_BSPC,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                DM_PLY1,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_DEL ,
        KC_CALC,KC_PERC,KC_1   ,KC_2   ,KC_3   ,KC_DLR ,                KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE,KC_VOLD,KC_VOLU,
                                KC_EQL ,KC_DOT ,KC_0   ,CTL_ENT,KC_RCTL,KC_RSFT,TG(_FN),KC_RALT,
                            KC_ESC ,                    BTN_2_1,XXXXXXX,                    KC_CAPS
    ),
    [COMMAND] = LAYOUT(
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,KC_APP , RESET ,KC_SLCK,TG(QWT),XXXXXXX,                KC_MAIL,KC_NLCK,KC_EJCT,XXXXXXX,XXXXXXX,XXXXXXX,
        XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                                XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,XXXXXXX,
                            XXXXXXX,                    XXXXXXX,XXXXXXX,                    XXXXXXX
    )
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;
bool is_typing_timer_active = false;
uint16_t typing_timer = 0;
uint8_t mod_state;

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

    if (is_typing_timer_active && IS_LAYER_ON(_FN)) {
        if (timer_elapsed(typing_timer) > 180000) {
            layer_off(_FN);
            is_typing_timer_active = false;
        }
    }
    
    (get_mods() & MOD_MASK_CTRL) == MOD_MASK_CTRL ? layer_on(COMMAND) : layer_off(COMMAND);
}

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (!is_typing_timer_active)
        is_typing_timer_active = IS_LAYER_ON(_FN);
    typing_timer = timer_read();
    mod_state = get_mods();
    switch (index) {
    case 0:
        if (clockwise) {
            if ((mod_state & MOD_MASK_CS) == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))
            ||  (mod_state & MOD_MASK_CS) == (MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT))) {
                del_mods(MOD_MASK_CS);
                IS_LAYER_ON(_FN) ? tap_code(XXXXXXX) : tap_code(KC_PGDN);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_ALT) {
                del_mods(MOD_MASK_ALT);
                IS_LAYER_ON(_FN) ? tap_code(KC_MNXT) : tap_code(KC_BTN5);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_SG) {
                IS_LAYER_ON(_FN) ? tap_code(KC_BRIU) : tap_code16(C(KC_RGHT));
            } else if (mod_state & MOD_MASK_CTRL) {
                IS_LAYER_ON(_FN) ? tap_code(KC_TAB)  : tap_code(KC_Y);
            } else {
                IS_LAYER_ON(_FN) ? tap_code(KC_VOLU) : tap_code(KC_WH_D);
            }
        } else {
            if ((mod_state & MOD_MASK_CS) == (MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT))
            ||  (mod_state & MOD_MASK_CS) == (MOD_BIT(KC_RCTL) | MOD_BIT(KC_RSFT))) {
                del_mods(MOD_MASK_CS);
                IS_LAYER_ON(_FN) ? tap_code(XXXXXXX)     : tap_code(KC_PGUP);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_ALT) {
                del_mods(MOD_MASK_ALT);
                IS_LAYER_ON(_FN) ? tap_code(KC_MPRV)     : tap_code(KC_BTN4);
                set_mods(mod_state);
            } else if (mod_state & MOD_MASK_SG) {
                IS_LAYER_ON(_FN) ? tap_code(KC_BRID)     : tap_code16(C(KC_LEFT));            
            } else if (mod_state & MOD_MASK_CTRL) {
                IS_LAYER_ON(_FN) ? tap_code16(S(KC_TAB)) : tap_code(KC_Z);
            } else {
                IS_LAYER_ON(_FN) ? tap_code(KC_VOLD)     : tap_code(KC_WH_U);
            }
        }
        break;
    }
    return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!is_typing_timer_active)
        is_typing_timer_active = IS_LAYER_ON(_FN);
    typing_timer = timer_read();
    mod_state = get_mods();
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
        case BTN_2_1:
            (record->event.pressed) ? tap_code(KC_BTN2) : tap_code(KC_BTN1);
            break;

    }
    return true;
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

// Define a type containing as many tapdance states as you need
typedef enum {
    SINGLE_TAP,
    SINGLE_HOLD,
    DOUBLE_TAP,
    OTHERWISE
} td_state_t;

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare tap dance functions:
// Function to determine the current tapdance state
uint8_t current_dance(qk_tap_dance_state_t *state);
uint8_t current_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:
            if (!state->interrupted && !state->pressed) return SINGLE_TAP;
            else if (state->pressed) return SINGLE_HOLD;
            else return OTHERWISE;
        case 2:
            if (!state->pressed) return DOUBLE_TAP;
        default:
            return OTHERWISE;
    }
}

// `finished` and `reset` functions for each tapdance keycode
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case SINGLE_TAP:  register_code16(C(KC_V)); break;
        case SINGLE_HOLD: tap_code16(C(KC_C));      break;
        case DOUBLE_TAP:  register_code16(C(KC_Z)); break;
        default:                                   return;
    }
}

void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:  unregister_code16(C(KC_V)); break;
        case SINGLE_HOLD: tap_code16(C(KC_V));        break;
        case DOUBLE_TAP:  unregister_code16(C(KC_Z)); break;
        default:                                     return;
    }
    td_state = OTHERWISE;
}

// Tap Dance
qk_tap_dance_action_t tap_dance_actions[] = {
    [WIN_FNLOCK]        = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LWIN, _FN),
    [IME_CAPSLOCK]      = ACTION_TAP_DANCE_DOUBLE(G(KC_SPC) , KC_CAPS),
    [INSERT_SCREENSHOT] = ACTION_TAP_DANCE_DOUBLE(KC_INSERT, LSG(KC_S)),
    [COPY_PASTE]        = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_copy_paste_finished, td_copy_paste_reset)
};