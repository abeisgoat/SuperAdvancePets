#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText GiraffeText = {
        .name = "Giraffe",
        .abilities = {
                "End turn: Give friend ahead +1/+1",
                "End turn: Give 2 friends ahead +1/+1",
                "End turn: Give 3 friends ahead +1/+1"},
};

EWRAM_DATA const static struct Pet Giraffe = {
        .id =  27,
        .attack =  2,
        .health =  5,
        .tier = 3
};
void giraffeTriggerEndOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);