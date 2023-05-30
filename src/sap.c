#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../engine/battle.h"
#include <stdio.h>
#include <time.h>
#include "../sprites/generated/sprites.h"
#include "mem_manager.h"
#include "../soundbank_bin.h"
#include "../soundbank.h"
#include <maxmod.h>
#include "../engine/globals.h"
#include "../sprites/generated/bg.h"
#include "mem_manager_enums.h"
#include "tick.h"
#include "structs.h"
#include "scene_store.h"
#include "scene_battle.h"
#include "../engine/impl.h"
#include "music.h"
#include "../sprites/generated/logo.h"

#define CBB_4 0
#define SBB_4 2

#define CBB_8 2
#define SBB_8 4

#define CBB_12 4
#define SBB_12 6

void main() {
    prepareEngine();

    int friendly[5] = {

            640000202, // 35 Monkey,
            208350444,
            208350444,
            0, // 24 Fish
            0, // 34 Mammoth

    };
    int enemies[5] = {
            29420920,
            1320910, // 1 Antbadger
            3320910, // 2 beaver
            4320910, // 2 bee
            5320910, // 2 bison
    };

    int store[7] = {
            29, 1, 2, 6, 0,  101, 107
    };


    prepareTeams(friendly, enemies);
    forceStore(store);

    tte_set_pos(32, 0);

    tickInit();
    // Background
    memcpy(pal_bg_mem, logoPal, logoPalLen);
    memcpy(&tile_mem[CBB_8][0], logoTiles, logoTilesLen);
    memcpy(&se_mem[SBB_8][0], logoMap, logoMapLen);
//    memcpy(pal_bg_mem, bgPal, bgPalLen);
//    memcpy(&tile_mem[CBB_8][0], bgTiles, bgTilesLen);
//    memcpy(&se_mem[SBB_8][0], bgMap, bgMapLen);

    // Sprites pal
    memcpy(pal_obj_mem, spritesPal, spritesPalLen);

    REG_BG0CNT= BG_CBB(CBB_4) | BG_SBB(SBB_4) | BG_4BPP | BG_REG_32x32 |  BG_PRIO(1);
    REG_BG1CNT= BG_CBB(CBB_8) | BG_SBB(SBB_8) | BG_8BPP | BG_REG_64x32 |  BG_PRIO(3);
    REG_BG2CNT= BG_CBB(CBB_12) | BG_SBB(SBB_12) | BG_4BPP | BG_REG_32x32 | BG_PRIO(1);
    REG_DISPCNT= DCNT_OBJ | DCNT_MODE0 | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;

    REG_BG1HOFS = 16;

    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    irq_add(II_VBLANK, mmVBlank);
    mmInitDefault((mm_addr)soundbank_bin, 20);

    // turn sound on
    REG_SNDSTAT= SSTAT_ENABLE;
    // snd1 on left/right ; both full volume
    REG_SNDDMGCNT = SDMG_BUILD_LR(SDMG_SQR1, 7);
    // DMG ratio to 100%
    REG_SNDDSCNT= SDS_DMG100;

    // no sweep
    REG_SND1SWEEP= SSW_OFF;
    // envelope: vol=12, decay, max step time (7) ; 50% duty
    REG_SND1CNT= SSQR_ENV_BUILD(12, 0, 7) | SSQR_DUTY1_2;
    REG_SND1FREQ= 0;

//    sap_song(0);

    memcpy(pal_bg_mem, bgPal, bgPalLen);
    memcpy(&tile_mem[CBB_8][0], bgTiles, bgTilesLen);
    memcpy(&se_mem[SBB_8][0], bgMap, bgMapLen);

    initSpriteMem();
    resetGame();

    // --- (1) Base TTE init for tilemaps ---
    tte_init_se(
            2,                      // Background number (BG 0)
            BG_CBB(CBB_12)|BG_SBB(SBB_12),   // BG control (for REG_BGxCNT)
            0,                      // Tile offset (special cattr)
            RGB8(28, 48, 24),             // Ink color
            15,                     // BitUnpack offset (on-pixel = 15)
            &sys8Font,                   // Default font (sys8)
            NULL);                  // Default renderer (se_drawg_s)
    // --- (2) Init some colors ---
    pal_bg_bank[1][15]= CLR_RED;
    pal_bg_bank[2][15]= CLR_WHITE;
    pal_bg_bank[3][15]= CLR_BLUE;
    pal_bg_bank[4][15]= CLR_WHITE;
    pal_bg_bank[5][15]= CLR_MAG;
    pal_bg_bank[4][14]= CLR_GRAY;

    char msg[50];

//    sprintf(msg, "ID: %d", getEnemyTeamPet(5)->id);
//    tte_write(msg);

    // Scroll around some
    int bg_x= 0, bg_y= -2;

    REG_BG2HOFS= bg_x;
    REG_BG2VOFS= bg_y;

    int pb = 0;
    OBJ_ATTR  * sprite = getOAMSprite(105);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16x16 | ATTR1_HFLIP,
                 ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | getMemForCursor(0));

    obj_set_pos(sprite, 0, 0);

    sprite =getOAMSprite(106);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16x16,
                 ATTR2_PALBANK(pb) | getMemFor16x16UI(UIElement_Btn_A_Outline));
    obj_set_pos(sprite, 8, 134);

    sprite = getOAMSprite(107);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16x16,
                 ATTR2_PALBANK(pb) | getMemFor16x16UI(UIElement_Btn_B_Outline));
    obj_set_pos(sprite, 8, 144);

    sprite = getOAMSprite(108);
    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | loadLabel(0, UILabel_Move));
    obj_set_pos(sprite, 20, 136);

    sprite = getOAMSprite(109);
    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | loadLabel(1, UILabel_Sell));
    obj_set_pos(sprite, 20, 146);

    int lastScene = -1;

    while(1)
    {

        switch (getScene()) {
            case 0:
            case 3:
                if (lastScene != 0) {
                    prepareSceneStore();
                    lastScene = 0;
                    screenAnimalSprites();
                    updateAnimalSprites();
                }
                tickSceneStore();
                break;
            case 1:
                if (lastScene != 1) {
                    prepareSceneBattle();
                    lastScene = 1;
                    screenAnimalSprites();
                    updateAnimalSprites();
                }
                tickSceneBattle();
                break;
        }

        tickMainLoop();
    }
}

