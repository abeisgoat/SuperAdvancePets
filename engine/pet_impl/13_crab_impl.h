#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CrabText = {
        .name = "Crab",
        .abilities = {
                "Buy: Copy 50% Health from the most healthy friend",
                "Buy: Copy 100% Health from the most healthy friend",
                "Buy: Copy 150% Health from the most healthy friend"},
};

EWRAM_DATA const static struct Pet Crab = {
        .id =  13,
        .attack =  3,
        .health =  1,
        .tier = 2
};
void crabTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);