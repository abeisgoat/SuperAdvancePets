#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SushiText = {
        .name = "Sushi",
        .abilities = {
                "Give 3 random animals +1/+1.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Sushi = {
        .id =  117,
        .attack =  0,
        .defence =  0,
        .tier = 5
};
void sushiTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);