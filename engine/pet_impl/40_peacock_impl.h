#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PeacockText = {
        .name = "Peacock",
        .abilities = {
                "Hurt: Gain 50% more Attack. Works 1 time(s) per turn.",
                "Hurt: Gain 50% more Attack. Works 2 time(s) per turn.",
                "Hurt: Gain 50% more Attack. Works 2 time(s) per turn."},
};

EWRAM_DATA const static struct Pet Peacock = {
        .id =  40,
        .attack =  1,
        .health =  5,
        .tier = 2
};
void peacockTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);