/* Tap Dance */
#pragma once

enum tap_dance_names {
    IME_CAPSLOCK,
    ALT_TABLE,
    ALT_LAYERS,
    COPY_PASTE_LAYERSLOCK,
    INSERT_SCREENSHOT_LAYERS,
    F_1,   F_2,   F_3,   F_4,
    F_5,   F_6,   F_7,   F_8,
    F_9,   F10,   F11,   F12,
};

/* Tap Dance */
typedef enum {
    SINGLE_HOLD, SINGLE_TAP,
    TAP_THEN_HOLD, DUAL_TAP,
    TAP_TAP_HOLD,TRIPLE_TAP,
    TRI_TAP_HOLD,  QUAD_TAP,
    OTHERWISE
} td_state_t;

td_state_t current_dance(qk_tap_dance_state_t *state) {
    switch (state->count) {
        case 1:  return (state->interrupted || !state->pressed) ? SINGLE_TAP : SINGLE_HOLD;
        case 2:  return (state->interrupted || !state->pressed) ?   DUAL_TAP : TAP_THEN_HOLD;
        case 3:  return (state->interrupted || !state->pressed) ? TRIPLE_TAP : TAP_TAP_HOLD;
        case 4:  return (state->interrupted || !state->pressed) ?   QUAD_TAP : TRI_TAP_HOLD;
        default: return OTHERWISE;
    }
}

void td_alt_tab_each_tap(qk_tap_dance_state_t *state, void *user_data);
void td_alt_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alt_layers_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alt_layers_reset(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_finished(qk_tap_dance_state_t *state, void *user_data);
void td_copy_paste_reset(qk_tap_dance_state_t *state, void *user_data);
void td_insert_screenshot_finished(qk_tap_dance_state_t *state, void *user_data);
void td_insert_screenshot_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [IME_CAPSLOCK] = ACTION_TAP_DANCE_DOUBLE(S(KC_LALT) , KC_CAPS),
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL),
    [ALT_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alt_layers_finished, td_alt_layers_reset),
    [COPY_PASTE_LAYERSLOCK] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_copy_paste_finished, td_copy_paste_reset),
    [INSERT_SCREENSHOT_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_insert_screenshot_finished, td_insert_screenshot_reset),
    [F_1] = ACTION_TAP_DANCE_DOUBLE(KC_F1, KC_CALC),
    [F_2] = ACTION_TAP_DANCE_DOUBLE(KC_F2, KC_CALC),
    [F_3] = ACTION_TAP_DANCE_DOUBLE(KC_F3, KC_CALC),
    [F_4] = ACTION_TAP_DANCE_DOUBLE(KC_F4, KC_CALC),
    [F_5] = ACTION_TAP_DANCE_DOUBLE(KC_F5, KC_CALC),
    [F_6] = ACTION_TAP_DANCE_DOUBLE(KC_F6, KC_CALC),
    [F_7] = ACTION_TAP_DANCE_DOUBLE(KC_F7, KC_CALC),
    [F_8] = ACTION_TAP_DANCE_DOUBLE(KC_F8, KC_CALC),
    [F_9] = ACTION_TAP_DANCE_DOUBLE(KC_F9, KC_CALC),
    [F10] = ACTION_TAP_DANCE_DOUBLE(KC_F10, KC_CALC),
    [F11] = ACTION_TAP_DANCE_DOUBLE(KC_F11, KC_CALC),
    [F12] = ACTION_TAP_DANCE_DOUBLE(KC_F12, KC_CALC),
};

