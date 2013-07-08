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
       a,      s,      d,      f,      g,   dash,  brktL,  brktR, braceL, braceR    ,  quote,
       z,      x,      c,      v,      b,   guiL,bkslash, arrowL, arrowD, arrowU, arrowR,
     FN1,   altL,  ctrlL,     bs, shiftR,          enter,  space,  ctrlR,   altR,     FN2)

// ............................................................................
};

