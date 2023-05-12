
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void antTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet) {
    printf("Activated Ant trigger Faint\n");

    struct Pet * teammate = randomOtherTeamMember(us, selfPet);

    if (teammate->id == 0) {
        printf("No teammate to receive boost.\n");
        return;
    }

    int givePos = petPosition(usOrThem, us, them, selfPet);
    int takePos = petPosition(usOrThem, us, them, teammate);

    animateStatsToTeamPosition(givePos, takePos);
    resolveAnimation();

    switch (expToLevel(selfPet->experience)) {
        case 1:
            teammate->battleModifierAttack += 1;
            teammate->battleModifierHealth += 1;
            break;
        case 2:
            teammate->battleModifierAttack += 2;
            teammate->battleModifierHealth += 2;
            break;
        case 3:
            teammate->battleModifierAttack += 3;
            teammate->battleModifierHealth += 3;
            break;
    }
}
