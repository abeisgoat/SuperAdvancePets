#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SkunkText = {
        .name = "Skunk",
        .abilities = {
                "Start of battle: Reduce the highest Health enemy by 33%.",
                "Start of battle: Reduce the highest Health enemy by 66%.",
                "Start of battle: Reduce the highest Health enemy by 66%."},
};

EWRAM_DATA const static struct Pet Skunk = {
        .id =  53,
        .attack =  3,
        .defence =  6,
        .tier = 4
};
void skunkTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);