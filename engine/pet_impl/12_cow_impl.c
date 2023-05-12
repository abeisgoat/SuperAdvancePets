
#include "../globals.h"
#include <stdio.h>

void cowTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Cow trigger Buy");
    store[5].id = 110;
    store[5].cost = 0;

    store[6].id = 110;
    store[6].cost = 0;
}
