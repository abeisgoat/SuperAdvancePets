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
        .health =  0,
        .tier = 4
};
void pearTriggerBuyAssign(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);