#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CamelText = {
        .name = "Camel",
        .abilities = {
                "Hurt: Give friend behind +1/+1",
                "Hurt: Give friend behind +2/+2",
                "Hurt: Give friend behind +3/+3"},
};

EWRAM_DATA const static struct Pet Camel = {
        .id =  9,
        .attack =  2,
        .health =  5,
        .tier = 3
};
void camelTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);