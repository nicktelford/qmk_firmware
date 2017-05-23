#include "ergodox.h"
#include "led.h"
#include "mousekey.h"
#include "debug.h"
#include "action_layer.h"
#include "action_util.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols layer
#define MDIA 2 // media layer
#define LOCK 3 // shift-lock layer

#define LSymb 0 // left symbol-shift key
#define LMdia 1 // left media-shift key
#define LLock 2 // left shift-lock key
#define RSymb 3 // right symbol-shift key
#define RMdia 4 // right media-shift key
#define RLock 5 // right shift-lock key

#define MUL   6 // mouse up left
#define MUR   7 // mouse up right
#define MDL   8 // mouse down left
#define MDR   9 // mouse down right

/*
 * The Linux Ordinary Layout for the Ergodox EZ keyboard, v1.0
 * 
 * Based on the modified Ordinary Layout by Nicholas Keene 
 * ergodoxez@nicholaskeene.com
 * 
 * Details: readme.md
 *          https://github.com/nrrkeene/qmk_firmware/tree/master/keyboard/ergodox_ez/keymaps/ordinary-linux
 */

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/******* Base Layer ********************************************************************************************************
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * | Lock   `~ |   1  |   2  |   3  |   4  |   5  | ESC  |           |  -   |   6  |   7  |   8  |   9  |   0  | =+   Lock |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * | Media Tab |   Q  |   W  |   E  |   R  |   T  |   -  |           |  =   |   Y  |   U  |   I  |   O  |   P  | \|  Media |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * | Symbol    |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |  ;   | '" Symbol |
 * |-----------+------+------+------+------+------|Shift |           | Tab  |------+------+------+------+------+-----------|
 * | LShift    |   Z  |   X  |   C  |   V  |   B  | -Tab |           |      |   N  |   M  |   ,  |   .  |  /   |    RShift |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     | LCtrl | Meh  |Hyper | LAlt | LGui |                                       | RGui | RAlt | Hyper|  Meh | RCtrl |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | Home | End  |           | Left | Right|
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | PgUp |           |  Up  |      |      |
 *                                  |Backsp| Del  |------|           |------| Enter| Space|
 *                                  |      |      | PgDn |           | Down |      |      |
 *                                  `--------------------'           `--------------------'
 */
[BASE] = KEYMAP(
// left hand
 F(LLock)  ,KC_1   ,KC_2   ,KC_3   ,KC_4  ,KC_5  ,KC_ESC
,F(LMdia)  ,KC_Q   ,KC_W   ,KC_E   ,KC_R  ,KC_T  ,KC_MINS
,M(LSymb)  ,KC_A   ,KC_S   ,KC_D   ,KC_F  ,KC_G
,KC_LSFT   ,KC_Z   ,KC_X   ,KC_C   ,KC_V  ,KC_B  ,LSFT(KC_TAB)
,KC_LCTL   ,KC_MEH ,KC_HYPR,KC_LALT,KC_LGUI
                                         ,KC_HOME,KC_END
                                                 ,KC_PGUP
                                 ,KC_BSPC,KC_DEL ,KC_PGDN
                                                                      // right hand
                                                                     ,KC_MINS ,KC_6   ,KC_7   ,KC_8   ,KC_9    ,KC_0     ,F(RLock)
                                                                     ,KC_EQL  ,KC_Y   ,KC_U   ,KC_I   ,KC_O    ,KC_P     ,F(RMdia)
                                                                              ,KC_H   ,KC_J   ,KC_K   ,KC_L    ,KC_SCLN  ,F(RSymb)
                                                                     ,KC_TAB  ,KC_N   ,KC_M   ,KC_COMM,KC_DOT  ,KC_SLSH  ,KC_RSFT
                                                                                      ,KC_RGUI,KC_RALT,KC_HYPR ,KC_MEH   ,KC_RCTL
                                                                     ,KC_LEFT ,KC_RGHT
                                                                     ,KC_UP
                                                                     ,KC_DOWN ,KC_ENT ,KC_SPC
    ),

