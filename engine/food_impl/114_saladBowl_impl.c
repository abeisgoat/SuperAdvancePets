#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void saladBowlTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Salad trigger Buy");

    struct Pet * friend1 = randomOtherTeamMember(us, itemPet);
    struct Pet * friend2 = randomOtherTeamMember(us, friend1);

    int friend1Pos = petPosition(usOrThem, us, them, friend1);
    int friend2Pos = petPosition(usOrThem, us, them, friend2);

    animateStatsToTeamPosition(friend1Pos, friend1Pos);
    animateStatsToTeamPosition(friend2Pos, friend2Pos);
    resolveAnimation();

    friend1->attack += 1 * getFoodMultiple();
    friend1->health += 1 * getFoodMultiple();

    friend2->attack += 1 * getFoodMultiple();
    friend2->health += 1 * getFoodMultiple();
}
