#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText OtterText = {
        .name = "Otter",
        .abilities = {
                "Buy: Give a random friend +1/+1",
                "Buy: Give a random friend +2/+2",
                "Buy: Give a random friend +2/+2"},
};

EWRAM_DATA const static struct Pet Otter = {
        .id =  37,
        .attack =  1,
        .health =  2,
        .tier = 1
};
void otterTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);