//
//    if (result == -1) {
//        tte_write(" #{cx:0x1000}You tied.\n");
//    }
//    if (result == -2) {
//        tte_write(" #{cx:0x3000}You lost.\n");
//    }
//    if (result == -3) {
//        tte_write(" #{cx:0x3000}You won!\n");
//    }


//    tte_write("#{cx:0x0000}");
//    tte_set_pos(88, 78);

//    tte_write(" #{cx:0x1000}Hello world! in red\n");
//    tte_write(" #{cx:0x2000}Hello world! in green\n");
////    tte_set_pos(8, 64);
//    tte_write("#{cx:0x0000}C#{cx:0x1000}o#{cx:0x2000}l");
//    tte_write("#{cx:0x3000}o#{cx:0x4000}r#{cx:0x5000}s");
//    tte_write("#{cx:0} provided by \\#{cx:#}.");

//    tte_set_pos(8, 132);
//    sprintf(msg, "#{cx:0x2000}Start of battle:\n Swallow friend ahead and \n release as Level 1.");
//    tte_write(msg);

// Modal
//    sprite = &obj_buffer[12];
//
//    obj_set_attr(sprite,
//                 ATTR0_WIDE | ATTR0_8BPP,
//                 ATTR1_SIZE_32x64,
//                 ATTR2_PALBANK(pb) | ATTR2_PRIO(5) | (endOfNums + 32));
//
//    obj_set_pos(sprite, 88, 64);

// (6) Update OAM (only one now)

//        spriteCount=0;
//        for (int s=0; s<10; s++) {
//            struct PetSprite * ps = &petSprites[s];
//            if (ps->pet != 0) {
//                OBJ_ATTR *sprite = &obj_buffer[spriteCount];
////                sprite->attr2= ATTR2_BUILD(tid0, pb0, 0);
//                 obj_set_pos(sprite, ps->worldX, ps->worldY);
//                spriteCount++;
//            }
//        }
