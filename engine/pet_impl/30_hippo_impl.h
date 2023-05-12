#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText HippoText = {
        .name = "Hippo",
        .abilities = {
                "Knock out: Gain +2/+2.",
                "Knock out: Gain +4/+4.",
                "Knock out: Gain +4/+4."},
};

EWRAM_DATA const static struct Pet Hippo = {
        .id =  30,
        .attack =  4,
        .defence =  7,
        .tier = 4
};
void hippoTriggerKnockOut(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);