/******* Symbols Layer *****************************************************************************************************
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  F1  |  F2  |  F3  |  F4  |  F5  | Esc  |           |  -   |  F6  |  F7  |  F8  |  F9  |  F10 |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |   !  |   @  |   {  |   }  |   <  |Paste |           |Paste | Home | PgDn | PgUp |  End |   ~  |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |   #  |   $  |   (  |   )  |   >  |------|           |------| Left | Down |  Up  |Right |   `  |           |
 * |-----------+------+------+------+------+------| Copy |           | Copy |------+------+------+------+------+-----------|
 * |           |   %  |   ^  |   [  |   ]  |   £  |      |           |      |   &  |   |  |   \  |   *  |   /  |           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     | LCtrl | Meh  |Hyper | LAlt | LGui |                                       | RGui | RAlt | Hyper|  Meh | RCtrl |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | Home | End  |           | Left | Right|
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | PgUp |           |  Up  |      |      |
 *                                  |Backsp| Del  |------|           |------| Enter| Space|
 *                                  |      |      | PgDn |           | Down |      |      |
 *                                  `--------------------'           `--------------------'
 */
[SYMB] = KEYMAP(
// left hand
 KC_TRNS ,KC_F1   ,KC_F2   ,KC_F3   ,KC_F4   ,KC_F5        ,KC_ESC
,KC_TRNS ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,LSFT(KC_COMM),S(KC_INS)
,KC_TRNS ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,LSFT(KC_DOT)
,KC_TRNS ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,UC(0x00A3)   ,LCTL(KC_INS)
,KC_LCTL ,KC_MEH  ,KC_HYPR ,KC_LALT ,KC_LGUI
                                         ,KC_HOME,KC_END
                                                 ,KC_PGUP
                                 ,KC_BSPC,KC_DEL ,KC_PGDN
                                                                     // right hand
                                                                     ,KC_MINS     ,KC_F6  ,KC_F7  ,KC_F8  ,KC_F9  ,KC_F10 ,KC_TRNS
                                                                     ,S(KC_INS)   ,KC_HOME,KC_PGDN,KC_PGUP,KC_END ,KC_TILD,KC_TRNS
                                                                                  ,KC_LEFT,KC_DOWN,KC_UP  ,KC_RGHT,KC_GRV ,KC_TRNS
                                                                     ,LCTL(KC_INS),KC_AMPR,KC_PIPE,KC_BSLS,KC_ASTR,KC_SLSH,KC_TRNS
                                                                                          ,KC_RGUI,KC_RALT,KC_HYPR,KC_MEH ,KC_RCTL
                                                                     ,KC_LEFT ,KC_RGHT
                                                                     ,KC_UP
                                                                     ,KC_DOWN ,KC_ENT ,KC_SPC
),

/******* Media Layer *******************************************************************************************************
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           | F11  | F12  | F13  | F14  | F15  | Esc  |           | Lock | F16  | F17  | F18  | F19  | F20  |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |   !  |   @  |   {  |   }  |   <  |Play/ |           |Play/ |MsLClk|MsScDn|MsScUp|MsRClk|Interr|           |
 * |-----------+------+------+------+------+------|Pause |           |Pause |------+------+------+------+------+-----------|
 * |           |   #  |   $  |   (  |   )  |   >  |------|           |------|MsLeft|MsDown| MsUp |MsRght| EOF  |           |
 * |-----------+------+------+------+------+------| Mute |           | Mute |------+------+------+------+------+-----------|
 * |           |   %  |   ^  |   [  |   ]  |   £  |      |           |      | Prev | VolDn| VolUp| Next |Backgr|           |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *     | LCtrl | Meh  |Hyper | LAlt | LGui |                                       | RGui | RAlt | Hyper|  Meh | RCtrl |
 *     `-----------------------------------'                                       `-----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         | Home | End  |           | Left | Right|
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      | PgUp |           |  Up  |      |      |
 *                                  |Backsp| Del  |------|           |------| Enter| Space|
 *                                  |      |      | PgDn |           | Down |      |      |
 *                                  `--------------------'           `--------------------'
 */
