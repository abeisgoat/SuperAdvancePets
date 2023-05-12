#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DolphinText = {
        .name = "Dolphin",
        .abilities = {
                "Start of battle: Deal 5 damage to the lowest health enemy",
                "Start of battle: Deal 10 damage to the lowest health enemy",
                "Start of battle: Deal 15 damage to the lowest health enemy"},
};

EWRAM_DATA const static struct Pet Dolphin = {
        .id =  20,
        .attack =  4,
        .health =  6,
        .tier = 4
};
void dolphinTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);