#include <gb/gb.h>
#include <stdint.h>

#include "enemy.h"
#include "player.h"
#include "tile_sheet.h"
#include "game.h"

int8_t EnemyVelocity = 1;
UBYTE EnemyPosition[2] = {40,36};

void InitEnemy(void) {
    SPRITES_8x8;

    EnemyVelocity = 1;
    EnemyPosition[0] = 40, EnemyPosition[0] = 36;

    set_sprite_data(1, 1, Sprites_Enemy);
    set_sprite_tile(1, 1);
    move_sprite(1, 100, 50);
}

void EnemyLoop(void) {
    ChasePlayer();
}

void ChasePlayer(void) {
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

    CheckPlayerPosition();
}

void CheckPlayerPosition(void) {
    BOOLEAN playerTouched;

    playerTouched = ComparePosition(PlayerPosition, EnemyPosition, 5);

    if (playerTouched == TRUE) PlayerHit();
}