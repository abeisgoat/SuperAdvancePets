#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ScorpionText = {
        .name = "Scorpion",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Scorpion = {
        .id =  48,
        .attack =  1,
        .defence =  1,
        .tier = 5
};
void scorpionTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);