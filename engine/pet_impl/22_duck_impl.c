
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void duckTriggerSell(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Duck trigger Sell");

    int health = 1;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            health *= 1;
            break;
        case 2:
            health *= 2;
            break;
        case 3:
            health *= 3;
            break;
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int i=0; i<=4; i++) {
        struct Pet * storePet = &store[i];
        int storePos = storePosition(store, storePet);
        animateStatsToTeamPosition(selfPos, storePos);
    }

    resolveAnimation();

    for (int i=0; i<=4; i++) {
        struct Pet * storePet = &store[i];

        if (storePet->id > 0) {
            storePet->health += health;
        }
    }
}
