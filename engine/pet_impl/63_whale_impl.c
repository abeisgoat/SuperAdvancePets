
#include "../globals.h"
#include "../../src/animations.h"
#include "../battle.h"
#include <stdio.h>

// TODO: Implement Whale StartOfBattle
void whaleTriggerStartOfBattle(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Whale trigger StartOfBattle");

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
    if (selfPet->id < 300) return;

    int selfPos = petPosition(usOrThem, us, them, selfPet);
    int exp = selfPet->experience;
    int id = (selfPet->id) - 300;

    emptyPet(selfPet);
    animatePoofAtPosition(selfPos);
    resolveAnimation();

    summonPet(getPetByID(id), selfPet);
    int lvl = expToLevel(selfPet->experience);
    selfPet->experience = exp;
    selfPet->health *= lvl;
    selfPet->attack *= lvl;
    postSummonPet(selfPet);
}