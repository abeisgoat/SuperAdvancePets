#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText FlyText = {
        .name = "Fly",
        .abilities = {
                "Friend faints: Summon a 5/5 fly in its place (Max 3 times)",
                "Friend faints: Summon a 10/10 fly in its place (Max 3 times)",
                "Friend faints: Summon a 10/10 fly in its place (Max 3 times)"},
};

EWRAM_DATA const static struct Pet Fly = {
        .id =  26,
        .attack =  5,
        .health =  5,
        .tier = 6
};
void flyTriggerFaint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet);