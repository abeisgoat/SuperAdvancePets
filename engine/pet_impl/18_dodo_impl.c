
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void dodoTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Dodo Start of Battle");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int posModifier = +1;

    if (usOrThem == 1) {
        posModifier *= -1;
    }

    struct Pet * adjacentPetAhead = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

    if (adjacentPetAhead->id > 0) {
        animateStatsToTeamPosition(selfPos, selfPos + posModifier);
    }
    resolveAnimation();

    int attack = selfPet->attack * .5;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            attack *= 1;
            break;
        case 2:
            attack *= 2;
            break;
        case 3:
            attack *= 3;
            break;
    }

    if (adjacentPetAhead->id > 0) {
        adjacentPetAhead->battleModifierAttack += attack;
    }
}
