#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SharkText = {
        .name = "Shark",
        .abilities = {
                "Friend faints: Gain +1/+2.",
                "Friend faints: Gain +2/+4.",
                "Friend faints: Gain +3/+6."},
};

EWRAM_DATA const static struct Pet Shark = {
        .id =  50,
        .attack =  4,
        .health =  2,
        .tier = 5
};
void sharkTriggerFriendFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);