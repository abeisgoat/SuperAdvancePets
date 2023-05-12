
#include "../globals.h"
#include <stdio.h>

// TODO: Implement Pig Sell
void pigTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Pig trigger Sell");
    selfPet->cost = -expToLevel(selfPet->experience);;
}

void pigTriggerLevelUp(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Pig trigger LevelUp");
    selfPet->cost = -expToLevel(selfPet->experience);
}
