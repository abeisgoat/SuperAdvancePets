#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MonkeyText = {
        .name = "Monkey",
        .abilities = {
                "End turn: Give right-most friend +2/+3",
                "End turn: Give right-most friend +4/+6",
                "End turn: Give right-most friend +4/+6"},
};

EWRAM_DATA const static struct Pet Monkey = {
        .id =  35,
        .attack =  1,
        .health =  2,
        .tier = 5
};
void monkeyTriggerEndOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);