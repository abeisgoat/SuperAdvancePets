#include "../pets.h"
#include <tonc_types.h>

EWRAM_DATA const static struct PetText ZombieCricketText = {
        .name = "Zombie Cricket",
        .abilities = {
                "Spooky cricket.",
                "Very spooky cricket.",
                "AAAHH! A ZOMBIE!"},
};

EWRAM_DATA const static struct Pet ZombieCricket = {
        .id =  65
};