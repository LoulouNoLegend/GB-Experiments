#ifndef MENUS_H
#define MENUS_H

#include "gb/gb.h"

extern BOOLEAN inMainMenu;

void MainMenu(void);

void DrawMainMenuUI(void);

void HandleMenuInput(void);
void checkSelectedButton(void);

void Playing(void);

#endif
