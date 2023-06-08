
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void snakeTriggerAfterAttack(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Snake trigger AfterAttack");

    int activatingPos = petPosition(usOrThem, us, them, activatingPet);
    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int ahead = 1;
    if (usOrThem == 1) {
        ahead *= -1;
    }

    if (selfPos+ahead != activatingPos) return;

    struct Pet * target = randomOtherTeamMember(them, selfPet);
    int targetPos = petPosition(usOrThem, us, them, target);
    if (target->id) {
        animateDamageToTeamPosition(selfPos,targetPos);
        resolveAnimation();
        int damage = expToLevel(selfPet->experience) * 5;
        damagePet(usOrThem, us, them, store, selfPet, target, damage);

    }
}
