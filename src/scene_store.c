#include <tonc.h>
#include "tick.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "../engine/globals.h"
#include "structs.h"

int frame;

int cursorHeldX = 0;
int cursorHeldPetID = 0;

int cursorX = 0;
int cursorY = 0;

int pb = 0;

void resetAnimalSpritesForStore() {
    int xOffset=49;
    int petPins=0;

    for (int i=0; i < 5; i++) {
        struct Pet *pet = getPlayerTeamPet(i);
        struct PetSprite * ps = getPetSprite(i);

        if (pet->id) {
            pet->pin = ++petPins;
            ps->petPin = pet->pin;
        } else {
            ps->petPin = 0;
        }

        ps->worldX = xOffset + (18 * i);
        ps->worldY = 50;
        ps->flip = 1;
        ps->shortStat = 0;
    }
        tte_set_pos(32, 0);
    for (int i=5; i <12; i++) {
        struct Pet *pet = getEnemyTeamPet(i-5);
        struct PetSprite * ps = getPetSprite(i);

        if (pet->id) {
            ps->shortStat = 1;
            pet->pin = ++petPins;
            ps->petPin = pet->pin;
        } else {
            ps->petPin = 0;
        }

        ps->worldX = xOffset + (18 * (i-5));
        ps->worldY = 99;
        ps->flip = 1;
    }
}


void prepareSceneStore() {
    resetAnimalSpritesForStore();
    updateAnimalSprites();
    for (int i=0; i <12; i++) {
        struct PetSprite * ps = getPetSprite(i);
        ps->visiblePet = true;
        ps->visibleStats = true;

    }
}

void tickSceneStore() {
    OBJ_ATTR *sprite;
    frame++;

    if (frame % 30 == 0 && cursorHeldPetID == 0) {
        sprite = getOAMSprite(105);
//        if (cursorOpen) {
//            sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | getMemForCursor(0);
//            cursorOpen = 0;
//        } else {
//            sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | getMemForCursor(1);
//            cursorOpen = 1;
//        }
    }


    if (key_hit(KEY_A) && cursorY == 0) {
        sprite = getOAMSprite(105);
        if (cursorHeldPetID == 0) {
            cursorHeldX = cursorX;
            cursorHeldPetID = getPlayerTeamPet(cursorHeldX)->id;

            if (cursorHeldPetID > 0) {
                usePetGfxMem(cursorHeldPetID, -1);
                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | getMemForCursor(0);
                getPetSprite(cursorX)->visiblePet = 0;
                loadLabel(0, UILabel_Place);
            }
        } else {
            resetCursorMem();
            getPetSprite(cursorHeldX)->visiblePet = 1;
            swapPets(getPlayerTeamPet(cursorX), getPlayerTeamPet(cursorHeldX));
            cursorHeldX = 0;
            cursorHeldPetID = 0;
            frame = 0;
        }
        resetAnimalSpritesForStore();
        updateAnimalSprites();
    }

    if (key_hit(KEY_RIGHT) || key_hit(KEY_LEFT)) {
        if (key_hit(KEY_RIGHT)) {
            cursorX += 1;
        }
        if (key_hit(KEY_LEFT)) {
            cursorX -= 1;
        }

        if (cursorHeldPetID) {
            int hoveredId = getPlayerTeamPet(cursorX)->id;

            if (hoveredId == cursorHeldPetID && cursorHeldX != cursorX) {
                loadLabel(0, UILabel_Stack); // Merge
            } else if (hoveredId == 0 || cursorHeldX == cursorX) {
                loadLabel(0, UILabel_Place); // Empty spot
            } else {
                loadLabel(0, UILabel_Swap);
            }
        }
    }

    if (cursorHeldPetID == 0 && cursorY == 0) {
        loadLabel(0, UILabel_Move);
    }
    if (cursorHeldPetID == 0 && cursorY == 1) {
        loadLabel(0, UILabel_Buy);
    }

    if (key_hit(KEY_DOWN)) {
        cursorY += 1;
        loadLabel(0, UILabel_Buy);
        loadLabel(1, UILabel_Freeze);
    }

    if (key_hit(KEY_UP)) {
        cursorY -= 1;
        loadLabel(0, UILabel_Move);
        loadLabel(1, UILabel_Sell);
    }

    if (cursorY < 0) {
        cursorY = 0;
    }
    if (cursorY > 1) {
        cursorY = 1;
    }

    if (cursorX < 0) {
        cursorX = 0;
    }

    if (cursorX > 4 && cursorY == 0) {
        cursorX = 4;
    }

    if (cursorX > 6 && cursorY == 1) {
        cursorX = 6;
    }


    int cursorScreenPosX = 49 + (cursorX * 18);
    int cursorScreenPosY = 49 + (cursorY * 50);
    if (cursorHeldPetID > 0) {
        cursorScreenPosY -= 4;
    }
    sprite = getOAMSprite(105);
    obj_set_pos(sprite, cursorScreenPosX, cursorScreenPosY);

    if (key_hit(KEY_R)) {
        sprite = getOAMSprite(101);
        obj_set_pos(sprite, 208, -2);

        sprite = getOAMSprite(105);
        obj_set_pos(sprite, -16, -16);

        setScene(1);

        for (int s=106; s<=109;s++) {
            sprite = getOAMSprite(s);
            sprite->attr0 ^= ATTR0_HIDE;
        }

        for (int t = 0; t < 10; t++) {
            tickMainLoop();
        }
        sprite = getOAMSprite(101);
        obj_set_pos(sprite, 208, 0);

        for (int t = 0; t < 20; t++) {
            tickMainLoop();
            sprite = getOAMSprite(100);
            obj_set_pos(sprite, 0, -t );
            sprite = getOAMSprite(101);
            obj_set_pos(sprite, 208, -t );
        }

        for (int t = 0; t < 50; t++) {
            tickMainLoop();
        }

    }

    if (key_hit(KEY_START))
        REG_DISPCNT ^= DCNT_OBJ_1D;
}