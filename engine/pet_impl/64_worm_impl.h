#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText WormText = {
        .name = "Worm",
        .abilities = {
                "Eats shop food: Gain +1/+1",
                "Eats shop food: Gain +2/+2",
                "Eats shop food: Gain +3/+3"},
};

EWRAM_DATA const static struct Pet Worm = {
        .id =  64,
        .attack =  3,
        .health =  3,
        .tier = 4
};
void wormTriggerEatsShopFood(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);