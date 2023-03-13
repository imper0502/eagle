/* Tap Dance */
#pragma once

enum tap_dance_names {
    ALT_TABLE,
    ALT_SHIFT_TABLE,
    ALT_LAYERS,
    INSERT_PLUS,
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
void td_alt_sft_tab_each_tap(qk_tap_dance_state_t *state, void *user_data);
void td_alt_sft_tab_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alt_layers_finished(qk_tap_dance_state_t *state, void *user_data);
void td_alt_layers_reset(qk_tap_dance_state_t *state, void *user_data);
void td_insert_plus_finished(qk_tap_dance_state_t *state, void *user_data);
void td_insert_plus_reset(qk_tap_dance_state_t *state, void *user_data);

qk_tap_dance_action_t tap_dance_actions[] = {
    [ALT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_tab_each_tap, td_alt_tab_finished, NULL),
    [ALT_SHIFT_TABLE] = ACTION_TAP_DANCE_FN_ADVANCED(td_alt_sft_tab_each_tap, td_alt_sft_tab_finished, NULL),
    [ALT_LAYERS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_alt_layers_finished, td_alt_layers_reset),
    [INSERT_PLUS] = ACTION_TAP_DANCE_FN_ADVANCED(NULL, td_insert_plus_finished, td_insert_plus_reset),
};

