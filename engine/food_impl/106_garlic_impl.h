#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText GarlicText = {
        .name = "Garlic",
        .abilities = {
                "Give an animal Garlic Armor.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Garlic = {
        .id =  106,
        .attack =  0,
        .health =  0,
        .tier = 3
};
void garlicTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);