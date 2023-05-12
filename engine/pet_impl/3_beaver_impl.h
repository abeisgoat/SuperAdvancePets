#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BeaverText = {
        .name = "Beaver",
        .abilities = {
                "Sell: Give two random friends +1 health",
                "Sell: Give two random friends +2 health",
                "Sell: Give two random friends +2 health"},
};

EWRAM_DATA const static struct Pet Beaver = {
        .id =  3,
        .attack =  2,
        .health =  2,
        .tier = 1
};
void beaverTriggerSell(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);