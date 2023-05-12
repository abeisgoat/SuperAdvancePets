
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void peacockTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Peacock trigger Hurt");
    int selfPos = petPosition(usOrThem, us, them, selfPet);
    animateStatAttackToTeamPosition(selfPos, selfPos);
    resolveAnimation();

    selfPet->attack += expToLevel(selfPet->experience) * 4;
}
