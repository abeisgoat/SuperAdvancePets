#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CannedFoodText = {
        .name = "Canned Food",
        .abilities = {
                "Give all current and future shop extras +2/+2.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet CannedFood = {
        .id =  102,
        .attack =  0,
        .health =  0,
        .tier = 4
};
void cannedFoodTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);