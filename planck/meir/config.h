#pragma once

#ifdef AUDIO_ENABLE
    #define STARTUP_SONG SONG(PLANCK_SOUND)
    // #define STARTUP_SONG SONG(NO_SOUND)

    #define DEFAULT_LAYER_SONGS { SONG(QWERTY_SOUND), \
                                  SONG(COLEMAK_SOUND), \
                                  SONG(DVORAK_SOUND) \
                                }
#endif

/*
 * MIDI options
 */

/* Prevent use of disabled MIDI features in the keymap */
//#define MIDI_ENABLE_STRICT 1

/* enable basic MIDI features:
   - MIDI notes can be sent when in Music mode is on
*/

#define MIDI_BASIC

/* enable advanced MIDI features:
   - MIDI notes can be added to the keymap
   - Octave shift and transpose
   - Virtual sustain, portamento, and modulation wheel
   - etc.
*/
//#define MIDI_ADVANCED

/* override number of MIDI tone keycodes (each octave adds 12 keycodes and allocates 12 bytes) */
//#define MIDI_TONE_KEYCODE_OCTAVES 2

// Most tactile encoders have detents every 4 stages
#define ENCODER_RESOLUTION 4


// place overrides here
#ifdef DEBOUNCE
#undef DEBOUNCE
#endif
#define DEBOUNCE 2
#define MOUSEKEY_INTERVAL           10
#define MOUSEKEY_DELAY              0
#define MOUSEKEY_TIME_TO_MAX        120
#define MOUSEKEY_MAX_SPEED          6
#define MOUSEKEY_WHEEL_DELAY        0
#define MOUSEKEY_WHEEL_MAX_SPEED    2
#define MOUSEKEY_WHEEL_TIME_TO_MAX  120
#define TAPPING_TOGGLE         1
#define TAPPING_TERM           200
#define FORCE_NKRO
#define PERMISSIVE_HOLD
