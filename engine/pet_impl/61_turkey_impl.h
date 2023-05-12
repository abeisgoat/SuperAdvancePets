#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText TurkeyText = {
        .name = "Turkey",
        .abilities = {
                "Friend summoned: Give it +3/+3.",
                "Friend summoned: Give it +6/+6.",
                "Friend summoned: Give it +6/+6."},
};

EWRAM_DATA const static struct Pet Turkey = {
        .id =  61,
        .attack =  3,
        .health =  4,
        .tier = 5
};
void turkeyTriggerSummoned(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);