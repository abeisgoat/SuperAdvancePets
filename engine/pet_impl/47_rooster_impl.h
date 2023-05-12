#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RoosterText = {
        .name = "Rooster",
        .abilities = {
                "Faint: Summon a Chick with 1 health and half the Attack of this.",
                "Faint: Summon 2 Chicks with 1 health and half the Attack of this.",
                "Faint: Summon 2 Chicks with 1 health and half the Attack of this."},
};

EWRAM_DATA const static struct Pet Rooster = {
        .id =  47,
        .attack =  5,
        .defence =  3,
        .tier = 4
};
void roosterTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);