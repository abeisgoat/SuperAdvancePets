#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText FlamingoText = {
        .name = "Flamingo",
        .abilities = {
                "Faint: Give the two friends behind +1/+1.",
                "Faint: Give the two friends behind +2/+2.",
                "Faint: Give the two friends behind +3/+3."},
};

EWRAM_DATA const static struct Pet Flamingo = {
        .id =  25,
        .attack =  3,
        .health =  1,
        .tier = 2
};
void flamingoTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);