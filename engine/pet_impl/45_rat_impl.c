
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void ratTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rat trigger Faint\n");

    struct Pet * space;
    int lvl = expToLevel(selfPet->experience);
    for (int l=1; l<= lvl; l++) {
        int ratPos = 0;
        if (usOrThem == 1) {
            ratPos = 4;
        }
        int hasSpace = tryToMakeRoom(usOrThem, them, ratPos);

        resolveAnimation();
        if (hasSpace) {
            space = &them[ratPos];
            animatePoofAtPosition(ratPos);
            resolveAnimation();

            summonPet(getPetByID(17), space);
//            space->attack = lvl;
//            space->health = lvl;
            resolveSpawns();
            postSummonPet(space);
        } else {
            return;
        }
    }
}
