/* Key Override */
#pragma once
const key_override_t circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX, KC_TILDE); // ^~
const key_override_t at_override   = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_GRAVE);         // @`
const key_override_t hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_EXCLAIM);     // #!
const key_override_t dlr_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, KC_QUESTION);  // $?

const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT);    // /%
const key_override_t labk_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_LEFT_PAREN);
const key_override_t rabk_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_PAREN);
const key_override_t ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_EXCLAIM);  // ?!
const key_override_t comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);      // ,;
const key_override_t dot_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);         // .:

const key_override_t **key_overrides = (const key_override_t *[]) {
    &circ_override,
    &at_override,
    &hash_override,
    &dlr_override,
    &slsh_override,
    &labk_override,
    &rabk_override,
    &ques_override,
    &comm_override,
    &dot_override,
    NULL // Null terminate the array of overrides!
};
