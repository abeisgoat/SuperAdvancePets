#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void meatBoneTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Meat Bone trigger Buy");

    targetPet->heldItem = itemPet->id;
}
