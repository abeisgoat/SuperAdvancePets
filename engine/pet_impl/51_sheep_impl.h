#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SheepText = {
        .name = "Sheep",
        .abilities = {
                "Faint: Summon two 2/2 Rams",
                "Faint: Summon two 4/4 Rams",
                "Faint: Summon two 4/4 Rams"},
};

EWRAM_DATA const static struct Pet Sheep = {
        .id =  51,
        .attack =  2,
        .health =  2,
        .tier = 3
};
void sheepTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);