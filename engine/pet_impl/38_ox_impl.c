
#include "../globals.h"
#include <stdio.h>

void oxTriggerFriendFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Ox trigger friend faints");

    int activatingPos = petPosition(usOrThem, us, them, activatingPet);
    int selfPos = petPosition(usOrThem, us, them, selfPet);

    int ahead = 1;
    if (usOrThem == 1) {
        ahead *= -1;
    }

    if (selfPos+ahead != activatingPos) return;

    int stats = expToLevel(expToLevel(selfPos)) * 1;
    selfPet->attack += stats;
    selfPet->heldItem = 109;
}
