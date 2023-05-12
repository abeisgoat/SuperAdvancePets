#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MushroomText = {
        .name = "Mushroom",
        .abilities = {
                "Give an animal Extra Life.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Mushroom = {
        .id =  111,
        .attack =  0,
        .defence =  0,
        .tier = 6
};
void mushroomTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);