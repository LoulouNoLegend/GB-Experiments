#ifndef PLAYER_H
#define PLAYER_H

extern UBYTE PlayerPosition[2];

void InitPlayer(void);
void PlayerLoop(void);
void HandlePlayerInput(void);

void PlayerHit(void);
void CheckHealth(void);

#endif
