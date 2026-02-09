#include <gb/gb.h>
#include <stdint.h>

// . Color 0: 00 - 00000000 - Light
// + Color 1: FF - 11111111 - Light Gray
// * Color 2: AA - 10101010 - Dark Gray
// # Color 3: 55 - 01010101 - Very dark
//
// 0 = 00
// 1 = 01
// 2 = 10
// 3 = 11

// One GB tile = 8x8 pixels
// Each tile = 2 bit per pixel (4 colors)
// 8 rows x 2 bytes per row = 16bytes total
const uint8_t smiley_tile[16] = {
    0x7E, 0x7E,
    0xFF, 0xC3,
    0xFF, 0x81,
    0xDB, 0xA5,
    0xFF, 0x81,
    0xE7, 0x99,
    0xFF, 0xC3,
    0x7E, 0x7E
};

// # # # # # # # # -> 3333 3333 -> 11 11 11 11 11 11 11 11 -> 55 55
// # . . # # . . # -> 3003 3003 -> 11 00 00 11 11 00 00 11 -> 
// # . . # # . . # -> 3003 3003 -> 11 00 00 11 11 00 00 11 -> 
// # # # # # # # # -> 3333 3333 -> 11 11 11 11 11 11 11 11 -> 
// # . # # # # . # -> 3033 3303 -> 11 00 11 11 11 11 00 11 -> 
// # # . . . . # # -> 3300 0033 -> 11 11 00 00 00 00 11 11 -> 
// # # # # # # # # -> 3333 3333 -> 11 11 11 11 11 11 11 11 -> 55 55
// # # # # # # # # -> 3333 3333 -> 11 11 11 11 11 11 11 11 -> 55 55

void main(void) {
    DISPLAY_OFF; // turn off screen, free VRAM / make changes safe
    SPRITES_8x8;

    set_sprite_data(0, 1, smiley_tile);
    set_sprite_tile(0, 0);
    move_sprite(0, 80, 72);

    SHOW_SPRITES;
    DISPLAY_ON;

    while(1) {
        uint8_t keys = joypad();

        if(keys & J_LEFT)  scroll_sprite(0, -1, 0);
        if(keys & J_RIGHT) scroll_sprite(0,  1, 0);
        if(keys & J_UP)    scroll_sprite(0,  0, -1);
        if(keys & J_DOWN)  scroll_sprite(0,  0,  1);

        wait_vbl_done();
    }
}
