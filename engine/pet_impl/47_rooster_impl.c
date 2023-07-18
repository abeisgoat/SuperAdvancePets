
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>
#include <tonc_math.h>


void roosterTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rooster trigger Faint\n");

    int lvl = expToLevel(selfPet->experience);
    selfPet->id = 0;
    int attack = selfPet->attack;
    for (int l=1; l<= lvl; l++) {
        struct Pet * space;
        int selfPos = petTeamPosition(usOrThem, us, selfPet);

        int hasSpace = tryToMakeRoom(usOrThem, us, selfPos);

        resolveAnimation();
        if (hasSpace) {
            space = &us[selfPos];
            int spawnPos = selfPos;
            animatePoofAtPosition(spawnPos);
            resolveAnimation();

            summonPet(getPetByID(11), space);
            space->attack = max(attack / 2, 1);
            space->health = 1;
            resolveSpawns();
            postSummonPet(space);
        } else {
            return;
        }
    }
}
