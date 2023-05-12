#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText TurtleText = {
        .name = "Turtle",
        .abilities = {
                "Faint: Give friend behind Melon Armor",
                "Faint: Give 2 friends behind Melon Armor",
                "Faint: Give 2 friends behind Melon Armor"},
};

EWRAM_DATA const static struct Pet Turtle = {
        .id =  62,
        .attack =  1,
        .health =  2,
        .tier = 3
};
void turtleTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);