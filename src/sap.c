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
#include "../sprites/generated/ui.h"
#include "../sprites/generated/bg.h"

#define CBB_4 0
#define SBB_4 2

#define CBB_8 2
#define SBB_8 4

#define CBB_12 4
#define SBB_12 6


OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

struct PetSprite {
    int x;
    int y;
    int flip;
    struct Pet * pet;
    int hidden;
};

struct PetSprite petSprites[10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

void resetAnimalSprites() {
    int petSpritesCount = 0;
    int xOffset=49;
    for (int i=0; i <=4; i++) {
        struct Pet *pet = getPlayerTeamPet(i);
        if (pet->id) {
            petSprites[petSpritesCount].pet = pet;
        } else {
            petSprites[petSpritesCount].pet = 0;
        }
        petSprites[petSpritesCount].x = xOffset  + (18 * i);
        petSprites[petSpritesCount].y = 49;
        petSprites[petSpritesCount].flip = 1;
        petSpritesCount++;
    }
}

void updateAnimalSprites(int startOfLvls, int startOfExp, int startOfNumbers) {
    for (int s=0; s<10; s++) {
        struct PetSprite *ps = &petSprites[s];

        if (ps->pet != 0) {
            unusePetGfxMem(ps->pet->id);
        }
    }
    OBJ_ATTR *sprite;
    int spriteCount=0;
    for (int s=0; s<10; s++) {
        struct PetSprite * ps = &petSprites[s];

        if (ps->pet != 0 && ps->hidden == 0) {
            int gfxMem = usePetGfxMem(ps->pet->id);


            u32 tid = gfxMem, pb = 0;
            sprite = &obj_buffer[++spriteCount];

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | ATTR2_PRIO(3)  | tid);

            obj_set_pos(sprite, ps->x, ps->y);

            if (ps->flip) {
                sprite->attr1 ^= ATTR1_HFLIP;
            }

            sprite = &obj_buffer[++spriteCount];

            int lvl = expToLevel(ps->pet->experience);

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | (startOfLvls + 8 * lvl));
            obj_set_pos(sprite, ps->x, ps->y - 30);

            sprite = &obj_buffer[++spriteCount];

            int expRemaining = expToRemainingToLevelUp(ps->pet->experience);

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | (startOfExp + 8 * expRemaining));
            obj_set_pos(sprite, ps->x, ps->y - 14);

            int health = getPetHealth(ps->pet);

            spriteCount++;
            if (health >= 10) {
                sprite = &obj_buffer[spriteCount];

                int healthTens = health / 10;

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | (startOfNumbers + (4 * healthTens)));
                obj_set_pos(sprite, ps->x + 5, ps->y - 14);
            }

            sprite = &obj_buffer[++spriteCount];

            int healthOnes = health % 10;
