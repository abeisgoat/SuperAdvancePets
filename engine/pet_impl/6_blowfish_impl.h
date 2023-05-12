#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BlowfishText = {
        .name = "Blowfish",
        .abilities = {
                "Hurt: Deal 2 damage to a random enemy.",
                "Hurt: Deal 4 damage to a random enemy.",
                "Hurt: Deal 6 damage to a random enemy."},
};

EWRAM_DATA const static struct Pet Blowfish = {
        .id =  6,
        .attack =  3,
        .health =  5,
        .tier = 3
};
void blowfishTriggerHurt(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);