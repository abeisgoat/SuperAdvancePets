#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText KangarooText = {
        .name = "Kangaroo",
        .abilities = {
                "Friend ahead attacks: Gain +2/+2",
                "Friend ahead attacks: Gain +4/+4",
                "Friend ahead attacks: Gain +4/+4"},
};

EWRAM_DATA const static struct Pet Kangaroo = {
        .id =  32,
        .attack =  1,
        .defence =  2,
        .tier = 3
};
void kangarooTriggerAfterAttack(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);