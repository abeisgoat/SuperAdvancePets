#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ChickText = {
        .name = "Chick",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Chick = {
        .id =  11
};
void chickTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);