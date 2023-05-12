
#include "../globals.h"
#include <stdio.h>

void boarTriggerBeforeAttack(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Boar trigger BeforeAttack");

    int stats = 1;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            stats *= 1;
            break;
        case 2:
            stats *= 2;
            break;
        case 3:
            stats *= 3;
            break;
    }

    selfPet->battleModifierAttack += stats;
    selfPet->battleModifierHealth += stats;
}
