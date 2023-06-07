#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void sushiTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Sushi trigger Buy");

    struct Pet * friend1 = randomOtherTeamMember(us, itemPet);
    struct Pet * friend2 = randomOtherTeamMember(us, friend1);

    friend1->attack+=2;
    friend1->health+=2;

    friend2->attack+=2;
    friend2->health+=2;
}
