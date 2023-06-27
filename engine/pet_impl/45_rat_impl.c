
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

// TODO: Verify rat
// TODO: ../SuperAdvancePetsCLI battle 360020404,240000203,010010302,030010303,450000405 030040606,370020304,140000102,240020405,030000202

void ratTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Rat trigger Faint\n");

    for (int l=1; l<= expToLevel(selfPet->experience); l++) {
        int hasSpace;
        struct Pet * space;
        if (usOrThem == 0) {
            if (shuffleRightUntilEmpty(them) == 2) {
                hasSpace = 1;
                space = &them[0];
            }
        }
        if (usOrThem == 1) {
            if (shuffleLeftUntilEmpty(them) == 2) {
                hasSpace = 1;
                space = &them[4];
            }
        }

        resolveAnimation();
        if (hasSpace) {
            int spawnPos = 5;
            if (usOrThem == 1) {
                spawnPos = 4;
            }
            animatePoofAtPosition(spawnPos);
            resolveAnimation();

            space->id = 17;
            space->attack = 1;
            space->health = 1;
        } else {
            return;
        }
    }
}
