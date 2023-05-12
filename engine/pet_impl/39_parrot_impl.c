
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Implement Parrot EndOfTurn
void parrotTriggerEndOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Parrot trigger EndOfTurn");

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int posModifier = 1;

    if (usOrThem == 1) {
        posModifier *= -1;
    }

    struct Pet * adjacentPetAhead = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

    if (adjacentPetAhead->id > 0) {
        animateAbilityFromTeamPosition(selfPos, selfPos + posModifier);
    }
    resolveAnimation();

    selfPet->id = adjacentPetAhead->id + 200;
}
