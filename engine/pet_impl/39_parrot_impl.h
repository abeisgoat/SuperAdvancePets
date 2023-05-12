#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ParrotText = {
        .name = "Parrot",
        .abilities = {
                "End Turn: Copy ability from pet ahead as lvl. 1 until end of battle.",
                "End Turn: Copy ability from pet ahead as lvl. 2 until end of battle.",
                "End Turn: Copy ability from pet ahead as lvl. 2 until end of battle."},
};

EWRAM_DATA const static struct Pet Parrot = {
        .id =  39,
        .attack =  5,
        .health =  3,
        .tier = 4
};
void parrotTriggerEndOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);