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
};

enum planck_keycodes {
  AZERTY,
  BACKLIT,
  EXT_PLV
};

//tap dance declarations
enum {
	TD_YANK,
	TD_PASTE
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Del  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp | V
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  '   | V
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   >  |   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   .  |   /  |Enter | V
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Lower |    Space    |Raise |   é  |   à  |   è  |AltGr | V
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_grid(
    KC_DELETE, FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,    KC_BSPC,
    KC_TAB,    FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,    KC_QUOT,
    KC_LSFT,   FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, FR_COLN, KC_ENT ,
    KC_ESCAPE, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   &  |   <  |   >  |   [  |   ]  |   `  |   @  |   +  |   -  |   /  |   *  |   =  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   |  |   ^  |   \  |   (  |   )  |   $  |LftArr|DwnArr| UpArr|RhtArr|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shft |   «  |   »  |   {  |   }  |   ~  |   "  |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      _      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_planck_grid(
    BP_AMPR , BP_LABK, BP_RABK, BP_LBRC, BP_RBRC, RALT(BP_EGRV), BP_AT  ,BP_PLUS, BP_MINS, BP_SLSH, BP_ASTR, BP_EQL ,
    BP_PIPE , BP_CIRC, BP_BSLS, BP_LPRN, BP_RPRN,      BP_DLR  , KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT,_______,  _______,
    KC_LSFT , BP_LDAQ, BP_RDAQ, BP_LCBR, BP_RCBR,      BP_TILD , BP_DQUO, _______, _______, _______, _______, _______,
    _______ , _______, _______, _______, _______,      BP_UNDS , _______, _______, _______, _______, _______, _______
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |  €   |  &   |  %   |  ^   |  [   |  ]   |   -  |   _  |   #  |   `  |   @  |      | V
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLo|AutoKp|      | Yank |   0  |   $  |   #  |   4  |   5  |   6  |   *  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |  à   |      |      |      |  â   |   %  |   1  |   2  |   3  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ù  |  é   |  è   |  ç   |      |             |   ,  |   0  |   .  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    ALGR(FR_AGRV), FR_AMPR, FR_UGRV , FR_CIRC, ALGR(FR_LPRN), ALGR(FR_RPRN), FR_MINS, FR_UNDS, ALGR(FR_DQUO), ALGR(FR_EGRV), ALGR(FR_AGRV), _______,
    KC_CAPS, C(A(BP_A)),    _______ , TD(TD_YANK) , BP_0   , BP_DLR , BP_HASH,            BP_4    , BP_5   , BP_6   , BP_ASTR, BP_EQL ,
    FR_CIRC,    FR_AGRV,    _______ ,     _______ , _______, _______, BP_PERC,            BP_1    , BP_2   , BP_3   , BP_MINS, KC_ENT ,
    FR_UGRV,    FR_EACU,   FR_EGRV  ,    FR_CCED ,  _______, _______, _______, LT(_RAISE, BP_COMM), BP_0   , BP_DOT , BP_PLUS, XXXXXXX
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
    _______, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  AZERTY,   BEPO,    _______, KC_PAUSE,
    _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  TERM_ON, TERM_OFF, _______, _______, KC_PRINT_SCREEN,
    BACKLIT, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______
)

};


layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case AZERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_AZERTY);
      }
      return false;
      break;
    case BEPO:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_BEPO);
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

qk_tap_dance_action_t tap_dance_actions[] = {
    [TD_YANK]  = ACTION_TAP_DANCE_DOUBLE(C(KC_INS), C(BP_C)),
    [TD_PASTE] = ACTION_TAP_DANCE_DOUBLE(S(KC_INS), C(BP_V))
};

