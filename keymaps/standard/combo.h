#pragma once

enum combos {
  WF_SFTALT,
  FP_SFTCTL,
  RS_LALT,
  ST_LCTL,
  RST_ALTCTL,
  CD_MC_REC1,
  LU_SFTCTL,
  UY_SFTALT,
  NE_RCTL,
  EI_RALT,
  NEI_ALTCTL,
  HCOMMA_MC_PLAY1,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM left_raise1_combo[] = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM left_raise2_combo[] = {KC_F, KC_P, COMBO_END};
const uint16_t PROGMEM left_home1_combo[] = {KC_R, KC_S, COMBO_END};
const uint16_t PROGMEM left_home2_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM left_home3_combo[] = {KC_R, KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM left_lower_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM right_raise1_combo[] = {KC_L, KC_U, COMBO_END};
const uint16_t PROGMEM right_raise2_combo[] = {KC_U, KC_Y, COMBO_END};
const uint16_t PROGMEM right_home1_combo[] = {KC_N, KC_E, COMBO_END};
const uint16_t PROGMEM right_home2_combo[] = {KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM right_home3_combo[] = {KC_N, KC_E, KC_I, COMBO_END};
const uint16_t PROGMEM right_lower_combo[] = {KC_H, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    [WF_SFTALT] = COMBO(left_raise1_combo, LSA(KC_NO)),
    [FP_SFTCTL] = COMBO(left_raise2_combo, S(C(KC_NO))),
    [RS_LALT] = COMBO(left_home1_combo, KC_LALT),
    [ST_LCTL] = COMBO(left_home2_combo, KC_LCTL),
    [RST_ALTCTL] = COMBO(left_home3_combo, LCA(KC_NO)),
    [CD_MC_REC1] = COMBO(left_lower_combo, DM_REC1),
    [LU_SFTCTL] = COMBO(right_raise1_combo, S(C(KC_NO))),
    [UY_SFTALT] = COMBO(right_raise2_combo, LSA(KC_NO)),
    [NE_RCTL] = COMBO(right_home1_combo, KC_RCTL),
    [EI_RALT] = COMBO(right_home2_combo, KC_RALT),
    [NEI_ALTCTL] = COMBO(right_home3_combo, LCA(KC_NO)), 
    [HCOMMA_MC_PLAY1] = COMBO(right_lower_combo, DM_PLY1),
};  