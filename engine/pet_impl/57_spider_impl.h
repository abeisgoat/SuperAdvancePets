#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SpiderText = {
        .name = "Spider",
        .abilities = {
                "Faint: Summon a level 1 tier 3 animal as a 2/2",
                "Faint: Summon a level 2 tier 3 animal as a 2/2",
                "Faint: Summon a level 2 tier 3 animal as a 2/2"},
};

EWRAM_DATA const static struct Pet Spider = {
        .id =  57,
        .attack =  2,
        .health =  2,
        .tier = 2
};
void spiderTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);