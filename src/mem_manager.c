#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/animals.h"

int getPetGfxMem(int id) {
    int pos=0;

    switch (id) {
        case 1:
            memcpy(&tile_mem[4][pos], antTiles, 160);
            break;
        case 2:
            memcpy(&tile_mem[4][pos], beaverTiles, 160);
            break;
        case 3:
            memcpy(&tile_mem[4][pos], cricketTiles, 160);
            break;
        case 4:
            memcpy(&tile_mem[4][pos], zombie_cricketTiles, 160);
            break;
    }

    return pos;
}