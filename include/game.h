#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>

extern BOOLEAN doGameLoop;

void MainGameLoop(void);
void EndGame(void);
BOOLEAN ComparePosition(UBYTE position[2], UBYTE position2[2], UBYTE distance);

#endif