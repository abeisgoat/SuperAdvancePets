#include "pets.h"
#include "../sprites/beaver.h"

struct PetText BeaverText = {
        .name = "Beaver",
        .abilities = {
                "Sell: Give two random friends +1 health",
                "Sell: Give two random friends +2 health",
                "Sell: Give two random friends +3 health"},
};

struct Pet Beaver = {
        .id =  2,
        .attack =  2,
        .defence =  2,
        // Always 0
        .battleModifierDefense = 0,
        .battleModifierAttack = 0,
};
void beaverSoldTrigger(int usOrThem, PetTeam pt, PetTeam et, struct Pet * pet);