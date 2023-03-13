#pragma once

enum combos {
  LUC1, LUC2,       RUC1, RUC2,
  LHC1, LHC2, LHC3, RHC1, RHC2, RHC3,
  LLC1, LLC2,       RLC1, RLC2,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM left_upper_combo1[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM left_upper_combo2[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM left_home_combo1[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM left_home_combo2[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM left_home_combo3[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM left_lower_combo1[] = {KC_X, KC_C, COMBO_END};
const uint16_t PROGMEM left_lower_combo2[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM right_upper_combo1[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM right_upper_combo2[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM right_home_combo1[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM right_home_combo2[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM right_home_combo3[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM right_lower_combo1[] = {KC_H, KC_COMM, COMBO_END};
const uint16_t PROGMEM right_lower_combo2[] = {KC_COMM, KC_DOT, COMBO_END};

combo_t key_combos[] = {
    [LUC1] = COMBO(left_upper_combo1, KC_ESC), 
    [LLC1] = COMBO(left_lower_combo1, KC_TAB), 
    [LLC2] = COMBO(left_lower_combo2, DM_REC1),
    [RUC2] = COMBO(right_upper_combo2, KC_INS),
    [RLC1] = COMBO(right_lower_combo1, DM_PLY1),
    [RLC2] = COMBO(right_lower_combo2, KC_ENT)
};  