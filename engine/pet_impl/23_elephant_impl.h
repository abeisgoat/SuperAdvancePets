#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ElephantText = {
        .name = "Elephant",
        .abilities = {
                "Before Attack: Deal 1 damage to 1 friends behind.",
                "Before Attack: Deal 1 damage to 2 friends behind.",
                "Before Attack: Deal 1 damage to 3 friends behind."},
};

EWRAM_DATA const static struct Pet Elephant = {
        .id =  23,
        .attack =  3,
        .health =  5,
        .tier = 2
};
void elephantTriggerBeforeAttack(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);