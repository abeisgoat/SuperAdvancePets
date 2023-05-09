#include "globals.h"
#include <stdio.h>

void cricketTriggerFeint(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet) {
    printf("Activated cricket feint trigger.\n");

    int petPos = petPosition(usOrThem, us, them, pet);

    printf("[>> Animate poof to zombie at pos %i<<]\n", petPos);

    pet->id = 4;
    switch (pet->level) {
        case 1:
            pet->battleModifierAttack = -pet->attack + 1;
            pet->battleModifierDefense = -pet->attack + 1;
            break;
        case 2:
            pet->battleModifierAttack = -pet->attack + 2;
            pet->battleModifierDefense = -pet->attack + 2;
            break;
        case 3:
            pet->battleModifierAttack = -pet->attack + 3;
            pet->battleModifierDefense = -pet->attack + 3;
            break;
    }
}