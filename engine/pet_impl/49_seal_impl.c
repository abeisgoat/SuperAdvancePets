
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void sealTriggerEatsShopFood(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Seal trigger EatsShopFood");

    struct Pet * friend1 = randomOtherTeamMember(them, selfPet);
    struct Pet * friend2 = randomOtherTeamMember(them, friend1);

    int givePos = petPosition(usOrThem, us, them, selfPet);
    int friend1Pos = petPosition(usOrThem, us, them, friend1);
    int friend2Pos = petPosition(usOrThem, us, them, friend2);

    animateStatsToTeamPosition(givePos, friend1Pos);
    animateStatsToTeamPosition(givePos, friend2Pos);
    resolveAnimation();

    int stats = expToLevel(selfPet->experience);
    friend1->attack+=stats;
    friend1->health+=stats;

    friend2->attack+=stats;
    friend2->health+=stats;
}
