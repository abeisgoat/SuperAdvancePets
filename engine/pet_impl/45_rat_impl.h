#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RatText = {
        .name = "Rat",
        .abilities = {
                "Faint: summon one 1/1 Dirty Rat for the opponent.",
                "Faint: summon two 1/1 Dirty Rat for the opponent.",
                "Faint: summon three 1/1 Dirty Rat for the opponent."},
};

EWRAM_DATA const static struct Pet Rat = {
        .id =  45,
        .attack =  4,
        .health =  5,
        .tier = 2
};
void ratTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);