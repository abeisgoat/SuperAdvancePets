
#include "../globals.h"
#include <stdio.h>

// Todo: finish hippo
void hippoTriggerKnockOut(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Hippo trigger KnockOut");

    int stats = expToLevel(selfPet->experience) * 3;
    selfPet->battleModifierHealth += stats;
    selfPet->battleModifierAttack += stats;
}
