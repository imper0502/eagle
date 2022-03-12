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
    _BS, _QW,
    _MK, _NP,
    _FN, MY_COMMAND
};

enum tap_dance_names {
    IME_CAPSLOCK,
    ALT_TABLE,
    COPY_PASTE_FNLOCK_SCREENSHOT,
    INSERT_SCREENSHOT_NUMPAD,
    F_1,    F_2,    F_3,    F_4,
    F_5,    F_6,    F_7,    F_8,
    F_9,    F_10,   F_11,   F_12,
};

/* Key Override */
const key_override_t arterisk_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_CIRCUMFLEX); // *^
const key_override_t at_override =       ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_DOLLAR);           // @$
const key_override_t hash_override =     ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_DOLLAR);         // #$
const key_override_t ampersand_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_DOLLAR);   // &$
const key_override_t slash_override =    ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT);       // /%
const key_override_t left_paren_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_PAREN, KC_RIGHT_PAREN);
const key_override_t left_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LBRACKET, KC_RBRACKET);
const key_override_t left_curly_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_CURLY_BRACE, KC_RIGHT_CURLY_BRACE);
const key_override_t left_angle_bracket_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_RIGHT_ANGLE_BRACKET);
const key_override_t question_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);  // ?!
const key_override_t comma_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);         // ,;
const key_override_t dot_override = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);              // .:

const key_override_t **key_overrides = (const key_override_t *[]) {
    &arterisk_override,
    &at_override,
    &hash_override,
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

#define TD_LANG TD(IME_CAPSLOCK)
#define ALT_TAB TD(ALT_TABLE)
#define CPY_PST TD(COPY_PASTE_FNLOCK_SCREENSHOT)
#define INS_SHT TD(INSERT_SCREENSHOT_NUMPAD)
#define GUI_ESC LGUI_T(KC_ESC)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define MK_TAB  LT(_MK, KC_TAB)
#define FN_SPC  LT(_FN, KC_SPC)
#define FN_RCTL LM(_FN, MOD_RCTL)
#define FN_RALT LM(_FN, MOD_RALT)
#define NEW_TAB C(KC_T)
#define ALT_ESC A(KC_ESC)
#define CLS_TAB C(KC_W)
#define PRV_TAB C(KC_PGUP)
#define NXT_TAB C(KC_PGDN)
#define PRV_WIN LCA(KC_LEFT)
#define NXT_WIN LCA(KC_RIGHT)
#define PRV_PG  C(S(KC_PGUP))
#define NXT_PG  C(S(KC_PGDN))

/* Keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
        KC_GRV , KC_ASTR, KC_AT  , KC_HASH, KC_AMPR, KC_SLSH,                   KC_BSLS, KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, TD_LANG,
        MK_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_MINS, KC_EQL ,
        GUI_ESC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUES,
 LSFT_T(KC_DEL), KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                   KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, KC_RSFT,
                          XXXXXXX,                            CPY_PST, INS_SHT,                            XXXXXXX
    ),
    [_QW] = LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_QUES,
        KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_MINS, KC_EQL ,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_QUOT, _______,
                                   _______, _______, _______, _______, _______, _______, _______, _______,
                          XXXXXXX,                            _______, _______,                            XXXXXXX
    ),
    [_MK] = LAYOUT(
        _______, PRV_TAB, NEW_TAB, NXT_TAB, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, PRV_WIN, ALT_TAB, NXT_WIN, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
        _______, PRV_PG , CLS_TAB, NXT_PG , XXXXXXX, XXXXXXX,                   XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, KC_DEL , KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN5,
                          XXXXXXX,                            _______, KC_BTN4,                            XXXXXXX
    ),
    [_NP] = LAYOUT(
        TD(F_1), TD(F_2), TD(F_3), TD(F_4), TD(F_5), TD(F_6),                   TD(F_7), TD(F_8), TD(F_9),TD(F_10),TD(F_11),TD(F_12),
        KC_TAB , KC_PPLS, KC_7   , KC_8   , KC_9   , KC_PAST,                   KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, KC_TAB ,
        KC_ESC , KC_PMNS, KC_4   , KC_5   , KC_6   , KC_PSLS,                   KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PMNS, KC_ESC ,
        KC_COMM, KC_EQL , KC_1   , KC_2   , KC_3   , KC_PERC,                   KC_PERC, KC_1   , KC_2   , KC_3   , KC_EQL , KC_COMM,
                                   KC_DOT , KC_0   , KC_PENT, _______, _______, _______, KC_0   , KC_DOT ,
                          XXXXXXX,                            _______, TG(_NP),                            XXXXXXX
    ),
    [_FN] = LAYOUT(
        TD(F_1), TD(F_2), TD(F_3), TD(F_4), TD(F_5), TD(F_6),                   TD(F_7), TD(F_8), TD(F_9),TD(F_10),TD(F_11),TD(F_12),
        KC_TAB , KC_PPLS, KC_7   , KC_8   , KC_9   , KC_PAST,                   KC_BRIU, KC_HOME, KC_UP  , KC_END , KC_PGUP, ALT_TAB,
        KC_ESC , KC_PMNS, KC_4   , KC_5   , KC_6   , KC_PSLS,                   KC_BRID, KC_LEFT, KC_DOWN, KC_RGHT, KC_PGDN, ALT_ESC,
        KC_COMM, KC_EQL , KC_1   , KC_2   , KC_3   , KC_PERC,                   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,
                                   KC_DOT , KC_0   , KC_PENT, _______, _______, _______, KC_RCTL, KC_RALT,
                          XXXXXXX,                            _______, TG(_FN),                            XXXXXXX
    ),
    [MY_COMMAND] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, TG(_QW), CG_NORM, TG(_FN), KC_PSCR, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  RESET , KC_SLCK, CG_TOGG, TG(_QW),                   CG_SWAP, KC_NLCK, EEP_RST, EEP_RST, CG_TOGG, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX,                            XXXXXXX, XXXXXXX,                          XXXXXXX
    )
};

/* Behavior */
void keyboard_pre_init_user(void) {
    setPinOutput(TXLED);
}

void matrix_scan_user(void) {
    bool led_pins_state = IS_LAYER_ON(_FN)||IS_LAYER_ON(_NP) ? LED_PIN_ON_STATE : !LED_PIN_ON_STATE;
    writePin(TXLED, led_pins_state);
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FN_SPC:
        return TAPPING_TERM - 25;
    case CPY_PST:
        return TAPPING_TERM - 75;
    case TD(ALT_TABLE):
        return TAPPING_TERM + 500;
    default:
        return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FN_SPC :
    case FN_RCTL:
    case FN_RALT:
        return true;
    default:
        return false;
    }
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LSFT:
    case KC_RSFT:
    case OS_LSFT:
    case OS_RSFT:
        get_mods() == MOD_MASK_SHIFT ? layer_on(MY_COMMAND) : layer_off(MY_COMMAND);
        break;
    case KC_ESC:
    case KC_GESC:
        clear_mods();
    case GUI_ESC:
    default:
        return;
    }
}

