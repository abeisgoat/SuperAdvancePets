
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void horseTriggerFriendSummoned(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Horse trigger Summoned\n");

    if (selfPet == activatingPet) return;

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int other = petPosition(0, us, them, activatingPet);
    animateStatsToTeamPosition(selfPos, other);
    resolveAnimation();

    activatingPet->battleModifierAttack += expToLevel(selfPet->experience);
}
