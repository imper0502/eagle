#pragma once

enum combos {
  ST_MK_LAYER,
  NE_MC_PLAY,
  RST_SFT,
  NEI_LAYER,
  COMBO_LENGTH
};
uint16_t COMBO_LEN = COMBO_LENGTH;

const uint16_t PROGMEM st_combo[] = {KC_S, KC_T, COMBO_END};
const uint16_t PROGMEM ne_combo[] = {KC_N, KC_E, COMBO_END};

combo_t key_combos[] = {
    [ST_MK_LAYER] = COMBO(st_combo, MO(_MK)),
    [NE_MC_PLAY] = COMBO(ne_combo, DM_PLY1),
};