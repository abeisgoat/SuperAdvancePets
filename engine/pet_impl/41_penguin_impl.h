#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PenguinText = {
        .name = "Penguin",
        .abilities = {
                "End turn: Give other Lvl. 2 and 3 friends +1/+1",
                "End turn: Give other Lvl. 2 and 3 friends +2/+2",
                "End turn: Give other Lvl. 2 and 3 friends +2/+2"},
};

EWRAM_DATA const static struct Pet Penguin = {
        .id =  41,
        .attack =  1,
        .health =  2,
        .tier = 4
};
void penguinTriggerEndOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);