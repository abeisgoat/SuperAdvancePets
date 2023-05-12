
#include "../globals.h"
#include <stdio.h>

void horseTriggerFriendSummoned(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Horse trigger Summoned");
    activatingPet->battleModifierAttack += expToLevel(selfPet->experience);
}
