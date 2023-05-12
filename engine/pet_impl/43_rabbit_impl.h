#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RabbitText = {
        .name = "Rabbit",
        .abilities = {
                "Pet eats shop food: Give it +1 Health",
                "Pet eats shop food: Give it +2 Health",
                "Pet eats shop food: Give it +2 Health"},
};

EWRAM_DATA const static struct Pet Rabbit = {
        .id =  43,
        .attack =  3,
        .defence =  2,
        .tier = 3
};
void rabbitTriggerEatsShopFood(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);