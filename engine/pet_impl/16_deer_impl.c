
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void deerTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Deer trigger Faint");
    int level = expToLevel(selfPet->experience);

    animatePoofAtPosition(petPosition(usOrThem, us, them, selfPet));
    resolveAnimation();

    int stats = 5;
    switch (level) {
        case 1:
            stats *= 1;
            break;
        case 2:
            stats *= 2;
            break;
        case 3:
            stats *= 3;
            break;
    }

    summonPet(getPetByID(8), selfPet);
    selfPet->attack = stats;
    selfPet->health = stats;
    postSummonPet(selfPet);
}
