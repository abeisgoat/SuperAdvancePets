#include <tonc.h>
#include "tick.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "../engine/globals.h"
#include "structs.h"
#include "animations.h"

int frame;

int cursorHeldX = 0;
int cursorHeldY = 0;
int cursorHeldPetID = 0;

int cursorX = 0;
int cursorY = 0;
int cursorOpen = 0;

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

void updateLabels() {
    if (cursorHeldPetID && cursorY == 1) {
        loadLabel(0, UILabel_Cancel);
        loadLabel(1, UILabel_Cancel);
    }else if (cursorHeldPetID) {
        int hoveredId = getPlayerTeamPet(cursorX)->id;

        if (cursorHeldY == 1) {
            loadLabel(1, UILabel_Cancel);
            if ((hoveredId == cursorHeldPetID || cursorHeldPetID > 100) && hoveredId) {
                loadLabel(0, UILabel_Stack);
            } else if (hoveredId == 0 && cursorHeldPetID < 100) {
                loadLabel(0, UILabel_Place);
            } else {
                loadLabel(0, UILabel_Cancel);
            }
        }

        if (cursorHeldY == 0) {
            loadLabel(1, UILabel_Cancel);
            if (hoveredId == cursorHeldPetID) {
                loadLabel(0, UILabel_Stack);
            } else if (hoveredId == 0) {
                loadLabel(0, UILabel_Place);
            } else {
                loadLabel(0, UILabel_Cancel);
            }
        }
    } else {

        if (cursorY == 0) {
            loadLabel(1, UILabel_Sell);
            loadLabel(0, UILabel_Move);
        } else {
            loadLabel(1, UILabel_Freeze);
            loadLabel(0, UILabel_Buy);
        }
    }
}

void updateGameplayInfo() {
    int lives = 5;
    int turn = 1;
    int money = getBankMoney();

    OBJ_ATTR *sprite;
    char msg[50];
    int counters_x = 144;
    int turn_offset=0;

    if (lives < 10) {
        counters_x += 8;
    }

    if (turn < 10) {
        turn_offset += 8;
    }

    int counters_y = 144;


    sprite = getOAMSprite(102);

    int money_offset=0;
    if (money < 10) {
        money_offset = 8;
    }
    tte_set_pos(counters_x + 8 + turn_offset + money_offset, counters_y);

    sprintf(msg, "%d ", money);
    tte_write(msg);

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Coin));

    obj_set_pos(sprite, counters_x + money_offset + + turn_offset, counters_y + 2);

    sprite = getOAMSprite(103);


    tte_set_pos(counters_x + 46+ turn_offset, counters_y);
    sprintf(msg, "%d ", turn);
    tte_write(msg);

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Turns));

    obj_set_pos(sprite, counters_x + 32 + turn_offset, counters_y+2);

    tte_set_pos(counters_x + 72 , counters_y);
    sprintf(msg, "%d ", lives);
    tte_write(msg);

    sprite = getOAMSprite(104);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Hearts));

    obj_set_pos(sprite, counters_x + 62, counters_y+2);
}


void prepareSceneStore() {
    resetAnimalSpritesForStore();
    updateAnimalSprites();
    for (int i=0; i <12; i++) {
        struct PetSprite * ps = getPetSprite(i);
        ps->visiblePet = true;
        ps->visibleStats = true;
    }
    updateGameplayInfo();
}

void tickSceneStore() {
    OBJ_ATTR *sprite = getOAMSprite(105);
    frame++;

    if (frame % 30 == 0 && cursorHeldPetID == 0) {
        cursorOpen = cursorOpen ? 0 : 1;
    }

    sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | getMemForCursor(cursorOpen);

    if (key_hit(KEY_A) && cursorY == 0) {
        sprite = getOAMSprite(105);
        if (cursorHeldPetID == 0) {
            cursorHeldX = cursorX;
            cursorHeldY = cursorY;
            cursorHeldPetID = getPlayerTeamPet(cursorHeldX)->id;

            if (cursorHeldPetID > 0) {
                usePetGfxMem(cursorHeldPetID, -1);
//                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(2) | getMemForCursor(0);
                getPetSprite(cursorX)->visiblePet = 0;
                cursorOpen = 0;
                loadLabel(0, UILabel_Place);
            }
        } else {
            resetCursorMem();
            getPetSprite(cursorHeldX)->visiblePet = 1;
            swapPets(getPlayerTeamPet(cursorX), getPlayerTeamPet(cursorHeldX));
            cursorHeldX = 0;
            cursorHeldY = 0;
            cursorHeldPetID = 0;
            frame = 0;
        }
        resetAnimalSpritesForStore();
        updateAnimalSprites();
        updateLabels();
    }

    if (key_hit(KEY_A) && cursorY == 1) {
        struct Pet * item = getEnemyTeamPet(cursorX);

        if (item->id > 100) {
            int triggered = buyItemAtPosition(cursorX);
            if (!triggered) {
                cursorHeldX = cursorX;
                cursorHeldY = cursorY;
                cursorOpen = 0;
                cursorHeldPetID = getEnemyTeamPet(cursorHeldX)->id;
                usePetGfxMem(cursorHeldPetID, -1);
                getPetSprite(5+cursorX)->visiblePet = 0;
                sleep(2);
            }
            updateGameplayInfo();
            updateAnimalSprites();
        }
        updateLabels();
    }

    if ((key_hit(KEY_RIGHT) || key_hit(KEY_LEFT)) && (!cursorHeldPetID || (cursorHeldY == 1 && cursorY == 0) || (cursorHeldY == 0 && cursorY == 0))) {
        if (key_hit(KEY_RIGHT)) {
            cursorX += 1;
        }
        if (key_hit(KEY_LEFT)) {
            cursorX -= 1;
        }

        updateLabels();
    }

    if (key_hit(KEY_DOWN) && !cursorHeldPetID) {
        cursorY += 1;
        updateLabels();
    }

    if (key_hit(KEY_UP)) {
        cursorY -= 1;
        updateLabels();
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
        if (cursorY == 1 && cursorHeldY == 1) {
            cursorScreenPosY -= 4;
        }else if (cursorY == 0 && cursorHeldY == 1) {
            cursorScreenPosY += 6;
        }else if (cursorY == 0) {
            cursorScreenPosY -= 4;
        }
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