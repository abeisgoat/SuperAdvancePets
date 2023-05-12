#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BoarText = {
        .name = "Boar",
        .abilities = {
                "Before attack: Gain +2/+2.",
                "Before attack: Gain +4/+4.",
                "Before attack: Gain +6/+6."},
};

EWRAM_DATA const static struct Pet Boar = {
        .id =  7,
        .attack =  8,
        .health =  6,
        .tier = 6
};
void boarTriggerBeforeAttack(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);