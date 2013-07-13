/* ----------------------------------------------------------------------------
 * Normal place for the licensing info
 * I really don't know what to put here
 * Thanks to Ben Blazak <benblazak.dev@gmail.com> for creating this
 * wonderful firmware
 * ------------------------------------------------------------------------- */
 
// saves current shift state to be restored later
#define SAVE_SHIFT_STATE()                                              \
        struct {                                                        \
        bool left_shift  : 1;                                           \
        bool right_shift : 1;                                           \
        } state = {                                                     \
            .left_shift  = usb__kb__read_key( KEYBOARD__LeftShift  ),   \
            .right_shift = usb__kb__read_key( KEYBOARD__RightShift ),   \
        };                                                              \
        usb__kb__set_key( false, KEYBOARD__LeftShift  );                \
        usb__kb__set_key( false, KEYBOARD__RightShift );    
        
        
// restores shift state saved by SAVE_SHIFT_STATE()
#define RESTORE_SHIFT_STATE()                                           \
        usb__kb__set_key( state.left_shift,  KEYBOARD__LeftShift  );    \
        usb__kb__set_key( state.right_shift, KEYBOARD__RightShift );    \
        usb__kb__send_report();

#define SHIFT_DOWN (state.left_shift || state.right_shift)

#define KEYS__UNSHIFT_SHIFT(name,keyfun1,keyfun2)                       \
void P(name) (void) {                                                   \
    SAVE_SHIFT_STATE();                                                 \
    if (!SHIFT_DOWN) P(keyfun1)();                                      \
    else P(keyfun2)();                                                  \
}                                                                       \
void R(name) (void) {                                                   \
    SAVE_SHIFT_STATE();                                                 \
    if (!SHIFT_DOWN) R(keyfun1)();                                      \
    else R(keyfun2)();                                                  \
}                                                                       