#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PearText = {
        .name = "Pear",
        .abilities = {
                "Give an animal +2/+2.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Pear = {
        .id =  112,
        .attack =  0,
        .defence =  0,
        .tier = 4
};
void pearTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);