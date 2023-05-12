#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DragonText = {
        .name = "Dragon",
        .abilities = {
                "Buy tier 1 animal: Give all friends +1/+1.",
                "Buy tier 1 animal: Give all friends +2/+2.",
                "Buy tier 1 animal: Give all friends +2/+2."},
};

EWRAM_DATA const static struct Pet Dragon = {
        .id =  21,
        .attack =  6,
        .health =  8,
        .tier = 6
};
void dragonTriggerBuyTier1Animal(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);