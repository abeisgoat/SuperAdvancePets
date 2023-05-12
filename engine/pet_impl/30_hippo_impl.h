#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText HippoText = {
        .name = "Hippo",
        .abilities = {
                "Knock out: Gain +3/+3.",
                "Knock out: Gain +6/+6.",
                "Knock out: Gain +9/+9."},
};

EWRAM_DATA const static struct Pet Hippo = {
        .id =  30,
        .attack =  4,
        .health =  5,
        .tier = 4
};
void hippoTriggerKnockOut(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);