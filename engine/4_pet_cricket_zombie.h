#include "pets.h"
#include "../sprites/zombie_cricket.h"

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
        .sprite = zombie_cricketTiles
};