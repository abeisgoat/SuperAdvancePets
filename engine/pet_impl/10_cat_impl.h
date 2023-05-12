#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CatText = {
        .name = "Cat",
        .abilities = {
                "Food with Health and Attack effects are doubled.",
                "Food with Health and Attack effects are tripled.",
                "Food with Health and Attack effects are tripled."},
};

EWRAM_DATA const static struct Pet Cat = {
        .id =  10,
        .attack =  4,
        .defence =  5,
        .tier = 6
};
void catTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);