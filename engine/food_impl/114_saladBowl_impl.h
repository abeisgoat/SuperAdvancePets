#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SaladBowlText = {
        .name = "Salad Bowl",
        .abilities = {
                "Give 2 random extras +1/+1.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet SaladBowl = {
        .id =  114,
        .attack =  0,
        .health =  0,
        .tier = 3
};
void saladBowlTriggerBuyAssign(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);