/* Tap Dance */
typedef enum {
    SINGLE_TAP, SINGLE_HOLD,
    DOUBLE_TAP, TAP_THEN_HOLD,
    OTHERWISE
} td_state_t;

td_state_t current_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:  return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
        case 2:  return (state->interrupted || !state->pressed) ? DOUBLE_TAP : TAP_THEN_HOLD;
        default: return OTHERWISE;
    }
}

void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data);
void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data);
void td_insert_screenshot_finished(qk_tap_dance_state_t *state, void *user_data);
void td_insert_screenshot_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [IME_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(S(KC_LALT) , KC_CAPS),
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL),
    [COPY_PASTE_FNLOCK_SCREENSHOT] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_copy_paste_finished, td_copy_paste_reset),
    [INSERT_SCREENSHOT_NUMPAD] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_insert_screenshot_finished, td_insert_screenshot_reset),
    [F_1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_CALC),
    [F_2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_CALC),
    [F_3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_CALC),
    [F_4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_CALC),
    [F_5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_CALC),
    [F_6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_CALC),
    [F_7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_CALC),
    [F_8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_CALC),
    [F_9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_CALC),
    [F_10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_CALC),
    [F_11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_CALC),
    [F_12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_CALC),
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
        case SINGLE_TAP:    register_code16(C(KC_V));   return;
        case SINGLE_HOLD:   tap_code16(C(KC_C));        return;
        case DOUBLE_TAP:    layer_invert(_NP);          return;
        case TAP_THEN_HOLD: tap_code16(C(KC_X));        return;
        default:            register_code16(LSG(KC_S)); return;
    }
}

void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:    unregister_code16(C(KC_V));   return;
        case SINGLE_HOLD:   tap_code16(C(KC_V));          return;
        case DOUBLE_TAP:    /* This line is necessary. */ return;
        case TAP_THEN_HOLD: /* This line is necessary. */ return;
        default:            unregister_code16(LSG(KC_S)); return;
    }
}

void td_insert_screenshot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (get_mods() == 0) {
            td_state = current_dance(state);
            switch (td_state) {
            case SINGLE_TAP: register_code16(LSG(KC_S)); return;
            case DOUBLE_TAP: layer_invert(_NP);          return;
            default:       /* This line is necessary. */ return;
        }
    }
    register_code(KC_INS);
}

void td_insert_screenshot_reset(qk_tap_dance_state_t *state, void *user_data) {
    if (get_mods() == 0) {
            switch (td_state) {
            case SINGLE_TAP: unregister_code16(LSG(KC_S)); return;
            default:         /* This line is necessary. */ return;
        }
    }
    unregister_code(KC_INS);
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