#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RabbitText = {
        .name = "Rabbit",
        .abilities = {
                "Pet eats shop food: Give it +1 Health",
                "Pet eats shop food: Give it +2 Health",
                "Pet eats shop food: Give it +3 Health"},
};

EWRAM_DATA const static struct Pet Rabbit = {
        .id =  43,
        .attack =  3,
        .health =  2,
        .tier = 3
};
void rabbitTriggerPetEatsShopFood(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);