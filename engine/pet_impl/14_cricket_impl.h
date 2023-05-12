#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CricketText = {
        .name = "Cricket",
        .abilities = {
                "Faint: Summon a 1/1 Cricket",
                "Faint: Summon a 2/2 Cricket",
                "Faint: Summon a 2/2 Cricket"},
};

EWRAM_DATA const static struct Pet Cricket = {
        .id =  14,
        .attack =  1,
        .health =  2,
        .tier = 1
};
void cricketTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);