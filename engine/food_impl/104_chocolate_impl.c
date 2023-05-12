#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void chocolateTriggerBuy(int _, PetTeam store, PetTeam them, struct Pet * itemPet, struct Pet * targetPet) {
    printf("Activated Chocolate trigger Buy");

    int givePos = itemPosition(store, itemPet);
    int takePos = petPosition(1, store, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->experience += 1;
}
