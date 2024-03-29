
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void otterTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Otter trigger Buy");
    for (int l=1; l<= expToLevel(selfPet->experience); l++) {
        struct Pet * friend1 = randomOtherTeamMember(us, selfPet);

        if (friend1->id > 0) {

            int selfPos = petPosition(usOrThem, us, them, selfPet);
            int friend1Pos = petPosition(usOrThem, us, them, friend1);

            animateStatsToTeamPosition(selfPos, friend1Pos);
            resolveAnimation();

            friend1->attack += 1;
            friend1->health += 1;
        }
    }
}
