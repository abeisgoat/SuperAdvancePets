#include <tonc.h>
#include "tick.h"
#include "stdlib.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "../engine/globals.h"
#include "structs.h"
#include "animations.h"
#include "ui.h"

int xOffset=264;
int result = 0;

int getWorldXForPetPositionInBattle(int petPosition) {
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
            ps->worldX = getWorldXForPetPositionInBattle(i) - 120;
            ps->worldY = 67;
            ps->flip = 1;
            ps->frozen = 0;
            ps->visibleStats = 0;
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
            ps->worldX = getWorldXForPetPositionInBattle(i + 5) + 120;
            ps->worldY = 67;
            ps->flip = 0;
            ps->frozen = 0;
            ps->shortStat = 0;
            ps->visibleStats = 0;
        } else {
            ps->petPin = 0;
        }
    }
}

void prepareSceneBattle() {
    for (int i=0; i <=12; i++) {
        struct PetSprite * ps = getPetSprite(i);
        ps->visiblePet = 1;
        ps->visibleStats = 1;
        ps->worldX = 0;
        ps->worldY = 0;
        ps->petPin = 0;
    }
    resetAnimalSpritesForBattle();
    updateAnimalSprites();
    updateGameplayInfo(0);
    result = 0;
}

void tickSceneBattle() {
    updateAnimalSprites();
    tickMainLoop();


    int walking=1;
    while (walking) {
        walking = 0;
        for (int i=0; i<10; i++) {
            struct PetSprite * ps = getPetSprite(i);

            if (ps->petPin) {
                int dx = getWorldXForPetPositionInBattle(i);

                if (ps->worldX < dx) {
                    ps->worldX += 1;
                    walking = 1;
                }
                if (ps->worldX > dx) {
                    ps->worldX -= 1;
                    walking = 1;
                }
                if (abs(ps->worldX - dx) < 1) {
                    ps->worldX = dx;
                }
            }
        }
        screenAnimalSprites();
        updateAnimalSprites();
        tickMainLoop();
    }
    sleep(30);
    for (int i=0; i<=9; i++) {
        getPetSprite(i)->visibleStats = 1;
    }
    updateAnimalSprites();
    sleep(90);

    if (!result) {
        backupTeam();
        result = battle();
        restoreTeam();
        tte_set_pos(80,114);
        if (result == -1) {
            tte_write(" #{cx:0x3000}You tied.\n");
        }
        if (result == -2) {
            tte_write(" #{cx:0x3000}You lost.\n");
            addLoss();
        }
        if (result == -3) {
            tte_write(" #{cx:0x3000}You won!\n");
            addWin();
        }
    }

    while (1) {
        if (key_hit(KEY_A)) {
            clearGameplayInfo();
            setScene(2);
            break;
        }
        tickMainLoop();
    }
}