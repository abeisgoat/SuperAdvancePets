#include "pets.h"

struct PetText CricketText = {
        .name = "Cricket",
        .abilities = {
                "Faint: Summon a +1/+1 Zombie Cricket",
                "Faint: Summon a +2/+2 Zombie Cricket",
                "Faint: Summon a +3/+3 Zombie Cricket"},
};

struct Pet Cricket = {
        .id =  3,
        .attack =  1,
        .defence =  1,
};
void cricketTriggerFeint(int usOrThem, PetTeam pt, PetTeam et, struct Pet * pet);