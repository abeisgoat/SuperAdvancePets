#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText CoconutText = {
        .name = "Coconut",
        .abilities = {
                "Blocks one attack",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Coconut = {
        .id =  119
};