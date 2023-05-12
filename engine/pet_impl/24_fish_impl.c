
#include "../globals.h"
#include <stdio.h>

void fishTriggerLevelUp(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Fish trigger LevelUp");

    int stats = expToLevel(selfPet->experience);

    for (int i=0; i<=4; i++) {
        struct Pet * pet = &us[i];

        if (pet->id > 0) {
            pet->health += stats;
            pet->attack += stats;
        }
    }
}
