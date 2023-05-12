
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void monkeyTriggerEndOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Monkey trigger EndOfTurn");

    struct Pet * frontMostPet;
    if (usOrThem == 0) {
        frontMostPet = getPlayerFighter(us);
    } else {
        frontMostPet = getEnemyFighter(us);
    }

    int health = 0;
    int attack = 0;

    switch (expToLevel(selfPet->experience)) {
        case 1:
            health = 2;
            attack = 3;
            break;
        case 2:
            health = 4;
            attack = 6;
            break;
        case 3:
            health = 6;
            attack = 9;
            break;
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    animateStatsToTeamPosition(selfPos, petPosition(usOrThem, us, them, frontMostPet));

    resolveAnimation();

    frontMostPet->attack += attack;
    frontMostPet->health += health;
}
