#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SharkText = {
        .name = "Shark",
        .abilities = {
                "Friend faints: Gain +2/+1.",
                "Friend faints: Gain +4/+2.",
                "Friend faints: Gain +4/+2."},
};

EWRAM_DATA const static struct Pet Shark = {
        .id =  50,
        .attack =  4,
        .health =  4,
        .tier = 5
};
void sharkTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);