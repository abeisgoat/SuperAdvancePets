#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CupcakeText = {
        .name = "Cupcake",
        .abilities = {
                "Give an animal +3/+3 until end of battle.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Cupcake = {
        .id =  105,
        .attack =  0,
        .health =  0,
        .tier = 2
};
void cupcakeTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);