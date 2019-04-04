/*
Copyright 2015 Jun Wako <wakojun@gmail.com>
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation either version 2 of the License  or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
#include "whitefox.h"
#include "action_layer.h"
#include "eeconfig.h"
extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
// #define _L2 2
// #define _L3 3
#define _WINDOWS 1
#define _GAMING 2
#define _UTILITY 3
#define _BASE_ADJUSTER 4

// #define _LW1 5
// #define _LW2 6
// #define _ADJUST 16

// Fillers to make layering more clear
#define _____ KC_TRNS
#define XXXXX KC_NO

// Mouse stuff    https://beta.docs.qmk.fm/features/feature_mouse_keys
#define MOUSEKEY_DELAY             0
#define MOUSEKEY_INTERVAL          16
#define MOUSEKEY_MAX_SPEED         7
#define MOUSEKEY_TIME_TO_MAX       40

// Custo KC_GRAVE,m macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define ALT_GRV     ALT_T(KC_GRV)               // Tap for Backtick, hold for Alt (Ctrl+Alt+Shift)
#define EXPAND       M(0)                        // Expand Atom nested functions
#define COLLAPSE     M(1)                        // Collapse Atom nested functions
#define JS_FUNC      M(2)                        // => {}
#define CTRL_ALT_DEL M(3)                   // Self explanitory
#define GB_PASTE     M(4)                       // Git Bash Paste
#define GB_RESET     M(5)                       // Git Bash Reset
#define VS_COLLAPSE  M(6)
#define SLDTY_FUNC   M(7)                      // Visual studio colapse
#define UNCLICK_MODS   M(8)                      // sends up code for all mods
#define CTRL_BSLSH CTL_T(KC_BSLS)
#define GUI_BSLSH GUI_T(KC_BSLS)
#define T_WIN DF(_WINDOWS)
#define T_GM DF(_GAMING)
#define T_MAIN DF(_QWERTY)

#define SHFT_ESC SFT_T(KC_ESC)
#define T2_SPC LT(_UTILITY,KC_SPC)
#define SHFT_ESC SFT_T(KC_ESC)

#define Layer_JS_FUNC LT(_UTILITY,JS_FUNC)
#define Base_INS LT(_BASE_ADJUSTER,KC_INS)



const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Layer 0: Default Layer
      * Qwerty
      *
      * ,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
      * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   \  |   `  |Insert|
      * |------`------`------`------`------`------`------`------`------`------`------`------`------`------`------`------|
      * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |  Bksp    |Delete|
      * |---------`------`------`------`------`------`------`------`------`------`------`------`------`----------`------|
      * | Ctrl/ \  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |  Enter       |Pg Up |
      * |----------`------`------`------`------`------`------`------`------`------`------`--------`--------------`------|
      * | Shift/Esc  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Sft       | Up    |Pg Dn |
      * |------------`------`------`------`------`-----'-------`------`------`------`------`-------------`-------`------|
      * | => {  |  Alt/` | GUI   |            Space                       | GUI   | GUI   |       | Left | Down  | Right |
      *  `------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------|
      */
    [_QWERTY] = LAYOUT_truefox( \
      /*,------+------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        KC_GRAVE, KC_1,  KC_2,  KC_3,  KC_4,  KC_5,  KC_6,  KC_7,  KC_8,  KC_9,   KC_0, KC_MINS, KC_EQL, KC_BSLS, KC_GRAVE, Base_INS, \
      /*,------     +------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        KC_TAB,    KC_Q,   KC_W,  KC_E,  KC_R,  KC_T,  KC_Y,  KC_U,  KC_I,  KC_O,  KC_P, KC_LBRC, KC_RBRC,  KC_BSPC,  KC_DEL, \
      /*|---------`------`------`------`------`------`------`------`------`------`------` ------`  ------`----------`------| */
        CTRL_BSLSH,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,  KC_H,  KC_J,  KC_K,  KC_L,  KC_SCLN, KC_QUOT,  KC_ENT,  KC_PGUP,\
      /*|--------- `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------| */
             SHFT_ESC, KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,  KC_N,  KC_M, KC_COMM, KC_DOT, KC_SLSH,    KC_RSFT,  KC_UP,  KC_PGDN,\
      /*|------------`------`------`------`------`-----'-------`------`------ `------ `------  `-------------`-------`------| */
        SLDTY_FUNC, ALT_GRV, KC_LGUI,                  T2_SPC      ,          KC_RALT, KC_RCTL,     KC_LEFT, KC_DOWN, KC_RGHT \
      /*`-------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------| */
    ),
    /* Layer 1: Windows
    * ,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   \  |   `  |Insert|
    * |------`------`------`------`------`------`------`------`------`------`------`------`------`------`------`------|
    * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |  Bksp    |Delete|
    * |---------`------`------`------`------`------`------`------`------`------`------`------`------`----------`------|
    * | GUI/ \   |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |  Enter       |Pg Up |
    * |----------`------`------`------`------`------`------`------`------`------`------`--------`--------------`------|
    * | Shift/Esc  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Sft       |  Up   |Pg Dn |
    * |------------`------`------`------`------`-----'-------`------`------`------`------`-------------`-------`------|
    * | => {  |  Alt/` | CTRL/\|            Space                       | GUI   | GUI   |       | Left | Down  |Right |
    *  `------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------|
    */
    [_WINDOWS] = LAYOUT_truefox( \
      /*,------+------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        _____, _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,   _____, _____, _____, _____, _____, _____, \
      /*,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------..*/
        _____,  _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____, _____,   _____,  _____, \
        /*|---------    `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        GUI_BSLSH    ,  _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____,   _____, _____,  _____,    _____,\
        /*|--------- `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        _____        , _____,  _____,  _____,  _____,  _____,  _____,  _____, _____, _____, _____,    _____,  _____,  _____,\
        /*|------------`------`------`------`------`-----'-------`------`------ `------ `------  `-------------`-------`------| */
        _____, _____, CTL_T(KC_BSLS),                 T2_SPC      ,      _____, _____,       _____, _____, _____  \
        /*`-------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+       +------+-------`------| */
    ),
    /* Layer 2: Utility
    * ,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   -  |   =  |   \  |   `  |   *  |
    * |------`------`------`------`------`------`------`------`------`------`------`------`------`------`------`------|
    * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |   [  |   ]  |  Bksp    |   *  |
    * |---------`------`------`------`------`------`------`------`------`------`------`------`------`----------`------|
    * | GUI/ \  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |  Enter       |   *  |
    * |----------`------`------`------`------`------`------`------`------`------`------`--------`--------------`------|
    * | Shift/Esc  |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |   Sft/Up    | Right |   *  |
    * |------------`------`------`------`------`-----'-------`------`------`------`------`-------------`-------`------|
    * | => {  |  Alt/` | CTRL/\|            Space                       | GUI   | GUI   |       | Down | Right |   *  |
    *  `------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------|
    */
    [_GAMING] = LAYOUT_truefox( \
      /*,------+------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        KC_ESC, _____, _____, _____, _____, _____, _____, _____, _____, _____,  _____, _____, _____, _____, _____, _____, \
      /*,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------..*/
        _____,       _____,  _____, _____,  _____,  _____,  _____,  _____,  _____,  _____,  _____,   _____, _____,   _____,  KC__VOLUP, \
        /*|--------- `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        KC_LCTRL,         _____, _____, _____, _____, _____, _____, _____, _____, _____,  _____, _____,  _____,    KC__VOLDOWN,\
        /*|---------    `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        _____,   _____, _____, _____, _____, _____, _____, _____ , _____, _____, _____,    _____,  _____,  KC_GRAVE,\
        /*|------------`------`------`------`------`-----'-------`------`------ `------ `------  `-------------`-------`------| */
        TG(_GAMING), _____, _____,                 KC_SPC,                         _____,   _____,       _____, _____, _____  \
      /*`-------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------| */
    ),

    /* Layer 3: Utility
    * ,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------.
    * | ESC  |GB_RES|GB_PST|VS_COL|AM_EXP|AM_COL|      |      |      |      |      |      |      |      |      | Play |
    * |------`------`------`------`------`------`------`------`------`------`------`------`------`------`------`------|
    * |   Tab   |   ,  |   *  |   +  |   =  |   _  |      |      |      |      |      |   [  |   ]  |  Bksp    | VolUp|
    * |---------`------`------`------`------`------`------`------`------`------`------`------`------`----------`------|
    * | GUI/ \   |   .  |   /  |   -  |   =  |   _  |      |       |     |      |   (  |   )    |  Enter       | VolDn|
    * |----------`------`------`------`------`------`------`------`------`------`------`--------`--------------`------|
    * | Shift/Esc  |   |  |  `   |   '  |   "  |      |      |      |      |   {  |   }  |   Sft/Up    |mouseU| Mute |
    * |------------`------`------`------`------`-----'-------`------`------`------`------`-------------`-------`------|
    * | C_A_D |  Alt/` | CTRL/\|            Space                       |mouseRC|mouseLC|       |mouseL|mouseD|mouseR|
    *  `------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------|
    */
    [_UTILITY] = LAYOUT_truefox( \
      /*,------+------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        _____, GB_RESET, GB_PASTE, VS_COLLAPSE, EXPAND, COLLAPSE, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, KC_MPLY, \
      /*,------+------+------    +------      +------+------    +------+------+------+------+------+------ +------+------+------+------..*/
        _____,       KC_COMM, KC_ASTR, KC_PLUS,  KC_EQUAL,  KC_UNDS, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX,   KC_LCBR, KC_RCBR,   KC_WH_U,  KC__VOLUP, \
        /*|--------- `------`------  `------     `------    `------   `------` ------`------`------`  ------`  ------`  ------`----------`------| */
        _____,           KC_DOT, KC_SLSH,  KC_MINS,  KC_EQUAL,  KC_UNDS, XXXXX, XXXXX, XXXXX, XXXXX,  KC_LPRN, KC_RPRN,  KC_WH_D,    KC__VOLDOWN,\
        /*|---------    `------`------  `------   `------    `------   `------   `------  `------  `------`  ------`  ------  `  ------`----------`------| */
        _____,        KC_PIPE,  KC_GRAVE,  KC_QUOT,  KC_DQT,  XXXXX,  XXXXX, XXXXX, XXXXX  , KC_LCBR, KC_RCBR,    KC_BTN1,  KC_MS_U,  KC_MUTE,\
        /*|------------`------`------   `------   `------  `-----  '-------`------`------  `------  `------  `-------------`-------`------| */
        CTRL_ALT_DEL, _____, _____,                              _____,      _____, KC_BTN2,       KC_MS_L, KC_MS_D, KC_MS_R  \
        /*`-------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+       +------+-------`------| */
    ),


    [_BASE_ADJUSTER] = LAYOUT_truefox( \
      /*,------+------+------+------+------+------+------+------+------+------+------+  ------+ ------+------+  ------+------..*/
        T_MAIN, T_WIN, T_GM , XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX, XXXXX,  XXXXX, XXXXX, XXXXX, XXXXX, UNCLICK_MODS, _____, \
      /*,------+------+------+------+------+------+------+------+------+------+------+------+------+------+------+------..*/
        XXXXX,       XXXXX,  XXXXX, XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,   XXXXX, XXXXX,   XXXXX,  EEP_RST, \
        /*|--------- `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        XXXXX, XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX, XXXXX,  XXXXX,    XXXXX,\
        /*|---------    `------`------`------`------`------`------`------`------`------`  ------`  ------`  ------`----------`------| */
        XXXXX, XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX,  XXXXX , XXXXX, XXXXX, XXXXX,    XXXXX,  XXXXX,  XXXXX,\
        /*|------------`------`------`------`------`-----'-------`------`---999--- `------ `------  `-------------`-------`------| */
        XXXXX, XXXXX, XXXXX,                 _____,      XXXXX, XXXXX,       XXXXX, XXXXX, XXXXX  \
      /*`-------+--------+-------+-----^^^-----------^^^---------^^^------+-------+--------+      +------+-------`------| */
    ),

};



