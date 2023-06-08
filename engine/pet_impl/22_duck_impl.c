
#include "../globals.h"
#include "../../src/animations.h"
#include "../../src/tick.h"
#include <stdio.h>

void duckTriggerSell(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Duck trigger Sell");

    int health = 1;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            health *= 1;
            break;
        case 2:
            health *= 2;
            break;
        case 3:
            health *= 3;
            break;
    }

    for (int i=0; i<7; i++) {
        struct Pet * storePet = &store[i];

        if (storePet->id > 0 && !isItem(storePet->id)) {
            storePet->health += health;
        }
    }
}
