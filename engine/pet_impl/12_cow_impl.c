
#include "../globals.h"
#include <stdio.h>

void cowTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Cow trigger Buy");
    int health = 2 * expToLevel(selfPet->experience);
    int attack = 1 * expToLevel(selfPet->experience);
    store[5].id = 110;
    store[5].cost = 0;
    store[5].attack = attack;
    store[5].health = health;

    store[6].id = 110;
    store[6].cost = 0;
    store[6].attack = attack;
    store[6].health = health;
}
