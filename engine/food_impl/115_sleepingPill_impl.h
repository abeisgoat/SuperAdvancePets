#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SleepingPillText = {
        .name = "Sleeping Pill",
        .abilities = {
                "Make a friendly animal faint.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet SleepingPill = {
        .id =  115,
        .attack =  0,
        .health =  0,
        .tier = 2,
        .cost = 1
};
void sleepingPillTriggerBuyAssign(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);