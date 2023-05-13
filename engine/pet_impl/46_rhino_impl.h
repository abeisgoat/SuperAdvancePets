#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RhinoText = {
        .name = "Rhino",
        .abilities = {
                "Knock out: Deal 4 damage to the first enemy.",
                "Knock out: Deal 8 damage to the first enemy.",
                "Knock out: Deal 12 damage to the first enemy."},
};

EWRAM_DATA const static struct Pet Rhino = {
        .id =  46,
        .attack =  5,
        .health =  8,
        .tier = 5
};
void rhinoTriggerKnockOut(int usOrThem, PetTeam pt, PetTeam et, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store);