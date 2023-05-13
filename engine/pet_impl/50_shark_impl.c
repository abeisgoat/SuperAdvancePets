
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void sharkTriggerFriendFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Shark trigger Faint");

    int health = 2 * expToLevel(selfPet->experience);
    int attack = expToLevel(selfPet->experience);

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    animateStatsToTeamPosition(selfPos, selfPos);
    resolveAnimation();

    selfPet->health += health;
    selfPet->attack += attack;
}
