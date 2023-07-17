
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void sleepingPillTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Sleeping Pill trigger Buy");

    targetPet->attack = 0;
    targetPet->health = 0;
}