//            sprintf(msg, "%d", healthOnes);
//            tte_write(msg);

            obj_set_attr(sprite,
                         ATTR0_TALL | ATTR0_8BPP,
                         ATTR1_SIZE_8,
                         ATTR2_PALBANK(pb) | (startOfNumbers + (4 * healthOnes)));
            obj_set_pos(sprite, ps->x + 9, ps->y - 14);

            int damage = getPetAttack(ps->pet);

            spriteCount++;
            if (damage >= 10) {
                sprite = &obj_buffer[spriteCount];

                int damageTens = damage / 10;

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | (startOfNumbers + (4 * damageTens)));
                obj_set_pos(sprite, ps->x + 5, ps->y - 22);
            }

            sprite = &obj_buffer[++spriteCount];

            int damageOnes = damage % 10;

            obj_set_attr(sprite,
                         ATTR0_TALL | ATTR0_8BPP,
                         ATTR1_SIZE_8,
                         ATTR2_PALBANK(pb) | (startOfNumbers + (4 * damageOnes)));
            obj_set_pos(sprite, ps->x + 9, ps->y - 22);
        } else {
            for (int s=0; s<7; s++) {
                sprite = &obj_buffer[++spriteCount];
                obj_set_pos(sprite, -16, -16);
            }
        }
    }
}
void main() {
    prepareEngine();

    int friendly[5] = {
            1352953, // 1 Ant
            24310313, // 24 Fish
            34321114, // 34 Mammoth
            0, // 32 Kangaroo
            35310910, // 35 Monkey

    };
    int enemies[5] = {
            1320910, // 1 Ant
            2320910, // 2 badger
            3320910, // 2 beaver
            4320910, // 2 bee
            5320910, // 2 bison


    };

    prepareTeams(friendly, enemies);
//    int result = battle();


    // Background
    memcpy(pal_bg_mem, bgPal, bgPalLen);
    memcpy(&tile_mem[CBB_8][0], bgTiles, bgTilesLen);
    memcpy(&se_mem[SBB_8][0], bgMap, bgMapLen);


    // Sprites
    memcpy(pal_obj_mem, spritesPal, spritesPalLen);
    oam_init(obj_buffer, 128);

    // set up BG0 for a 4bpp 64x32t map, using
    //   using charblock 0 and screenblock 31
    REG_BG0CNT= BG_CBB(CBB_4) | BG_SBB(SBB_4) | BG_4BPP | BG_REG_32x32 |  BG_PRIO(2);
    REG_BG1CNT= BG_CBB(CBB_8) | BG_SBB(SBB_8) | BG_4BPP | BG_REG_32x32 |  BG_PRIO(3);
    REG_BG2CNT= BG_CBB(CBB_12) | BG_SBB(SBB_12) | BG_4BPP | BG_REG_32x32 | BG_PRIO(1);
    REG_DISPCNT= DCNT_OBJ | DCNT_MODE0 | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1 | DCNT_BG2;


    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    irq_add(II_VBLANK, mmVBlank);
    mmInitDefault((mm_addr)soundbank_bin, 20);


    // --- (1) Base TTE init for tilemaps ---
    tte_init_se(
            2,                      // Background number (BG 0)
            BG_CBB(CBB_12)|BG_SBB(31),   // BG control (for REG_BGxCNT)
            0,                      // Tile offset (special cattr)
            CLR_BLACK,             // Ink color
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

    tte_set_pos(80, 80);

    char msg[50];

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

    // Scroll around some
    int bg_x= 0, bg_y= -2;

    REG_BG2HOFS= bg_x;
    REG_BG2VOFS= bg_y;
    int frame=0;



//    for (int i=0; i <=4; i++) {
//        struct Pet *pet = getEnemyTeamPet(i);
//        if (pet->id) {
//            petSprites[petSpritesCount].pet = pet;
//            petSprites[petSpritesCount].x = xOffset + 100 + (18 * i);
//            petSprites[petSpritesCount].y = 50;
//            petSprites[petSpritesCount].flip = 0;
//            petSpritesCount++;
//        }
//    }

    // We use first addresses 12*8 address for 12 possible animals on screen. (full team + 7 store spots)
    u32 startOfNumbers = (12 * 8) + 4, pb = 0;

    memcpy(&tile_mem[4][startOfNumbers + 4 * 0], num0Tiles, num0TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 1], num1Tiles, num1TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 2], num2Tiles, num2TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 3], num3Tiles, num3TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 4], num4Tiles, num4TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 5], num5Tiles, num5TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 6], num6Tiles, num6TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 7], num7Tiles, num7TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 8], num8Tiles, num8TilesLen);
    memcpy(&tile_mem[4][startOfNumbers + 4 * 9], num9Tiles, num9TilesLen);

    u32 endOfNums = startOfNumbers + 4 * 10;

    memcpy(&tile_mem[4][endOfNums], uiLeftBumperRollTiles, uiLeftBumperRollTilesLen);
    memcpy(&tile_mem[4][endOfNums + 16], uiRightBumperFightTiles, uiRightBumperFightTilesLen);

    u32 startOfLvls = endOfNums + 24;

    memcpy(&tile_mem[4][startOfLvls + 8 * 1], uiBannerLvl1Tiles, uiBannerLvl1TilesLen);
    memcpy(&tile_mem[4][startOfLvls + 8 * 2], uiBannerLvl2Tiles, uiBannerLvl2TilesLen);
    memcpy(&tile_mem[4][startOfLvls + 8 * 3], uiBannerLvl3Tiles, uiBannerLvl3TilesLen);

    u32 startOfExp = startOfLvls + 8 * 4;

    memcpy(&tile_mem[4][startOfExp + 8 * 0], uiBannerExpZeroTiles, uiBannerExpZeroTilesLen);
    memcpy(&tile_mem[4][startOfExp + 8 * 1], uiBannerExpOneTiles, uiBannerExpOneTilesLen);
    memcpy(&tile_mem[4][startOfExp + 8 * 2], uiBannerExpTwoTiles, uiBannerExpTwoTilesLen);
    memcpy(&tile_mem[4][startOfExp + 8 * 3], uiBannerExpThreeTiles, uiBannerExpThreeTilesLen);

    u32 startOfIcons = startOfLvls + 8 * 8;

    memcpy(&tile_mem[4][startOfIcons + 4 * 0], uiCoin8x8Tiles, uiCoin8x8TilesLen);
    memcpy(&tile_mem[4][startOfIcons + 4 * 1], uiHeart8x8Tiles, uiHeart8x8TilesLen);
    memcpy(&tile_mem[4][startOfIcons + 4 * 2], uiTurns8x8Tiles, uiTurns8x8TilesLen);

    u32 cursor = startOfIcons + 16;

    memcpy(&tile_mem[4][cursor], uiCursorOpenTiles, uiCursorOpenTilesLen);
    memcpy(&tile_mem[4][cursor + 8], uiCursorCloseTiles, uiCursorCloseTilesLen);
