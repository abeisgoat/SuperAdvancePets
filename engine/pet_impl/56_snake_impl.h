#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SnakeText = {
        .name = "Snake",
        .abilities = {
                "Friend ahead attacks: Deal 5 damage to a random enemy.",
                "Friend ahead attacks: Deal 10 damage to a random enemy.",
                "Friend ahead attacks: Deal 10 damage to a random enemy."},
};

EWRAM_DATA const static struct Pet Snake = {
        .id =  56,
        .attack =  6,
        .health =  6,
        .tier = 6
};
void snakeTriggerAfterAttack(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);