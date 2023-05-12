#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ZombieFlyText = {
        .name = "Zombie Fly",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet ZombieFly = {
        .id =  66
};
void zombieFlyTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);