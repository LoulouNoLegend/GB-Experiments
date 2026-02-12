#ifndef ENEMY_H
#define ENEMY_H

extern UBYTE EnemyPosition[2];

void initEnemy(void);
void chasePlayer(void);
void checkPlayerPosition(void);
void hitPlayer(void);

#endif
