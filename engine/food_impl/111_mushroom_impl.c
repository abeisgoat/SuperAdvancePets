#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

//TODO: Implement mushroom
void mushroomTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Mushroom trigger Buy");

    targetPet->heldItem = itemPet->id;
}
