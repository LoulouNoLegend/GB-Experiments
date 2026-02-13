#ifndef MENUS_H
#define MENUS_H

#include "gb/gb.h"

void DrawMainMenuUI(void);

void HandleMenuInput(void);
void checkSelectedButton(void);

void StartGame(void);
void EndGame(void);

#endif
