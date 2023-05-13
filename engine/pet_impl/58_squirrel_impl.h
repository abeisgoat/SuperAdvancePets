#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SquirrelText = {
        .name = "Squirrel",
        .abilities = {
                "Start of turn: Add one shop food and discount them by 1 gold.",
                "Start of turn: Add one shop food and discount them by 2 gold.",
                "Start of turn: Add one shop food and discount them by 3 gold."},
};

EWRAM_DATA const static struct Pet Squirrel = {
        .id =  58,
        .attack =  2,
        .health = 5,
        .tier = 4
};
void squirrelTriggerStartOfTurn(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);