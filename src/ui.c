#include <tonc.h>
#include "../engine/globals.h"
#include "tick.h"
#include "mem_manager.h"

void clearGameplayInfo() {
    tte_erase_screen();

    for (int i=102; i<=104;i++) {
        OBJ_ATTR * sprite = sprite = getOAMSprite(i);
        obj_set_pos(sprite, -16, -16);
    }
}
void updateGameplayInfo(int includeCoins) {
    int pb=0;
    int lives = 5;
    int turn = getTurn();
    int money = getBankMoney();

    OBJ_ATTR *sprite;
    char msg[50];
    int counters_x = 144;
    int turn_offset=0;

    if (lives < 10) {
        counters_x += 8;
    }

    if (turn < 10) {
        turn_offset += 8;
    }

    int counters_y = 144;


    sprite = getOAMSprite(102);
    tte_write("#{cx:0x0000}");
    int money_offset=0;
    if (money < 10) {
        money_offset = 8;
    }
    tte_set_pos(counters_x + 8 + turn_offset + money_offset, counters_y);

    if (includeCoins) {
        sprintf(msg, "%d ", money);
        tte_write(msg);

        obj_set_attr(sprite,
                     ATTR0_SQUARE | ATTR0_8BPP,
                     ATTR1_SIZE_8x8,
                     ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Coin));

        obj_set_pos(sprite, counters_x + money_offset + +turn_offset, counters_y + 2);
    } else {
        tte_erase_screen();
        obj_set_pos(sprite, -16,-16);
    }

    sprite = getOAMSprite(103);


    tte_set_pos(counters_x + 46+ turn_offset, counters_y);
    sprintf(msg, "%d ", turn);
    tte_write(msg);

    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Turns));

    obj_set_pos(sprite, counters_x + 32 + turn_offset, counters_y+2);

    tte_set_pos(counters_x + 72 , counters_y);
    sprintf(msg, "%d ", lives);
    tte_write(msg);

    sprite = getOAMSprite(104);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(pb) | getMemForUIIcon(UIIcon_Hearts));

    obj_set_pos(sprite, counters_x + 62, counters_y+2);
}