//    memcpy(&tile_mem[4][endOfNums + 32], uiModalTiles, uiModalTilesLen);

    // UI Left Bumper
    OBJ_ATTR *sprite = &obj_buffer[100];

    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | (endOfNums));

    obj_set_pos(sprite, 0, 0);

    // UI Right Bumper
    sprite = &obj_buffer[101];
    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | (endOfNums + 16));

    obj_set_pos(sprite, 208, 0);


    int turn = 4;

    int counters_x = 144;

    if (turn < 10) {
        counters_x += 8;
    }

    int counters_y = 144;


    sprite = &obj_buffer[102];

    tte_set_pos(counters_x + 8, counters_y);
    sprintf(msg, "%d", 10);
    tte_write(msg);

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | (startOfIcons));

    obj_set_pos(sprite, counters_x, counters_y+2);

    sprite = &obj_buffer[103];


    tte_set_pos(counters_x + 46, counters_y);
    sprintf(msg, "%d", 10);
    tte_write(msg);

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | (startOfIcons + 4));

    obj_set_pos(sprite, counters_x + 32, counters_y+2);

    tte_set_pos(counters_x + 72, counters_y);
    sprintf(msg, "%d", turn);
    tte_write(msg);

    sprite = &obj_buffer[104];
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | (startOfIcons + 8));

    obj_set_pos(sprite, counters_x + 62, counters_y+2);


    int cursorOpen=1;
    int cursorX = 0;
    int cursorY = 0;

    sprite = &obj_buffer[105];
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16x16 | ATTR1_HFLIP,
                 ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | cursor);

    obj_set_pos(sprite, 0, 0);


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

    resetAnimalSprites();
    updateAnimalSprites(startOfLvls, startOfExp, startOfNumbers);

    int cursorHeldX = 0;
    int cursorHeldPetID = 0;
    while(1)
    {
        frame++;
        vid_vsync();
        key_poll();
        mmFrame();


        if (frame % 30 == 0 && cursorHeldPetID == 0) {
            sprite = &obj_buffer[105];
            if (cursorOpen) {
                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | cursor+0;
                cursorOpen = 0;
            } else {
                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | cursor+8;
                cursorOpen = 1;
            }
        }

        if(key_hit(KEY_A) && cursorY == 0)
        {
            if (cursorHeldPetID == 0) {
                cursorHeldX = cursorX;
                cursorHeldPetID = getPlayerTeamPet(cursorHeldX)->id;

                if (cursorHeldPetID > 0) {
                    int heldMem = usePetGfxMem(cursorHeldPetID);
                    sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | heldMem;
                    petSprites[cursorX].hidden = 1;
                }
            } else {
                unusePetGfxMem(cursorHeldPetID);
                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | cursor+0;
                petSprites[cursorHeldX].hidden = 0;
                swapPets(getPlayerTeamPet(cursorX), getPlayerTeamPet(cursorHeldX));
                cursorHeldX = 0;
                cursorHeldPetID = 0;
            }
            resetAnimalSprites();
            updateAnimalSprites(startOfLvls, startOfExp, startOfNumbers);
        }

        if(key_hit(KEY_RIGHT))
        {
            cursorX += 1;
        }

        if(key_hit(KEY_LEFT))
        {
            cursorX -= 1;
        }

        if(key_hit(KEY_DOWN))
        {
            cursorY += 1;
        }

        if(key_hit(KEY_UP))
        {
            cursorY -= 1;
        }

        if (cursorY < 0) {
            cursorY = 0;
        }
        if (cursorY > 1) {
            cursorY = 1;
        }

        if (cursorX < 0) {
            cursorX = 0;
        }

        if (cursorX > 4 && cursorY == 0) {
            cursorX = 4;
        }

        if (cursorX > 6 && cursorY == 1) {
            cursorX = 6;
        }


        int cursorScreenPosX = 49 + (cursorX * 18);
        int cursorScreenPosY = 49 + (cursorY * 50);
        if (cursorHeldPetID > 0) {
            cursorScreenPosY -= 4;
        }
        sprite = &obj_buffer[105];
        obj_set_pos(sprite, cursorScreenPosX, cursorScreenPosY);


//        OBJ_ATTR *sprite = &obj_buffer[10];
//        obj_set_pos(sprite, 10, 10);
//
//        sprite = &obj_buffer[11];
//        obj_set_pos(sprite, 10, 26);

//        sp0_x += 2*key_tri_horz();
//        sp0_y += 2*key_tri_vert();

        // increment/decrement starting tile with R/L
//        tid0 += bit_tribool(key_hit(-1), KI_R, KI_L);
//        tid0 += bit_tribool(key_hit(-1), KI_R, KI_L);
//        tid0 += bit_tribool(key_hit(-1), KI_R, KI_L);
//        tid0 += bit_tribool(key_hit(-1), KI_R, KI_L);
        // flip
//        if(key_hit(KEY_A))  // horizontally
//        {
//            PetSprite0->attr1 ^= ATTR1_HFLIP;
//            mmEffect(SFX_AUDIO_SHOOT);
//        }
//
//        if(key_hit(KEY_B))  // vertically
//            PetSprite0->attr1 ^= ATTR1_VFLIP;

        // make it glow (via palette swapping)
//        pb0= key_is_down(KEY_SELECT) ? 1 : 0;

        // toggle mapping mode
        if(key_hit(KEY_START))
            REG_DISPCNT ^= DCNT_OBJ_1D;

//        spriteCount=0;
//        for (int s=0; s<10; s++) {
//            struct PetSprite * ps = &petSprites[s];
//            if (ps->pet != 0) {
//                OBJ_ATTR *sprite = &obj_buffer[spriteCount];
////                sprite->attr2= ATTR2_BUILD(tid0, pb0, 0);
//                 obj_set_pos(sprite, ps->x, ps->y);
//                spriteCount++;
//            }
//        }

        // Hey look, it's one of them build macros!
//        PetSprite0->attr2= ATTR2_BUILD(tid0, pb0, 0);
//        obj_set_pos(PetSprite0, sp0_x, sp0_y);
//
//        PetSprite1->attr2= ATTR2_BUILD(tid1, pb1, 0);
//        obj_set_pos(PetSprite1, sp1_x, sp1_y);

        oam_copy(oam_mem, obj_buffer, 127);   // (6) Update OAM (only one now)
    }
}

