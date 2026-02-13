#ifndef GAME_H
#define GAME_H

#include <gb/gb.h>

extern BOOLEAN doGameLoop;
extern const unsigned char BlankTile[];

void MainGameLoop(void);
void EndGame(void);
void ClearScreen(void);
BOOLEAN ComparePosition(UBYTE position[2], UBYTE position2[2], UBYTE distance);

#endif