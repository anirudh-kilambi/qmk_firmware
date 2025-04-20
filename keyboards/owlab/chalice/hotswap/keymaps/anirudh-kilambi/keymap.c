/* 
Copyright 2022 Owlab

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

enum chalice_layers {
	_BASE,
	_BASE_RAISE,
	_BASE_LOWER,
	_BASE_ADJUST,
	_GAMING_BASE,
	_GAMING_RAISE,
	_GAMING_LOWER,
	_GAMING_ADJUST
};

enum chalice_keycodes {
	BASE = SAFE_RANGE,
	BASE_RAISE,
	BASE_LOWER,
	BASE_ADJUST,
	GAMING_BASE,
	GAMING_RAISE,
	GAMING_LOWER,
	GAMING_ADJUST
};

enum combo_events {
  COMBO_ENTER,
  COMBO_TAB,
  COMBO_ESC
};

#ifdef COMBO_ENABLE
const uint16_t PROGMEM combo_enter[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_tab[] = {LCTL_T(KC_D), LSFT_T(KC_F), COMBO_END};
const uint16_t PROGMEM combo_esc[] = {KC_J, KC_K, COMBO_END};

// #ifdef KEY_CANCELLATION_ENABLE
// const key_cancellation_t PROGMEM key_cancellation_list[] = {
//     // on key down
//     //       |    key to be released
//     //       |     |
//     [0] = {KC_D, KC_A},
//     [1] = {KC_A, KC_D}
// };
// #endif


combo_t key_combos[COMBO_COUNT] = {
  [COMBO_ENTER] = COMBO(combo_enter,KC_ENT),
  [COMBO_TAB] = COMBO(combo_tab,KC_TAB),
  [COMBO_ESC] = COMBO(combo_esc,KC_ESC)
};
#endif

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

	// The following four keymaps are for standard computer usage.
	[_BASE] = LAYOUT_hot(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, 
		OSM(MOD_LCTL),  LGUI_T(KC_A),    LALT_T(KC_S),    LCTL_T(KC_D),    LSFT_T(KC_F),    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOTE, 
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENTER, KC_ENTER,
		KC_LCTL, KC_LGUI, BASE_LOWER,  BASE_LOWER, KC_SPC,   BASE_RAISE,   KC_RGUI, KC_RALT, KC_RCTL
	),

	[_BASE_RAISE] = LAYOUT_hot(
		KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DOLLAR, KC_PERCENT,    KC_GRV,    KC_0,    KC_LPRN,    KC_RPRN,    KC_DLR,    KC_BSPC,  
		KC_TAB,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, NK_TOGG, KC_GRV, KC_MINS, KC_LBRC, KC_RBRC, KC_EQL,  KC_BSLS, 
		KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_HOME,   KC_END,  KC_F11,  KC_F12,  KC_RSFT, 
		KC_LCTL, KC_LALT, KC_SPC,  BASE_LOWER, BASE_LOWER, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
	),
	[_BASE_LOWER] = LAYOUT_hot(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,  
		KC_TAB, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, NK_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_EQL,  KC_BSLS, 
		KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_COMM,   KC_DOT,   KC_SLSH,  KC_F11,  KC_F12,  KC_RSFT, 
		KC_LCTL, KC_LALT, KC_SPC,  KC_TRNS, KC_TRNS, BASE_RAISE, KC_MPLY, KC_VOLD, KC_VOLU
	),
	[_BASE_ADJUST] = LAYOUT_hot(
		GAMING_BASE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_DEL,  
		KC_TAB, KC_TRNS, KC_TRNS,  KC_F23, KC_TRNS, NK_TOGG, KC_LEFT, KC_DOWN, KC_UP, KC_RIGHT, KC_EQL,  KC_BSLS, 
		KC_LSFT, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F24,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_RSFT, 
		KC_LCTL, KC_LALT, KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_MPLY, KC_VOLD, KC_VOLU
	),
	[_GAMING_BASE] = LAYOUT_hot(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, 
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOTE, 
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENTER, KC_ENTER,
		KC_LCTL, KC_LGUI, KC_SPC,  KC_SPC, GAMING_LOWER, GAMING_RAISE, KC_RGUI, KC_RALT, KC_RCTL
	),
	[_GAMING_RAISE] = LAYOUT_hot(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, 
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOTE, 
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENTER, KC_ENTER,
		KC_LCTL, KC_LGUI, KC_SPC,  KC_SPC, GAMING_LOWER, KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL
	),
	[_GAMING_LOWER] = LAYOUT_hot(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,     KC_BSPC, 
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOTE, 
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENTER, KC_ENTER,
		KC_LCTL, KC_LGUI, KC_SPC,  KC_SPC, KC_TRNS, GAMING_RAISE, KC_RGUI, KC_RALT, KC_RCTL
	),
	[_GAMING_ADJUST] = LAYOUT_hot(
		BASE,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_DEL,  
		KC_ESC,  KC_A,    KC_S,    KC_F23,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    RSFT_T(KC_SCLN),  KC_QUOTE, 
		KC_LSFT, KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_F24,     KC_COMM,  KC_DOT,  KC_SLSH,  KC_ENTER, KC_ENTER,
		KC_LCTL, KC_LGUI, KC_SPC,  KC_SPC, KC_TRNS, KC_TRNS, KC_RGUI, KC_RALT, KC_RCTL
	)

};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  /*for changing layers*/
  switch (keycode) {
        case BASE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_BASE);
          }
          return false;
          break;
        case GAMING_BASE:
          if (record->event.pressed) {
            set_single_persistent_default_layer(_GAMING_BASE);
          }
          return false;
          break;
        case BASE_LOWER:
          if (record->event.pressed) {
            layer_on(_BASE_LOWER);
            update_tri_layer(_BASE_LOWER, _BASE_RAISE, _BASE_ADJUST);
          } else {
            layer_off(_BASE_LOWER);
            update_tri_layer(_BASE_LOWER, _BASE_RAISE, _BASE_ADJUST);
          }
          return false;
          break;
        case BASE_RAISE:
          if (record->event.pressed) {
            layer_on(_BASE_RAISE);
            update_tri_layer(_BASE_LOWER, _BASE_RAISE, _BASE_ADJUST);
          } else {
            layer_off(_BASE_RAISE);
            update_tri_layer(_BASE_LOWER, _BASE_RAISE, _BASE_ADJUST);
          }
          return false;
          break;
        case GAMING_LOWER:
          if (record->event.pressed) {
            layer_on(_GAMING_LOWER);
            update_tri_layer(_GAMING_LOWER, _GAMING_RAISE, _GAMING_ADJUST);
          } else {
            layer_off(_GAMING_LOWER);
            update_tri_layer(_GAMING_LOWER, _GAMING_RAISE, _GAMING_ADJUST);
          }
          return false;
          break;
        case GAMING_RAISE:
          if (record->event.pressed) {
            layer_on(_GAMING_RAISE);
            update_tri_layer(_GAMING_LOWER, _GAMING_RAISE, _GAMING_ADJUST);
          } else {
            layer_off(_GAMING_RAISE);
            update_tri_layer(_GAMING_LOWER, _GAMING_RAISE, _GAMING_ADJUST);
          }
          return false;
          break;
      }
    return true;
};
