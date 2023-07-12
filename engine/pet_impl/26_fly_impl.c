
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

// TODO: Verify fly
void flyTriggerFriendFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Fly trigger Friend Faint");
    if (selfPet->activations == 3 || activatingPet->id == 66) return;

    struct Pet * space;
    int activatingPos = petTeamPosition(usOrThem, us, activatingPet);

//    activatingPet->id = 0;
    int hasSpace = tryToMakeRoom(usOrThem, us, activatingPos);
    int lvl = expToLevel(selfPet->experience);

    resolveAnimation();
    if (hasSpace) {
        space = &us[activatingPos];
        animatePoofAtPosition(activatingPos);
        resolveAnimation();

        summonPet(getPetByID(66), space);
        space->attack = 1;//lvl * 2;
        space->health = 1;//lvl * 2;
        resolveSpawns();
        postSummonPet(space);
    } else {
        return;
    }

    selfPet->activations++;
}
