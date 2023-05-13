#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText WhaleText = {
        .name = "Whale",
        .abilities = {
                "Start of battle: Swallow friend ahead and release as Level 1.",
                "Start of battle: Swallow friend ahead and release as Level 2.",
                "Start of battle: Swallow friend ahead and release as Level 3."},
};

EWRAM_DATA const static struct Pet Whale = {
        .id =  63,
        .attack =  3,
        .health =  8,
        .tier = 4
};
void whaleTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);
void whaleTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);