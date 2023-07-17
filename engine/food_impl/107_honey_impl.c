#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void honeyTriggerBuyAssign(int usOrThem, PetTeam us, PetTeam them, struct Pet * itemPet, struct Pet * targetPet, PetTeam store) {
    printf("Activated Honey trigger Buy");

    int givePos = storePosition(store, itemPet);
    int takePos = petPosition(usOrThem,us, them, targetPet);

    animateToTeamPosition(givePos, takePos);
    resolveAnimation();

    targetPet->heldItem = itemPet->id;
}

void honeyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Honey faint trigger Buy");


    struct Pet * space;
    int selfPos = petTeamPosition(usOrThem, us, selfPet);

    selfPet->id = 0;
    int hasSpace = tryToMakeRoom(usOrThem, us, selfPos);

    resolveAnimation();
    if (hasSpace) {
        space = &us[selfPos];
        animatePoofAtPosition(selfPos);
        resolveAnimation();

        summonPet(getPetByID(4), space);
        space->attack = 1;
        space->health = 1;
        resolveSpawns();
        postSummonPet(space);
    } else {
        return;
    }
}
