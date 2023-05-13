
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void snailTriggerBuyAfterLoss(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Snail trigger BuyAfterLoss");

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    for (int i = 0; i<=4; i++) {
        struct Pet * friend = &us[i];
        if (friend->id) {
            int petPos = petPosition(usOrThem, us, them, selfPet);
            animateStatsToTeamPosition(selfPos, petPos);
        }
    }

    resolveAnimation();

    int stats = expToLevel(selfPet->experience);
    for (int i = 0; i<=4; i++) {
        struct Pet * friend = &us[i];
        if (friend->id) {
            friend->health += stats;
            friend->attack += stats;
        }
    }
}
