#include <tonc.h>
#include "tick.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "../engine/globals.h"
#include "structs.h"
#include "animations.h"

int xOffset=256;

int getWorldXForPetPosition(int petPosition) {
    if (petPosition <= 4) {
        return xOffset + (18 * petPosition);
    } else {
        return xOffset + 100 + (18 * (petPosition-5));
    }
}



void resetAnimalSpritesForBattle() {
    int petPins = 0;
    for (int i=0; i <=4; i++) {
        struct Pet *pet = getPlayerTeamPet(i);
        struct PetSprite * ps = getPetSprite(i);
        if (pet->id) {
            pet->pin = ++petPins;
            ps->petPin = pet->pin;
            ps->worldX = xOffset + (18 * i);
            ps->worldY = 49;
            ps->flip = 1;
        } else {
            ps->petPin = 0;
        }
    }

    for (int i=0; i <=4; i++) {
        struct Pet *pet = getEnemyTeamPet(i);
        struct PetSprite * ps = getPetSprite(i+5);
        if (pet->id) {
            pet->pin = ++petPins;
            ps->petPin = petPins;
            ps->worldX = xOffset + 100 + (18 * i);
            ps->worldY = 50;
            ps->flip = 0;
            ps->shortStat = 0;
        } else {
            ps->petPin = 0;
        }
    }
}

void prepareSceneBattle() {
    for (int i=0; i <=12; i++) {
        struct PetSprite * ps = getPetSprite(i);
        ps->visiblePet = true;
        ps->visibleStats = true;
        ps->worldX = 0;
        ps->worldY = 0;
        ps->petPin = 0;
    }
    resetAnimalSpritesForBattle();
    updateAnimalSprites();
}

int result = 0;
void tickSceneBattle() {
    updateAnimalSprites();
    tickMainLoop();
    sleep(30);
    if (!result) {
        result = battle();
        tte_set_pos(0,0);
        if (result == -1) {
            tte_write(" #{cx:0x1000}You tied.\n");
        }
        if (result == -2) {
            tte_write(" #{cx:0x3000}You lost.\n");
        }
        if (result == -3) {
            tte_write(" #{cx:0x3000}You won!\n");
        }
    }

    updateAnimalSprites();
    tickMainLoop();
//    OBJ_ATTR *sprite;
//    struct PetSprite * ps = getPetSprite(0);
//    ps->screenX = 200;
//    ps->screenY = 50;
//    updateAnimalSprites();
}