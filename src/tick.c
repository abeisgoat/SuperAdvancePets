#include <tonc.h>
#include <maxmod.h>
#include <stdlib.h>
#include "../engine/globals.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "structs.h"
#include "ui.h"
#include "animations.h"

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

OBJ_ATTR * getOAMSprite(int index) {
    return &obj_buffer[index];
}

void tickInit() {
    oam_init(obj_buffer, 128);
}

int screenX;
int screenY;

int screenXTarget;
int screenYTarget;
int activeScene;

struct PetSprite petSprites[12] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

struct PetSprite * getPetSprite(int index) {
    return &petSprites[index];
}

int spritePerAnimals=8;
void updateAnimalSprites() {
    OBJ_ATTR *sprite;
    int spriteCount=0;
    for (int s=0; s<12; s++) {
        int startSpriteCount = spriteCount;
        struct PetSprite * ps = &petSprites[s];

        if (ps->petPin != 0 && ps->visiblePet) {
            struct Pet *pet = getPetByPin(ps->petPin);
            int gfxMem = usePetGfxMem(pet->id, s);


            if (isItem(pet->id)) {
                ps->visibleStats = 0;
            }

            int pb = 0;

            sprite = getOAMSprite(spriteCount++);

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | ATTR2_PRIO(2) | gfxMem);

            obj_set_pos(sprite, ps->screenX, ps->screenY);

            if (getPetHealth(pet) == 0 && !isItem(pet->id)) {
//                sprite->attr1 ^= ATTR1_VFLIP;
                sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(2) | getMemFor16x16UI(UIElement_Bandaid);
            }

            if (ps->flip) {
                sprite->attr1 ^= ATTR1_HFLIP;
            }

            sprite = getOAMSprite(spriteCount++);

            if (pet->heldItem) {
                obj_set_attr(sprite,
                             ATTR0_SQUARE | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | ATTR2_PRIO(1)  | (getMemForHeldItem(pet->heldItem)));
                obj_set_pos(sprite, ps->screenX + 10, ps->screenY + 11);
            } else {
                obj_set_pos(sprite, -16, -16);
            }

            if (ps->visibleStats) {
                int lvl = expToLevel(pet->experience);
                int expRemaining = expToRemainingToLevelUp(pet->experience);
                int bottomMem = getBannerBottomForExp(expRemaining);
                int topMem = getBannerTopForLvl(lvl);
                int statOffsetY = 0;

                sprite = getOAMSprite(spriteCount++);
                obj_set_attr(sprite,
                             ATTR0_SQUARE | ATTR0_8BPP,
                             ATTR1_SIZE_16,
                             ATTR2_PALBANK(pb) | ATTR2_PRIO(2) | topMem);

                if (ps->shortStat) {
                    bottomMem = getBannerBottomForExp(4);
                    statOffsetY = 34;
                    obj_set_pos(sprite, -16, -16);
                } else {
                    obj_set_pos(sprite, ps->screenX, ps->screenY - 30 + statOffsetY);
                }

                if (ps->frozen) {
                    sprite->attr2 = ATTR2_PALBANK(pb) | ATTR2_PRIO(0) | getMemFor16x16UI(UIElement_IceBlock);
                    obj_set_pos(sprite, ps->screenX, ps->screenY - 34 + statOffsetY);
                }

                sprite = getOAMSprite(spriteCount++);

                int bannerYOffset = 0;

                if (ps->shortStat) {
                    bannerYOffset = -2;
                }

                obj_set_attr(sprite,
                             ATTR0_SQUARE | ATTR0_8BPP,
                             ATTR1_SIZE_16,
                             ATTR2_PALBANK(pb) | ATTR2_PRIO(2)  | bottomMem);
                obj_set_pos(sprite, ps->screenX, ps->screenY - 14 + bannerYOffset + statOffsetY);


                int numYOffset = 0;
                int numXOffset = 0;
                if (ps->shortStat) {
                    numYOffset += 6;
                    numXOffset = -1;
                }
                int health = getPetHealth(pet);

                sprite = getOAMSprite(spriteCount++);
                if (health >= 10) {
                    int healthTens = health / 10;

                    obj_set_attr(sprite,
                                 ATTR0_TALL | ATTR0_8BPP,
                                 ATTR1_SIZE_8,
                                 ATTR2_PALBANK(pb) | ATTR2_PRIO(2) | (getMemForNumber(healthTens)));
                    obj_set_pos(sprite, ps->screenX + 6 + numXOffset, ps->screenY - 14 + numYOffset + statOffsetY);
                } else {
                    obj_set_pos(sprite, -16,-16);
                }

                sprite = getOAMSprite(spriteCount++);

                int healthOnes = health % 10;
//            sprintf(msg, "%d", healthOnes);
//            tte_write(msg);

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | ATTR2_PRIO(2)  | (getMemForNumber(healthOnes)));
                obj_set_pos(sprite, ps->screenX + 10 + numXOffset, ps->screenY - 14 + numYOffset  + statOffsetY);

                int damage = getPetAttack(pet);

                if (ps->shortStat) {
                    numYOffset += 1;
                }

                sprite = getOAMSprite(spriteCount++);
                if (damage >= 10) {

                    int damageTens = damage / 10;

                    obj_set_attr(sprite,
                                 ATTR0_TALL | ATTR0_8BPP,
                                 ATTR1_SIZE_8,
                                 ATTR2_PALBANK(pb) | ATTR2_PRIO(2)  | (getMemForNumber(damageTens)));
                    obj_set_pos(sprite, ps->screenX + 6 + numXOffset, ps->screenY - 22 + numYOffset + statOffsetY);
                } else {
                    obj_set_pos(sprite, -16,-16);
                }

                sprite = getOAMSprite(spriteCount++);

                int damageOnes = damage % 10;

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | ATTR2_PRIO(2)  | (getMemForNumber(damageOnes)));
                obj_set_pos(sprite, ps->screenX + 10 + numXOffset, ps->screenY - 22 + numYOffset + statOffsetY);
            }
        }

        for (int s=spriteCount; s<startSpriteCount+spritePerAnimals; s++) {
            sprite = getOAMSprite(spriteCount++);
            obj_hide(sprite);
        }
    }
}

