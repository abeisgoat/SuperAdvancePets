#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/bg.h"
#include "../engine/battle.h"
#include <stdio.h>
#include <time.h>
#include "../sprites/generated/sprites.h"
#include "mem_manager.h"
#include "../soundbank_bin.h"
#include "../soundbank.h"
#include <maxmod.h>
#include "../engine/globals.h"
#include "../engine/impl.h"
#include "../sprites/animals.h"
#include "../sprites/generated/uiBannerTopLvl1.h"
#include "../sprites/generated/uiBannerTopLvl2.h"
#include "../sprites/generated/uiBannerBottomEmpty.h"
#include "../sprites/generated/num0.h"
#include "../sprites/generated/num1.h"
#include "../sprites/generated/num2.h"
#include "../sprites/generated/num3.h"

#define CBB_4 0
#define SBB_4 2

#define CBB_8 2
#define SBB_8 4

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

struct PetSprite {
    int x;
    int y;
    int flip;
    struct Pet * pet;
};

struct PetSprite petSprites[10] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}};


void main() {
    prepareEngine();

    int friendly[5] = {
            1360953, // 1 Ant
            24310910, // 24 Fish
            34310910, // 34 Mammoth
            32310910, // 32 Kangaroo
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
    int result = battle();


    // Background
    memcpy(pal_bg_mem, bgPal, bgPalLen);
    memcpy(&tile_mem[CBB_8][0], bgTiles, bgTilesLen);
    memcpy(&se_mem[SBB_8][0], bgMap, bgMapLen);


    // Sprites
    memcpy(pal_obj_mem, spritesPal, spritesPalLen);
    oam_init(obj_buffer, 128);

    // set up BG0 for a 4bpp 64x32t map, using
    //   using charblock 0 and screenblock 31
    REG_BG0CNT= BG_CBB(CBB_4) | BG_SBB(SBB_4) | BG_4BPP | BG_REG_32x32;
    REG_BG1CNT= BG_CBB(CBB_8) | BG_SBB(SBB_8) | BG_4BPP | BG_REG_32x32;
    REG_DISPCNT= DCNT_OBJ | DCNT_MODE0 | DCNT_OBJ_1D | DCNT_BG0 | DCNT_BG1;


    irq_init(NULL);
    irq_add(II_VBLANK, NULL);
    irq_add(II_VBLANK, mmVBlank);
    mmInitDefault((mm_addr)soundbank_bin, 20);


    // --- (1) Base TTE init for tilemaps ---
    tte_init_se(
            0,                      // Background number (BG 0)
            BG_CBB(CBB_4)|BG_SBB(SBB_4),   // BG control (for REG_BGxCNT)
            0,                      // Tile offset (special cattr)
            CLR_BLACK,             // Ink color
            14,                     // BitUnpack offset (on-pixel = 15)
            &sys8Font,                   // Default font (sys8)
            NULL);                  // Default renderer (se_drawg_s)

    // --- (2) Init some colors ---
    pal_bg_bank[1][15]= CLR_RED;
    pal_bg_bank[2][15]= CLR_GREEN;
    pal_bg_bank[3][15]= CLR_BLUE;
    pal_bg_bank[4][15]= CLR_WHITE;
    pal_bg_bank[5][15]= CLR_MAG;

    pal_bg_bank[4][14]= CLR_GRAY;

    tte_set_pos(80, 80);

    char msg[50];


    if (result == -1) {
        tte_write(" #{cx:0x1000}You tied.\n");
    }
    if (result == -2) {
        tte_write(" #{cx:0x3000}You lost.\n");
    }
    if (result == -3) {
        tte_write(" #{cx:0x2000}You won!\n");
    }


    tte_write("#{cx:0x0000}");
    tte_set_pos(88, 78);

//    tte_write(" #{cx:0x1000}Hello world! in red\n");
//    tte_write(" #{cx:0x2000}Hello world! in green\n");
////    tte_set_pos(8, 64);
//    tte_write("#{cx:0x0000}C#{cx:0x1000}o#{cx:0x2000}l");
//    tte_write("#{cx:0x3000}o#{cx:0x4000}r#{cx:0x5000}s");
//    tte_write("#{cx:0} provided by \\#{cx:#}.");

    // Scroll around some
    int bg_x= 0, bg_y= -4;

    REG_BG0HOFS= bg_x;
    REG_BG0VOFS= bg_y;
    int frame=0;

    int petSpritesCount = 0;
    int xOffset=20;
    for (int i=0; i <=4; i++) {
        struct Pet *pet = getPlayerTeamPet(i);
        if (pet->id) {
            petSprites[petSpritesCount].pet = pet;
            petSprites[petSpritesCount].x = xOffset  + (20 * i);
            petSprites[petSpritesCount].y = 50;
            petSprites[petSpritesCount].flip = 1;
            petSpritesCount++;

//            int x = 24 + (24*i);
//            sprintf(msg, "#{P:%d,20}%d   \n", x, expToLevel(pet->experience));
//            tte_write(msg);
//            sprintf(msg, "#{P:%d,28}%d   \n", x, pet->health);
//            tte_write(msg);
//            sprintf(msg, "#{P:%d,36}%d   \n", x, pet->attack);
//            tte_write(msg);

        }
    }

    for (int i=0; i <=4; i++) {
        struct Pet *pet = getEnemyTeamPet(i);
        if (pet->id) {
            petSprites[petSpritesCount].pet = pet;
            petSprites[petSpritesCount].x = xOffset + 100 + (20 * i);
            petSprites[petSpritesCount].y = 50;
            petSprites[petSpritesCount].flip = 0;
            petSpritesCount++;
        }
    }

    u32 tid = 100, pb = 0;
    memcpy(&tile_mem[4][tid], uiBannerTopLvl2Tiles, uiBannerTopLvl2TilesLen);
    memcpy(&tile_mem[4][tid+10], uiBannerBottomEmptyTiles, uiBannerBottomEmptyTilesLen);
    memcpy(&tile_mem[4][tid+20], num0Tiles, num0TilesLen);
    memcpy(&tile_mem[4][tid+30], num1Tiles, num1TilesLen);
    memcpy(&tile_mem[4][tid+40], num2Tiles, num2TilesLen);
    memcpy(&tile_mem[4][tid+50], num3Tiles, num3TilesLen);
    memcpy(&tile_mem[4][tid+60], uiBannerTopLvl1Tiles, uiBannerTopLvl1TilesLen);

    OBJ_ATTR *sprite = &obj_buffer[10];
    int ui_x = 20;
    int ui_y = 20;

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16,
                 ATTR2_PALBANK(pb) | (tid + 2));

    obj_set_pos(sprite, ui_x, ui_y);

   sprite = &obj_buffer[11];

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16,
                 ATTR2_PALBANK(pb) | (tid+12));

    obj_set_pos(sprite, ui_x, ui_y+16);

    sprite = &obj_buffer[12];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+32));

    obj_set_pos(sprite, ui_x+6, ui_y+8);

    sprite = &obj_buffer[13];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+32));

    obj_set_pos(sprite, ui_x+6, ui_y+16);

    sprite = &obj_buffer[14];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+42));

    obj_set_pos(sprite, ui_x+10, ui_y+8);


    sprite = &obj_buffer[15];
    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+52));

    obj_set_pos(sprite, ui_x+10, ui_y+16);

    ui_x = 20+20;
    ui_y = 20;

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16,
                 ATTR2_PALBANK(pb) | (tid + 62));

    obj_set_pos(sprite, ui_x, ui_y);

    sprite = &obj_buffer[16];

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16,
                 ATTR2_PALBANK(pb) | (tid+12));

    obj_set_pos(sprite, ui_x, ui_y+16);

    sprite = &obj_buffer[17];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+52));

    obj_set_pos(sprite, ui_x+6, ui_y+8);

    sprite = &obj_buffer[18];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+32));

    obj_set_pos(sprite, ui_x+6, ui_y+16);

    sprite = &obj_buffer[19];

    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+42));

    obj_set_pos(sprite, ui_x+10, ui_y+8);


    sprite = &obj_buffer[20];
    obj_set_attr(sprite,
                 ATTR0_TALL | ATTR0_8BPP,
                 ATTR1_SIZE_8,
                 ATTR2_PALBANK(pb) | (tid+52));

    obj_set_pos(sprite, ui_x+10, ui_y+16);


    int spriteCount=0;
    for (int s=0; s<10; s++) {
        struct PetSprite * ps = &petSprites[s];

        if (ps->pet != 0) {
            int gfxMem = usePetGfxMem(ps->pet->id);

//            sprintf(msg, "%d gfxmem %d\n", ps->pet->id, gfxMem);
//            tte_write(msg);

            u32 tid = gfxMem, pb = 0;
            OBJ_ATTR *sprite = &obj_buffer[spriteCount];

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | tid);

            obj_set_pos(sprite, ps->x, ps->y);

            if (ps->flip) {
                sprite->attr1 ^= ATTR1_HFLIP;
            }
            spriteCount++;
        }
    }

    while(1)
    {
//        vid_vsync();
//        if((frame & 7) == 0)
//            key_poll();
        // check state of each button
//        for(int ii=0; ii<KI_MAX; ii++) {
//            int btn = 1 << ii;
//            if (key_hit(btn) && ii==0) { // "A" button hit
//                tte_erase_screen();
//                tte_set_pos(8, 59);
//                srand(frame);
//                sprintf(msg, "Random: %i", rand());
//                tte_write(msg);
//            }
//        }
//        REG_BG0HOFS= 6;
//        REG_BG0VOFS= 0;
        frame++;

        vid_vsync();
        key_poll();
        mmFrame();

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

        spriteCount=0;
        for (int s=0; s<10; s++) {
            struct PetSprite * ps = &petSprites[s];
            if (ps->pet != 0) {
                OBJ_ATTR *sprite = &obj_buffer[spriteCount];
//                sprite->attr2= ATTR2_BUILD(tid0, pb0, 0);
                 obj_set_pos(sprite, ps->x, ps->y);
                spriteCount++;
            }
        }

        // Hey look, it's one of them build macros!
//        PetSprite0->attr2= ATTR2_BUILD(tid0, pb0, 0);
//        obj_set_pos(PetSprite0, sp0_x, sp0_y);
//
//        PetSprite1->attr2= ATTR2_BUILD(tid1, pb1, 0);
//        obj_set_pos(PetSprite1, sp1_x, sp1_y);

        oam_copy(oam_mem, obj_buffer, 23);   // (6) Update OAM (only one now)
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