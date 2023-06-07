#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void garlicTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Garlic trigger Buy");

    targetPet->heldItem = itemPet->id;
}
