#ifndef PETS_H
#define PETS_H
typedef const char PetAbilities[3][40];

struct Pet {
    int id;
    int attack;
    int defence;
    int battleModifierDefense;
    int battleModifierAttack;
    int level;
    int experience;
    const unsigned int *sprite[40];
};

struct PetText {
    char *name[10];
    PetAbilities abilities;
};

typedef struct Pet PetTeam[5];
#endif