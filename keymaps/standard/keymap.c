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

#include "layer.h"

#include "key_override.h"

#include "tap_dance.h"

#ifdef COMBO_ENABLE
#    include "combo.h"
#endif

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

#include "keycode_user.h"

/* Layer Keymaps */
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BS] = LAYOUT(
        OS_L_FN, KC_ASTR, KC_AT  , KC_HASH, KC_DLR , KC_AMPR,                   KC_GRV , KC_LPRN, KC_LBRC, KC_LCBR, KC_LABK, OS_L_FN,
        MK_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                   KC_J   , KC_L   , KC_U   , KC_Y   , KC_SLSH, KC_BSLS,
        GUI_ESC, KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                   KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUES,
 LSFT_T(KC_DEL), KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                   KC_K   , KC_H   , KC_COMM, KC_DOT , KC_QUOT, KC_RSFT,
                                   ALT_LYS, KC_LCTL, OS_LSFT, KC_BSPC, KC_ENT , FN_SPC , FN_MINS, FN_EQL ,
                          XXXXXXX,                            CPY_PST, INS_SHT,                            XXXXXXX
    ),
    [_QW] = LAYOUT(
        KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                   KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , _______,
        KC_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                   KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
        KC_CAPS, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
        KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                   KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                   _______, _______, _______, _______, _______, _______, _______, _______,
                          XXXXXXX,                            _______, _______,                            XXXXXXX
    ),
    [_MK] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, TG(_MK), PRV_WIN, NEW_TAB, NXT_WIN, XXXXXXX,                   DM_REC2, KC_WH_L, KC_MS_U, KC_WH_R, KC_WH_U, XXXXXXX,
        _______, XXXXXXX, PRV_TAB, ALT_TAB, NXT_TAB, XXXXXXX,                   DM_REC1, KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D, XXXXXXX,
        _______, XXXXXXX, PRV_PG , CLS_TAB, NXT_PG , XXXXXXX,                   DM_RSTP, DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX,
                                   _______, _______, _______, _______, KC_BTN1, KC_BTN3, KC_BTN2, KC_BTN5,
                          XXXXXXX,                            _______, KC_BTN4,                            XXXXXXX
    ),
    [_NP] = LAYOUT(
        _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
        KC_TAB , KC_PPLS, KC_7   , KC_8   , KC_9   , KC_PAST,                   KC_PAST, KC_7   , KC_8   , KC_9   , KC_PPLS, KC_TAB ,
        KC_ESC , KC_PMNS, KC_4   , KC_5   , KC_6   , KC_PSLS,                   KC_PSLS, KC_4   , KC_5   , KC_6   , KC_PMNS, KC_ESC ,
        KC_COMM, KC_EQL , KC_1   , KC_2   , KC_3   , KC_PERC,                   KC_PERC, KC_1   , KC_2   , KC_3   , KC_EQL , KC_COMM,
                                   KC_DOT , KC_0   , KC_PENT, _______, _______, FN_SPC , KC_0   , KC_DOT ,
                          XXXXXXX,                            _______, _______,                            XXXXXXX
    ),
    [_FN] = LAYOUT(
        TD(F_1), TD(F_2), TD(F_3), TD(F_4), TD(F_5), TD(F_6),                   TD(F_7), TD(F_8), TD(F_9), TD(F10), TD(F11), TD(F12),
        KC_TAB , KC_PPLS, KC_7   , KC_8   , KC_9   , KC_PAST,                   KC_PGUP, KC_HOME, KC_UP  , KC_END , ALT_TAB, KC_BRIU,
        KC_ESC , KC_PMNS, KC_4   , KC_5   , KC_6   , KC_PSLS,                   KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, ALT_ESC, KC_BRID,
        KC_COMM, KC_EQL , KC_1   , KC_2   , KC_3   , KC_PERC,                   KC_MUTE, KC_VOLD, KC_VOLU, KC_MPRV, KC_MPLY, KC_MNXT,
                                   KC_DOT , KC_0   , KC_PENT, _______, _______, TO(_BS), KC_RCTL, KC_RALT,
                          XXXXXXX,                            _______, _______,                            XXXXXXX
    ),
    [CMD] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, TG(_QW), CG_NORM, TG(_FN), KC_PSCR, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX,  RESET , KC_SLCK, CG_TOGG, TG(_QW),                   CG_SWAP, KC_NLCK, EEP_RST, EEP_RST, CG_TOGG, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, KC_CAPS,  DEBUG , XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                          XXXXXXX,                            XXXXXXX, XXXXXXX,                          XXXXXXX
    )
};

/* LED Behavior */
void keyboard_pre_init_user(void) {
    setPinOutput(TXLED);
    setPinOutput(RXLED);
}

typedef enum {
    OFF, FLASH, ON
} led_status_t;

led_status_t  rx_led_status;
led_status_t  tx_led_status;
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
    case _MK:
        tx_led_status = FLASH;
        break;
    case _NP:
    case _FN:
        tx_led_status = ON;
        break;
    case CMD:
        tx_led_status = FLASH;
        rx_led_status = FLASH;
        break;
    default:
        tx_led_status = OFF;
        rx_led_status = OFF;
        break;
    }
  return state;
}

