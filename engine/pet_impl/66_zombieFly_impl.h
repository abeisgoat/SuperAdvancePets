#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ZombieFlyText = {
        .name = "Zombie Fly",
        .abilities = {
                "Dang flies.",
                "Dang big flies.",
                "Dang huge flies."},
};

EWRAM_DATA const static struct Pet ZombieFly = {
        .id =  66
};