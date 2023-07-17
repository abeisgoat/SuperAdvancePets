
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

int hippoTriggerKnockOut(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Hippo trigger KnockOut");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    animateStatsToTeamPosition(selfPos, selfPos);
    resolveAnimation();
    int stats = expToLevel(selfPet->experience) * 3;
    selfPet->attack += stats;
    selfPet->health += stats;
    return 0;
}
