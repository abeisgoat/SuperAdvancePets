#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText MammothText = {
        .name = "Mammoth",
        .abilities = {
                "Faint: Give all friends +2/+2",
                "Faint: Give all friends +4/+4",
                "Faint: Give all friends +6/+6"},
};

EWRAM_DATA const static struct Pet Mammoth = {
        .id =  34,
        .attack =  3,
        .health =  9,
        .tier = 6
};
void mammothTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);