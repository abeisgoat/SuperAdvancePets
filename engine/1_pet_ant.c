#include "globals.h"
#include <stdio.h>

void antTriggerFeint(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet) {
    printf("Activated Ant feint trigger.\n");

    struct Pet * teammate = randomOtherTeamMember(us, pet);

    if (teammate->id == 0) {
        printf("No teammate to receive boost.\n");
        return;
    }

    int givePos = petPosition(usOrThem, us, them, pet);
    int takePos = petPosition(usOrThem, us, them, teammate);

    printf("[>> Animate Stat Boost from pos %i to pos %i <<]\n", givePos, takePos);

    switch (pet->level) {
        case 1:
            teammate->battleModifierAttack += 1;
            teammate->battleModifierDefense += 1;
            break;
        case 2:
            teammate->battleModifierAttack += 2;
            teammate->battleModifierDefense += 2;
            break;
        case 3:
            teammate->battleModifierAttack += 3;
            teammate->battleModifierDefense += 3;
            break;
    }
}