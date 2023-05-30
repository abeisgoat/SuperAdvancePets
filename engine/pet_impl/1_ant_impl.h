#include <tonc_types.h>
#include "../pets.h"

EWRAM_DATA const static struct PetText AntText = {
        .name = "Ant",
        .abilities = {
                "Faint: Give a random friend +2/+1",
                "Faint: Give a random friend +4/+2",
                "Faint: Give a random friend +4/+2"},
};

EWRAM_DATA const static struct Pet Ant = {
        .id =  1,
        .attack =  2,
        .health =  1,
        .tier = 1
};
void antTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet,
        struct Pet * activatingPet, PetTeam store);