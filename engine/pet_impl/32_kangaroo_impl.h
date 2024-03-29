#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText KangarooText = {
        .name = "Kangaroo",
        .abilities = {
                "Friend ahead attacks: Gain +2/+2",
                "Friend ahead attacks: Gain +4/+4",
                "Friend ahead attacks: Gain +6/+6"},
};

EWRAM_DATA const static struct Pet Kangaroo = {
        .id =  32,
        .attack =  1,
        .health =  2,
        .tier = 3
};
void kangarooTriggerFriendAttacks(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);