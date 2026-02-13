#include <stdio.h>
#include "gb/gb.h"
#include "menus.h"

#include "player.h"
#include "enemy.h"
#include "menu_tile_sheet.h"
#include "game.h"

/*---------------------------------------------*/

#define VRAM_BLANK      0
#define VRAM_PLAY       1 // +8 next
#define VRAM_SETTINGS   9 // +8 next
#define VRAM_TITLE      17

BOOLEAN inMainMenu = TRUE, inPlayingState = FALSE;

// Play = 0
// Settings = 1
UBYTE selectedButton = 0;

/*---------------------------------------------*/
// GAME TITLE
const unsigned char MM_Title_Map[] = {
    VRAM_TITLE + 0,  VRAM_TITLE + 1,  VRAM_TITLE + 2,  VRAM_TITLE + 3,
    VRAM_TITLE + 4,  VRAM_TITLE + 5,  VRAM_TITLE + 6,  VRAM_TITLE + 7,
    VRAM_TITLE + 8,  VRAM_TITLE + 9,  VRAM_TITLE + 10, VRAM_TITLE + 11,
    VRAM_TITLE + 12, VRAM_TITLE + 13, VRAM_TITLE + 14, VRAM_TITLE + 15,
    VRAM_TITLE + 16, VRAM_TITLE + 17, VRAM_TITLE + 18, VRAM_TITLE + 19,
    VRAM_TITLE + 20, VRAM_TITLE + 21, VRAM_TITLE + 22, VRAM_TITLE + 23,
    VRAM_TITLE + 24
};

// PLAY BUTTON
const unsigned char MM_Btn_Play_Map[] = {
    VRAM_PLAY + 0,
    VRAM_PLAY + 1,
    VRAM_PLAY + 2,
    VRAM_PLAY + 3
};
const unsigned char MM_Btn_Play_Hover_Map[] = {
    VRAM_PLAY + 4,
    VRAM_PLAY + 5,
    VRAM_PLAY + 6,
    VRAM_PLAY + 7
};

// SETTINGS BUTTON
const unsigned char MM_Btn_Settings_Map[] = {
    VRAM_PLAY + 0,
    VRAM_PLAY + 1,
    VRAM_PLAY + 2,
    VRAM_PLAY + 3
};
const unsigned char MM_Btn_Settings_Hover_Map[] = {
    VRAM_PLAY + 4,
    VRAM_PLAY + 5,
    VRAM_PLAY + 6,
    VRAM_PLAY + 7
};

/*---------------------------------------------*/

void MainMenu(void) {
    DrawMainMenuUI();

    while (inMainMenu == TRUE) {
        HandleMenuInput();
    }
    
}

void DrawMainMenuUI(void) {
    DISPLAY_OFF;

    move_bkg(0, 0);

    set_bkg_data(VRAM_BLANK, 1, BlankTile);
    set_bkg_data(VRAM_PLAY, 8, Tiles_Btn);
    set_bkg_data(VRAM_TITLE, 24, Tiles_MM);

    ClearScreen();

    /* GAME TITLE (BADSHAPES) */
    set_bkg_tiles(4, 6, 12, 2, MM_Title_Map);

    /* BUTTONS */

    set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Hover_Map);

    DISPLAY_ON;
    SHOW_BKG;
}

void HandleMenuInput(void) {
    uint8_t keys = joypad();

    if ((keys & J_DOWN) && selectedButton == 0) selectedButton = 1;
    else if ((keys & J_UP) && selectedButton == 1) selectedButton = 0;

    // Check selected and change button textures based on that
    if (selectedButton == 0) set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Hover_Map);
    else set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Map);
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