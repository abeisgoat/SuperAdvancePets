
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void shrimpTriggerSell(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Shrimp trigger Sell");

    struct Pet * friend = randomOtherTeamMember(us, selfPet);

    if (friend->id) {
        int givePos = petPosition(usOrThem, us, them, selfPet);
        int friendPos = petPosition(usOrThem, us, them, friend);

        animateStatsToTeamPosition(givePos, friendPos);
        resolveAnimation();

        friend->attack += expToLevel(selfPet->experience);
    }
}
