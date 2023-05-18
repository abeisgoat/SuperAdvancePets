
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

int gorillaTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Gorilla trigger Hurt");

    if (selfPet->activations < expToLevel(selfPet->experience)) {
        animatePoofAtPosition(petPosition(usOrThem, us, them, selfPet));
        resolveAnimation();
        selfPet->heldItem = 109;
        selfPet->activations++;
        return 1;
    }
    return 0;
}
