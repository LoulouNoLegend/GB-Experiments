#include <stdio.h>
#include "gb/gb.h"
#include "menus.h"

#include "player.h"
#include "enemy.h"
#include "menu_tile_sheet.h"
#include "game.h"

/*---------------------------------------------*/

#define VRAM_BLANK      0
#define VRAM_BUTTONS    1 // +16 next
#define VRAM_TITLE      17 // +24 next

// Indices VRAM buttons
#define BTN_PLAY            (VRAM_BUTTONS + 0)  // 0..3
#define BTN_PLAY_HOVER      (VRAM_BUTTONS + 4)  // 4..7
#define BTN_SETTINGS        (VRAM_BUTTONS + 8)  // 8..11
#define BTN_SETTINGS_HOVER  (VRAM_BUTTONS + 12) // 12..15

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
    BTN_PLAY+0, BTN_PLAY+1, BTN_PLAY+2, BTN_PLAY+3
};
const unsigned char MM_Btn_Play_Hover_Map[] = {
    BTN_PLAY_HOVER+0, BTN_PLAY_HOVER+1, BTN_PLAY_HOVER+2, BTN_PLAY_HOVER+3
};

// SETTINGS BUTTON
const unsigned char MM_Btn_Settings_Map[] = {
    BTN_SETTINGS+0, BTN_SETTINGS+1, BTN_SETTINGS+2, BTN_SETTINGS+3
};
const unsigned char MM_Btn_Settings_Hover_Map[] = {
    BTN_SETTINGS_HOVER+0, BTN_SETTINGS_HOVER+1, BTN_SETTINGS_HOVER+2, BTN_SETTINGS_HOVER+3
};

/*---------------------------------------------*/

void MainMenu(void) {
    DrawMainMenuUI();

    while (inMainMenu == TRUE) {
        HandleMenuInput();
        vsync();
    }
    
}

void DrawMainMenuUI(void) {
    DISPLAY_OFF;

    move_bkg(0, 0);

    set_bkg_data(VRAM_BLANK, 1, BlankTile);
    set_bkg_data(VRAM_BUTTONS, 16, Tiles_Btn);
    set_bkg_data(VRAM_TITLE, 24, Tiles_MM);

    ClearScreenBkg();

    /* GAME TITLE (BADSHAPES) */
    set_bkg_tiles(4, 6, 12, 2, MM_Title_Map);

    /* BUTTONS */

    set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Hover_Map);

    set_bkg_tiles(8, 14, 4, 1, MM_Btn_Settings_Map);

    DISPLAY_ON;
    SHOW_BKG;
}

void HandleMenuInput(void) {
    uint8_t keys = joypad();
    UBYTE prev = selectedButton;

    if ((keys & J_DOWN) && selectedButton == 0) selectedButton = 1;
    else if ((keys & J_UP) && selectedButton == 1) selectedButton = 0;

    // Check selected and change button textures based on that
    if (selectedButton != prev) {
        if (selectedButton == 0) {
            set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Hover_Map);
            set_bkg_tiles(8, 14, 4, 1, MM_Btn_Settings_Map);
        } else {
            set_bkg_tiles(8, 12, 4, 1, MM_Btn_Play_Map);
            set_bkg_tiles(8, 14, 4, 1, MM_Btn_Settings_Hover_Map);
        }
        delay(120); // anti-spam input
    }

    if ((keys & (J_A | J_START))) {
        if (selectedButton == 0) {
            inMainMenu = FALSE;
            Playing();
        } else {
            // later that
        }
        delay(150); // avoid double-trigger
    }
}

void Playing(void) {
    DISPLAY_OFF;
    ClearScreenBkg();

    DISPLAY_ON;
    SHOW_SPRITES;
    SPRITES_8x8;

    InitPlayer();
    InitEnemy();

    inPlayingState = TRUE;

    while (inPlayingState == TRUE) {
        PlayerLoop();
        EnemyLoop();
        
        vsync();
    }
}