#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void sushiTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Sushi trigger Buy");

    struct Pet * friend1 = randomOtherTeamMember(pt, selfPet);
    struct Pet * friend2 = randomOtherTeamMember(pt, friend1);

    int friend1Pos = petPosition(usOrThem, pt, et, friend1);
    int friend2Pos = petPosition(usOrThem, pt, et, friend2);

    animateStatsToTeamPosition(friend1Pos, friend1Pos);
    animateStatsToTeamPosition(friend2Pos, friend2Pos);
    resolveAnimation();

    friend1->attack += 2 * getFoodMultiple();
    friend1->health += 2 * getFoodMultiple();

    friend2->attack += 2 * getFoodMultiple();
    friend2->health += 2 * getFoodMultiple();
}
