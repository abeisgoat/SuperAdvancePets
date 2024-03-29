#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SnailText = {
        .name = "Snail",
        .abilities = {
                "Buy: If you lost last battle, give all friends +1/+1",
                "Buy: If you lost last battle, give all friends +2/+2",
                "Buy: If you lost last battle, give all friends +3/+3"},
};

EWRAM_DATA const static struct Pet Snail = {
        .id =  55,
        .attack =  2,
        .health =  2,
        .tier = 3
};
void snailTriggerBuy(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);