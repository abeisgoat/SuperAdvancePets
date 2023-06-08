#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void cupcakeTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Cupcake trigger Buy");

    targetPet->battleModifierAttack += 3 * getFoodMultiple();
    targetPet->battleModifierHealth += 3 * getFoodMultiple();
}
