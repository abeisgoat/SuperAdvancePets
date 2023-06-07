#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void chocolateTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Chocolate trigger Buy");

    targetPet->experience += 1;
}
