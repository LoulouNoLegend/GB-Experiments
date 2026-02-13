#include <gb/gb.h>
#include <stdint.h>
#include <stdio.h>

#include "player.h"
#include "tile_sheet.h"
#include "enemy.h"
#include "main.h"
#include "game.h"

int8_t PlayerVelocity = 2;
UBYTE PlayerPosition[2] = {80,72};
UBYTE PlayerHealth = 3;

void InitPlayer(void) {
    SPRITES_8x8;

    set_sprite_data(0, 1, Sprites_Player);
    set_sprite_tile(0, 0);
    move_sprite(0, 80, 72);
}

void PlayerLoop(void) {
    HandlePlayerInput();
}

void HandlePlayerInput(void) {
    uint8_t keys = joypad();

    //if (((keys & J_UP) && (keys & J_RIGHT)) || ((keys & J_UP) && (keys & J_LEFT)) || ((keys & J_DOWN) && (keys & J_RIGHT)) || ((keys & J_DOWN) && (keys & J_LEFT))) PlayerVelocity = 1;
    //else PlayerVelocity = 2;
    if (((keys & J_UP) || (keys & J_DOWN)) && ((keys & J_LEFT) || (keys & J_RIGHT))) return;
    else {
        if (keys & J_UP) /*scroll_sprite(0, 0, -PlayerVelocity);*/ PlayerPosition[1]-=PlayerVelocity;
        if (keys & J_DOWN) /*scroll_sprite(0, 0, PlayerVelocity);*/ PlayerPosition[1]+=PlayerVelocity;
        if (keys & J_LEFT) /*scroll_sprite(0, -PlayerVelocity, 0);*/ PlayerPosition[0]-=PlayerVelocity;
        if (keys & J_RIGHT) /*scroll_sprite(0, PlayerVelocity, 0);*/ PlayerPosition[0]+=PlayerVelocity;
        move_sprite(0, PlayerPosition[0], PlayerPosition[1]);
    }
}

void PlayerHit(void) {
    PlayerHealth-=1;
    CheckHealth();
}

void CheckHealth(void) {
    if (PlayerHealth <= 0) {
        printf("DEAD!");
        EndGame();
    }
    else printf("Hit!");
}