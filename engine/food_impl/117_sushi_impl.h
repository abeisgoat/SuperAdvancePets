#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SushiText = {
        .name = "Sushi",
        .abilities = {
                "Give 2 random animals +2/+2.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Sushi = {
        .id =  117,
        .attack =  0,
        .health =  0,
        .tier = 5
};
void sushiTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);