#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ChickText = {
        .name = "Chick",
        .abilities = {
                "It's a lil baby.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Chick = {
        .id =  11
};