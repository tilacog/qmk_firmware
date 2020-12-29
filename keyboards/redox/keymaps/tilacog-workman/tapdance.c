// Tap Dance keycodes
enum td_keycodes {
    RSFT_RP,  // Our example key: `RSFT` when held, `)` when tapped. Add additional keycodes for each tapdance.
    TD_HOME_END,
};

// Define a type containing as many tapdance states as you need
typedef enum {  // clang-format off
  SINGLE_TAP,
  SINGLE_HOLD,
  DOUBLE_SINGLE_TAP
} td_state_t;  // clang-format on

// Create a global instance of the tapdance state type
static td_state_t td_state;

// Declare your tapdance functions:

// Function to determine the current tapdance state
uint8_t cur_dance(qk_tap_dance_state_t *state);

// `finished` and `reset` functions for each tapdance keycode
void rsft_rp_finished(qk_tap_dance_state_t *state, void *user_data);
void rsft_rp_reset(qk_tap_dance_state_t *state, void *user_data);

// Determine the tapdance state to return
uint8_t cur_dance(qk_tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed)
            return SINGLE_TAP;
        else
            return SINGLE_HOLD;
    }

    if (state->count == 2)
        return DOUBLE_SINGLE_TAP;
    else
        return 3;  // Any number higher than the maximum state value you return above
}

// Handle the possible states for each tapdance keycode you define:

void rsft_rp_finished(qk_tap_dance_state_t *state, void *user_data) {
    td_state = cur_dance(state);
    switch (td_state) {
        case SINGLE_TAP:
            register_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            register_mods(MOD_BIT(KC_RSFT));
            break;
        case DOUBLE_SINGLE_TAP:  // Allow nesting of 2 parens `))` within tapping term
            tap_code16(KC_RPRN);
            register_code16(KC_RPRN);
    }
}

void rsft_rp_reset(qk_tap_dance_state_t *state, void *user_data) {
    switch (td_state) {
        case SINGLE_TAP:
            unregister_code16(KC_RPRN);
            break;
        case SINGLE_HOLD:
            unregister_mods(MOD_BIT(KC_RSFT));
            break;
        case DOUBLE_SINGLE_TAP:
            unregister_code16(KC_RPRN);
    }
}

// Define `ACTION_TAP_DANCE_FN_ADVANCED()` for each tapdance keycode, passing in `finished` and `reset` functions
qk_tap_dance_action_t tap_dance_actions[] = {  // clang-format off
  [TD_HOME_END] = ACTION_TAP_DANCE_DOUBLE(KC_HOME, KC_END),
  [RSFT_RP] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, rsft_rp_finished, rsft_rp_reset, 75)
};  // clang-format on
