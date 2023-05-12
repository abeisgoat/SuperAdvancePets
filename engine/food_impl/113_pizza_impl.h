#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PizzaText = {
        .name = "Pizza",
        .abilities = {
                "Give 2 random animals +3/+3.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Pizza = {
        .id =  113,
        .attack =  0,
        .health =  0,
        .tier = 6
};
void pizzaTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);