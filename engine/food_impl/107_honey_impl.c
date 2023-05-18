#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void honeyTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Honey trigger Buy");

    int givePos = storePosition(store, itemPet);
    int takePos = petPosition(usOrThem,us, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->heldItem = itemPet->id;
}
