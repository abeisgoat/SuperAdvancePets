#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ScorpionText = {
        .name = "Scorpion",
        .abilities = {
                "Summoned: Gain Peanut.",
                "Summoned: Gain Peanut.",
                "Summoned: Gain Peanut."},
};

EWRAM_DATA const static struct Pet Scorpion = {
        .id =  48,
        .attack =  1,
        .health =  1,
        .tier = 5,
        .heldItem = 118,
};