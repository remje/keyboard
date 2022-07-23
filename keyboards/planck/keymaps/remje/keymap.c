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
  _QWERTY,
  _AZERTY,
  _BEPO,
  _MOUSE,
  _LOWER,
  _RAISE,
  _ADJUST,
  _FUNCTIONS
};

enum planck_keycodes {
  QWERTY = SAFE_RANGE,
  AZERTY,
  BEPO,
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

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mouse| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = LAYOUT_planck_grid(
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
    KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT ,
    TO(_MOUSE), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
),

/* Azerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   A  |   Z  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   Q  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   M  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   >  |   W  |   X  |   C  |   V  |   B  |   N  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Mouse| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_AZERTY] = LAYOUT_planck_grid(
    KC_TAB,     FR_A,    FR_Z,    FR_E,    FR_R,    FR_T,    FR_Y,    FR_U,    FR_I,    FR_O,    FR_P,                    KC_BSPC,
    KC_ESC,     FR_Q,    FR_S,    FR_D,    FR_F,    FR_G,    FR_H,    FR_J,    FR_K,    FR_L,    FR_M,                    KC_QUOT,
    KC_LSFT,    FR_LABK, FR_W,    FR_X,    FR_C,    FR_V,    FR_B,    FR_N,    FR_COMM, FR_SCLN, LT(_FUNCTIONS, FR_COLN), KC_ENT ,
    TO(_MOUSE), KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,                   KC_RGHT
),

/* Bepo
 * ,-----------------------------------------------------------------------------------.
 * | Tab  :w
 * |   '  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  |   A  |   O  |   E  |   U  |   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Shift|   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Brite| Ctrl | Alt  | GUI  |Lower |    Space    |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 *   KC_TAB,  KC_QUOT, KC_COMM, KC_DOT,  KC_P,    KC_Y,    KC_F,    KC_G,    KC_C,    KC_R,    KC_L,    KC_BSPC,
 *   KC_ESC,  KC_A,    KC_O,    KC_E,    KC_U,    KC_I,    KC_D,    KC_H,    KC_T,    KC_N,    KC_S,    KC_SLSH,
 *   KC_LSFT, KC_SCLN, KC_Q,    KC_J,    KC_K,    KC_X,    KC_B,    KC_M,    KC_W,    KC_V,    KC_Z,    KC_ENT ,
 *   BACKLIT, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
 *
 *
 * ,-----------------------------------------------------------------------------------.
 * |   W  |   B  |   É  |   P  |   O  |   È  |   ^  |   V  |   D  |   L  |   J  |   Z  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Tab  |   A  |   U  |   I  |   E  |   ,  |   C  |   T  |   S  |   R  |   N  |   M  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Ê/Shft|   À  |   Y  |   X  |   .  |   K  |   '  |   Q  |   G  |   H  |   F  |Ç/Shft|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Esc  | Ctrl | Alt  | GUI  |Del/- |  Space/AWM  |Ent/Ra| BckSp| AltGr| Ctrl | Mouse|
 * `-----------------------------------------------------------------------------------'
 */
[_BEPO] = LAYOUT_planck_grid(
    BP_W          , BP_B   , BP_EACU,         BP_P   ,            BP_O    , BP_EGRV , BP_DCIR , BP_V              , BP_D   , BP_L   ,                BP_J   ,       BP_Z    ,
    KC_TAB        , BP_A   , BP_U   ,         BP_I   ,            BP_E    , BP_COMM , BP_C    , BP_T              , BP_S   , BP_R   ,                BP_N   ,       BP_M    ,
    SFT_T(BP_ECIR), BP_AGRV, BP_Y   ,         BP_X   ,            BP_DOT  , BP_K    , BP_QUOT , BP_Q              , BP_G   , BP_H   , LT(_FUNCTIONS, BP_F)  , SFT_T(BP_CCED),
    KC_ESC        , KC_LCTL, KC_LALT, LGUI_T(BP_SLSH), LT(_LOWER, BP_MINS), KC_SPACE, KC_SPACE, LT(_RAISE, KC_ENT), KC_BSPC, KC_RALT,                KC_RCTL,    TO(_MOUSE)
),
/* Mouse
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |  Up  |      |      |      |Accel2|Accel1|Accel0|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      | Left | Down | Right|      |ScrolL|ScrolD|ScrolU|ScrolR|      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | BEPO |      |      |      |      |Middle Click |LftClk|RhtClk|      |      | Azer |
 * `-----------------------------------------------------------------------------------'
 */
[_MOUSE] = LAYOUT_planck_grid(
	      _______, _______, _______, KC_MS_U, _______, _______, _______, KC_ACL2, KC_ACL1, KC_ACL0, _______, _______,
	      _______, _______, KC_MS_L, KC_MS_D, KC_MS_R, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    TO(_BEPO), _______, _______, _______, _______, _______, KC_BTN3, KC_BTN1, KC_BTN2, _______, TO(_QWERTY), TO(_AZERTY)
),
/*
 *  [_MOUSE] = LAYOUT_planck_grid(
 *   KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
 *   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
 *   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
 *   _______, _______, _______, _______, _______, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
 *),
 */
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      | Paste|      |      |   €  |   7  |   8  |   9  |   /  | Bsp  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |CapsLo|AutoKp|      | Yank |   0  |   $  |   #  |   4  |   5  |   6  |   *  |  =   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ^  |  à   |      |      |      |  â   |   %  |   1  |   2  |   3  |   -  | Enter|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ù  |  é   |  è   |  ç   |      |             |   ,  |   0  |   .  |   +  |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_planck_grid(
    _______,    _______,    _______ , TD(TD_PASTE), _______, _______, BP_EURO,            BP_7    , BP_8   , BP_9   , BP_SLSH, KC_BSPC,
    KC_CAPS, C(A(BP_A)),    _______ , TD(TD_YANK) , BP_0   , BP_DLR , BP_HASH,            BP_4    , BP_5   , BP_6   , BP_ASTR, BP_EQL ,
    FR_CIRC,    FR_AGRV,    _______ ,     _______ , _______, _______, BP_PERC,            BP_1    , BP_2   , BP_3   , BP_MINS, KC_ENT ,
    FR_UGRV,    FR_EACU,   FR_EGRV  ,    FR_CCED ,  _______, _______, _______, LT(_RAISE, BP_COMM), BP_0   , BP_DOT , BP_PLUS, XXXXXXX
),
/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ù  |  é   |  è   |  ç   |  à   |             |  €   | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/*[_LOWER] = LAYOUT_planck_grid(
*    KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
*    KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
*    _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
*    FR_UGRV, FR_EACU, FR_EGRV, FR_CCED, FR_AGRV, _______, _______, _______,    KC_MNXT,    KC_VOLD, KC_VOLU, KC_MPLY
*),
*/
/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
/*[_RAISE] = LAYOUT_planck_grid(
 *   KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
 *   KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
 *   _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
 *   _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
 *),
 */
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
),
/* Function keys
 * ,-----------------------------------------------------------------------------------.
 * |      |  F1  |  F2  |  F3  |  F4  |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F5  |  F6  |  F7  |  F8  |      |      | Ctrl |  Alt |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |  F9  |  F10 |  F11 |  F12 |      |      |      |      | Mute |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |             |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_FUNCTIONS] = LAYOUT_planck_grid(
    _______, KC_F1  , KC_F2  , KC_F3  , KC_F4  , _______, _______, _______, _______, _______, _______, _______,
    _______, KC_F5  , KC_F6  , KC_F7  , KC_F8  , _______, _______, KC_LCTL, KC_LALT, _______, _______, _______,
    _______, KC_F9  , KC_F10 , KC_F11 , KC_F12 , _______, _______, _______, _______, KC_MUTE, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY
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

