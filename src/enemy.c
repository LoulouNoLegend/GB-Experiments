#include <gb/gb.h>
#include <stdint.h>

#include "enemy.h"
#include "player.h"
#include "tile_sheet.h"

int8_t EnemyVelocity = 1;
UBYTE EnemyPosition[2] = {40,36};

void initEnemy(void) {
    SPRITES_8x8;

    set_sprite_data(1, 1, Sprites_Enemy);
    set_sprite_tile(1, 1);
    move_sprite(1, 100, 50);
}

void chasePlayer(void) {
    if (EnemyPosition[0] < PlayerPosition[0]) {
        EnemyPosition[0]+=EnemyVelocity;
    } else if (EnemyPosition[0] > PlayerPosition[0]) {
        EnemyPosition[0]-=EnemyVelocity;
    }

    if (EnemyPosition[1] < PlayerPosition[1]) {
        EnemyPosition[1]+=EnemyVelocity;
    } else if (EnemyPosition[1] > PlayerPosition[1]) {
        EnemyPosition[1]-=EnemyVelocity;
    }

    move_sprite(1, EnemyPosition[0], EnemyPosition[1]);

    checkPlayerPosition();
}

void checkPlayerPosition(void) {
    UBYTE PosDiffX, PosDiffY;

    // Check the difference of position from the enemy and the player
    PosDiffX = PlayerPosition[0] - EnemyPosition[0];
    PosDiffY = PlayerPosition[1] - EnemyPosition[1];

    // If they are too close, get hit!!!!
    if (PosDiffX < 1 && PosDiffY < 1) {
        hitPlayer();
    }
}