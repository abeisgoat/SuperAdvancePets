
#include "../globals.h"
#include <stdio.h>

// TODO: There may be an issue with bonus costs being lost when stacking pigs, idk
void pigTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Pig trigger Sell");
    selfPet->cost = -1 - expToLevel(selfPet->experience);
}

void pigTriggerLevelUp(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Pig trigger LevelUp");
    selfPet->cost = -1 - expToLevel(selfPet->experience);
}
