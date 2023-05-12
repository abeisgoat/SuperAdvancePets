#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DogText = {
        .name = "Dog",
        .abilities = {
                "Friend summoned: Gain +1 Attack or +1 Health.",
                "Friend summoned: Gain +2 Attack or +2 Health.",
                "Friend summoned: Gain +2 Attack or +2 Health."},
};

EWRAM_DATA const static struct Pet Dog = {
        .id =  19,
        .attack =  2,
        .defence =  2,
        .tier = 3
};
void dogTriggerSummoned(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);