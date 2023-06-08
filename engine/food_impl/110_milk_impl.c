
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void milkTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Milk trigger Buy");

    targetPet->attack += itemPet->attack * getFoodMultiple();
    targetPet->health += itemPet->health * getFoodMultiple();
}