[MDIA] = KEYMAP(
// left hand
 KC_TRNS ,KC_F11  ,KC_F12  ,KC_F13  ,KC_F14  ,KC_F15       ,KC_ESC
,KC_TRNS ,KC_EXLM ,KC_AT   ,KC_LCBR ,KC_RCBR ,LSFT(KC_COMM),KC_MPLY
,KC_TRNS ,KC_HASH ,KC_DLR  ,KC_LPRN ,KC_RPRN ,LSFT(KC_DOT)  
,KC_TRNS ,KC_PERC ,KC_CIRC ,KC_LBRC ,KC_RBRC ,UC(0x00A3)     ,KC_MUTE
,KC_LCTL   ,KC_MEH ,KC_HYPR,KC_LALT ,KC_LGUI
                                         ,KC_HOME,KC_END
                                                 ,KC_PGUP
                                 ,KC_BSPC,KC_DEL ,KC_PGDN
                                                                     // right hand
                                                                     ,LCTL(LALT(KC_L)),KC_F16 ,KC_F17 ,KC_F18 ,KC_F19 ,KC_F20    ,KC_TRNS
                                                                     ,KC_MPLY         ,KC_BTN1,KC_WH_D,KC_WH_U,KC_BTN2,LCTL(KC_C),KC_TRNS
                                                                                      ,KC_MS_L,KC_MS_D,KC_MS_U,KC_MS_R,LCTL(KC_D),KC_TRNS
                                                                     ,KC_MUTE         ,KC_MPRV,KC_VOLD,KC_VOLU,KC_MNXT,LCTL(KC_Z),KC_TRNS
                                                                                              ,KC_RGUI,KC_RALT,KC_HYPR,KC_MEH    ,KC_RCTL
                                                                     ,KC_LEFT ,KC_RGHT
                                                                     ,KC_UP
                                                                     ,KC_DOWN ,KC_ENT ,KC_SPC
),

/******* Lock Layer ********************************************************************************************************
 *
 * ,-----------------------------------------------------.           ,-----------------------------------------------------.
 * |           |  Esc |      |      |      |      |      |           |      |      |      |      |      | Bspc |           |
 * |-----------+------+------+------+------+-------------|           |------+------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |      |           |      |      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * |           |      |      |      |      |      |------|           |------|      |      |      |      |      |           |
 * |-----------+------+------+------+------+------|      |           |      |------+------+------+------+------+-----------|
 * | Caps LOCK |      |      |      |      |      |      |           |      |      |      |      |      |      | Caps LOCK |
 * `-----------+------+------+------+------+-------------'           `-------------+------+------+------+------+-----------'
 *      |      |      |      |      |      |                                       |      |      |      |      |      |
 *      `----------------------------------'                                       `----------------------------------'
 *                                         ,-------------.           ,-------------.
 *                                         |      |      |           |      |      |
 *                                  ,------|------|------|           |------+------+------.
 *                                  |      |      |      |           |      |      |      |
 *                                  |      |      |------|           |------|      |      |
 *                                  |      |      |      |           |      |      |      |
 *                                  `--------------------'           `--------------------'
 */
[LOCK] = KEYMAP(
// left hand
 KC_TRNS ,KC_ESC  ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_CAPS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                             ,KC_TRNS ,KC_TRNS
                                                      ,KC_TRNS
                                     ,KC_TRNS,KC_TRNS ,KC_TRNS
                                                                     // right hand
                                                                     ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_BSPC ,KC_TRNS
                                                                     ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                              ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS
                                                                     ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_CAPS
                                                                                       ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS ,KC_TRNS

                                                                     ,KC_TRNS ,KC_TRNS
                                                                     ,KC_TRNS
                                                                     ,KC_TRNS ,KC_TRNS ,KC_TRNS
    )
};

const uint16_t PROGMEM fn_actions[] = {
     // the six faux shift keys are implemented as macro taps
     [LSymb] = ACTION_MACRO_TAP(LSymb)
    ,[LMdia] = ACTION_MACRO_TAP(LMdia)
    ,[LLock] = ACTION_MACRO_TAP(LLock)
    ,[RSymb] = ACTION_MACRO_TAP(RSymb)
    ,[RMdia] = ACTION_MACRO_TAP(RMdia)
    ,[RLock] = ACTION_MACRO_TAP(RLock)
};

uint16_t symb_shift = 0; // there are two shift keys for each layer, and two lock
uint16_t mdia_shift = 0; // keys; we increment a counter for each key pressed and
uint16_t shift_lock = 0; // decrement when released.

