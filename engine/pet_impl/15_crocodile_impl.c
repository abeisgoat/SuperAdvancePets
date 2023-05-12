
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void crocodileTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Crocodile trigger StartOfBattle");

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    for (int r = 0; r < expToLevel(selfPet->experience); r++) {
        int lastEnemyPosition = getLastEnemyTeamPosition(usOrThem, us, them);
        if (lastEnemyPosition == -1) return;

        struct Pet * enemy = getPetByPosition(usOrThem, us, them, lastEnemyPosition);
        animateDamageToTeamPosition(selfPos, lastEnemyPosition);
        resolveAnimation();
        damagePet(enemy, 8);
    }
}
