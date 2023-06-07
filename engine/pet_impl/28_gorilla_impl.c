
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Add coconut for gorilla
int gorillaTriggerHurt(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Gorilla trigger Hurt");

    if (selfPet->activations < expToLevel(selfPet->experience)) {
        int selfPos = petPosition(usOrThem, us, them, selfPet);
        animateIconToTeamPosition(selfPos, selfPos, UIIcon_Melon);
        resolveAnimation();
        selfPet->heldItem = 109;
        selfPet->activations++;
        return 1;
    }
    return 0;
}
