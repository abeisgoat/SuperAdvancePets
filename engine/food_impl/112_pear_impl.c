#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void pearTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Pear trigger Buy");

    targetPet->attack += 2 * getFoodMultiple();
    targetPet->health += 2 * getFoodMultiple();
}
