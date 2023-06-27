
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

int rhinoTriggerKnockOut(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rhino trigger KnockOut\n");

    if (isDead(selfPet)) return 0;

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
        return damagePet(usOrThem, us, them, store, selfPet, target, damage);
    }
    return 0;
}
