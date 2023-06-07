#include <tonc.h>
#include "tick.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "../engine/globals.h"
#include "structs.h"
#include "animations.h"
#include "ui.h"

int frame;

int cursorHeldX = 0;
int cursorHeldY = 0;
int cursorHeldPetID = 0;

int cursorX = 0;
int cursorY = 0;
int cursorOpen = 0;
int cursorMem = 0;

int pb = 0;

int getWorldXForPetPositionInStore(int petPosition) {
    int xOffset=52;
    if (petPosition <= 4) {
        return xOffset + (18 * petPosition);
    } else {
        return xOffset + 100 + (18 * (petPosition-5));
    }
}


void setupStoreUI() {
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
}

void resetAnimalSpritesForStore() {
    int xOffset=65;
    int petPins=0;

    for (int i=0; i < 5; i++) {
        struct Pet *pet = getPlayerTeamPet(i);
        struct PetSprite * ps = getPetSprite(i);

        if (pet->id) {
            pet->pin = ++petPins;
            ps->petPin = pet->pin;
        } else {
            ps->petPin = 0;
        }

        ps->worldX = xOffset + (18 * i);
        ps->worldY = 50;
        ps->flip = 1;
        ps->shortStat = 0;
        ps->frozen = 0;
    }
        tte_set_pos(32, 0);
    for (int i=5; i <12; i++) {
        struct Pet *pet = getEnemyTeamPet(i-5);
        struct PetSprite * ps = getPetSprite(i);

        if (pet->id) {
            ps->shortStat = 1;
            pet->pin = ++petPins;
            ps->petPin = pet->pin;

        } else {
            ps->petPin = 0;
        }
        ps->frozen = isFrozen(i-5);
        ps->worldX = xOffset + (18 * (i-5));
        ps->worldY = 83;
        ps->flip = 1;
    }
}

void hideLabels() {
    OBJ_ATTR * sprite;
    for (int s=106; s<=109;s++) {
        sprite = getOAMSprite(s);
        sprite->attr0 |= ATTR0_HIDE;
    }
}

void hideTopLabel() {
    OBJ_ATTR * sprite;
    for (int s=106; s<=108;s+=2) {
        sprite = getOAMSprite(s);
        sprite->attr0 |= ATTR0_HIDE;
    }
}

void showLabels() {
    OBJ_ATTR  * sprite;
    for (int s=106; s<=109;s++) {
        sprite = getOAMSprite(s);
        sprite->attr0  &= ~ATTR0_HIDE;
    }
}


void updateLabels() {
    showLabels();
    int hoveredId;

    if (cursorY == 0) {
        hoveredId = getPlayerTeamPet(cursorX)->id;
    }
    if (cursorY == 1) {
        hoveredId = getEnemyTeamPet(cursorX)->id;
    }

    if (cursorHeldPetID && cursorY == 1) {
        hideTopLabel();
        loadLabel(1, UILabel_Cancel);
    }else if (cursorHeldPetID) {
        if (cursorHeldY == 1) {
           hideTopLabel();
            if (cursorHeldPetID < 100) {
                if (hoveredId == cursorHeldPetID) {
                    showLabels();
                    loadLabel(0, UILabel_Stack);
                } else if (hoveredId == 0) {
                    showLabels();
                    loadLabel(0, UILabel_Place);
                }

            } else if (cursorHeldPetID > 100) {
                if (hoveredId > 0) {
                    showLabels();
                    loadLabel(0, UILabel_Buy);
                } else {
                    loadLabel(1, UILabel_Cancel);
                }
            } else {
                loadLabel(0, UILabel_Cancel);
            }
        }

        if (cursorHeldY == 0) {
            loadLabel(1, UILabel_Cancel);
            if (hoveredId == cursorHeldPetID && cursorX != cursorHeldX) {
                loadLabel(0, UILabel_Stack);
            } else if (hoveredId == 0 || (hoveredId == cursorHeldPetID && cursorX == cursorHeldX)) {
                loadLabel(0, UILabel_Place);
            } else if (hoveredId > 0) {
                loadLabel(0, UILabel_Swap);
            } else {
                hideTopLabel();
                loadLabel(0, UILabel_Cancel);
            }
        }
    } else {
        if (cursorY == 0) {
            if (hoveredId > 0) {
                loadLabel(1, UILabel_Sell);
                loadLabel(0, UILabel_Move);
            } else {
                hideLabels();
            }
        } else {
            if (hoveredId > 0) {
                loadLabel(1, UILabel_Freeze);
                loadLabel(0, UILabel_Buy);
            } else {
                hideLabels();
            }

        }
    }
}

