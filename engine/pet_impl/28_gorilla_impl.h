#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText GorillaText = {
        .name = "Gorilla",
        .abilities = {
                "Hurt: Gain Coconut Shield (Works 1x).",
                "Hurt: Gain Coconut Shield (Works 2x).",
                "Hurt: Gain Coconut Shield (Works 3x)."},
};

EWRAM_DATA const static struct Pet Gorilla = {
        .id =  28,
        .attack =  6,
        .health =  9,
        .tier = 6,
};
int gorillaTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);