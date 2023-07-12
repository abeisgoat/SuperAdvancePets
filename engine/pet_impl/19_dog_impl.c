
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>
#include <stdlib.h>

void dogTriggerFriendSummoned(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Dog trigger Friend Summoned");

    if (activatingPet == selfPet) return;

    int attackOrHealth = rand()%2;

    int stat = 1;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            stat *= 1;
            break;
        case 2:
            stat *= 2;
            break;
        case 3:
            stat *= 3;
            break;
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    if (attackOrHealth == 0) {
        animateStatAttackToTeamPosition(selfPos, selfPos);
        resolveAnimation();
        selfPet->battleModifierAttack += stat;
    } else {
        animateStatHealthToTeamPosition(selfPos, selfPos);
        resolveAnimation();
        selfPet->battleModifierHealth += stat;
    }
}
