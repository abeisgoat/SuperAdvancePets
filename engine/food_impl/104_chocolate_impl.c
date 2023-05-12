#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void chocolateTriggerBuy(int _, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Chocolate trigger Buy");

    int givePos = itemPosition(store, itemPet);
    int takePos = petPosition(1, store, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->experience += 1;
}
