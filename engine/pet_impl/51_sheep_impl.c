
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>
#include <tonc_math.h>

void sheepTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Sheep trigger Faint\n");

    int lvl = expToLevel(selfPet->experience);
    selfPet->id = 0;
    for (int l=1; l<= 2; l++) {
        struct Pet * space;
        int selfPos = petTeamPosition(usOrThem, us, selfPet);

        int hasSpace = tryToMakeRoom(usOrThem, us, selfPos);

        resolveAnimation();
        if (hasSpace) {
            space = &us[selfPos];
            animatePoofAtPosition(selfPos);
            resolveAnimation();

            summonPet(getPetByID(44), space);
            space->attack = lvl * 2;
            space->health = lvl * 2;
            resolveSpawns();
            postSummonPet(space);
        } else {
            return;
        }
    }
}
