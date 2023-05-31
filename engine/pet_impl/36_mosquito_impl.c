
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void mosquitoTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Mosquito trigger StartOfBattle");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    for (int l=1; l<= expToLevel(selfPet->experience); l++) {
        struct Pet * enemy = randomOtherTeamMember(them, selfPet);

        if (enemy->id) {
            int enemyPos = petPosition(usOrThem, us, them, enemy);
            int damage = 1;
            animateDamageToTeamPosition(selfPos, enemyPos);
            resolveAnimation();
            damagePet(usOrThem, us, them, store, enemy, damage);
        }
    }
}
