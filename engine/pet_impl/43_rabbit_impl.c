
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void rabbitTriggerPetEatsShopFood(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rabbit trigger EatsShopFood");
    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int activatingPos = petPosition(usOrThem, us, them, activatingPet);

    animateStatHealthToTeamPosition(selfPos, activatingPos);
    resolveAnimation();

    activatingPet->health += expToLevel(selfPet->experience);
}
