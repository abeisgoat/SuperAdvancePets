
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Implement Turtle Faint
void turtleTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Turtle trigger Faint");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int l=1; l<=expToLevel(selfPet->experience); l++) {
        int posModifier = -l;

        if (usOrThem == 1) {
            posModifier *= -1;
        }

        struct Pet * adjacentPetBehind = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

        if (adjacentPetBehind->id > 0) {
            animateDamageToTeamPosition(selfPos, selfPos + posModifier);
        }
        resolveAnimation();

        int damage = 1;

        if (adjacentPetBehind->id > 0) {
            damagePet(adjacentPetBehind, damage);
        }
    }
}
