#include "pets.h"
#include <stdio.h>
#include <stdlib.h>

struct Pet NoOpPet = {
    .id = 0
};

int isDead(struct Pet *pet) {
    return pet->health + pet->battleModifierHealth <= 0 ? 1 : 0;
}

int expToLevel(int exp) {
    if (exp == 5) {
        return 3;
    }
    if (exp >= 2) {
        return 2;
    }
    return 1;
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

struct Pet * pets[100] = {};
const struct PetText * petTexts[100] = {};
struct Pet * foods[20] = {};
const struct PetText * foodTexts[100] = {};


void registerPet(int petId, const struct Pet * pet, const struct PetText * petText) {
    pets[petId] = pet;
    petTexts[petId] = petText;
}

void registerFood(int petId, const struct Pet * pet, const struct PetText * petText) {
    foods[petId] = pet;
    foodTexts[petId] = petText;
}

const struct PetText* getPetTextByID(int petId) {
    return petTexts[petId];
}

struct Pet * getPetByID(int petId) {
    return pets[petId];
}

void shuffleForward() {

}

int itemPosition(PetTeam store, struct Pet * pet) {
    for (int i=0; i<=4; i++) {
        if (&store[i] == pet) {
            return 100+i;
        }
    }
    return -1;
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
    return pet->health + pet->battleModifierHealth;
}

void spawnPet(int petId, struct Pet * dest) {
    struct Pet *pet = getPetByID(petId);

    dest->id = pet->id;
    dest->attack = pet->attack;
    dest->health = pet->health;
    dest->battleModifierHealth = pet->battleModifierHealth;
    dest->battleModifierAttack = pet->battleModifierAttack;
    dest->experience = pet->experience;
}

void printPet(struct Pet * pet) {
    const struct PetText * text = getPetTextByID(pet->id);
    if ((text->name) == 0) {
        printf("Unknown Pet!! Something is wrong %d", pet->id);
        return;
    }
    printf("Pet :: %s %d/%d @ Lvl %d (%d experience)\n", *text->name, pet->attack, pet->health, expToLevel(pet->experience), pet->experience);
}

void deserializePet(int num, struct Pet * dest) {
    int attack,defence,id,heldItem,experience;

    defence = num % 100;
    attack = ((num % 10000) - defence) / 100;
    experience = ((num % 100000) - attack - defence) / 10000;
    heldItem = ((num % 1000000) - attack - defence - experience) / 100000;
    id = ((num % 100000000) - attack - defence - experience - heldItem) / 1000000;

    dest->id = id;
    dest->attack = attack;
    dest->health = defence;
    dest->heldItem = heldItem;
    dest->experience = experience;
    printPet(dest);
}