
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

void whaleTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Whale trigger StartOfBattle\n");

    int ahead = 1;
    if (usOrThem == 1) {
        ahead *= -1;
    }

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int damage = 100;
    struct Pet * friend = getFriendByPosition(usOrThem, us, selfPos+ahead);

    if (friend->id > 0) {
        int friendPos = petPosition(usOrThem, us, them, friend);
        animateDamageToTeamPosition(selfPos, friendPos);
        resolveAnimation();
        damagePet(usOrThem, us, them, store, selfPet, friend, damage);
        selfPet->id = (friend->id) + 300;
    }
}

void whaleTriggerFaint(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Whale trigger faint\n");
    if (selfPet->id < 300) return;

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int exp = selfPet->experience;
    int id = (selfPet->id) - 300;
    int lvl = expToLevel(selfPet->experience);

    animatePoofAtPosition(selfPos);
    resolveAnimation();

    summonPet(getPetByID(id), selfPet);
    selfPet->experience = exp;
    selfPet->health *= lvl;
    selfPet->attack *= lvl;
    selfPet->activations = 0;
    postSummonPet(selfPet);
}