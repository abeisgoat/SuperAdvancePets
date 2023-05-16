
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void leopardTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Leopard trigger StartOfBattle");

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    for (int l=1; l<= expToLevel(selfPet->experience); l++) {
        struct Pet * enemy = randomOtherTeamMember(them, selfPet);
        int enemyPos = petPosition(usOrThem, us, them, selfPet);
        int damage = selfPet->attack * .5;
        animateDamageToTeamPosition(selfPos, enemyPos);
        resolveAnimation();
        damagePet(usOrThem, us, them, store, enemy, damage);
    }
}
