#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BusText = {
        .name = "Bus",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Bus = {
        .id =  8
};
void busTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);