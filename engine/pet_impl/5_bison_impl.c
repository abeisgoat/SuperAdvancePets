
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void bisonTriggerEndOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Bison trigger EndOfTurn");

    int hasLevel3Friend = 0;
    for (int i = 0; i<=4; i++) {
        if (expToLevel(us[i].experience) == 3) {
            hasLevel3Friend = 1;
            break;
        }
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    if (hasLevel3Friend) {
        animateStatsToTeamPosition(selfPos, selfPos);
    }
    resolveAnimation();

    int stats = 1;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            stats *= 1;
            break;
        case 2:
            stats *= 2;
            break;
        case 3:
            stats *= 3;
            break;
    }


    if (hasLevel3Friend) {
        selfPet->health += stats;
        selfPet->attack += stats;
    }
}
