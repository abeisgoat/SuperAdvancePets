#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void cupcakeTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Cupcake trigger Buy");

    targetPet->battleModifierAttack += 3;
    targetPet->battleModifierHealth += 3;
}
