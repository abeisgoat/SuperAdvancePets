#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void saladTriggerBuy(int _, PetTeam store, PetTeam them, struct Pet * itemPet, struct Pet * targetPet) {
    printf("Activated Salad trigger Buy");

    struct Pet * friend1 = randomOtherTeamMember(them, itemPet);
    struct Pet * friend2 = randomOtherTeamMember(them, friend1);

    int givePos = itemPosition(store, itemPet);
    int friend1Pos = petPosition(1, store, them, friend1);
    int friend2Pos = petPosition(1, store, them, friend2);

    animateStatsToTeamPosition(givePos, friend1Pos);
    animateStatsToTeamPosition(givePos, friend2Pos);
    resolveAnimation();

    friend1->attack+=1;
    friend1->health+=1;

    friend2->attack+=1;
    friend2->health+=1;
}
