
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void cricketTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Cricket trigger Faint");
    int level = expToLevel(selfPet->experience);
    emptyPet(selfPet);

    animatePoofAtPosition(petPosition(usOrThem, us, them, selfPet));
    resolveAnimation();

    int stats = 1;
    switch (level) {
        case 1:
            stats *= 1;
            break;
        case 2:
            stats *= 2;
            break;
        case 3:
            stats *= 3;
            break;
    }


    selfPet->id = 65;
    selfPet->attack = stats;
    selfPet->health = stats;
}
