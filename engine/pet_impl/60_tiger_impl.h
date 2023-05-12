#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText TigerText = {
        .name = "Tiger",
        .abilities = {
                "Friend ahead repeats their ability in battle as if they were level 1.",
                "Fiend ahead repeats their ability in battle as if they were level 2.",
                "Friend ahead repeats their ability in battle as if they were level 2."},
};

EWRAM_DATA const static struct Pet Tiger = {
        .id =  60,
        .attack =  4,
        .defence =  3,
        .tier = 6
};
void tigerTriggerCastsAbility(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);