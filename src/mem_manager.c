#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/animals.h"

struct GfxCacheEntry {
    int id;
    int uses;
};
struct GfxCacheEntry gfxCache[10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

int usePetGfxMem(int id) {
    int pos=0;

    for (int i = 0; i <= 1; i++) {
        struct GfxCacheEntry * cacheEntry = &gfxCache[i];
        if (cacheEntry->id == id) {
            cacheEntry->uses += 1;
            return 1+(i * 4);
        }
        if (cacheEntry->id <= 0) {
            pos = i;
        }
    }

    int memPos = pos*4;
    switch (id) {
        case 1:
            memcpy(&tile_mem[4][memPos], antTiles, 160);
            break;
        case 2:
            memcpy(&tile_mem[4][memPos], beaverTiles, 160);
            break;
        case 3:
            memcpy(&tile_mem[4][memPos], cricketTiles, 160);
            break;
        case 4:
            memcpy(&tile_mem[4][memPos], zombie_cricketTiles, 160);
            break;
    }

    gfxCache[pos].id = id;
    gfxCache[pos].uses += 1;

    return 1+memPos;
}

void unusePetGfxMem(int id) {
    for (int i = 0; i < 10; i++) {
        struct GfxCacheEntry * cacheEntry = &gfxCache[i];
        if (cacheEntry->id == id) {
            cacheEntry->uses -= 1;

            if (cacheEntry->uses == 0) {
                cacheEntry->id = 0;
            }
        }
    }
}