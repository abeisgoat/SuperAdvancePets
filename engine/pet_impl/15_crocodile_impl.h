#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CrocodileText = {
        .name = "Crocodile",
        .abilities = {
                "Start of battle: Deal 8 damage to the last enemy",
                "Start of battle: Deal 16 damage to the last enemy",
                "Start of battle: Deal 16 damage to the last enemy"},
};

EWRAM_DATA const static struct Pet Crocodile = {
        .id =  15,
        .attack =  8,
        .defence =  4,
        .tier = 5
};
void crocodileTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);