#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BisonText = {
        .name = "Bison",
        .abilities = {
                "End turn: Gain +1/+1 if there is at least one Lvl. 3 friend.",
                "End turn: Gain +2/+2 if there is at least one Lvl. 3 friend.",
                "End turn: Gain +3/+3 if there is at least one Lvl. 3 friend."},
};

EWRAM_DATA const static struct Pet Bison = {
        .id =  5,
        .attack =  4,
        .health =  4,
        .tier = 4
};
void bisonTriggerEndOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);