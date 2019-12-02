#include QMK_KEYBOARD_H


extern keymap_config_t keymap_config;




// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _L1 1
#define _L2 2
#define _L3 3
#define _WINDOWS 4
#define _LW1 5
#define _LW2 6
#define _LW3 7
#define _TMUX 8
// #define _ADJUST 16



// enum {
//   LAYER_DANCE0 = 0,
//   LAYER_DANCE1,
//   LAYER_DANCE2
// };

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

// Custom macros
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
// #define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
// #define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Alt+Shift)
#define ALT_GRV     ALT_T(KC_GRV)               // Tap for Backtick, hold for Alt (Ctrl+Alt+Shift)
#define EXPAND      M(0)                        // Expand Atom nested functions
#define COLLAPSE    M(1)                        // Collapse Atom nested functions
#define JS_FUNC    M(2)                        // => {}
#define CTRL_ALT_DEL    M(3)                   // Self explanitory
#define GB_PASTE    M(4)                       // Git Bash Paste
#define GB_RESET    M(5)                       // Git Bash Reset
#define VS_COLLAPSE    M(6)                     // Visual studio colapse
#define SSD          M(7)                     // Linux Screenshot Display
#define SSW          M(8)                     // Linux Screenshot Window
#define SSS          M(9)                     // Linux Screenshot Selection
#define TMUX         M(10)                     // Tmux (ctrl + B)


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_QWERTY] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
  CTL_T(KC_BSLS) ,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,    KC_QUOT     ,
/*|---------      `-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    SFT_T(KC_ESC)  ,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    RSFT_T(KC_UP)    ,
/*|----------     `-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
    JS_FUNC  ,   ALT_GRV     ,   KC_LGUI ,  LT(1,KC_ENT)  ,  LT(2,KC_SPC)    ,  LT(10, KC_RGUI) , KC_LEFT, KC_DOWN,   KC_RIGHT  ),
/*`--------- +---------------+---------  +-------^^^------+-------^^^------- +----------+--------+--------+--------------'*/


/* Lower
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   `     |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | Ctrl/ \  |   .  |   *  |   +  |   =  |   _  |   _  |   4  |   5  |   6  |   .  |   '    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc |   ,  |   /  |   -  |  =   |  _  |       |   1  |   2  |   3  |      | VolU  |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 *|SceenShot|   Alt/` |  GUI   |    L1/Enter  |    L2/Space  |  GUI    |Expand| VolD |Collapse|
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_L1] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
  KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______, KC_DOT, KC_ASTR, KC_KP_PLUS, KC_EQUAL, KC_UNDS, KC_UNDS,  KC_4  ,  KC_5  ,  KC_6  , KC_DOT ,    _______     ,
/*|--------`-------`--------`--------    `--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______,  KC_COMM,  KC_SLSH, KC_MINS, KC_KP_EQUAL, KC_UNDS, XXXXXXX,   KC_1,    KC_2,    KC_3,  XXXXXXX,   KC_PGUP,
/*|----------`-------`-------- `--------`--------    `--------`--------`--------`--------`--------`--------`---------------|*/
  SWIN_T(KC_4),   _______   , _______ ,     _______    ,      _______       , _______ , EXPAND  ,KC_PGDOWN,    COLLAPSE ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------   +--------------'*/

/* Raise
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   ~     |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | Ctrl/ \  |  .   |  /   |  -   |   =  |   _  |   _  |   [  |   ]  |   {  |   }  |   |    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc  |  ,   |  *   |  +   |  =   |  _  |       |      | WIN |   [  |   ]  |  VolU |
 * |----------- `------`------`------`------`-----'-------`------`------`------`------`-------|
 *|SceenShot|   Alt/`  |  GUI   |    L1/Enter  |    L2/Space  |  GUI    | (    | VolD |    )  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_L2] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
   KC_TILD ,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_DEL       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ , KC_DOT, KC_SLSH, KC_MINS, KC_EQUAL, KC_UNDS, KC_UNDS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,    KC_PIPE     ,
/*|---------`-------`--------`-------- `--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______ , KC_COMM, KC_ASTR, KC_KP_PLUS,  KC_KP_EQUAL,  KC_UNDS, XXXXXXX, XXXXXXX,  TO(4)  , KC_LBRC, KC_RBRC, KC__VOLUP,
/*|----------`-------`--------`--------    `--------    `--------`--------`-------- `--------   `--------`--------`---------------|*/
  SWIN_T(KC_4),   _______     , _______ ,     _______    ,     _______       , _______ , KC_LABK , KC_VOLD,     KC_RABK   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* Adjust (Lower + Raise)
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |         | Reset|      |      |      |      |      |      |      |      |      |  Reset  |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * |          |      |      |      |      |AGnorm|AGswap|Qwerty|Colemk|Dvorak|      |        |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * |           |      |      |      |      |     |       |      |      |      |      |       |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |        |         |        |              |              |         |      |      |       |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
// [_ADJUST] = LAYOUT_arrow(
// /*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
//     _______, RESET , _______, _______, _______, _______, _______, _______, _______, _______, _______,      RESET      ,
// /*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
//     _______ ,_______, _______, _______, _______, AG_NORM, AG_SWAP,  QWERTY, COLEMAK,  DVORAK, _______,    _______     ,
// /*|---------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
//     _______  ,_______, _______, _______, _______, _______, _______, _______, _______, _______, _______,    _______    ,
// /*|----------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
//     _______ ,   _______     , _______ ,     _______    ,     _______     , _______ ,  _______, _______,     _______   ),
// /*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/



