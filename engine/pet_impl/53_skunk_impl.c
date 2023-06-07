
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void skunkTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Skunk trigger StartOfBattle");
    struct Pet * target;
    int highestHealth = 0;
    for (int i=0; i<=4; i++) {
        struct Pet * other = &them[i];
        if (getPetHealth(other) > highestHealth) {
            target = other;
        }
    }


    if (target->id) {
        int selfPos = petPosition(usOrThem, us, them, selfPet);
        int enemyPos = petPosition(usOrThem, us, them, target);
        animateDamageToTeamPosition(selfPos, enemyPos);
        resolveAnimation();
        float multiple = .33f * expToLevel(selfPet->experience);
        target->health -= (target->health * multiple);

        if (target->health <= 0) {
            target->health = 1;
        }
    }
}
