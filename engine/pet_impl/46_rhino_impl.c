
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void rhinoTriggerKnockOut(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rhino trigger KnockOut");

    struct Pet * target;
    if (usOrThem == 0) {
        target = getLeftMostPet(them);
    } else {
        target = getRightMostPet(them);
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    if (target->id > 0) {
        int damage = expToLevel(selfPet->experience) * 4;
        int targetPos = petPosition(usOrThem, us, them, target);
        animateDamageToTeamPosition(selfPos, targetPos);
        resolveAnimation();
        damagePet(usOrThem, us, them, store, selfPet, target, damage);
    }
}
