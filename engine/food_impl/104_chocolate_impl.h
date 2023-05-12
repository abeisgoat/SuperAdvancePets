#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ChocolateText = {
        .name = "Chocolate",
        .abilities = {
                "Give an animal +1 Experience.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Chocolate = {
        .id =  104,
        .attack =  0,
        .health =  0,
        .tier = 5
};
void chocolateTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);