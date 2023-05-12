#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BisonText = {
        .name = "Bison",
        .abilities = {
                "End turn: Gain +2/+2 if there is at least one Lvl. 3 friend.",
                "End turn: Gain +4/+4 if there is at least one Lvl. 3 friend.",
                "End turn: Gain +4/+4 if there is at least one Lvl. 3 friend."},
};

EWRAM_DATA const static struct Pet Bison = {
        .id =  5,
        .attack =  6,
        .health =  6,
        .tier = 4
};
void bisonTriggerEndOfTurnWithLvl3Friend(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);