#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText DirtyRatText = {
        .name = "Dirty Rat",
        .abilities = {
                "Rude lil rat guy.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet DirtyRat = {
        .id =  17,
        .attack =  1,
        .health =  1,
};