void cancelAction() {
    cursorMem = getMemForCursor(0);
    int spriteOffset = cursorHeldY * 5;
    getPetSprite(cursorHeldX + spriteOffset)->visiblePet = 1;
    getOAMSprite(105)->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | cursorMem;
    cursorY = cursorHeldY;
    cursorX = cursorHeldX;
    cursorHeldX = 0;
    cursorHeldY = 0;
    cursorHeldPetID = 0;
    frame = 0;
}

void prepareSceneStore() {
    setupStoreUI();
    nextTurn();
//    randomizeStore();
    resetBankForTurn();
    hideLabels();

    for (int i=0; i<=4; i++) {
        struct Pet * pet = getPlayerTeamPet(i);
        pet->battleModifierHealth = 0;
        pet->battleModifierAttack = 0;
    }

    resetAnimalSpritesForStore();
    updateAnimalSprites();

    cursorHeldX = 0;
    cursorHeldY = 0;
    cursorHeldPetID = 0;

    cursorX = 0;
    if (getTurn() == 1) {
        cursorY = 1;
    } else {
        cursorY = 0;
    }
    cursorOpen = 0;
    cursorMem = 0;
    OBJ_ATTR *sprite;
    for (int i=0; i <12; i++) {
        struct PetSprite * ps = getPetSprite(i);
        ps->visiblePet = true;
        ps->visibleStats = true;
    }

    tte_erase_screen();
    updateGameplayInfo(1);

    // UI Left Bumper
    sprite = getOAMSprite(100);
    int pb=0;
    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | getMemFor32x16UI(UIElement_LeftBumperRoll));

    obj_set_pos(sprite, 0, 0);

    // UI Right Bumper
    sprite = getOAMSprite(101);
    obj_set_attr(sprite,
                 ATTR0_WIDE | ATTR0_8BPP,
                 ATTR1_SIZE_16x32,
                 ATTR2_PALBANK(pb) | getMemFor32x16UI(UIElement_RightBumperFight));

    obj_set_pos(sprite, 208, 0);
    updateLabels();

    // Cursor
    sprite = getOAMSprite(105);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_16x16 | ATTR1_HFLIP,
                 ATTR2_PALBANK(pb) | ATTR2_PRIO(4) | getMemForCursor(0));

    obj_set_pos(sprite, 0, 0);
}

void updateCursor() {
    OBJ_ATTR * sprite;
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
    int cursorScreenPosY = 49 + (cursorY * 34);
    if (cursorHeldPetID > 0) {
        if (cursorY == 1 && cursorHeldY == 1) {
            cursorScreenPosY -= 4;
        }else if (cursorY == 0 && cursorHeldY == 1) {
            cursorScreenPosY += 6;
        }else if (cursorY == 0) {
            cursorScreenPosY -= 4;
        }
    }
    sprite = getOAMSprite(105);
    obj_set_pos(sprite, cursorScreenPosX, cursorScreenPosY);
}

