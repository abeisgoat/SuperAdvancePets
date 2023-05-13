#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ChiliText = {
        .name = "Chili",
        .abilities = {
                "Give an animal Splash Attack.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Chili = {
        .id =  103,
        .attack =  0,
        .health =  0,
        .tier = 5
};
void chiliTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);