void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}



const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
      switch(id) {
        case 0:
          if (record->event.pressed){  // Expand Atom nested functions
          return MACRO( D(LGUI), D(LALT), T(LBRC), U(LALT), U(LGUI), END  );
          }
        case 1:
          if (record->event.pressed){  // Collapse Atom nested functions
          return MACRO( D(LGUI), D(LALT), T(RBRC), U(LALT), U(LGUI),  END  );
          }
        case 2:
          if (record->event.pressed){  // => {
            SEND_STRING("=> {");
            return false;
          }
        case 3:
          if (record->event.pressed){  // Ctrl Alt Delete
          return MACRO( D(LCTRL), D(LALT), T(DEL), U(LALT), U(LCTRL),  END  );
          }
        case 4:
          if (record->event.pressed){   // Git Bash Paste
          return MACRO( D(LSHIFT), D(INSERT), U(LSHIFT), U(INSERT),  END  );
          }
        case 5:
          if (record->event.pressed){   // Git Bash Reset
          return MACRO( D(LALT), D(F8), U(LALT), U(F8),  END  );
          }
        case 6:
          if (record->event.pressed){   // Visual Studio Collapse Menus
          return MACRO( D(LCTRL), T(K), U(LCTRL), D(LCTRL), T(2), U(LCTRL),  END  );
          }
        case 7:
          if (record->event.pressed){  // () {}
            return MACRO( D(LSHIFT), T(9), U(LSHIFT),
                          D(LSHIFT), T(0), U(LSHIFT),
                          T(SPC),
                          D(LSHIFT), T(LBRC), U(LSHIFT),
                          D(LSHIFT), T(RBRC), U(LSHIFT),
                          T(LEFT), END );
          }
        case 8:
          if (record->event.pressed){   // Attempt to unstick mods
          return MACRO( U(LCTRL), U(RCTRL), U(LSHIFT), U(RSHIFT), T(LALT), U(RALT),
              U(LGUI), U(RGUI), END  );
          }
      }
    return MACRO_NONE;
};
