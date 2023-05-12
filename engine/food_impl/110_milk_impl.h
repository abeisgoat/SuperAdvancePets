#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MilkText = {
        .name = "Milk",
        .abilities = {
                "Give an animal +2/+2",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Milk = {
        .id =  110,
};
void milkTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);