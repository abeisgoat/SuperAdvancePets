
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void turkeyTriggerFriendSummoned(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Turkey trigger FriendSummoned");
    if (selfPet == activatingPet) return;

    int stats = expToLevel(selfPet->experience) * 3;
    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int activatingPos = petPosition(usOrThem, us, them, activatingPet);

    animateStatsToTeamPosition(selfPos, activatingPos);
    resolveAnimation();

    activatingPet->attack += stats;
    activatingPet->health += stats;
}
