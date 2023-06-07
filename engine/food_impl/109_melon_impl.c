#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void melonTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Melon trigger Buy");

    targetPet->heldItem = itemPet->id;
}
