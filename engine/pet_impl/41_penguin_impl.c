
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>
#include <stdlib.h>

// TODO: finish penguin
void penguinTriggerEndOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Penguin trigger EndOfTurn");

    int selfPos = petPosition(usOrThem, us, them, selfPet);

    struct Pet * firstPet = selfPet;
    struct Pet * secondPet = selfPet;

    int start = rand() % 5;
    for (int s=start; s < start+5; s++) {
        int as = s % 5;
        if (us[as].id > 0 && !isDead(&us[as]) && &us[as] != selfPet) {
            if (firstPet == selfPet) {
                firstPet = &us[as];
            } else {
                secondPet = &us[as];
            }
        }
    }

    if (firstPet != selfPet) {
        animateStatsToTeamPosition(selfPos, petPosition(usOrThem, us, them, firstPet));
    }

    if (secondPet != selfPet) {
        animateStatsToTeamPosition(selfPos, petPosition(usOrThem, us, them, secondPet));
    }

    resolveAnimation();

    int stats = 1 * expToLevel(selfPet->experience);

    if (firstPet != selfPet) {
        firstPet->attack += stats;
        firstPet->health += stats;
    }

    if (secondPet != selfPet) {
        secondPet->attack += stats;
        secondPet->health += stats;
    }
}