uint16_t _timer = 0;
bool next_led_pins_state = !LED_PIN_ON_STATE;
void matrix_scan_user(void) {
    switch (tx_led_status) {
    case ON:
        next_led_pins_state = LED_PIN_ON_STATE;
        break;
    case FLASH:
        if (timer_elapsed(_timer) > TAPPING_TERM) {
            next_led_pins_state = !next_led_pins_state;
            _timer = timer_read();
        }
        break;
    default:
        next_led_pins_state = !LED_PIN_ON_STATE;
        break;
    }
    switch (rx_led_status) {
    case FLASH:
        writePin(RXLED, !next_led_pins_state);
        break;
    default:
        writePin(RXLED, !host_keyboard_led_state().caps_lock);
        break;
    }
    writePin(TXLED, next_led_pins_state);
}

/* Key Behavior */
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FN_SPC:
        return TAPPING_TERM - 25;
    case CPY_PST:
        return TAPPING_TERM - 75;
    case ALT_TAB:
        return TAPPING_TERM + 500;
    case ALT_LYS:
        return TAPPING_TERM + 25;
    default:
        return TAPPING_TERM;
    }
}

bool get_tapping_force_hold(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case FN_SPC :
        return true;
    default:
        return false;
    }
}

#ifdef CONSOLE_ENABLE
void keyboard_post_init_user(void) {
  debug_enable=true;
  debug_matrix=true;
  debug_keyboard=true;
  debug_mouse=true;
}
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    dprintf("KL: kc: 0x%04X, col: %2u, row: %2u, pressed: %u, time: %5u, int: %u, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
    switch (keycode) {
    case LT(0, KC_MINS):
        if (!record->tap.count) {
            if (record->event.pressed) {
                add_mods(MOD_RCTL);
                layer_on(_FN);
            }else {
                layer_off(_FN);
                del_mods(MOD_RCTL);
            }
            return false;
        }
        break;
    case LT(0, KC_EQL):
        if (!record->tap.count) {
            if (record->event.pressed) {
                add_mods(MOD_LALT);
                layer_on(_FN);
            } else {
                layer_off(_FN);
                del_mods(MOD_LALT);
            }
            return false;
        }
        break;
    }
    return true;
}

void post_process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
    case KC_LSFT:
    case KC_RSFT:
    case OS_LSFT:
    case OS_RSFT:
        get_mods() == MOD_MASK_SHIFT ? layer_on(CMD) : layer_off(CMD);
        break;
    case KC_ESC:
    case KC_GESC:
    case KC_CAPS:
        clear_mods();
    case GUI_ESC:
    default:
        return;
    }
}

/* Tap Dance */
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

void td_alt_layers_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case SINGLE_TAP:           register_code(KC_CAPS); return;
        case SINGLE_HOLD: register_mods(MOD_BIT(KC_LALT)); return;
        case TAP_THEN_HOLD:             layer_invert(_FN); return;
        case TAP_TAP_HOLD:              layer_invert(_MK); return;
        default:             /* This line is necessary. */ return;
    }
}

void td_alt_layers_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:           unregister_code(KC_CAPS); return;
        case SINGLE_HOLD: unregister_mods(MOD_BIT(KC_LALT)); return;
        case TAP_THEN_HOLD:               layer_invert(_FN); return;
        case TAP_TAP_HOLD:                layer_invert(_MK); return;
        default:               /* This line is necessary. */ return;
    }
}

void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = current_dance(state);
    switch (td_state) {
        case SINGLE_TAP:                   register_code16(C(KC_V)); return;
        case DUAL_TAP:                            layer_invert(_NP); return;
        case TRIPLE_TAP:                          layer_invert(_MK); return;
        case QUAD_TAP:                              layer_move(_BS); return;
        case SINGLE_HOLD:                       tap_code16(C(KC_C)); return;
        case TAP_THEN_HOLD:                     tap_code16(C(KC_X)); return;
        case TAP_TAP_HOLD: tap_code16(C(KC_A)); tap_code16(C(KC_C)); return;
        case TRI_TAP_HOLD: tap_code16(C(KC_A)); tap_code16(C(KC_X)); return;
        default:                                    layer_move(_BS); return;
    }
}

void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP: unregister_code16(C(KC_V)); return;
        case SINGLE_HOLD:
        case TAP_THEN_HOLD:
        case TAP_TAP_HOLD:
        case TRI_TAP_HOLD:      tap_code16(C(KC_V)); return;
        default:       /* This line is necessary. */ return;
    }
}

void td_insert_screenshot_finished(qk_tap_dance_state_t *state, void *user_data) {
    if (get_mods() == 0) {
            td_state = current_dance(state);
            switch (td_state) {
            case SINGLE_TAP: register_code16(LSG(KC_S)); return;
            case DUAL_TAP:            layer_invert(_NP); return;
            case TRIPLE_TAP:          layer_invert(_MK); return;
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
#ifdef ENCODER_ENABLE
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
#endif