void setScene(int scene) {
    switch (scene) {
        case 0:
            screenXTarget = 16;
            screenYTarget = 0;
            break;
        case 1:
            screenXTarget = 240;
            screenYTarget = 0;
            break;
        case 2:
            screenXTarget = 240;
            screenYTarget = 96;
            break;
        case 3:
            screenXTarget = 16;
            screenYTarget = 0;
            screenX = 16;
            screenY = 96;
    }
    activeScene = scene;
}


int getScreenX() {
    return screenX;
}

int getScreenY() {
    return screenY;
}

int getScene() {
    return activeScene;
}

int moveScreenTowardsTarget() {
    int maxSpeed = 4;
    int x_diff = screenXTarget - screenX;
    int y_diff = screenYTarget - screenY;
    if (abs(x_diff) < maxSpeed) {
        screenX = screenXTarget;
    }

    if (abs(y_diff) < maxSpeed) {
        screenY = screenYTarget;
    }

    if (screenY < screenYTarget) {
        screenY +=  maxSpeed;
        return 1;
    }
    if (screenY > screenYTarget) {
        screenY -=  maxSpeed;
        return 1;
    }
    if (screenX < screenXTarget) {
        screenX +=  maxSpeed;
        return 1;
    }
    if (screenX < screenXTarget) {
        screenX -=  maxSpeed;
        return 1;
    }
    return 0;
}

void screenAnimalSprites() {
    OBJ_ATTR *sprite;
    for (int s = 0; s < 12; s++) {
        struct PetSprite *ps = &petSprites[s];
        ps->screenX = ps->worldX - screenX;
        ps->screenY = ps->worldY - screenY;

        sprite = getOAMSprite((s * spritePerAnimals));
        obj_set_pos(sprite, ps->screenX, ps->screenY);
    }
}

void refreshOAM() {
    oam_copy(oam_mem, obj_buffer, 127);
}

int r=0;
void readyTick() {
    r = 0;
    screenX = 16;
    screenY = 0;

    screenXTarget = 16;
    screenYTarget = 0;
    activeScene = 0;
}
void reset() {
    // TOOD: Make reset clear properly
    r = -1;
}
// Progress main game loop
int tickMainLoop() {
    vid_vsync();
    key_poll();
    mmFrame();

    if (moveScreenTowardsTarget()) {
        screenAnimalSprites();
        updateAnimalSprites();
    } else {
        if (getScene() == 3) {
            setScene(0);
        }
    }

    REG_BG1HOFS = screenX;
    REG_BG1VOFS = screenY;
    refreshOAM();
    return r;
}