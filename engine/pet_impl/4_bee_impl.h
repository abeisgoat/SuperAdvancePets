#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BeeText = {
        .name = "Bee",
        .abilities = {
                "",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Bee = {
        .id =  4,
        .attack =  1,
        .defence =  1,
};