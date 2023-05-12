#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void cupcakeTriggerBuy(int _, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Cupcake trigger Buy");

    int givePos = storePosition(store, itemPet);
    int takePos = petPosition(1, store, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->battleModifierAttack += 3;
    targetPet->battleModifierHealth += 3;
}
