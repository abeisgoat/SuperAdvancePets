
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void sheepTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Sheep trigger Faint");


    for (int l=1; l<= 2; l++) {
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

            summonPet(44, space);
            int stats = expToLevel(selfPet->experience) * 2;
            space->attack = stats;
            space->health = stats;
        } else {
            return;
        }
    }
}
