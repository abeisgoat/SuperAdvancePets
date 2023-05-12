#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MosquitoText = {
        .name = "Mosquito",
        .abilities = {
                "Start of battle: Deal 1 damage to a random enemy",
                "Start of battle: Deal 2 damage to a random enemy",
                "Start of battle: Deal 2 damage to a random enemy"},
};

EWRAM_DATA const static struct Pet Mosquito = {
        .id =  36,
        .attack =  2,
        .health =  2,
        .tier = 1
};
void mosquitoTriggerStartOfBattle(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);