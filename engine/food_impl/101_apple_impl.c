
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void appleTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Apple trigger Buy");
    targetPet->attack += 1 * getFoodMultiple();
    targetPet->health += 1 * getFoodMultiple();
}
