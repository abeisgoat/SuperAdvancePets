#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText PeanutsText = {
        .name = "Peanuts",
        .abilities = {
                "Give an insta-kill once.",
                "",
                ""},
};

EWRAM_DATA const static struct Pet Peanuts = {
        .id =  118
};