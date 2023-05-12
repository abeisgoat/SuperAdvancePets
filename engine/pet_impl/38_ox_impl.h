#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText OxText = {
        .name = "Ox",
        .abilities = {
                "Friend ahead attacks: Gain Melon Armor and +2 attack",
                "Friend ahead attacks: Gain Melon Armor and +4 attack",
                "Friend ahead attacks: Gain Melon Armor and +4 attack"},
};

EWRAM_DATA const static struct Pet Ox = {
        .id =  38,
        .attack =  1,
        .defence =  4,
        .tier = 3
};
void oxTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);