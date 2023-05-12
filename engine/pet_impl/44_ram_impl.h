#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText RamText = {
        .name = "Ram",
        .abilities = {
                "It's a ram :|",
                "It's a big ram :)",
                "It's the biggest ram :O"},
};

EWRAM_DATA const static struct Pet Ram = {
        .id =  44
};