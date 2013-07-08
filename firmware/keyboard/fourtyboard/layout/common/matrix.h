/* ----------------------------------------------------------------------------
 * Copyright (c) 2012, 2013 Ben Blazak <benblazak.dev@gmail.com>
 * Released under The MIT License (see "doc/licenses/MIT.md")
 * Project located at <https://github.com/benblazak/ergodox-firmware>
 * ------------------------------------------------------------------------- */

/**                                                                 description
 * Information about the matrix
 */


#ifndef ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H
#define ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H
// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------


/**                                             macros/MATRIX_LAYER/description
 * Mapping from spatial position to matrix position.
 *
 * - Spatial position: Where the key is spatially, relative to other keys, both
 *   on the keyboard and in the layout.
 * - Matrix position: The coordinate in the matrix to which a key is scanned by
 *   the update functions.
 *
 * - Location numbers are in the format `row##column`, where both 'row' and
 *   'column' are single digit hex numbers corresponding to the matrix position
 *   (which also corresponds to the row and column pin labels used in the
 *   Teensy and MCP23018 files).
 *
 * - Coordinates:
 *     - optional keys
 *         - k15, k16 (left hand thumb group)
 *         - k17, k18 (right hand thumb group)
 *     - unused keys
 *         - k36, k00 (left hand)
 *         - k37, k0D (right hand)
 *
 * - Other Info:
 *       ----------------------------------------------------
 *                 rows x columns = positions;  used,  unused
 *       per hand:    6 x  7      = 42;         40,    2
 *          total:    6 x 14      = 84;         80,    4
 *       
 *       left hand  : rows 0..5, cols 0..6
 *       right hand : rows 0..5, cols 7..D
 *       ----------------------------------------------------
 */
#define MATRIX_LAYER(                                                                                           \
            /* the name of a macro to call on all arguments */                                                  \
            M,                                                                                                  \
                                                                                                                \
            /* for unused positions */                                                                          \
            na,                                                                                                 \
                                                                                                                \
            /* left hand, spatial positions */                                                                  \
            k30,k31,k32,k33,k34,k35,k36,k37,k38,k39,k3A,                                                        \
            k20,k21,k22,k23,k24,k25,k26,k27,k28,k29,k2A,                                                        \
            k10,k11,k12,k13,k14,k15,k16,k17,k18,k19,k1A,                                                        \
            k00,k01,k02,k03,k04,    k06,k07,k08,k09,k0A)                                                        \
                                                                                                                \
    /* matrix positions */                                                                                      \
    {{ M(k00),M(k01),M(k02),M(k03),M(k04),M( na),M(k06),M(k07),M(k08),M(k09),M(k0A)},                           \
     { M(k10),M(k11),M(k12),M(k13),M(k14),M(k15),M(k16),M(k17),M(k18),M(k19),M(k1A)},                           \
     { M(k20),M(k21),M(k22),M(k23),M(k24),M(k25),M(k26),M(k27),M(k28),M(k29),M(k2A)},                           \
     { M(k30),M(k31),M(k32),M(k33),M(k34),M(k35),M(k36),M(k37),M(k38),M(k39),M(k3A)}}


// ----------------------------------------------------------------------------
// ----------------------------------------------------------------------------
#endif  // ERGODOX_FIRMWARE__FIRMWARE__KEYBOARD__ERGODOX__LAYOUT__COMMON__MATRIX__H

