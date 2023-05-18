
#include "../globals.h"
#include <stdio.h>

void cannedFoodTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Canned Food trigger Buy");
    addCanBoost(2);

    for (int i=0; i<7; i++) {
        struct Pet * item = &store[i];
        if (item->health) item->health += 2;
        if (item->attack) item->attack += 2;
    }
}
