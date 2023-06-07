
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void milkTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Milk trigger Buy");

    targetPet->attack += itemPet->attack;
    targetPet->health += itemPet->health;
}
