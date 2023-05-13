
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void kangarooTriggerFriendAttacks(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Kangaroo trigger FriendAttacks");

    int activatingPos = petPosition(usOrThem, us, them, activatingPet);
    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int ahead = 1;
    if (usOrThem == 1) {
        ahead *= -1;
    }

    if (selfPos+ahead != activatingPos) return;

    animateStatsToTeamPosition(selfPos, selfPos);
    resolveAnimation();

    int stats = expToLevel(selfPet->experience) * 2;
    selfPet->battleModifierAttack += stats;
    selfPet->battleModifierHealth += stats;
}
