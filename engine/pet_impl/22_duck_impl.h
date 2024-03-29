#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DuckText = {
        .name = "Duck",
        .abilities = {
                "Sell: Give shop extras +1 Health",
                "Sell: Give shop extras +2 Health",
                "Sell: Give shop extras +3 Health"},
};

EWRAM_DATA const static struct Pet Duck = {
        .id =  22,
        .attack =  1,
        .health =  3,
        .tier = 1
};
void duckTriggerSell(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);