#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText LeopardText = {
        .name = "Leopard",
        .abilities = {
                "Start of battle: Deal 50% Attack damage to a random enemy.",
                "Start of battle: Deal 50% Attack damage to 2 random enemies.",
                "Start of battle: Deal 50% Attack damage to 3 random enemies."},
};

EWRAM_DATA const static struct Pet Leopard = {
        .id =  33,
        .attack =  10,
        .health =  4,
        .tier = 6
};
void leopardTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);