#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SealText = {
        .name = "Seal",
        .abilities = {
                "Eats shop food: Give 2 random friends +1/+1.",
                "Eats shop food: Give 2 random friends +2/+2.",
                "Eats shop food: Give 2 random friends +2/+2."},
};

EWRAM_DATA const static struct Pet Seal = {
        .id =  49,
        .attack =  3,
        .health =  8,
        .tier = 5
};
void sealTriggerEatsShopFood(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);