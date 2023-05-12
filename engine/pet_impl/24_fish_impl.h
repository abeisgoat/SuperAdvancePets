#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText FishText = {
        .name = "Fish",
        .abilities = {
                "Level-up: Give all friends +1/+1",
                "Level-up: Give all friends +2/+2",
                "Level-up: Give all friends +2/+2"},
};

EWRAM_DATA const static struct Pet Fish = {
        .id =  24,
        .attack =  2,
        .health =  3,
        .tier = 1
};
void fishTriggerLevelUp(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);