
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void elephantTriggerBeforeAttack(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Elephant trigger BeforeAttack");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    if (expToLevel(selfPet->experience) > selfPet->activations) {
        int posModifier = -1;

//        if (usOrThem == 1) {
//            posModifier *= -1;
//        }

        struct Pet * adjacentPetBehind = getPetByPosition(usOrThem, us, them, selfPos + posModifier);

        if (adjacentPetBehind->id > 0) {
            animateDamageToTeamPosition(selfPos, selfPos + posModifier);
        }
        resolveAnimation();

        int damage = 1;

        if (adjacentPetBehind->id > 0) {
            damagePet(usOrThem, us, them, store, selfPet, adjacentPetBehind, damage);
        }
    }
}