bool symb_lock = false;  // when shift-lock is used in conjunction with a shift
bool mdia_lock = false;  // key the lock flag is toggled

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        // shift and lock between layers

        case LSymb:
        if (record->event.pressed) {
            symb_shift++;
            if(shift_lock) symb_lock = !symb_lock;
            layer_on(SYMB);
        } else {
            symb_shift--;
            if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
        }
        break;

        case LMdia:
        if (record->event.pressed) {
            if (record->tap.count && !shift_lock) {
                register_code(KC_TAB);
            } else {
                mdia_shift++;
                if(shift_lock) mdia_lock = !mdia_lock;
                layer_on(MDIA);
            }
        } else {
            if(record->tap.count && !shift_lock) {
                unregister_code(KC_TAB);
            } else {
                mdia_shift--;
                if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
            }
        }
        break;

        case LLock:
        if (record->event.pressed) {
            shift_lock++;
            if(symb_shift) symb_lock = !symb_lock;
            if(mdia_shift) mdia_lock = !mdia_lock;
            if(!record->tap.count && (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))) {
                register_code(KC_CAPS);
                unregister_code(KC_CAPS);
            }
            layer_on(LOCK);
          } else {
            if(record->tap.count && !record->tap.interrupted && !symb_shift && !mdia_shift) {
                register_code(KC_GRV);
                unregister_code(KC_GRV);
            }
            shift_lock--;
            if(!shift_lock) layer_off(LOCK);
        }
        break;

        case RSymb:
        if (record->event.pressed) {
            if (record->tap.count && !shift_lock) {
                register_code(KC_QUOT);
            } else {
                symb_shift++;
                if(shift_lock) symb_lock = !symb_lock;
                layer_on(SYMB);
            }
        } else {
            if(record->tap.count && !shift_lock) {
                unregister_code(KC_QUOT);
            } else {
                symb_shift--;
                if((!symb_shift) && (!symb_lock)) layer_off(SYMB);
            }
        }
        break;

        case RMdia:
        if (record->event.pressed) {
            if (record->tap.count && !shift_lock) {
                register_code(KC_BSLS);
            } else {
                mdia_shift++;
                if(shift_lock) mdia_lock = !mdia_lock;
                layer_on(MDIA);
            }
        } else {
            if(record->tap.count && !shift_lock) {
                unregister_code(KC_BSLS);
            } else {
                mdia_shift--;
                if((!mdia_shift) && (!mdia_lock)) layer_off(MDIA);
            }
        }
        break;

        case RLock:
        if (record->event.pressed) {
            shift_lock++;
            if(symb_shift) symb_lock = !symb_lock;
            if(mdia_shift) mdia_lock = !mdia_lock;
            if(!record->tap.count && (keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT)))) {
                    register_code(KC_CAPS);
                    unregister_code(KC_CAPS);
            } 
            layer_on(LOCK);
        } else {
            if (record->tap.count && !record->tap.interrupted && !symb_shift && !mdia_shift) {
                register_code(KC_EQL);
                unregister_code(KC_EQL);
            }
            shift_lock--;
            if(!shift_lock) layer_off(LOCK);
        }
        break;

        // mouse diagonals

        case MUL: // mouse up left
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MUR: // mouse up right
        if (record->event.pressed) {
            mousekey_on(KC_MS_UP);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_UP);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        case MDL: // mouse down left
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_LEFT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_LEFT);
            mousekey_send();
        }
        break;

        case MDR: // mouse down right
        if (record->event.pressed) {
            mousekey_on(KC_MS_DOWN);
            mousekey_on(KC_MS_RIGHT);
            mousekey_send();
        } else {
            mousekey_off(KC_MS_DOWN);
            mousekey_off(KC_MS_RIGHT);
            mousekey_send();
        }
        break;

        default:
            // none
            break;
    }
    
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {

};

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {
    // shift or caps lock turns on red light
    if((keyboard_report->mods & (MOD_BIT(KC_LSFT) | MOD_BIT(KC_RSFT))) || (host_keyboard_leds() & (1<<USB_LED_CAPS_LOCK))) {
        ergodox_right_led_1_on();
    } else {
        ergodox_right_led_1_off();
    }

    // Symbol layer turns on green light
    if(layer_state & (1UL<<SYMB)) {
        ergodox_right_led_2_on();
    } else {
        ergodox_right_led_2_off();
    }

    // Media layer turns on blue light
    if(layer_state & (1UL<<MDIA)) {
        ergodox_right_led_3_on();
    } else {
        ergodox_right_led_3_off();
    }
};

