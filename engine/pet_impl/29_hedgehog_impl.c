
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void hedgehogTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Hedgehog trigger Faint");

    for (int i=0; i <= 4; i++) {
        struct Pet * pet = &us[i];

        if (pet->id) {
            animateDamageToTeamPosition(petPosition(usOrThem, us, them, selfPet), petPosition(usOrThem, us, them, pet));
        }
    }

    for (int i=0; i <= 4; i++) {
        struct Pet * pet = &them[i];

        if (pet->id) {
            animateDamageToTeamPosition(petPosition(usOrThem, us, them, selfPet), petPosition(usOrThem, us, them, pet));
        }
    }

    resolveAnimation();

    int damage = expToLevel(selfPet->experience) * 2;

    for (int i=0; i <= 4; i++) {
        struct Pet * pet = &us[i];
        if (pet->id && pet != selfPet) {
            damagePet(usOrThem, us, them, store, pet, damage);
        }
    }

    for (int i=0; i <= 4; i++) {
        struct Pet * pet = &them[i];

        if (pet->id && pet != selfPet) {
            damagePet(usOrThem, us, them, store, pet, damage);
        }
    }
}
