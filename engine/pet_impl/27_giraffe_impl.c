
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void giraffeTriggerEndOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Giraffe trigger EndOfTurn");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int l=1; l<=expToLevel(selfPet->experience); l++) {
        int posModifier = l;

        if (usOrThem == 1) {
            posModifier *= -1;
        }

        struct Pet * adjacentPetAhead = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

        if (adjacentPetAhead->id > 0) {
            animateStatsToTeamPosition(selfPos, selfPos + posModifier);
        }
        resolveAnimation();

        int stats = 1;

        if (adjacentPetAhead->id > 0) {
            adjacentPetAhead->attack += stats;
            adjacentPetAhead->health += stats;
        }
    }
}
