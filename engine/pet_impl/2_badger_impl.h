#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BadgerText = {
        .name = "Badger",
        .abilities = {
                "Faint: Deal Attack x1 damage to adjacent animals",
                "Faint: Deal Attack x2 damage to adjacent animals",
                "Faint: Deal Attack x2 damage to adjacent animals"},
};

EWRAM_DATA const static struct Pet Badger = {
        .id =  2,
        .attack =  5,
        .defence =  4,
        .tier = 3
};
void badgerTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);