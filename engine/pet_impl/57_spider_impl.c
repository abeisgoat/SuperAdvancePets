
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void spiderTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Spider trigger Faint\n");

    struct Pet * space;
    int selfPos = petTeamPosition(usOrThem, us, selfPet);

    selfPet->id = 0;
    int hasSpace = tryToMakeRoom(usOrThem, us, selfPos);
    int lvl = expToLevel(selfPet->experience);

    resolveAnimation();
    if (hasSpace) {
        space = &us[selfPos];
        animatePoofAtPosition(selfPos);
        resolveAnimation();

        summonPet(getRandomPetFromTier(3), space);
        space->attack = lvl * 2;
        space->health = lvl * 2;
        resolveSpawns();
        postSummonPet(space);
    } else {
        return;
    }
}
