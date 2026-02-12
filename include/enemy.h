#ifndef ENEMY_H
#define ENEMY_H

extern UBYTE EnemyPosition[2];

void InitEnemy(void);
void EnemyLoop(void);
void ChasePlayer(void);
void CheckPlayerPosition(void);

#endif
