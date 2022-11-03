#pragma once

enum combos {
  CD_MK_LAYER,
  HCOMMA_MC_PLAY,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM left_combo[] = {KC_C, KC_D, COMBO_END};
const uint16_t PROGMEM right_combo[] = {KC_H, KC_COMM, COMBO_END};

combo_t key_combos[] = {
    [CD_MK_LAYER] = COMBO(left_combo, MO(_MK)),
    [HCOMMA_MC_PLAY] = COMBO(right_combo, DM_PLY1),
};