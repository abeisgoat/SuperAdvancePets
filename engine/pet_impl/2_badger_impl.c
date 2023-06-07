
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void badgerTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated badger trigger Faint\n");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    struct Pet * adjacentPetLeft = getPetByPosition(usOrThem, us, them, selfPos - 1);
    struct Pet * adjacentPetRight = getPetByPosition(usOrThem, us, them, selfPos + 1);

    if (adjacentPetLeft->id > 0) {
        animateDamageToTeamPosition(selfPos, selfPos-1);
    }
    if (adjacentPetRight->id > 0) {
        animateDamageToTeamPosition(selfPos, selfPos+1);
    }
    resolveAnimation();

    int damage = selfPet->attack + selfPet->battleModifierAttack;
    switch (expToLevel(selfPet->experience)) {
        case 1:
            damage *= 1;
            break;
        case 2:
            damage *= 2;
            break;
        case 3:
            damage *= 3;
            break;
    }

    if (adjacentPetLeft->id > 0) {
        damagePet(usOrThem, us, them, store, selfPet, adjacentPetLeft, damage);
    }

    if (adjacentPetRight->id > 0) {
        damagePet(usOrThem, us, them, store, selfPet, adjacentPetRight, damage);
    }
}
