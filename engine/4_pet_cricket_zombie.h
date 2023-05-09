#include "pets.h"

struct PetText CricketZombieText = {
        .name = "Cricket (Zombie)",
        .abilities = {"", "", ""},
};

struct Pet CricketZombie = {
        .id =  3,
        .attack =  1,
        .defence =  1,
        // Always 0
        .battleModifierDefense = 0,
        .battleModifierAttack = 0,
};