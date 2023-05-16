#include "tick.h"
#include "structs.h"
#include "scene_battle.h"
#include "../engine/pets.h"
#include "../engine/globals.h"
#include "../engine/battle.h"
#include "stdlib.h"


void sleep(int frames) {
    for (int i=0; i<frames;i++) {
        screenAnimalSprites();
        tickMainLoop();
    }
}

void animateToTeamPosition(int from, int to) {
}

void animatePoofAtPosition(int pos) {
}

void animateStatsToTeamPosition(int from, int to) {

}

void animateStatHealthToTeamPosition(int from, int to) {

}

void animateStatAttackToTeamPosition(int from, int to) {

}

void animateDamageToTeamPosition(int from, int to) {

}

void animateAbilityFromTeamPosition(int from, int to) {

}

void animateShuffleAtPosition(int from, int to) {

    while (1) {
        int hasMovement = 0;

        for (int i=0; i<10; i++) {
            struct Pet * pet;
            struct PetSprite * ps;

            if (i < 5) {
                pet = getPlayerTeamPet(i);
            } else {
                pet = getEnemyTeamPet(i-5);
            }


            for (int s = 0; s<12; s++) {
                ps = getPetSprite(s);
                if (ps->petPin == pet->pin) {
                    break;
                }
            }

            if (pet->pin > 0 && pet->pin == ps->petPin) {
                int idealX = getWorldXForPetPosition(i);
                if (abs(ps->worldX - idealX) > 3) {
                    if (idealX > ps->worldX) {
                        ps->worldX += 1;
                        hasMovement = 1;
                    }
                    if (idealX < ps->worldX) {
                        ps->worldX -= 1;
                        hasMovement = 1;
                    }
                } else {
                    ps->worldX = idealX;
                }
            }
        }

        if (hasMovement == 0) break;
        updateAnimalSprites();
        screenAnimalSprites();
        tickMainLoop();
    }
}

void animateDeath(struct Pet * pet) {
    struct PetSprite * ps;

    for (int s = 0; s<12; s++) {
        ps = getPetSprite(s);
        if (ps->petPin == pet->pin) {
            break;
        }
    }

    if (ps->petPin > 0 && ps->petPin == pet->pin) {
        ps->worldY = 0;
    }
}

void animateFighterAttack(struct Pet * fighterLeft, struct Pet * fighterRight) {
    struct PetSprite * leftSprite;
    struct PetSprite * rightSprite;

    for (int i=0; i<12; i++) {
        struct PetSprite * potentialSprite = getPetSprite(i);

        if (potentialSprite->petPin == fighterLeft->pin) {
            leftSprite = potentialSprite;
        }
        if (potentialSprite->petPin == fighterRight->pin) {
            rightSprite = potentialSprite;
        }
    }

    leftSprite->worldX += 5;
    rightSprite->worldX -= 5;

    sleep(30);

    leftSprite->worldX -= 5;
    rightSprite->worldX += 5;
}

void resolveAnimation() {
    screenAnimalSprites();
    updateAnimalSprites();
}