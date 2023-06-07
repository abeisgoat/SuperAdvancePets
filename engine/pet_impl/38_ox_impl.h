#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText OxText = {
        .name = "Ox",
        .abilities = {
                "Friend ahead attacks: Gain Melon Armor and +1 attack",
                "Friend ahead attacks: Gain Melon Armor and +2 attack",
                "Friend ahead attacks: Gain Melon Armor and +3 attack"},
};

EWRAM_DATA const static struct Pet Ox = {
        .id =  38,
        .attack =  1,
        .health =  3,
        .tier = 3
};
void oxTriggerFriendFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);