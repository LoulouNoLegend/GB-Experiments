#include <gb/gb.h>
#include <stdint.h>

#include "player.h"
#include "enemy.h"

void main(void) {
    DISPLAY_OFF; // turn off screen, free VRAM / make changes safe
    SPRITES_8x8;

    initPlayer();
    initEnemy();

    SHOW_SPRITES;
    DISPLAY_ON;

    while(1) {
        HandlePlayerInput();

        chasePlayer();

        wait_vbl_done();
    }
}