#ifndef PETS_H
#define PETS_H
typedef const char PetAbilities[3][70];

struct Pet {
    int id;
    int attack;
    int defence;
    int battleModifierDefense;
    int battleModifierAttack;
    int experience;
    int heldItem;
    int tier;
};

const struct PetText {
    char *name[10];
    PetAbilities abilities;
};

typedef struct Pet PetTeam[5];
#endif