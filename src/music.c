#include <tonc.h>
#include <string.h>
#include <stdlib.h>
#include "../sprites/generated/logo.h"
#include "../engine/battle.h"

int seedframes = 0;
void note_play(int note, int octave)
{
    char str[32];

    seedframes++;
    REG_SND1FREQ = SFREQ_RESET | SND_RATE(note, octave);
}

int wait(int count) {
    for (int c=0; c<count; c++) {
        key_poll();
        if(key_hit(KEY_START)) {
            return 1;
        }
        seedframes++;
        VBlankIntrDelay(1);
    }
    return 0;
}

int quarterNote(int note, int octave, int speed) {
    note_play(note, octave);
    return wait(8*speed);
}

int eighthNote(int note, int octave, int speed) {
    note_play(note, octave);
    return wait(4*speed);
}

int tripletNote(int note, int octave, int speed) {
    note_play(note, octave);
    return wait(3*speed);
}

int sixteenthNote(int note, int octave, int speed) {
    note_play(note, octave);
    return wait(2*speed);
}

int halfNote(int note, int octave, int speed) {
    note_play(note, octave);
    return wait(16*speed);
}

void sap_song(int f) {
    int B_FLAT = NOTE_BES;
    int E_FLAT = NOTE_DIS;
    int G_FLAT = NOTE_FIS;
    int G_SHARP = NOTE_GIS;
    int F_SHARP = NOTE_FIS;
    int F = NOTE_F;

    int speed = 4;
    int octave = 1;
    int start=0;

    while (1) {
        start = quarterNote(E_FLAT, octave, speed);
        if (start) break;
        start =  quarterNote(B_FLAT, octave, speed);
        if (start) break;
        start = halfNote(G_FLAT, octave, speed);
        if (start) break;
        start = wait(12 * speed);
        if (start) break;
        start = tripletNote(B_FLAT, octave, speed);
        if (start) break;
        start =tripletNote(G_SHARP, octave, speed);
        if (start) break;
        start = wait(3 * speed);
        if (start) break;
        start = tripletNote(B_FLAT, octave, speed);
        if (start) break;
        start = tripletNote(F_SHARP, octave, speed);
        if (start) break;
        start = wait(3 * speed);
        if (start) break;
        start = tripletNote(F, octave, speed);
        if (start) break;
    }

    srand(seedframes);
}