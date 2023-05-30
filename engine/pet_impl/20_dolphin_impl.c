
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void dolphinTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Dolphin trigger StartOfBattle\n");
    int lowestHealth = 50;
    int lowestHealthPos;
    struct Pet * enemy;
    for (int i=0; i<=4; i++) {
        enemy = &them[i];
        if (getPetHealth(&them[i]) < lowestHealth && enemy->id > 0) {
            lowestHealth = getPetHealth(&them[i]);
            lowestHealthPos = i;
        }
    }


    enemy = &them[lowestHealthPos];
    int selfPos = petPosition(usOrThem, us, them, selfPet);

    if (enemy->id) {
        int enemyPos = petPosition(usOrThem, us, them, enemy);
        animateDamageToTeamPosition(selfPos, enemyPos);
    }
    printf("target %d", lowestHealthPos);
    printf("target id %d", enemy->id);
    resolveAnimation();

    int damage = 5;
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
