
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

int gorillaTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Gorilla trigger Hurt\n");

    if (selfPet->activations < expToLevel(selfPet->experience)) {
        int selfPos = petPosition(usOrThem, us, them, selfPet);
        animateIconToTeamPosition(selfPos, selfPos, UIIcon_Coconut);
        resolveAnimation();
        selfPet->heldItem = 119;
        selfPet->activations++;
        return 1;
    }
    return 0;
}
