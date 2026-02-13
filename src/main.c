#include <gb/gb.h>
#include <stdint.h>

#include "game.h"
#include "menus.h"
#include "player.h"
#include "enemy.h"

typedef enum {
    STATE_MENU = 0,
    STATE_PLAYING = 1
} GameState;

GameState g_state = STATE_MENU;

BOOLEAN inMainMenu = TRUE, inPlayingState = FALSE;

void main(void) {
    DISPLAY_ON;

    while (1) {
        switch (g_state) {
            case STATE_MENU:
                g_state = STATE_MENU;
                inMainMenu = TRUE;
                DrawMainMenuUI();
                while (inMainMenu) {
                    HandleMenuInput();
                    vsync();
                }
                break;

            case STATE_PLAYING:
                inPlayingState = TRUE;
                StartGame();
                while (inPlayingState) {
                    PlayerLoop();
                    EnemyLoop();
                    vsync();
                }
                EndGame();
                g_state = STATE_MENU;
                break;
        }
    }
}