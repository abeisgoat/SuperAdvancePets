#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DeerText = {
        .name = "Deer",
        .abilities = {
                "Faint: Summon a 5/5 Bus with Splash Attack",
                "Faint: Summon a 10/10 Bus with Splash Attack",
                "Faint: Summon a 10/10 Bus with Splash Attack"},
};

EWRAM_DATA const static struct Pet Deer = {
        .id =  16,
        .attack =  1,
        .defence =  1,
        .tier = 4
};
void deerTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);