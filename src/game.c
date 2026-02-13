#include <stdio.h>

#include "game.h"

#include "menus.h"

BOOLEAN doGameLoop = TRUE;

const unsigned char BlankTile[] = {
  0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00,
  0x00,0x00, 0x00,0x00, 0x00,0x00, 0x00,0x00
};

void MainGameLoop(void) {
    MainMenu();
}

void EndGame(void) {
    doGameLoop = FALSE;
}

void ClearScreenBkg(void) {
    HIDE_BKG;
    DISPLAY_OFF;

    fill_bkg_rect(0, 0, 32, 32, 0);

    DISPLAY_ON;
    SHOW_BKG;
}

/*
 * Compare the position between two. (Ex: Entities)
 * - Position 1:    First Position
 * - Position 2:    Second Position
 * - Distance:      The distance between the two positions that would return true
*/
BOOLEAN ComparePosition(UBYTE position1[2], UBYTE position2[2], UBYTE distance) {
    UBYTE PosDiffX, PosDiffY;

    // Check the difference of position from the first and second given entities
    PosDiffX = position1[0] - position2[0];
    PosDiffY = position1[1] - position2[1];

    // If they are too close, wooo
    if (PosDiffX < distance && PosDiffY < distance) {
        return TRUE;
    }
    return FALSE;
}