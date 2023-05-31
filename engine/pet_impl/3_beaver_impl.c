
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Implement Beaver Sell
void beaverTriggerSell(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Beaver trigger Sell");

    struct Pet * friend1 = randomOtherTeamMember(us, selfPet);
    struct Pet * friend2 = randomOtherTeamMember(us, friend1);

//    int selfPos = petPosition(usOrThem, us, them, selfPet);
//
////    if (friend1->id) {
////        int friend1Pos = petPosition(0, us, them, friend1);
////        animateStatsToTeamPosition(selfPos, friend1Pos);
////    }
////    if (friend2->id) {
////        int friend2Pos = petPosition(0, us, them, friend2);
////        animateStatsToTeamPosition(selfPos, friend2Pos);
////    }
////    resolveAnimation();

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

    if (friend1->id > 0) {
        friend1->health += health;
    }
    if (friend2->id > 0) {
        friend2->health += health;
    }
}
