#include "pets.h"
#include <stdio.h>

struct Pet NoOpPet = {
    .id = 0
};

int isDead(struct Pet *pet) {
    return pet->defence + pet->battleModifierDefense <= 0 ? 1 : 0;
}

struct Pet * randomOtherTeamMember(PetTeam team, struct Pet * exclude) {
    int start = rand() % 5;
    for (int s=start; s < start+5; s++) {
        int as = s % 5;
        if (team[as].id > 0 && !isDead(&team[as]) && &team[as] != exclude) {
            return &team[as];
        }
    }
    return &NoOpPet;
}

struct Pet * pets[30] = {};
struct PetText * petTexts[30] = {};
void registerPet(int petId, struct Pet * pet, struct PetText * petText) {
    pets[petId] = pet;
    petTexts[petId] = petText;
}

struct PetText* getPetTextByID(int petId) {
    return petTexts[petId];
}

struct Pet * getPetByID(int petId) {
    return pets[petId];
}

int petPosition(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet) {
    for (int i=0; i<=4; i++) {
        if (usOrThem == 0) {
            if (&us[i] == pet) {
                return i;
            }
        } else {
            if (&them[i] == pet) {
                return i;
            }
        }
    }
    for (int i=0; i<=4; i++) {
        if (usOrThem == 1) {
            if (&us[i] == pet) {
                return i + 5;
            }
        } else {
            if (&them[i] == pet) {
                return i + 5;
            }
        }
    }

    return -1;
}

int getPetAttack(struct Pet *pet) {
    return pet->attack + pet->battleModifierAttack;
}
int getPetDefence(struct Pet *pet) {
    return pet->defence + pet->battleModifierDefense;
}

void spawnPet(int petId, struct Pet * dest) {
    struct Pet *pet = getPetByID(petId);

    dest->id = pet->id;
    dest->attack = pet->attack;
    dest->defence = pet->defence;
    dest->battleModifierDefense = pet->battleModifierDefense;
    dest->battleModifierAttack = pet->battleModifierAttack;
    dest->experience = pet->experience;

    dest->level = 1;
    dest->battleModifierDefense = 0;
    dest->battleModifierAttack = 0;
}