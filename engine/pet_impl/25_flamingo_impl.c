
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void flamingoTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Flamingo trigger Faint");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int posModifier1 = -1;
    int posModifier2 = -2;
    if (usOrThem == 1) {
        posModifier1 *= -1;
        posModifier2 *= -1;

    }

    struct Pet * adjacentPetBehind1 = getPetByPosition(usOrThem, us, them, selfPos + posModifier1);
    struct Pet * adjacentPetBehind2 = getPetByPosition(usOrThem, us, them, selfPos + posModifier2);

    if (adjacentPetBehind1->id > 0) {
        animateStatsToTeamPosition(selfPos, selfPos + posModifier1);
    }
    if (adjacentPetBehind2->id > 0) {
        animateStatsToTeamPosition(selfPos, selfPos + posModifier2);
    }
    resolveAnimation();

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

    if (adjacentPetBehind1->id > 0) {
        adjacentPetBehind1->health += stats;
        adjacentPetBehind1->attack += stats;
    }
    if (adjacentPetBehind2->id > 0) {
        adjacentPetBehind2->health += stats;
        adjacentPetBehind2->attack += stats;
    }
}
