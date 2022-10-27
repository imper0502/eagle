#pragma once

#include "key_override.h"

#include "tap_dance.h"
#define TD_LANG TD(IME_CAPSLOCK)
#define ALT_TAB TD(ALT_TABLE)
#define ALT_LYS TD(ALT_LAYERS)
#define CPY_PST TD(COPY_PASTE_LAYERSLOCK)
#define INS_SHT TD(INSERT_SCREENSHOT_LAYERS)

#ifdef CONSOLE_ENABLE
#include "print.h"
#endif

#define GUI_ESC LGUI_T(KC_ESC)
#define OS_LSFT OSM(MOD_LSFT)
#define OS_RSFT OSM(MOD_RSFT)
#define OS_L_FN OSL(_FN)

#define MK_TAB  LT(_MK, KC_TAB)
#define FN_MINS LT(0, KC_MINS)
#define FN_EQL  LT(0, KC_EQL)
#define FN_SPC  LT(_FN, KC_SPC)
#define FN_RCTL LM(_FN, MOD_RCTL)
#define FN_RALT LM(_FN, MOD_RALT)

#define ALT_ESC A(KC_ESC)
#define NEW_TAB C(KC_T)
#define CLS_TAB C(KC_W)
#define PRV_TAB C(KC_PGUP)
#define NXT_TAB C(KC_PGDN)
#define PRV_WIN LCA(KC_LEFT)
#define NXT_WIN LCA(KC_RIGHT)
#define PRV_PG  C(S(KC_PGUP))
#define NXT_PG  C(S(KC_PGDN))