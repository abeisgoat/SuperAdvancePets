#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CowText = {
        .name = "Cow",
        .abilities = {
                "Buy: Replace food shop with 2 free milk that gives +2/+2.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Cow = {
        .id =  12,
        .attack =  4,
        .health =  6,
        .tier = 5
};
void cowTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);