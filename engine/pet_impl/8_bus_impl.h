#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText BusText = {
        .name = "Bus",
        .abilities = {
                "It's a bus :)",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Bus = {
        .id =  8
};