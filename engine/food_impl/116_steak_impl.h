#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SteakText = {
        .name = "Steak",
        .abilities = {
                "Give an animal Steak Attack.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Steak = {
        .id =  116,
        .attack =  0,
        .defence =  0,
        .tier = 6
};
void steakTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);