#include "gb/gb.h"
#include <stdio.h>
#include "menus.h"

#include "player.h"
#include "enemy.h"

BOOLEAN inMainMenu = TRUE, inPlayingState = FALSE;

void MainMenu(void) {
    while (inMainMenu == TRUE) {
        printf("Menu ");
    }
    
}

void Playing(void) {
    InitPlayer();
    InitEnemy();

    inPlayingState = TRUE;

    while (inPlayingState == TRUE) {
        PlayerLoop();
        EnemyLoop();
    }
}