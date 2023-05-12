#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RamText = {
        .name = "Ram",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Ram = {
        .id =  44
};
void ramTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);