void tickSceneStore() {

    OBJ_ATTR *sprite = getOAMSprite(105);
    frame++;

    if (cursorMem == 0 && cursorHeldPetID == 0) {
        cursorMem = getMemForCursor(0);
    }

    if (frame % 30 == 0 && cursorHeldPetID == 0) {
        cursorOpen = cursorOpen ? 0 : 1;
        cursorMem = getMemForCursor(cursorOpen);
    }

    sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | cursorMem;

    if (key_hit(KEY_B)) {
        if (cursorHeldPetID > 0) {
            cancelAction();
        } else {
            if (cursorY == 0) {
                struct Pet * hoveredPet = getPlayerTeamPet(cursorX);
                if (hoveredPet->id == 0) {
                    // Nada
                } else if (hoveredPet->id > 0) {
                    // Sell
                    sellPet(cursorX);
                    updateGameplayInfo(1);
                }
            }
            if (cursorY == 1) {
                int hoveredId = getEnemyTeamPet(cursorX)->id;
                if (hoveredId == 0) {
                    // Nada
                } else if (hoveredId > 0) {
                    // Freeze
                    struct PetSprite * ps = getPetSprite(cursorX + (cursorY * 5));
                    ps->frozen = ps->frozen ? 0 : 1;

                    if (ps->frozen) {
                        freeze(cursorX);
                    } else {
                        unfreeze(cursorX);
                    }
                }
            }
        }
        resetAnimalSpritesForStore();
        updateAnimalSprites();
        updateLabels();
    }

    if (key_hit(KEY_A) && cursorY == 0) {
        sprite = getOAMSprite(105);
        if (cursorHeldPetID == 0) {
            if (getPlayerTeamPet(cursorX)->id > 0) {
                cursorHeldX = cursorX;
                cursorHeldY = cursorY;
                cursorOpen = 0;
                cursorHeldPetID = getPlayerTeamPet(cursorHeldX)->id;
                cursorMem = getMemForPet(cursorX);
                getOAMSprite(105)->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | cursorMem;
                getPetSprite(cursorX)->visiblePet = 0;
            }
        } else {
            if (cursorHeldPetID > 100) {
                if (cursorY == 0 && getPlayerTeamPet(cursorX)->id > 0) {
                    if (buyAssignItemAtPosition(cursorHeldX, cursorX)) {
                        resolveTriggers();
                    };
                    unfreeze(cursorHeldX);
                }
                int oldX = cursorX;
                int oldY = cursorY;
                cancelAction();
                cursorY = oldY;
                cursorX = oldX;
            } else if (getPlayerTeamPet(cursorX)->id == cursorHeldPetID) {
                if (cursorX == cursorHeldX && cursorY == cursorHeldY) {
                    cancelAction();
                } else {
                    struct Pet * other = getPlayerTeamPet(cursorX);
                    struct Pet * heldPet = getPlayerTeamPet(cursorHeldX);

                    if (expToLevel(other->experience) == 3 || expToLevel(heldPet->experience) == 3) {
                        cancelAction();
                    } else {
                        int cost = -1;
                        if (cursorHeldY == 1) {
                            heldPet = getEnemyTeamPet(cursorHeldX);
                            cost = getPetCost(heldPet);
                        }

                        if (cost >= 0 && spendBankMoney(cost) == 0) {
                            cancelAction();
                        } else {
                            unfreeze(cursorHeldX);
                            buyPet(heldPet);
                            // TODO: Stacked pets probably result in level of held pet being applied to buy trigger
                            stackPets(heldPet, other);
                            int oldX = cursorX;
                            int oldY = cursorY;
                            cancelAction();
                            cursorY = oldY;
                            cursorX = oldX;
                        }
                    }

                }
            } else  {
                if (cursorHeldY == 0) {
                    swapPets(getPlayerTeamPet(cursorX), getPlayerTeamPet(cursorHeldX));
                    int oldX = cursorX;
                    int oldY = cursorY;
                    cancelAction();
                    cursorY = oldY;
                    cursorX = oldX;
                } else if (cursorHeldY == 1 && getPlayerTeamPet(cursorX)->id == 0) {
                    struct Pet * heldPet = getPlayerTeamPet(cursorHeldX);
                    int cost = -1;
                    if (cursorHeldY == 1) {
                        heldPet = getEnemyTeamPet(cursorHeldX);
                        cost = getPetCost(heldPet);
                    }

                    if (cost >= 0 && spendBankMoney(cost) == 0) {
                        cancelAction();
                    }  else {
                        unfreeze(cursorHeldX);
                        struct Pet * dest = getPlayerTeamPet(cursorX);
                        clonePet(heldPet, dest);

                        getPetSprite(cursorX)->visiblePet = 1;
                        obj_set_pos(getOAMSprite(105), -16, -16);

                        buyPet(heldPet);
                        summonPet(heldPet, dest);
                        emptyPet(heldPet);
                        resetAnimalSpritesForStore();
                        updateAnimalSprites();
                        int oldX = cursorX;
                        int oldY = cursorY;
                        cancelAction();
                        cursorY = oldY;
                        cursorX = oldX;
                        postSummonPet(dest);
                    }
                }

            }
        }
        resetAnimalSpritesForStore();
        updateAnimalSprites();
        updateLabels();
        updateGameplayInfo(1);
    }

    if (key_hit(KEY_A) && cursorY == 1) {
        struct Pet * item = getEnemyTeamPet(cursorX);

        if (cursorHeldPetID > 0) {
            cancelAction();
        } else if (item->id > 100) {
            int triggered = buyItemAtPosition(cursorX);
            if (!triggered) {
                unfreeze(cursorHeldX);
                cursorHeldX = cursorX;
                cursorHeldY = cursorY;
                cursorOpen = 0;
                cursorHeldPetID = getEnemyTeamPet(cursorHeldX)->id;
                cursorMem = getMemForPet(5+cursorX);
                getOAMSprite(105)->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | cursorMem;
                getPetSprite(5+cursorX)->visiblePet = 0;
            }
            updateGameplayInfo(1);
            updateAnimalSprites();
        } else if (item->id > 0) {
            cursorHeldX = cursorX;
            cursorHeldY = cursorY;
            cursorOpen = 0;
            cursorHeldPetID = getEnemyTeamPet(cursorHeldX)->id;
            cursorMem = getMemForPet(5+cursorX);
            getOAMSprite(105)->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | cursorMem;
            getPetSprite(5+cursorX)->visiblePet = 0;
        }
        resetAnimalSpritesForStore();
        updateAnimalSprites();
        updateLabels();
        sleep(10);
    }

    if ((key_hit(KEY_RIGHT) || key_hit(KEY_LEFT)) && (!cursorHeldPetID || (cursorHeldY == 1 && cursorY == 0) || (cursorHeldY == 0 && cursorY == 0))) {
        if (key_hit(KEY_RIGHT)) {
            cursorX += 1;
        }
        if (key_hit(KEY_LEFT)) {
            cursorX -= 1;
        }

        updateLabels();
    }

    if (key_hit(KEY_DOWN) && !cursorHeldPetID) {
        cursorY += 1;
        updateLabels();
    }

    if (key_hit(KEY_UP)) {
        cursorY -= 1;
        updateLabels();
    }

    updateCursor();

    if (key_hit(KEY_L)) {
        if (getBankMoney() >= 1) {
            spendBankMoney(1);
            sprite = getOAMSprite(100);
            obj_set_pos(sprite, 0, -2);

            sleep(10);

            sprite = getOAMSprite(100);
            obj_set_pos(sprite, 0, 0);

            sleep(5);
            randomizeStore();
            resetAnimalSpritesForStore();
            updateAnimalSprites();
            updateLabels();
            updateGameplayInfo(1);
        }
    }

    if (key_hit(KEY_R)) {
        cancelAction();
        resetAnimalSpritesForStore();
        updateAnimalSprites();
        hideLabels();
        updateGameplayInfo(0);

        sprite = getOAMSprite(101);
        obj_set_pos(sprite, 208, -2);

        sprite = getOAMSprite(105);
        obj_set_pos(sprite, -16, -16);


        endTurn();
        while (isAnimating()) {
            tickMainLoop();
        }
        setScene(1);

        for (int t = 0; t < 10; t++) {
            tickMainLoop();
        }

        sprite = getOAMSprite(101);
        obj_set_pos(sprite, 208, 0);

        for (int t = 0; t < 20; t++) {
            tickMainLoop();
            sprite = getOAMSprite(100);
            obj_set_pos(sprite, 0, -t );
            sprite = getOAMSprite(101);
            obj_set_pos(sprite, 208, -t );
        }

        for (int t = 0; t < 50; t++) {
            tickMainLoop();
        }

    }
}