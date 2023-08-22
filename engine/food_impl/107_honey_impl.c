#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void honeyTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Honey trigger Buy");

    int givePos = storePosition(store, itemPet);
    int takePos = petPosition(usOrThem,us, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->heldItem = itemPet->id;
}

void honeyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Honey faint trigger Buy");

    animatePoofAtPosition(petPosition(usOrThem, us, them, selfPet));
    resolveAnimation();

    summonPet(getPetByID(4), selfPet);
    selfPet->attack = 1;
    selfPet->health = 1;
    postSummonPet(selfPet);
}
