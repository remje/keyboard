/* Copyright 2015-2021 Jack Humbert
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "muse.h"
#include "keymap_bepo.h"
#include "keymap_french.h"

enum planck_layers {
  _AZERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ACCENTS,
};

enum planck_keycodes {
  AZERTY = SAFE_RANGE,
  BACKLIT
};

#define RAISE MO(_RAISE)
#define LOWER MO(_LOWER)
#define ACCENTS MO(_ACCENTS)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Del  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   >  |   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |Acct |  Ins  |  Scr |AltGr |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_grid(
    KC_DELETE, FR_A,    FR_Z,    FR_E,    FR_R,         FR_T,    FR_Y,    FR_U,         FR_I,    FR_O,    FR_P,    KC_BSPC,
    KC_TAB,    FR_Q,    FR_S,    FR_D,    FR_F,         FR_G,    FR_H,    FR_J,         FR_K,    FR_L,    FR_M,    MO(_ACCENTS),
    KC_LSFT,   FR_LABK, FR_W,    FR_X,    FR_C,         FR_V,    FR_B,    FR_N,         FR_COMM, FR_SCLN, FR_COLN, KC_ENT ,
    KC_ESCAPE, KC_LCTL, KC_LALT, KC_LGUI, MO(_LOWER),   KC_SPC,  KC_SPC,  MO(_RAISE),   KC_RSFT, KC_INS,  KC_PSCR, KC_ALGR
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |      |VerrNm| MouUp|  F12 |   F1 |   F2 |   F3 |RgtClk|  7   |  8   |  9   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |MouLft|MouDwn|MouRgt|   F4 |   F5 |   F6 |MidClk|  4   |  5   |  6   |  *   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | Mute |VolUp |VolDwn|   F7 |   F8 |   F9 |LftClk|  1   |  2   |  3   |  -   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |  F10 |  F11 |      |  0   |  .   | Entr |  +   |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    _______, KC_NUM_LOCK, KC_MS_UP,        KC_F12,            KC_F1,   KC_F2,  KC_F3,  KC_MS_BTN2, KC_KP_7, KC_KP_8,   KC_KP_9,     KC_KP_SLASH,
    _______, KC_MS_LEFT,  KC_MS_DOWN,      KC_MS_RIGHT,       KC_F4,   KC_F5,  KC_F6,  KC_MS_BTN3, KC_KP_4, KC_KP_5,   KC_KP_6,     KC_KP_ASTERISK,
    _______, KC_KB_MUTE,  KC_KB_VOLUME_UP, KC_KB_VOLUME_DOWN, KC_F7,   KC_F8,  KC_F9,  KC_MS_BTN1, KC_KP_1, KC_KP_2,   KC_KP_3,     KC_KP_MINUS,
    _______, _______,     _______,         _______,           _______, KC_F10, KC_F11, _______,    KC_KP_0, KC_KP_DOT, KC_KP_ENTER, KC_KP_PLUS
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  €   |  &   |  =   |      |  [   |  ]   |   -  |   _  |   #  |   `  |   @  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |  '   |  "   |  (  |   )   | Left |  Up  | Down | Right|      |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      | °/)  | £/$  | µ *  |  {   |  }   |  §/! |  Deb |  End | Pgup | PgDwn|      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    ALGR(FR_AGRV), FR_AMPR, FR_EQL,  _______, ALGR(FR_LPRN), ALGR(FR_RPRN), FR_MINS, FR_UNDS, ALGR(FR_DQUO), ALGR(FR_EGRV), ALGR(FR_AGRV), ALGR(FR_UNDS),
    _______,       _______, FR_QUOT, FR_DQUO, FR_LPRN,       FR_RPRN,       KC_LEFT, KC_UP,   KC_DOWN,       KC_RIGHT,      _______,       ALGR(FR_MINS),
    _______,       FR_RPRN, FR_DLR,  FR_ASTR, ALGR(FR_QUOT), ALGR(FR_EQL),  FR_EXLM, KC_HOME, KC_END,        KC_PAGE_UP,    KC_PAGE_DOWN,  _______,
    _______,       _______, _______, _______, _______,       _______,       _______, _______,  _______,       _______,       _______,       _______
),
/* Adjust (Lower + Raise)
 *                      v------------------------RGB CONTROL--------------------v
 * ,-----------------------------------------------------------------------------------.
 * |      | Reset|Debug | RGB  |RGBMOD| HUE+ | HUE- | SAT+ | SAT- |BRGTH+|BRGTH-|  Del |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |MUSmod|Aud on|Audoff|AGnorm|AGswap|Qwerty|Azerty| BEPO |Plover| Pause|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|TermOn|TermOf|      |      |Print |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = LAYOUT_planck_grid(
    _______, QK_BOOT, DEBUG,   RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD,  RGB_VAI, RGB_VAD, KC_DEL ,
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, _______,  AZERTY,  _______, _______, KC_PAUSE,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, KC_PRINT_SCREEN,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
),
/* Accents
 * ,-----------------------------------------------------------------------------------.
 * |      |  à   |  ^/¨ |  é   |      |      |      |   ù  |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |  è   |     |       |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |  ç   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ACCENTS] = LAYOUT_planck_grid(
    _______, FR_AGRV, FR_CIRC, FR_EACU, _______, _______, _______, _______, FR_UGRV, _______, _______, _______,
    _______, _______, _______, FR_EGRV, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, FR_CCED, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
),

};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case AZERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_AZERTY);
      }
      return false;
      break;
    case BACKLIT:
      if (record->event.pressed) {
        register_code(KC_RSFT);
        #ifdef BACKLIGHT_ENABLE
          backlight_step();
        #endif
        #ifdef KEYBOARD_planck_rev5
          writePinLow(E6);
        #endif
      } else {
        unregister_code(KC_RSFT);
        #ifdef KEYBOARD_planck_rev5
          writePinHigh(E6);
        #endif
      }
      return false;
      break;
   }
  return true;
}

bool muse_mode = false;
uint8_t last_muse_note = 0;
uint16_t muse_counter = 0;
uint8_t muse_offset = 70;
uint16_t muse_tempo = 50;

bool encoder_update_user(uint8_t index, bool clockwise) {
  if (muse_mode) {
    if (IS_LAYER_ON(_RAISE)) {
      if (clockwise) {
        muse_offset++;
      } else {
        muse_offset--;
      }
    } else {
      if (clockwise) {
        muse_tempo+=1;
      } else {
        muse_tempo-=1;
      }
    }
  } else {
    if (clockwise) {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_DOWN);
      #else
        tap_code(KC_PGDN);
      #endif
    } else {
      #ifdef MOUSEKEY_ENABLE
        tap_code(KC_MS_WH_UP);
      #else
        tap_code(KC_PGUP);
      #endif
    }
  }
    return true;
}

bool dip_switch_update_user(uint8_t index, bool active) {
    switch (index) {
        case 0: {
            break;
        }
        case 1:
            if (active) {
                muse_mode = true;
            } else {
                muse_mode = false;
            }
    }
    return true;
}

void matrix_scan_user(void) {
#ifdef AUDIO_ENABLE
    if (muse_mode) {
        if (muse_counter == 0) {
            uint8_t muse_note = muse_offset + SCALE[muse_clock_pulse()];
            if (muse_note != last_muse_note) {
                stop_note(compute_freq_for_midi_note(last_muse_note));
                play_note(compute_freq_for_midi_note(muse_note), 0xF);
                last_muse_note = muse_note;
            }
        }
        muse_counter = (muse_counter + 1) % muse_tempo;
    } else {
        if (muse_counter) {
            stop_all_notes();
            muse_counter = 0;
        }
    }
#endif
}

bool music_mask_user(uint16_t keycode) {
  switch (keycode) {
    case RAISE:
    case LOWER:
      return false;
    default:
      return true;
  }
}


