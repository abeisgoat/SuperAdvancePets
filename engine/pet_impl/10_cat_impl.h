#include "../pets.h"
#include <tonc_types.h>

// TODO Implement modifier for food eatin
EWRAM_DATA const static struct PetText CatText = {
        .name = "Cat",
        .abilities = {
                "Food with Health and Attack effects are 2x.",
                "Food with Health and Attack effects are 3x.",
                "Food with Health and Attack effects are 4x."},
};

EWRAM_DATA const static struct Pet Cat = {
        .id =  10,
        .attack =  4,
        .health =  5,
        .tier = 6
};