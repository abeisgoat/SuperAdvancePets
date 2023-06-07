
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void crabTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Crab trigger start of battle");
    int maxHealth = 0;
    int healerPos = 0;


    for (int i=0; i<=4; i++) {
        if (us[i].health > maxHealth) {
            maxHealth = us[i].health;
            healerPos = i;

            if (usOrThem == 1) {
                healerPos += 5;
            }
        }
    }

    animateStatHealthToTeamPosition(healerPos, petPosition(usOrThem, us, them, selfPet));
    resolveAnimation();

    maxHealth *= .5;
    maxHealth *= expToLevel(selfPet->health);
    selfPet->health = maxHealth;
}
