#include "pets.h"
#include "../sprites/beaver.h"

struct PetText AntText = {
        .name = "Ant",
        .abilities = {
                "Faint: Give a random friend +1/+1",
                "Faint: Give a random friend +2/+2",
                "Faint: Give a random friend +3/+3"},
};

struct Pet Ant = {
        .id =  1,
        .attack =  2,
        .defence =  1,
        // Always 0
        .battleModifierDefense = 0,
        .battleModifierAttack = 0,
};
void antTriggerFeint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * pet);