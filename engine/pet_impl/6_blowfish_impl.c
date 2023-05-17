
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void blowfishTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Blowfish trigger Hurt");

    struct Pet * enemy = randomOtherTeamMember(them, selfPet);

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    if (enemy->id) {
        int enemyPos = petPosition(usOrThem, us, them, enemy);
        animateDamageToTeamPosition(selfPos, enemyPos);
    }
    resolveAnimation();

    int damage = 2;
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

    if (enemy->id > 0) {
        damagePet(usOrThem, us, them, store, enemy, damage);
    }
}
