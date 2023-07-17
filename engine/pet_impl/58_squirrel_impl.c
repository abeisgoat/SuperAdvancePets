
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: make squrrel animate
void squirrelTriggerStartOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Squirrel trigger StartOfTurn");

    for (int i=0; i<7; i++) {
        if (store[i].id > 100) {
            if (store[i].cost == -1) {
                store[i].cost = 3;
            }
            store[i].cost -= 1;
        }
    }

//    int selfPos = petPosition(usOrThem, us, them, selfPet);
//    animateStatsToTeamPosition(selfPos, selfPos);
//    resolveAnimation();
}
