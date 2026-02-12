#include <gb/gb.h>
#include <stdint.h>

#include "player.h"
#include "enemy.h"

BOOLEAN doGameLoop = TRUE;

void main(void) {
    DISPLAY_OFF; // turn off screen, free VRAM / make changes safe
    SPRITES_8x8;

    InitPlayer();
    InitEnemy();

    SHOW_SPRITES;
    DISPLAY_ON;

    while(doGameLoop == TRUE) {
        PlayerLoop();

        EnemyLoop();

        wait_vbl_done();
    }
}