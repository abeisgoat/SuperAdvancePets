
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void dragonTriggerBuyFriend(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Dragon trigger buy friend");
    int isTierOne = activatingPet->tier == 1;

    if (!isTierOne) return;

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int i = 0; i <=4; i++) {
        struct Pet * friend = &us[i];

        if (friend->id && friend != selfPet) {
            int friendPos = petPosition(usOrThem, us, them, friend);
            animateStatsToTeamPosition(selfPos, friendPos);
        }
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

    for (int i = 0; i <=4; i++) {
        struct Pet * friend = &us[i];

        if (friend->id && friend != selfPet) {
            friend->health += stats;
            friend->attack += stats;
        }
    }
}
