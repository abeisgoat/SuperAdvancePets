#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText HoneyText = {
        .name = "Honey",
        .abilities = {
                "Give an animal Honey Bee.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Honey = {
        .id =  107,
        .attack =  0,
        .health =  0,
        .tier = 1
};
void honeyTriggerBuyAssign(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);