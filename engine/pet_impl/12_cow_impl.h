#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CowText = {
        .name = "Cow",
        .abilities = {
                "Buy: Replace food shop with 2 free milk that gives +1/+2.",
                "Buy: Replace food shop with 2 free milk that gives +2/+4.",
                "Buy: Replace food shop with 2 free milk that gives +2/+4."},
};

EWRAM_DATA const static struct Pet Cow = {
        .id =  12,
        .attack =  4,
        .defence =  6,
        .tier = 5
};
void cowTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);