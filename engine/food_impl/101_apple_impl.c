
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void appleTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Apple trigger Buy");
    targetPet->attack++;
    targetPet->health++;
}
