#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ZombieCricketText = {
        .name = "Zombie Cricket",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet ZombieCricket = {
        .id =  65
};
void zombieCricketTriggerNoOp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);