#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ShrimpText = {
        .name = "Shrimp",
        .abilities = {
                "Friend sold: Give a random friend +1 Health.",
                "Friend sold: Give a random friend +2 Health.",
                "Friend sold: Give a random friend +2 Health."},
};

EWRAM_DATA const static struct Pet Shrimp = {
        .id =  52,
        .attack =  2,
        .defence =  3,
        .tier = 2
};
void shrimpTriggerSell(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);