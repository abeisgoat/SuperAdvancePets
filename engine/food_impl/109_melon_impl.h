#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MelonText = {
        .name = "Melon",
        .abilities = {
                "Give an animal Melon Armor.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Melon = {
        .id =  109,
        .attack =  0,
        .defence =  0,
        .tier = 6
};
void melonTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);