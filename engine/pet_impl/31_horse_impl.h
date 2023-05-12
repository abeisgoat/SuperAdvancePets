#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText HorseText = {
        .name = "Horse",
        .abilities = {
                "Friend summoned: Give it +1 Attack until end of battle",
                "Friend summoned: Give it +2 Attack until end of battle",
                "Friend summoned: Give it +2 Attack until end of battle"},
};

EWRAM_DATA const static struct Pet Horse = {
        .id =  31,
        .attack =  2,
        .health =  1,
        .tier = 1
};
void horseTriggerSummoned(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);