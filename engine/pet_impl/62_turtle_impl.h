#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText TurtleText = {
        .name = "Turtle",
        .abilities = {
                "Faint: Give friend behind Melon Armor",
                "Faint: Give 2 friends behind Melon Armor",
                "Faint: Give 3 friends behind Melon Armor"},
};

EWRAM_DATA const static struct Pet Turtle = {
        .id =  62,
        .attack =  2,
        .health =  5,
        .tier = 4
};
void turtleTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);