/* Qwerty/WINDOWS
 *
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   Tab   |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  |  Bksp   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | GUI/ \  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |   '    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc |   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Sft/Up|
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 * |   => { |  Alt/`  |  CTRL  |    L1/Enter  |    L2/Space  |Ctrl+Sft | Left | Down | Right  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_WINDOWS] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
    KC_TAB,   KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC      ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    GUI_T(KC_BSLS) ,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,    KC_QUOT     ,
/*|---------      `-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`----------------|*/
    SFT_T(KC_ESC)  ,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH,    RSFT_T(KC_UP)    ,
/*|----------     `-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`---------------|*/
  SWIN_T(KC_4),   ALT_GRV     ,  CTL_T(KC_BSLS) ,  LT(5,KC_ENT)  ,  LT(6,KC_SPC)    ,C_S_T(KC_BSLS), KC_LEFT, KC_DOWN,   KC_RIGHT  ),
/*`--------- +---------------+---------         +-------^^^------+-------^^^------- +----------+--------+--------+--------------'*/


/* Lower
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   `     |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | GUI/ \   |   .  |   *  |   +  |   =  |   _  |   _  |   4  |   5  |   6  |   .  |   '    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc |   ,  |   /  |   -  |  =   |  _  |       |   1  |   2  |   3  |      | VolU  |
 * |-----------`------`------`------`------`-----'-------`------`------`------`------`-------|
 *|SceenShot|   Alt/` |  CRTL   |    L5/Enter  |    L6/Space  |  C+A+D  |Expand| VolD |Collapse|
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_LW1] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
  KC_GRAVE,   KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______, KC_DOT, KC_ASTR, KC_KP_PLUS, KC_EQUAL, KC_UNDS, KC_UNDS,  KC_4  ,  KC_5  ,  KC_6  , KC_DOT ,    _______     ,
/*|--------`-------`--------`--------    `--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______,  KC_COMM,  KC_SLSH, KC_MINS, KC_KP_EQUAL, KC_UNDS, XXXXXXX,   KC_1,    KC_2,    KC_3,  XXXXXXX,   KC_PGUP,
/*|----------`-------`-------- `--------`--------    `--------`--------`--------`--------`--------`--------`---------------|*/
  _______   ,   _______   , _______ ,     _______    ,      _______       , _______ , GB_RESET  ,KC_PGDOWN,    VS_COLLAPSE ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------   +--------------'*/

/* Raise WINDOWS
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   ~     |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | GUI/ \   |  .   |  /   |  -   |   =  |   _  |   _  |   [  |   ]  |   {  |   }  |   |    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc  |  ,   |  *   |  +   |  =   |  _  |       |GBPASTE| MAC |   [  |   ]  | VolU |
 * |----------- `------`------`------`------`-----'-------`------`------`------`------`------|
 * | CAD    |  Alt/`  |  CRTL  |    L5/Enter  |    L6/Space  | C+A+D   |  (   | VolD |    )  |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
[_LW2] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
   KC_TILD ,KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN,    KC_DEL       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
    _______ , KC_DOT, KC_SLSH, KC_MINS, KC_EQUAL, KC_UNDS, KC_UNDS, KC_LBRC, KC_RBRC, KC_LCBR, KC_RCBR,    KC_PIPE     ,
/*|---------`-------`--------`-------- `--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______ , KC_COMM, KC_ASTR, KC_KP_PLUS,  KC_KP_EQUAL,  KC_UNDS, XXXXXXX, GB_PASTE,  TO(0)   , KC_LBRC, KC_RBRC, KC__VOLUP,
/*|----------`-------`--------`--------    `--------    `--------`--------`-------- `--------   `--------`--------`---------------|*/
   CTRL_ALT_DEL ,   _______     , _______ ,     LT(7, KC_ENT)    ,     _______       , _______ , KC_LABK , KC_VOLD,     KC_RABK   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/
/* Function WINDOWS
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   ~     |   F1 |   F2 |   F3 |   F4 |   F5 | SSD  |LClick|  MUp |RClick| SWUp |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | GUI/ \   |  F6  |  F7  |  F8  |   F9 |  F10 | SSS  |MLeft |MDown |MRight| SWDN |   |    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc | F11  |  F12 |  F13 |  F14 |  F15 | SSW   |      |      |      |      | VolU |
 * |-----------`------`------`------`------`------'-------`------`------`------`------`------|
 * | C-A-D  |  Alt/`  |  CRTL  |    L5/Enter  |    L6/Space  | C+A+D   |      | VolD |       |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */

