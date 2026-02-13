#include <gb/gb.h>
#include <stdint.h>

#include "game.h"

void main(void) {
    DISPLAY_OFF; // turn off screen, free VRAM / make changes safe
    //SPRITES_8x8;

    //SHOW_SPRITES;
    //DISPLAY_ON;

    while(1) {
        MainGameLoop();

        vsync();
    }
}