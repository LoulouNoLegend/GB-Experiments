#ifndef MAIN_H
#define MAIN_H

#include <gb/gb.h>

typedef enum GameState {
    STATE_MENU = 0,
    STATE_PLAYING = 1
} GameState;

extern GameState g_state;

extern BOOLEAN inMainMenu, inPlayingState;

#endif
