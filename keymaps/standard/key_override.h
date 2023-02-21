/* Key Override */
#pragma once
const key_override_t circ_override = ko_make_basic(MOD_MASK_SHIFT, KC_CIRCUMFLEX, G(KC_S));            // ^
const key_override_t at_override   = ko_make_basic(MOD_MASK_SHIFT, KC_AT, KC_CALCULATOR);              // @  
const key_override_t hash_override = ko_make_basic(MOD_MASK_SHIFT, KC_HASH, KC_MEDIA_PREV_TRACK);      // #
const key_override_t dlr_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOLLAR, KC_MEDIA_PLAY_PAUSE);    // $
const key_override_t ampr_override = ko_make_basic(MOD_MASK_SHIFT, KC_AMPERSAND, KC_MEDIA_NEXT_TRACK); // & 
const key_override_t astr_override = ko_make_basic(MOD_MASK_SHIFT, KC_ASTERISK, KC_AUDIO_MUTE);        // * 
const key_override_t ques_override = ko_make_basic(MOD_MASK_SHIFT, KC_QUESTION, KC_AUDIO_VOL_DOWN);    // ?
const key_override_t exlm_override = ko_make_basic(MOD_MASK_SHIFT, KC_EXCLAIM, KC_AUDIO_VOL_UP);       // !
const key_override_t grv_override  = ko_make_basic(MOD_MASK_SHIFT, KC_GRAVE, KC_BRIGHTNESS_DOWN);      // `
const key_override_t tild_override = ko_make_basic(MOD_MASK_SHIFT, KC_TILDE, KC_BRIGHTNESS_UP);        // ~

const key_override_t slsh_override = ko_make_basic(MOD_MASK_SHIFT, KC_SLASH, KC_PERCENT);              // /%

const key_override_t comm_override = ko_make_basic(MOD_MASK_SHIFT, KC_COMMA, KC_SCOLON);               // ,;
const key_override_t dot_override  = ko_make_basic(MOD_MASK_SHIFT, KC_DOT, KC_COLON);                  // .:
const key_override_t labk_override = ko_make_basic(MOD_MASK_SHIFT, KC_LEFT_ANGLE_BRACKET, KC_LEFT_PAREN);
const key_override_t rabk_override = ko_make_basic(MOD_MASK_SHIFT, KC_RIGHT_ANGLE_BRACKET, KC_RIGHT_PAREN);

const key_override_t **key_overrides = (const key_override_t *[]) {
    &circ_override,
    &at_override  ,
    &hash_override,
    &dlr_override ,
    &ampr_override,
    &astr_override,
    &ques_override,
    &exlm_override,
    &grv_override ,
    &tild_override,
    &slsh_override,
    &comm_override,
    &dot_override ,
    &labk_override,
    &rabk_override,
    NULL // Null terminate the array of overrides!
};
