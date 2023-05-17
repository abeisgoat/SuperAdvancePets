#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/animals.h"
#include "../sprites/generated/ui.h"
#include "mem_manager_enums.h"

struct GfxCacheEntry {
    int id;
    int uses;
};
struct GfxCacheEntry gfxCache[10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

int usePetGfxMem(int id) {
    int pos=0;

    for (int i = 0; i < 10; i++) {
        struct GfxCacheEntry * cacheEntry = &gfxCache[i];
        if (cacheEntry->id == id) {
            cacheEntry->uses += 1;
            return (i * 10);
        }
        if (cacheEntry->id <= 0) {
            pos = i;
        }
    }

    int memPos = pos*10;
    int size = 320;
    switch (id) {
        case 1:
            memcpy(&tile_mem[4][memPos], antTiles, size);
            break;
        case 2:
            memcpy(&tile_mem[4][memPos], badgerTiles, size);
            break;
        case 3:
            memcpy(&tile_mem[4][memPos], beaverTiles, size);
            break;
        case 4:
            memcpy(&tile_mem[4][memPos], beeTiles, size);
            break;
        case 5:
            memcpy(&tile_mem[4][memPos], bisonTiles, size);
            break;
        case 6:
            memcpy(&tile_mem[4][memPos], blowfishTiles, size);
            break;
        case 7:
            memcpy(&tile_mem[4][memPos], hogTiles, size);
            break;
        case 8:
            memcpy(&tile_mem[4][memPos], busTiles, size);
            break;
        case 9:
            memcpy(&tile_mem[4][memPos], camelTiles, size);
            break;
        case 10:
            memcpy(&tile_mem[4][memPos], catTiles, size);
            break;
        case 11:
            memcpy(&tile_mem[4][memPos], chickTiles, size);
            break;
        case 12:
            memcpy(&tile_mem[4][memPos], cowTiles, size);
            break;
        case 13:
            memcpy(&tile_mem[4][memPos], crabTiles, size);
            break;
        case 14:
            memcpy(&tile_mem[4][memPos], cricketTiles, size);
            break;
        case 15:
            memcpy(&tile_mem[4][memPos], crocodileTiles, size);
            break;
        case 16:
            memcpy(&tile_mem[4][memPos], deerTiles, size);
            break;
        case 17:
            memcpy(&tile_mem[4][memPos], bad_ratTiles, size);
            break;
        case 18:
            memcpy(&tile_mem[4][memPos], dodoTiles, size);
            break;
        case 19:
            memcpy(&tile_mem[4][memPos], dogTiles, size);
            break;
        case 20:
            memcpy(&tile_mem[4][memPos], dolphinTiles, size);
            break;
        case 21:
            memcpy(&tile_mem[4][memPos], dragonTiles, size);
            break;
        case 22:
            memcpy(&tile_mem[4][memPos], duckTiles, size);
            break;
        case 23:
            memcpy(&tile_mem[4][memPos], elephantTiles, size);
            break;
        case 24:
            memcpy(&tile_mem[4][memPos], fishTiles, size);
            break;
        case 25:
            memcpy(&tile_mem[4][memPos], flamingoTiles, size);
            break;
        case 26:
            memcpy(&tile_mem[4][memPos], flyTiles, size);
            break;
        case 27:
            //TODO: Draw giraffe
            memcpy(&tile_mem[4][memPos], antTiles, size);
            break;
        case 28:
            memcpy(&tile_mem[4][memPos], gorillaTiles, size);
            break;
        case 29:
            memcpy(&tile_mem[4][memPos], hedgehogTiles, size);
            break;
        case 30:
            //TODO: Draw hippo
            memcpy(&tile_mem[4][memPos], antTiles, size);
            break;
        case 31:
            memcpy(&tile_mem[4][memPos], horseTiles, size);
            break;
        case 32:
            memcpy(&tile_mem[4][memPos], kangarooTiles, size);
            break;
        case 33:
            memcpy(&tile_mem[4][memPos], cheetahTiles, size);
            break;
        case 34:
            memcpy(&tile_mem[4][memPos], mammothTiles, size);
            break;
        case 35:
            memcpy(&tile_mem[4][memPos], monkeyTiles, size);
            break;
        case 36:
            memcpy(&tile_mem[4][memPos], mosquitoTiles, size);
            break;
        case 37:
            memcpy(&tile_mem[4][memPos], otterTiles, size);
            break;
        case 38:
            memcpy(&tile_mem[4][memPos], oxenTiles, size);
            break;
        case 39:
            memcpy(&tile_mem[4][memPos], parrotTiles, size);
            break;
        case 40:
            memcpy(&tile_mem[4][memPos], peacockTiles, size);
            break;
        case 41:
            memcpy(&tile_mem[4][memPos], penguinTiles, size);
            break;
        case 42:
            memcpy(&tile_mem[4][memPos], pigTiles, size);
            break;
        case 43:
            memcpy(&tile_mem[4][memPos], rabbitTiles, size);
            break;
        case 44:
            memcpy(&tile_mem[4][memPos], ramTiles, size);
            break;
        case 45:
            memcpy(&tile_mem[4][memPos], ratTiles, size);
            break;
        case 46:
            memcpy(&tile_mem[4][memPos], rhinoTiles, size);
            break;
        case 47:
            memcpy(&tile_mem[4][memPos], roosterTiles, size);
            break;
        case 48:
            memcpy(&tile_mem[4][memPos], scorpionTiles, size);
            break;
        case 49:
            memcpy(&tile_mem[4][memPos], sealTiles, size);
            break;
        case 50:
            memcpy(&tile_mem[4][memPos], sharkTiles, size);
            break;
        case 51:
            memcpy(&tile_mem[4][memPos], sheepTiles, size);
            break;
        case 52:
            memcpy(&tile_mem[4][memPos], shrimpTiles, size);
            break;
        case 53:
            memcpy(&tile_mem[4][memPos], skunkTiles, size);
            break;
        case 54:
            memcpy(&tile_mem[4][memPos], slothTiles, size);
            break;
        case 55:
            memcpy(&tile_mem[4][memPos], snailTiles, size);
            break;
        case 56:
            memcpy(&tile_mem[4][memPos], snakeTiles, size);
            break;
        case 57:
            memcpy(&tile_mem[4][memPos], spiderTiles, size);
            break;
        case 58:
            memcpy(&tile_mem[4][memPos], squirrelTiles, size);
            break;
        case 59:
            memcpy(&tile_mem[4][memPos], swanTiles, size);
            break;
        case 60:
            memcpy(&tile_mem[4][memPos], tigerTiles, size);
            break;
        case 61:
            memcpy(&tile_mem[4][memPos], turkeyTiles, size);
            break;
        case 62:
            memcpy(&tile_mem[4][memPos], turtleTiles, size);
            break;
        case 63:
            memcpy(&tile_mem[4][memPos], whaleTiles, size);
            break;
        case 64:
            memcpy(&tile_mem[4][memPos], wormTiles, size);
            break;
        case 65:
            memcpy(&tile_mem[4][memPos], zombie_cricketTiles, size);
            break;
        case 66:
            memcpy(&tile_mem[4][memPos], zombie_flyTiles, size);
            break;

    }

    gfxCache[pos].id = id;
    gfxCache[pos].uses += 1;

    return memPos;
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

const int memStartOfNumbers = (12 * 8) + 4;
const int memStartOfWideUI =  memStartOfNumbers + 80;
const int memStartOfLabels = memStartOfWideUI + 80;
const int memStartOfLvls = memStartOfLabels + 44;
const int memStartOfExp = memStartOfLvls + 8 * 4;
const int memStartOfIcons = memStartOfExp + 32;
const int memThrowable = memStartOfIcons + 16;
const int memCursor = memThrowable + 4;
const int memStartOfSquareUI =  memCursor + 16;

int getMemForNumber(int num) {
    return memStartOfNumbers + (num * 4);
}

int getMemFor32x16UI(enum UIElements32x16 element) {
    return memStartOfWideUI + element * 16;
}

int getMemFor16x16UI(enum UIElements16x16 element) {
    return memStartOfSquareUI + element * 8;
}

int getBannerTopForLvl(int lvl) {
    return memStartOfLvls + lvl * 8;
}

int getBannerBottomForExp(int exp) {
    return memStartOfExp + exp * 8;
}

int getMemForUIIcon(enum UIIcon icon) {
    return memStartOfIcons + icon * 4;
}

int getMemForCursor(int frame) {
    return memCursor + (frame * 8);
}

int loadLabel(int upperOrLower, enum UILabels label) {
    int memPos = memStartOfLabels + upperOrLower * 16;
    switch (label) {
        case UILabel_Buy:
            memcpy(&tile_mem[4][memPos], uiLabelBuyTiles, uiLabelBuyTilesLen);
            break;
        case UILabel_Sell:
            memcpy(&tile_mem[4][memPos], uiLabelSellTiles, uiLabelSellTilesLen);
            break;
        case UILabel_Cancel:
            memcpy(&tile_mem[4][memPos], uiLabelCancelTiles, uiLabelCancelTilesLen);
            break;
        case UILabel_Freeze:
            memcpy(&tile_mem[4][memPos], uiLabelFreezeTiles, uiLabelFreezeTilesLen);
            break;
        case UILabel_Move:
            memcpy(&tile_mem[4][memPos], uiLabelMoveTiles, uiLabelMoveTilesLen);
            break;
        case UILabel_Stack:
            memcpy(&tile_mem[4][memPos], uiLabelStackTiles, uiLabelStackTilesLen);
            break;
        case UILabel_Place:
            memcpy(&tile_mem[4][memPos], uiLabelPlaceTiles, uiLabelPlaceTilesLen);
            break;
        case UILabel_Swap:
            memcpy(&tile_mem[4][memPos], uiLabelSwapTiles, uiLabelSwapTilesLen);
            break;
    }

    return memPos;
}

int loadThrowable(enum UIThrowable label) {
    switch (label) {
        case UIThrowable_Damage:
            memcpy(&tile_mem[4][memThrowable], uiThrowableDamageTiles, uiThrowableDamageTilesLen);
            break;
        case UIThrowable_StatHealth:
            memcpy(&tile_mem[4][memThrowable], uiHeart8x8Tiles, uiHeart8x8TilesLen);
            break;
        case UIThrowable_StatAttack:
            memcpy(&tile_mem[4][memThrowable], uiThrowableStatAttackTiles, uiThrowableStatAttackTilesLen);
            break;
        case UIThrowable_Stats:
            memcpy(&tile_mem[4][ memThrowable], uiCoin8x8Tiles, uiCoin8x8TilesLen);
            break;
    }

    return  memThrowable;
}

void initSpriteMem() {
    // We use first addresses 12*8 address for 12 possible animals on screen. (full team + 7 store spots)
    memcpy(&tile_mem[4][getMemForNumber(0)], num0Tiles, num0TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(1)], num1Tiles, num1TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(2)], num2Tiles, num2TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(3)], num3Tiles, num3TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(4)], num4Tiles, num4TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(5)], num5Tiles, num5TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(6)], num6Tiles, num6TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(7)], num7Tiles, num7TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(8)], num8Tiles, num8TilesLen);
    memcpy(&tile_mem[4][getMemForNumber(9)], num9Tiles, num9TilesLen);

    // Two empty spaces for labels
    memcpy(&tile_mem[4][getMemFor32x16UI(UIElement_LeftBumperRoll)], uiLeftBumperRollTiles, uiLeftBumperRollTilesLen);
    memcpy(&tile_mem[4][getMemFor32x16UI(UIElement_RightBumperFight)], uiRightBumperFightTiles, uiRightBumperFightTilesLen);

    memcpy(&tile_mem[4][getBannerTopForLvl(1)], uiBannerLvl1Tiles, uiBannerLvl1TilesLen);
    memcpy(&tile_mem[4][getBannerTopForLvl(2)], uiBannerLvl2Tiles, uiBannerLvl2TilesLen);
    memcpy(&tile_mem[4][getBannerTopForLvl(3)], uiBannerLvl3Tiles, uiBannerLvl3TilesLen);

    memcpy(&tile_mem[4][getBannerBottomForExp(0)], uiBannerExpZeroTiles, uiBannerExpZeroTilesLen);
    memcpy(&tile_mem[4][getBannerBottomForExp(1)], uiBannerExpOneTiles, uiBannerExpOneTilesLen);
    memcpy(&tile_mem[4][getBannerBottomForExp(2)], uiBannerExpTwoTiles, uiBannerExpTwoTilesLen);
    memcpy(&tile_mem[4][getBannerBottomForExp(3)], uiBannerExpThreeTiles, uiBannerExpThreeTilesLen);

    memcpy(&tile_mem[4][getMemForUIIcon(UIIcon_Coin)], uiCoin8x8Tiles, uiCoin8x8TilesLen);
    memcpy(&tile_mem[4][getMemForUIIcon(UIIcon_Hearts)], uiHeart8x8Tiles, uiHeart8x8TilesLen);
    memcpy(&tile_mem[4][getMemForUIIcon(UIIcon_Turns)], uiTurns8x8Tiles, uiTurns8x8TilesLen);

    memcpy(&tile_mem[4][getMemForCursor(0)], uiCursorOpenTiles, uiCursorOpenTilesLen);
    memcpy(&tile_mem[4][getMemForCursor(1)], uiCursorCloseTiles, uiCursorCloseTilesLen);

    memcpy(&tile_mem[4][getMemFor16x16UI(UIElement_Btn_A_Outline)], uiButtonAOutlineTiles, uiButtonAOutlineTilesLen);
    memcpy(&tile_mem[4][getMemFor16x16UI(UIElement_Btn_B_Outline)], uiButtonBOutlineTiles, uiButtonBOutlineTilesLen);
//    memcpy(&tile_mem[4][endOfNums + 32], uiModalTiles, uiModalTilesLen);
}