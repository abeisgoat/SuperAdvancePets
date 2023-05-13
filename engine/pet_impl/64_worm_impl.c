
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void wormTriggerEatsShopFood(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Worm trigger EatsShopFood");

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    animateStatsToTeamPosition(selfPos, selfPos);
    resolveAnimation();
    selfPet->attack += expToLevel(selfPet->experience);
    selfPet->health += expToLevel(selfPet->experience);
}
