#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DirtyRatText = {
        .name = "Dirty Rat",
        .abilities = {
                "Friend ahead attacks: Deal it 1 damage",
                "Friend ahead attacks: Deal it 2 damage",
                "Friend ahead attacks: Deal it 2 damage"},
};

EWRAM_DATA const static struct Pet DirtyRat = {
        .id =  17,
        .attack =  1,
        .health =  1,
};
void dirtyRatTriggerAfterAttack(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);