
#include "../globals.h"
#include <stdio.h>

// TODO: Implement Skunk StartOfBattle
void skunkTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Skunk trigger StartOfBattle");
    struct Pet * target;
    int highestHealth = 0;
    for (int i=0; i<=4; i++) {
        struct Pet * other = &them[i];
        if (getPetHealth(other) > highestHealth) {
            target = other;
        }
    }

    if (target->id) {
        float multiple = .33f * expToLevel(selfPet->experience);
        target->health -= (target->health * multiple);
    }
}
