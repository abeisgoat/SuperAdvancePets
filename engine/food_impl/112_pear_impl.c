#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void pearTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Pear trigger Buy");

    int givePos = storePosition(store, itemPet);
    int takePos = petPosition(usOrThem,us, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->attack+=2;
    targetPet->health+=2;
}
