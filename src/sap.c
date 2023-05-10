#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/bg.h"
#include "../engine/battle.h"
#include <stdio.h>
#include <time.h>
#include "../sprites/sprites.h"
#include "mem_manager.h"
#include "../soundbank_bin.h"
#include "../soundbank.h"
#include <maxmod.h>

#define CBB_4 0
#define SBB_4 2

#define CBB_8 2
#define SBB_8 4

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

void main() {
    setupBattle();
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
    REG_DISPCNT= DCNT_OBJ | DCNT_OBJ_1D | DCNT_MODE0 | DCNT_BG0 | DCNT_BG1;


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

    tte_set_pos(8, 59);

    char msg[50];
    sprintf(msg, "Random: %i", rand());
    tte_write(msg);

    if (result == -1) {
        tte_write(" #{cx:0x1000}You tied.\n");
    }
    if (result == -2) {
        tte_write(" #{cx:0x3000}You lost.\n");
    }
    if (result == -3) {
        tte_write(" #{cx:0x2000}You won!.\n");
    }
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

    int sp_x= 170, sp_y= 75;
    int antGfxMem = getPetGfxMem(1);

    u32 tid = 0, pb= antGfxMem;      // (3) tile id, pal-bank
    OBJ_ATTR *PetSprite0= &obj_buffer[0];

    obj_set_attr(PetSprite0,
                 ATTR0_SQUARE,              // Square, regular sprite
                 ATTR1_SIZE_16,              // 64x64p,
                 ATTR2_PALBANK(pb) | tid);   // palbank 0, tile 0

    obj_set_pos(PetSprite0, sp_x, sp_y);

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
//        REG_BG1HOFS= x;
//        REG_BG1VOFS= y;
        frame++;

        vid_vsync();
        key_poll();
        mmFrame();

        sp_x += 2*key_tri_horz();
        sp_y += 2*key_tri_vert();

        // increment/decrement starting tile with R/L
        tid += bit_tribool(key_hit(-1), KI_R, KI_L);
        tid += bit_tribool(key_hit(-1), KI_R, KI_L);
        tid += bit_tribool(key_hit(-1), KI_R, KI_L);
        tid += bit_tribool(key_hit(-1), KI_R, KI_L);
        // flip
        if(key_hit(KEY_A))  // horizontally
        {
            PetSprite0->attr1 ^= ATTR1_HFLIP;
            mmEffect(SFX_AUDIO_SHOOT);
        }

        if(key_hit(KEY_B))  // vertically
            PetSprite0->attr1 ^= ATTR1_VFLIP;

        // make it glow (via palette swapping)
        pb= key_is_down(KEY_SELECT) ? 1 : 0;

        // toggle mapping mode
        if(key_hit(KEY_START))
            REG_DISPCNT ^= DCNT_OBJ_1D;

        // Hey look, it's one of them build macros!
        PetSprite0->attr2= ATTR2_BUILD(tid, pb, 0);
        obj_set_pos(PetSprite0, sp_x, sp_y);

        oam_copy(oam_mem, obj_buffer, 1);   // (6) Update OAM (only one now)
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
//        quarterNote(E_FLAT, 0, speed);
//        quarterNote(B_FLAT, 0, speed);
//        halfNote(G_FLAT, 0, speed);
//
//        VBlankIntrDelay(12 * speed);
////    VBlankIntrDelay(12*speed);
//
//        tripletNote(B_FLAT, 0, speed);
//        tripletNote(G_SHARP, 0, speed);
//
//        VBlankIntrDelay(3 * speed);
//
//        tripletNote(B_FLAT, 0, speed);
//        tripletNote(F_SHARP, 0, speed);
//
//        VBlankIntrDelay(3 * speed);
//
//        tripletNote(F, 0, speed);
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