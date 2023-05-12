#include <tonc_types.h>
#include "../pets.h"

EWRAM_DATA const static struct PetText AppleText = {
        .name = "Apple",
        .abilities = {
                "Give an animal +1/+1.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Apple = {
        .id =  101,
        .attack =  0,
        .health =  0,
        .tier = 1
};
void appleTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);