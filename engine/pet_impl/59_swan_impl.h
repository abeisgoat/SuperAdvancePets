#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SwanText = {
        .name = "Swan",
        .abilities = {
                "Start of turn: Gain 1 gold.",
                "Start of turn: Gain 2 gold.",
                "Start of turn: Gain 3 gold."},
};

EWRAM_DATA const static struct Pet Swan = {
        .id =  59,
        .attack =  1,
        .health =  3,
        .tier = 2
};
void swanTriggerStartOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);