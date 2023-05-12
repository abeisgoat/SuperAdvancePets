#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PigText = {
        .name = "Pig",
        .abilities = {
                "Sell: Gain an extra 1 gold",
                "Sell: Gain an extra 2 gold",
                "Sell: Gain an extra 2 gold"},
};

EWRAM_DATA const static struct Pet Pig = {
        .id =  42,
        .attack =  3,
        .health =  1,
        .tier = 1
};
void pigTriggerSell(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);