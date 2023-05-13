#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText SlothText = {
        .name = "Sloth",
        .abilities = {
                "He truly believes in you!",
                "He truly believes in you!",
                "He truly believes in you!"},
};

EWRAM_DATA const static struct Pet Sloth = {
        .id =  54,
        .attack =  1,
        .health =  1,
        .tier = 1
};