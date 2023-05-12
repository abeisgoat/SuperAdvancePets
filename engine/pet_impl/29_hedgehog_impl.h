#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText HedgehogText = {
        .name = "Hedgehog",
        .abilities = {
                "Faint: Deal 2 damage to all.",
                "Faint: Deal 4 damage to all.",
                "Faint: Deal 6 damage to all."},
};

EWRAM_DATA const static struct Pet Hedgehog = {
        .id =  29,
        .attack =  3,
        .health =  2,
        .tier = 2
};
void hedgehogTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);