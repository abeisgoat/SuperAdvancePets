#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MushroomText = {
        .name = "Mushroom",
        .abilities = {
                "Give an animal Extra Life (as +1/+1).",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Mushroom = {
        .id =  111,
        .attack =  0,
        .health =  0,
        .tier = 6
};
void mushroomTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);