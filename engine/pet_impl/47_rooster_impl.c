
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

// Todo: make spwaning multiple boys work
// TODO: ../SuperAdvancePetsCLI battle 490010409,520030506,420000301,330021106,160010202 310050706,260010606,240050708,470020705,640030606
void roosterTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rooster trigger Faint");

    for (int l=1; l<= expToLevel(selfPet->experience); l++) {
        int hasSpace;
        struct Pet * space;
        if (usOrThem == 0) {
            if (shuffleLeftUntilEmpty(us) == 2) {
                hasSpace = 1;
                space = &us[4];
            }
        }
        if (usOrThem == 1) {
            if (shuffleRightUntilEmpty(us) == 2) {
                hasSpace = 1;
                space = &us[0];
            }
        }

        resolveAnimation();
        if (hasSpace) {
            int spawnPos = 4;
            if (usOrThem == 1) {
                spawnPos = 5;
            }
            animatePoofAtPosition(spawnPos);
            resolveAnimation();

            summonPet(getPetByID(44), space);
            space->attack = (selfPet->attack / 2);
            space->health = 1;
            postSummonPet(space);
        } else {
            return;
        }
    }
}
