#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DodoText = {
        .name = "Dodo",
        .abilities = {
                "Start of battle: Give 50% Attack to friend ahead.",
                "Start of battle: Give 100% Attack to friend ahead.",
                "Start of battle: Give 100% Attack to friend ahead."},
};

EWRAM_DATA const static struct Pet Dodo = {
        .id =  18,
        .attack =  2,
        .defence =  3,
        .tier = 2
};
void dodoTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);