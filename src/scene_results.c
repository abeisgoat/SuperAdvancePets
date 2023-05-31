#include <tonc.h>
#include "tick.h"
#include "mem_manager.h"
#include "animations.h"
#include "../engine/globals.h"
#include "../engine/battle.h"

int getXForHeart(int i) {
    return 72 + ((i-110)*20);
}

int getXForTrophy(int i) {
    return 22 + ((i-116)*20);
}

int heartY = 44+100;
int trophyY = 114+100;
int bigX = 104;
int bigY = 170;

int yOffset = 0;


void updateSpritesForSceneResults() {
    OBJ_ATTR * sprite;
    for (int i=110; i <= 114; i++) {
        sprite = getOAMSprite(i);
        obj_set_pos(sprite, getXForHeart(i), heartY-getScreenY()+yOffset);
    }

    for (int i=116; i <= 125; i++) {
        sprite = getOAMSprite(i);
        obj_set_pos(sprite, getXForTrophy(i), trophyY-getScreenY()+yOffset);
    }


    sprite = getOAMSprite(107);
    obj_set_pos(sprite, bigX, bigY - getScreenY()+yOffset);
}

void clearSpritesSceneResults() {
    OBJ_ATTR * sprite;
    for (int i=110; i <= 114; i++) {
        sprite = getOAMSprite(i);
        obj_set_pos(sprite, -16,-16);
    }

    for (int i=116; i <= 125; i++) {
        sprite = getOAMSprite(i);
        obj_set_pos(sprite, -16,-16);
    }

}


void prepareSceneResults() {
    yOffset = 15;
    OBJ_ATTR * sprite;
    for (int i=110; i <= 114; i++) {
        sprite = getOAMSprite(i);
        int mem = getMemFor16x16UI(UIElement_HeartEmpty);

        if (i < 110+getHearts()) {
            mem = getMemFor16x16UI(UIElement_Heart);
        }

        obj_set_attr(sprite,
                     ATTR0_SQUARE | ATTR0_8BPP,
                     ATTR1_SIZE_16x16,
                     ATTR2_PALBANK(0) | ATTR2_PRIO(1) | mem);
    }

    for (int i=116; i <= 125; i++) {
        sprite = getOAMSprite(i);
        int mem = getMemFor16x16UI(UIElement_TrophyEmpty);

        if (i < 116+getWins()) {
            mem = getMemFor16x16UI(UIElement_Trophy);
        }

        obj_set_attr(sprite,
                     ATTR0_SQUARE | ATTR0_8BPP,
                     ATTR1_SIZE_16x16,
                     ATTR2_PALBANK(0) | ATTR2_PRIO(1) | mem);
    }

    sprite = getOAMSprite(107);

    int bigMem = 0;

    switch (getLastResult()) {
        case -1:
            bigMem = load32x32UI(UIElement32x32_Meh);
            break;
        case -2:
            bigMem = load32x32UI(UIElement32x32_Frown);
            break;
        case -3:
            bigMem = load32x32UI(UIElement32x32_Smile);
            break;
    }

    if (getWins() == 10) {
        bigMem = load32x32UI(UIElement32x32_Trophy);
    }

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_32x32,
                 ATTR2_PALBANK(0) | ATTR2_PRIO(1) | bigMem);
    obj_set_pos(sprite, -32,-32);

    updateSpritesForSceneResults();
}

void tickSceneResults() {

    for (int i=0; i<30;i++) {
        updateSpritesForSceneResults();
        tickMainLoop();
        yOffset--;
        if (yOffset < 0) {
            yOffset = 0;
        }
    }


    while (1) {
        tickMainLoop();
        if (key_hit(KEY_A)) {
            break;
        }
    }

    int hasMsg = 0;
    tte_set_pos(20, 90);
    tte_write("#{cx:0x0000}");

    if (getWins() == 10) {
        tte_write("You win! Congratulations!");
        hasMsg = 1;
    } else if (getHearts() == 0) {
        tte_set_pos(60, 90);
        tte_write("Gameover! Sorry!");
        hasMsg = 1;
    } else if (getTurn() == 2) {
        tte_write("Tier 2 Pets now Unlocked!");
        hasMsg = 1;
    } else if (getTurn() == 4) {
        tte_write("Tier 3 Pets now Unlocked!");
        hasMsg = 1;
    }
    else if (getTurn() == 6) {
        tte_write("Tier 4 Pets now Unlocked!");
        hasMsg = 1;
    }
    else if (getTurn() == 8) {
        tte_write("Tier 5 Pets now Unlocked!");
        hasMsg = 1;
    } else if (getTurn() == 10) {
        tte_write("Tier 6 Pets now Unlocked!");
        hasMsg = 1;
    }


    if (hasMsg) {
        getOAMSprite(107)->attr0 |= ATTR0_HIDE;
        tickMainLoop();
        while (1) {

            if (key_hit(KEY_A)) {
                if (getWins() == 10 || getHearts() == 0) {
                    tte_erase_screen();
                    reset();
                    return;
                } else {
                    setScene(3);
                }
                tte_erase_screen();
                break;
            }
            tickMainLoop();
        }
    } else {
        setScene(3);
    }



    for (int i=0; i<20;i++) {
        updateSpritesForSceneResults();
        tickMainLoop();
        yOffset++;
    }
    clearSpritesSceneResults();
}