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
    QMKBEST = SAFE_RANGE
};

// Tap Dance declarations
enum {
    TD_WIN_FN,
    TD_DOT_FN,
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_WIN_FN] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_LWIN, _FN),
    [TD_DOT_FN] = ACTION_TAP_DANCE_LAYER_TOGGLE(KC_DOT , _FN),
};

// RT keys
#define TD_LWIN TD(TD_WIN_FN)
#define TD_DOT  TD(TD_DOT_FN)
#define SFT_ENT KC_SFTENT
#define ST_SPC  SFT_T(KC_SPC)
#define SR_IME  G(KC_SPC)
// R1 keys
#define SR_COMM KC_COMMA
#define SR_DOT  KC_DOT
#define SR_QUES KC_QUESTION
// R4 keys
#define SR_PIPE KC_PIPE         // |^
#define SR_AT   KC_AT           // @`
#define SR_HASH KC_HASH         // #~
#define SR_ASTR KC_ASTERISK     //\*&
#define SR_PERC KC_PERCENT	    // %$
#define SR_LABK KC_LEFT_ANGLE_BRACKET   // <>
#define SR_LPRN KC_LEFT_PAREN           // ()
#define SR_LBRC KC_LBRACKET             // []
#define SR_LCBR KC_LEFT_CURLY_BRACE     // {}
#define SR_SLSH KC_SLASH                // /

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BS] = LAYOUT(
    _______,SR_PIPE,SR_AT  ,SR_HASH,SR_ASTR,SR_PERC,                SR_LABK,SR_LPRN,SR_LBRC,SR_LCBR,SR_SLSH,_______,
    KC_TAB ,KC_Q   ,KC_W   ,KC_F   ,KC_P   ,KC_B   ,                KC_J   ,KC_L   ,KC_U   ,KC_Y   ,KC_MINS,KC_EQL ,
    KC_BSPC,KC_A   ,KC_R   ,KC_S   ,KC_T   ,KC_G   ,                KC_M   ,KC_N   ,KC_E   ,KC_I   ,KC_O   ,KC_QUOT,
    KC_LSFT,KC_Z   ,KC_X   ,KC_C   ,KC_D   ,KC_V   ,                KC_K   ,KC_H   ,SR_COMM,SR_DOT ,SR_QUES,KC_RSFT,
                            KC_LALT,TD_LWIN,KC_LCTL,KC_LSFT,SFT_ENT,ST_SPC ,TT(_FN),KC_RALT,
                            KC_ESC ,                QMKBEST,KC_CAPS,                 SR_IME
    ),
    [_FN] = LAYOUT(
    KC_F1  ,KC_F2  ,KC_F3  ,KC_F4  ,KC_F5  ,KC_F6  ,                KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_F11 ,KC_F12 ,
    _______,KC_PSLS,KC_7   ,KC_8   ,KC_9   ,KC_PMNS,                KC_PGUP,KC_HOME,KC_UP  ,KC_END ,KC_INS ,_______,
    _______,KC_PAST,KC_4   ,KC_5   ,KC_6   ,KC_PPLS,                KC_PGDN,KC_LEFT,KC_DOWN,KC_RGHT,KC_DEL ,_______,
    _______,_______,KC_1   ,KC_2   ,KC_3   ,_______,                _______,_______,_______,_______,_______,_______,
                            KC_EQL ,TD_DOT ,KC_0   ,KC_PENT,_______,_______,TT(_FN),_______,
                            _______,                _______,_______,                _______
    )
};

// Initialize variable holding the binary
// representation of active modifiers.
uint8_t mod_state;
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    // Store the current modifier state in the variable for later reference
    mod_state = get_mods();
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                tap_code16(C(KC_C));
            } else {
                // when keycode QMKBEST is released
                tap_code16(C(KC_V));
            }
            break;
        // R1 keys
        case SR_COMM:{
            // Initialize a boolean variable that keeps track
            // of the comma key status: registered or not?
            static bool commakey_registered;
            if (record->event.pressed) {
                // Detect the activation of either shift keys
                if (mod_state & MOD_MASK_SHIFT) {
                    // First temporarily canceling both shifts so that
                    // shift isn't applied to the KC_COMMA keycode
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_SCOLON);
                    // Update the boolean variable to reflect the status of KC_COMMA
                    commakey_registered = true;
                    // Reapplying modifier state so that the held shift key(s)
                    // still work even after having tapped the comma/semicolon key.
                    set_mods(mod_state);
                    return false;
                }
            } else {
                // on release of KC_COMMA
                // In case KC_SCOLON is still being sent even after the release of KC_COMMA
                if (commakey_registered) {
                    unregister_code(KC_SCOLON);
                    commakey_registered = false;
                    return false;
                }
            }
            // Let QMK process the KC_COMMA keycode as usual outside of shift
            return true;
        }
        case SR_DOT:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_COLON);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_COLON);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_QUES:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_EXCLAIM);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_EXCLAIM);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        // R4 keys
        case SR_PIPE:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_CIRCUMFLEX);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_CIRCUMFLEX);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_AT:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_GRAVE);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code(KC_GRAVE);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_HASH:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_TILDE);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_TILDE);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_ASTR:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_AMPERSAND);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_AMPERSAND);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_PERC:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_DOLLAR);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_DOLLAR);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_LABK:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_RIGHT_ANGLE_BRACKET);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_RIGHT_ANGLE_BRACKET);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_LPRN:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_RIGHT_PAREN);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_RIGHT_PAREN);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_LBRC:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_RBRACKET);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code(KC_RBRACKET);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_LCBR:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code16(KC_RIGHT_CURLY_BRACE);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code16(KC_RIGHT_CURLY_BRACE);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
        case SR_SLSH:{
            static bool this_key_registered;
            if (record->event.pressed) {
                if (mod_state & MOD_MASK_SHIFT) {
                    del_mods(MOD_MASK_SHIFT);
                    register_code(KC_BSLASH);
                    this_key_registered = true;
                    set_mods(mod_state);
                    return false;
                }
            } else {
                if (this_key_registered) {
                    unregister_code(KC_BSLASH);
                    this_key_registered = false;
                    return false;
                }
            }
            return true;
        }
    }
    return true;
}