//u8 txt_scrolly= 8;
//
//const char *names[]=
//        {   "C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "  };
//
//// === FUNCTIONS ======================================================
//
//// Show the octave the next note will be in
//void note_prep(int octave)
//{
//    char str[32];
//    siprintf(str, "[  %+2d]", octave);
//    se_puts(8, txt_scrolly, str, 0x1000);
//}
//
//
//// Play a note and show which one was played
//void note_play(int note, int octave)
//{
//    char str[32];
//
//    // Clear next top and current rows
//    SBB_CLEAR_ROW(31, (txt_scrolly/8-2)&31);
//    SBB_CLEAR_ROW(31, txt_scrolly/8);
//
//    // Display note and scroll
//    siprintf(str, "%02s%+2d", names[note], octave);
//    se_puts(16, txt_scrolly, str, 0);
//
//    txt_scrolly -= 8;
//    REG_BG0VOFS= txt_scrolly-8;
//
//    // Play the actual note
//    REG_SND1FREQ = SFREQ_RESET | SND_RATE(note, octave);
//}
//
//void quarterNote(int note, int octave, int speed) {
//    note_play(note, octave);
//    VBlankIntrDelay(8*speed);
//}
//
//void eighthNote(int note, int octave, int speed) {
//    note_play(note, octave);
//    VBlankIntrDelay(4*speed);
//}
//
//void tripletNote(int note, int octave, int speed) {
//    note_play(note, octave);
//    VBlankIntrDelay(3*speed);
//}
//
//void sixteenthNote(int note, int octave, int speed) {
//    note_play(note, octave);
//    VBlankIntrDelay(2*speed);
//}
//
//void halfNote(int note, int octave, int speed) {
//    note_play(note, octave);
//    VBlankIntrDelay(16*speed);
//}
//
//void sap_song() {
//    int B_FLAT = NOTE_BES;
//    int E_FLAT = NOTE_DIS;
//    int G_FLAT = NOTE_FIS;
//    int G_SHARP = NOTE_GIS;
//    int F_SHARP = NOTE_FIS;
//    int F = NOTE_F;
//
//    int speed = 4;
//
//    while (true) {
//        int octave = 1;
//        quarterNote(E_FLAT, octave, speed);
//        quarterNote(B_FLAT, octave, speed);
//        halfNote(G_FLAT, octave, speed);
//
//        VBlankIntrDelay(12 * speed);
////    VBlankIntrDelay(12*speed);
//
//        tripletNote(B_FLAT, octave, speed);
//        tripletNote(G_SHARP, octave, speed);
//
//        VBlankIntrDelay(3 * speed);
//
//        tripletNote(B_FLAT, octave, speed);
//        tripletNote(F_SHARP, octave, speed);
//
//        VBlankIntrDelay(3 * speed);
//
//        tripletNote(F, octave, speed);
//
////        quarterNote(E_FLAT, 0, speed);
////        quarterNote(B_FLAT, 0, speed);
////        halfNote(G_FLAT, 0, speed);
//
////        VBlankIntrDelay(4 * speed);
//    }
//}
//
//int main()
//{
//    REG_DISPCNT= DCNT_MODE0 | DCNT_BG0;
//
//    irq_init(NULL);
//    irq_add(II_VBLANK, NULL);
//
//    txt_init_std();
//    txt_init_se(0, BG_CBB(0) | BG_SBB(31), 0, CLR_ORANGE, 0);
//    pal_bg_mem[0x11]= CLR_GREEN;
//
//    int octave= 0;
//
//    // turn sound on
//    REG_SNDSTAT= SSTAT_ENABLE;
//    // snd1 on left/right ; both full volume
//    REG_SNDDMGCNT = SDMG_BUILD_LR(SDMG_SQR1, 7);
//    // DMG ratio to 100%
//    REG_SNDDSCNT= SDS_DMG100;
//
//    // no sweep
//    REG_SND1SWEEP= SSW_OFF;
//    // envelope: vol=12, decay, max step time (7) ; 50% duty
//    REG_SND1CNT= SSQR_ENV_BUILD(12, 0, 7) | SSQR_DUTY1_2;
//    REG_SND1FREQ= 0;
//
////sos();
//
//    while(1)
//    {
//        VBlankIntrWait();
//        key_poll();
//
//        // Change octave:
//        octave += bit_tribool(key_hit(-1), KI_R, KI_L);
//        octave= wrap(octave, -2, 6);
//        note_prep(octave);
//
//        // Play note
//        if(key_hit(KEY_DIR|KEY_A))
//        {
//            if(key_hit(KEY_UP))
//                note_play(NOTE_D, octave+1);
//            if(key_hit(KEY_LEFT))
//                note_play(NOTE_B, octave);
//            if(key_hit(KEY_RIGHT))
//                note_play(NOTE_A, octave);
//            if(key_hit(KEY_DOWN))
//                note_play(NOTE_F, octave);
//            if(key_hit(KEY_A))
//                note_play(NOTE_D, octave);
//        }
//
//        // Play ditty
//        if(key_hit(KEY_B))
//            sap_song();
//    }
//    return 0;
//}