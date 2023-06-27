
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void mammothTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Mammoth trigger Faint\n");

    int stats = expToLevel(selfPet->experience)*2;
    int selfPos = petPosition(usOrThem, us, them, selfPet);
    for (int i=0; i<=4; i++) {
        struct Pet * friend = &us[i];
        if (friend->id > 0 && friend != selfPet) {
            int friendPos = petPosition(usOrThem, us, them, friend);
            animateStatsToTeamPosition(selfPos, friendPos);
        }
    }

    resolveAnimation();

    for (int i=0; i<=4; i++) {
        struct Pet * friend = &us[i];
        if (friend->id > 0 && friend != selfPet) {
            friend->attack += stats;
            friend->health += stats;
        }
    }
}
