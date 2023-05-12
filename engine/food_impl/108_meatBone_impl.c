#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void meatBoneTriggerBuy(int _, PetTeam store, PetTeam them, struct Pet * itemPet, struct Pet * targetPet) {
    printf("Activated Meat Bone trigger Buy");

    int givePos = itemPosition(store, itemPet);
    int takePos = petPosition(1, store, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->heldItem = itemPet->id;
}
