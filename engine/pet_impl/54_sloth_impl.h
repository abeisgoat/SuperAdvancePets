#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SlothText = {
        .name = "Sloth",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Sloth = {
        .id =  54,
        .attack =  1,
        .health =  1,
        .tier = 1
};
void slothTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);