[_LW3] = LAYOUT_arrow(
/*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
   KC_TILD ,  KC_F1,   KC_F2,  KC_F3 ,  KC_F4 , KC_F5  ,   SSD  , KC_BTN1, KC_MS_U, KC_BTN2, KC_WH_U,    KC_DEL       ,
/*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`------------------|*/
    _______ , KC_F6 , KC_F7  , KC_F8   , KC_F9   , KC_F10,   SSS  , KC_MS_L, KC_MS_D, KC_MS_R, KC_WH_D,    KC_PIPE     ,
/*|---------`-------`--------`-------- `--------`--------`--------`--------`--------`--------`--------`----------------|*/
    _______ , KC_F11 , KC_F12 , KC_F13,  KC_F14, KC_F15 ,    SSW  , XXXXXXX,  XXXXXXX , XXXXXXX, XXXXXXX, KC__VOLUP,
/*|----------`-------`--------`--------`--------`--------`--------`-------- `-------- `--------`--------`--------------|*/
   _______ ,   _______     , _______ ,     _______    ,     _______       , _______ , XXXXXXX , KC_VOLD,     XXXXXXX   ),
/*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

/* TMUX WINDOWS
 * ,---------+------+------+------+------+------+------+------+------+------+------+---------.
 * |   ~     | Tmux |      |      |      |      |      |      |  MUp |   (  | TD)  |   Del   |
 * |---------`------`------`------`------`------`------`------`------`------`------`---------|
 * | GUI/ \   |      |      |      |      |      |      | MLeft| MDown| MRight| TD] |   |    |
 * |----------`------`------`------`------`------`------`------`------`------`------`--------|
 * | Shift/Esc |      |      |      |      |      |       |      | ScUp | ScDn |  TD} |  Home|
 * |-----------`------`------`------`------`------'-------`------`------`------`------`------|
 * | C-A-D  |  Alt/`  |  CRTL  |    L5/Enter  |    L6/Space  | C+A+D   | PGUp | END  |  PGDn |
 *  `-------+---------+--------+-----^^^------+-----^^^------+---------+------+------+-------'
 */
// [_TMUX] = LAYOUT_arrow(
// /*,--------+-------+--------+--------+--------+--------+--------+--------+--------+--------+--------+-----------------.*/
//    KC_TILD ,  TMUX ,   XXXXXXX,  XXXXXXX ,  XXXXXXX , XXXXXXX  , XXXXXXX, KC_BTN1, KC_MS_U, KC_BTN2, TD(TD_PAREN),    KC_DEL       ,
// /*|--------`-------`--------`--------`--------`--------`--------`--------`--------`--------`--------`-----------------|*/
//     _______ , XXXXXXX, XXXXXXX , XXXXXXX , XXXXXXX , XXXXXXX, XXXXXXX, KC_MS_L    , KC_MS_D    , KC_MS_R    , TD(TD_BRACK),    KC_PIPE     ,
// /*|---------`-------`--------`-------- `--------`--------`--------`--------`--------`--------`--------`----------------|*/
//     _______ , XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX , KC_WH_U, TD(TD_CURLY), KC_HOME,
// /*|----------`-------`--------`--------`--------`--------`--------`-------- `--------   `--------`--------`---------------|*/
//    _______ ,   _______     , _______ ,     _______    ,     _______       , _______ , KC_PGUP , KC_END,     KC_PGDOWN   ),
// /*`---------+---------------+---------+-------^^^------+-------^^^-------+----------+--------+--------+--------------'*/

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
          if (record->event.pressed){   // Linux Screen Shot Whole Screen
          return MACRO( T(PSCR),  END  );
          }
        case 8:
          if (record->event.pressed){   // Linux Screen Shot Current Window
          return MACRO( D(LALT), T(PSCR), U(LALT),  END  );
          }
        case 9:
          if (record->event.pressed){   // Linux Screen Shot Selection
          return MACRO( D(LSHIFT), T(PSCR), U(LSHIFT),  END  );
          }
        case 10:
          if (record->event.pressed){   // Tmux
          return MACRO( D(LCTRL), T(B), U(LCTRL),  END  );
          }
      }
    return MACRO_NONE;
};


// Tap Dance
void dance_layers_dance(qk_tap_dance_state_t *state, void *user_data) {
  switch (state->count) {
  case 1:
    return MACRO( T(LSFT()) );  // go to default layer
    break;
  case 2:   // toggle on layer 1
    return MACRO( T(TO(0)), T(TG(1)) );    // to get TRNS layers to work correctly start from here
    break;
  case 3:   // toggle on layer 2
    return MACRO( T(TO(0)), T(TG(1)), T(TG(2)));     // to get TRNS layers to work correctly start from here
    break;
  }
}

qk_tap_dance_action_t tap_dance_actions[] = {
  [LAYER_DANCE0]  = ACTION_TAP_DANCE_DOUBLE(TG(1), TG(2)),
  [LAYER_DANCE1]  = ACTION_TAP_DANCE_DOUBLE(TO(0), TG(2)),
  [LAYER_DANCE2]  = ACTION_TAP_DANCE_DOUBLE(TO(0), TG(1))
  // [LAYER_DANCE]  = ACTION_TAP_DANCE_FN (dance_layers_dance)
};
