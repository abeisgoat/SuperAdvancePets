
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void camelTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Camel trigger Hurt");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int posModifier = -1;

    if (usOrThem == 1) {
        posModifier *= -1;
    }

    struct Pet * adjacentPetBehind = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

    if (adjacentPetBehind->id > 0) {
        animateStatsToTeamPosition(selfPos, selfPos + posModifier);
    }
    resolveAnimation();

    int stats = 2;
    switch (expToLevel(selfPet->experience)) {
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

    if (adjacentPetBehind->id > 0) {
        adjacentPetBehind->health += stats;
        adjacentPetBehind->attack += stats;
    }
}
