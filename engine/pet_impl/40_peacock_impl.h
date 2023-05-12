#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PeacockText = {
        .name = "Peacock",
        .abilities = {
                "Hurt: Gain +4 Attack.",
                "Hurt: Gain +8 Attack.",
                "Hurt: Gain +12 more Attack."},
};

EWRAM_DATA const static struct Pet Peacock = {
        .id =  40,
        .attack =  2,
        .health =  5,
        .tier = 2
};
void peacockTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);