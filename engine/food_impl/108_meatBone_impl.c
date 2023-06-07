#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Implement meatbone
void meatBoneTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Meat Bone trigger Buy");

    targetPet->heldItem = itemPet->id;
}
