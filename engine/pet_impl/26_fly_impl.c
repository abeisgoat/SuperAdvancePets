
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void flyTriggerFriendFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Fly trigger Friend Faint");

    if (activatingPet->id == 66 || selfPet->activations == 3) return;

    int stats = 2;
    switch (expToLevel(selfPet->experience)) {
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

    emptyPet(activatingPet);
    animatePoofAtPosition(petPosition(usOrThem, us, them, selfPet));
    resolveAnimation();

    activatingPet->id = 66;
    activatingPet->health = stats;
    activatingPet->attack = stats;

    selfPet->activations++;
}
