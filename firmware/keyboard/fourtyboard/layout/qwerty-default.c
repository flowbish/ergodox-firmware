/* ----------------------------------------------------------------------------
 * Copyright (c) 2013 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (see "doc/licenses/MIT.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

/**                                                                 description
 * A QWERTY layout adapted from the default Kinesis layout.  The position of
 * the symbol keys on the function layer was (roughly) taken from the Arensito
 * layout.
 *
 * Implements the "layout" section of '.../firmware/keyboard.h'
 */


#include "./common/definitions.h"


// ----------------------------------------------------------------------------
// matrix control
// ----------------------------------------------------------------------------

#include "./common/exec_key.c.h"


// ----------------------------------------------------------------------------
// LED control
// ----------------------------------------------------------------------------

void kb__led__logical_on(char led) {
    switch(led) {
        case 'N': kb__led__on(1); break;  // numlock
        case 'C': kb__led__on(2); break;  // capslock
        case 'S': kb__led__on(3); break;  // scroll lock
        case 'O':                 break;  // compose
        case 'K':                 break;  // kana
    };
}

void kb__led__logical_off(char led) {
    switch(led) {
        case 'N': kb__led__off(1); break;  // numlock
        case 'C': kb__led__off(2); break;  // capslock
        case 'S': kb__led__off(3); break;  // scroll lock
        case 'O':                  break;  // compose
        case 'K':                  break;  // kana
    };
}


// ----------------------------------------------------------------------------
// keys
// ----------------------------------------------------------------------------

#include "./common/keys.c.h"

KEYS__LAYER__NUM_PUSH(10, 3);
KEYS__LAYER__NUM_POP(10);

//KEYS__LAYER__PUSH_POP(1,1)
#define FN1 lpupo1l1

//KEYS__LAYER__PUSH_POP(2,2)
#define FN2 lpupo2l2

// saves current shift state to be restored later
#define SAVE_SHIFT_STATE()                                              \
        struct {                                                        \
        bool left_shift  : 1;                                           \
        bool right_shift : 1;                                           \
        } state = {                                                     \
            .left_shift  = usb__kb__read_key( KEYBOARD__LeftShift  ),   \
            .right_shift = usb__kb__read_key( KEYBOARD__RightShift ),   \
        };
        
// restores shift state saved by SAVE_SHIFT_STATE()
#define RESTORE_SHIFT_STATE()                                           \
        usb__kb__set_key( state.left_shift,  KEYBOARD__LeftShift  );    \
        usb__kb__set_key( state.right_shift, KEYBOARD__RightShift );    \
        usb__kb__send_report();

#define SHIFT_DOWN (state.left_shift || state.right_shift)

// this defines a key that sends a parenthesis when pressed normally
// and a bracket when pressed 
void P(pnbrL) (void) {    
    SAVE_SHIFT_STATE();
    
    // if either shift is held down send "[" (KEYBOARD__LeftBracket_LeftBrace)
    if (SHIFT_DOWN) {
        usb__kb__set_key( false, KEYBOARD__LeftShift  );
        usb__kb__set_key( false, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(press)(KEYBOARD__LeftBracket_LeftBrace);
    }
    // otherwise send "(" (KEYBOARD__9_LeftParenthesis)
    else {
        usb__kb__set_key( true, KEYBOARD__LeftShift  );
        usb__kb__set_key( true, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(press)(KEYBOARD__9_LeftParenthesis);
    }
    
    RESTORE_SHIFT_STATE();
}

void R(pnbrL) (void) {
    SAVE_SHIFT_STATE();
    
    // if either shift is held down send "[" (KEYBOARD__LeftBracket_LeftBrace)
    if (SHIFT_DOWN) {
        usb__kb__set_key( false, KEYBOARD__LeftShift  );
        usb__kb__set_key( false, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(release)(KEYBOARD__LeftBracket_LeftBrace);
    }
    // otherwise send "(" (KEYBOARD__9_LeftParenthesis)
    else {
        usb__kb__set_key( true, KEYBOARD__LeftShift  );
        usb__kb__set_key( true, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(release)(KEYBOARD__9_LeftParenthesis);
    }
    
    RESTORE_SHIFT_STATE();
}

void P(pnbrR) (void) {    
    SAVE_SHIFT_STATE();
    
    // if either shift is held down send "[" (KEYBOARD__LeftBracket_LeftBrace)
    if (SHIFT_DOWN) {
        usb__kb__set_key( false, KEYBOARD__LeftShift  );
        usb__kb__set_key( false, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(press)(KEYBOARD__RightBracket_RightBrace);
    }
    // otherwise send "(" (KEYBOARD__9_LeftParenthesis)
    else {
        usb__kb__set_key( true, KEYBOARD__LeftShift  );
        usb__kb__set_key( true, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(press)(KEYBOARD__0_RightParenthesis);
    }
    
    RESTORE_SHIFT_STATE();
}

void R(pnbrR) (void) {
    SAVE_SHIFT_STATE();
    
    // if either shift is held down send "[" (KEYBOARD__LeftBracket_LeftBrace)
    if (SHIFT_DOWN) {
        usb__kb__set_key( false, KEYBOARD__LeftShift  );
        usb__kb__set_key( false, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(release)(KEYBOARD__RightBracket_RightBrace);
    }
    // otherwise send "(" (KEYBOARD__9_LeftParenthesis)
    else {
        usb__kb__set_key( true, KEYBOARD__LeftShift  );
        usb__kb__set_key( true, KEYBOARD__RightShift  );
        usb__kb__send_report();
        KF(release)(KEYBOARD__0_RightParenthesis);
    }
    
    RESTORE_SHIFT_STATE();
}
// ----------------------------------------------------------------------------
// layout
// ----------------------------------------------------------------------------

#include "./common/matrix.h"


static _layout_t _layout = {

// ............................................................................
   
   MATRIX_LAYER( //layer 0: default sort
// macro, unused
       K,    nop,
// main keyboard
       q,      w,      e,      r,      t,    esc,      y,      u,      i,      o,      p,
       a,      s,      d,      f,      g,  grave,      h,      j,      k,      l,semicol,
       z,      x,      c,      v,      b,   guiL,      n,      m,  comma, period,  slash,
     FN1,   altL,  ctrlL,     bs, shiftR,          enter,  space,  ctrlR,   altR,     FN2),
     
// ............................................................................
   
   MATRIX_LAYER( //layer 1: FN1 layer
// macro, unused
       K,    nop,
// main keyboard
       1,      2,      3,      4,      5,  equal,      6,      7,      8,      9,      0,
       a,      s,      d,      f,      g,   dash, braceL, braceR,  pnbrL,  pnbrR,  quote,
       z,      x,      c,      v,      b,   guiL,bkslash, arrowL, arrowD, arrowU, arrowR,
     FN1,   altL,  ctrlL,     bs, shiftR,          enter,  space,  ctrlR,   altR,     FN2),

// ............................................................................
   
   MATRIX_LAYER( //layer 2: FN2 layer
// macro, unused
       K,    nop,
// main keyboard
       1,      2,      3,      4,      5,  equal,      6,      7,      8,      9,      0,
       a,      s,      d,      f,      g,   dash, braceL, braceR,  pnbrL,  pnbrR,  quote,
       z,      x,      c,      v,      b,  btldr,bkslash, arrowL, arrowD, arrowU, arrowR,
     FN1,   altL,  ctrlL,     bs, shiftR,          enter,  space,  ctrlR,   altR,     FN2)

// ............................................................................
};

