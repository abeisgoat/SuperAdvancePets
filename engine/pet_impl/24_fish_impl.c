
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void fishTriggerLevelUp(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Fish trigger LevelUp");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int i=0; i<=4;i++) {
        if (&us[i] != selfPet && us[i].id > 0) {
            int other = petPosition(0, us, them, &us[i]);
            animateStatsToTeamPosition(selfPos, other);
        }
    }
    resolveAnimation();

    int stats = expToLevel(selfPet->experience);

    for (int i=0; i<=4; i++) {
        struct Pet * pet = &us[i];

        if (pet->id > 0) {
            pet->health += stats;
            pet->attack += stats;
        }
    }
}
