#include "../globals.h"
#include <stdio.h>

// TODO: Implement steak
void steakTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Steak trigger Buy");

    targetPet->heldItem = itemPet->id;
}
