#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MeatBoneText = {
        .name = "Meat Bone",
        .abilities = {
                "Give an animal Bone Attack.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet MeatBone = {
        .id =  108,
        .attack =  0,
        .defence =  0,
        .tier = 2
};
void meatBoneTriggerBuy(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);