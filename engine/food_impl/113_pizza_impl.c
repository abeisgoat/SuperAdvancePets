#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void pizzaTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Pizza trigger Buy");

    struct Pet * friend1 = randomOtherTeamMember(us, itemPet);
    struct Pet * friend2 = randomOtherTeamMember(us, friend1);

    int givePos = storePosition(store, itemPet);
    int friend1Pos = petPosition(usOrThem, us, them, friend1);
    int friend2Pos = petPosition(usOrThem, us, them, friend2);

    animateStatsToTeamPosition(givePos, friend1Pos);
    animateStatsToTeamPosition(givePos, friend2Pos);
    resolveAnimation();

    friend1->attack+=3;
    friend1->health+=3;

    friend2->attack+=3;
    friend2->health+=3;
}
