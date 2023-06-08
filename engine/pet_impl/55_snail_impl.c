
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void snailTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Snail trigger buy");

    if (getLastResult() != -2) return;

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    for (int i = 0; i<=4; i++) {
        struct Pet * friend = &us[i];
        if (friend->id && friend != selfPet) {
            int petPos = petPosition(usOrThem, us, them, &us[i]);
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
