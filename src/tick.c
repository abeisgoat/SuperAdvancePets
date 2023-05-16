#include <tonc.h>
#include <maxmod.h>
#include "../engine/globals.h"
#include "mem_manager.h"
#include "../engine/battle.h"
#include "structs.h"

OBJ_ATTR obj_buffer[128];
OBJ_AFFINE *obj_aff_buffer= (OBJ_AFFINE*)obj_buffer;

OBJ_ATTR * getOAMSprite(int index) {
    return &obj_buffer[index];
}

void tickInit() {
    oam_init(obj_buffer, 128);
}

int screenX = -1;
int screenY = 0;

int screenXTarget = 0;
int screenYTarget = 0;
int activeScene = 0;
float screenMomentum = 0;

struct PetSprite petSprites[12] = {{}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}, {}};

struct PetSprite * getPetSprite(int index) {
    return &petSprites[index];
}

void updateAnimalSprites() {
//    for (int s=0; s<10; s++) {
//        struct PetSprite *ps = &petSprites[s];
//
//        if (ps->pet != 0) {
//            unusePetGfxMem(ps->pet->id);
//        }
//    }
    OBJ_ATTR *sprite;
    int spriteCount=0;
    for (int s=0; s<12; s++) {
        int startSpriteCount = spriteCount;
        struct PetSprite * ps = &petSprites[s];

        if (ps->petPin != 0 && ps->visiblePet) {
            struct Pet *pet = getPetByPin(ps->petPin);

            int gfxMem = usePetGfxMem(pet->id);

            u32 tid = gfxMem, pb = 0;
            sprite = getOAMSprite(++spriteCount);

            obj_set_attr(sprite,
                         ATTR0_SQUARE | ATTR0_8BPP,
                         ATTR1_SIZE_16,
                         ATTR2_PALBANK(pb) | ATTR2_PRIO(3)  | tid);

            obj_set_pos(sprite, ps->screenX, ps->screenY);

            if (ps->flip) {
                sprite->attr1 ^= ATTR1_HFLIP;
            }

            if (ps->visibleStats) {
                sprite = getOAMSprite(++spriteCount);

                int lvl = expToLevel(pet->experience);

                obj_set_attr(sprite,
                             ATTR0_SQUARE | ATTR0_8BPP,
                             ATTR1_SIZE_16,
                             ATTR2_PALBANK(pb) | (getBannerTopForLvl(lvl)));
                obj_set_pos(sprite, ps->screenX, ps->screenY - 30);

                sprite = getOAMSprite(++spriteCount);;

                int expRemaining = expToRemainingToLevelUp(pet->experience);

                obj_set_attr(sprite,
                             ATTR0_SQUARE | ATTR0_8BPP,
                             ATTR1_SIZE_16,
                             ATTR2_PALBANK(pb) | (getBannerBottomForExp(expRemaining)));
                obj_set_pos(sprite, ps->screenX, ps->screenY - 14);

                int health = getPetHealth(pet);

                sprite = getOAMSprite(++spriteCount);
                if (health >= 10) {
                    int healthTens = health / 10;

                    obj_set_attr(sprite,
                                 ATTR0_TALL | ATTR0_8BPP,
                                 ATTR1_SIZE_8,
                                 ATTR2_PALBANK(pb) | (getMemForNumber(healthTens)));
                    obj_set_pos(sprite, ps->screenX + 6, ps->screenY - 14);
                } else {
                    obj_set_pos(sprite, -16,-16);
                }

                sprite = getOAMSprite(++spriteCount);

                int healthOnes = health % 10;
//            sprintf(msg, "%d", healthOnes);
//            tte_write(msg);

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | (getMemForNumber(healthOnes)));
                obj_set_pos(sprite, ps->screenX + 10, ps->screenY - 14);

                int damage = getPetAttack(pet);

                sprite = getOAMSprite(++spriteCount);
                if (damage >= 10) {

                    int damageTens = damage / 10;

                    obj_set_attr(sprite,
                                 ATTR0_TALL | ATTR0_8BPP,
                                 ATTR1_SIZE_8,
                                 ATTR2_PALBANK(pb) | (getMemForNumber(damageTens)));
                    obj_set_pos(sprite, ps->screenX + 6, ps->screenY - 22);
                } else {
                    obj_set_pos(sprite, -16,-16);
                }

                sprite = getOAMSprite(++spriteCount);

                int damageOnes = damage % 10;

                obj_set_attr(sprite,
                             ATTR0_TALL | ATTR0_8BPP,
                             ATTR1_SIZE_8,
                             ATTR2_PALBANK(pb) | (getMemForNumber(damageOnes)));
                obj_set_pos(sprite, ps->screenX + 10, ps->screenY - 22);
            }
        }

        for (int s=spriteCount; s<startSpriteCount+7; s++) {
            sprite = getOAMSprite(++spriteCount);
            obj_set_pos(sprite, -16, -16);
        }
    }
}

void setScene(int scene) {
    switch (scene) {
        case 0:
            screenXTarget = 0;
            screenYTarget = 0;
            break;
        case 1:
            screenXTarget = 230;
            screenYTarget = 0;
            break;
        case 2:
            screenXTarget = 230;
            screenYTarget = 90;
            break;
        case 3:
            screenXTarget = 0;
            screenYTarget = 90;
    }
    activeScene = scene;
}

int getScene() {
    return activeScene;
}

int moveScreenTowardsTarget() {
    int maxSpeed = 4;
    int x_diff = screenXTarget - screenX;
    int y_diff = screenYTarget - screenY;
    int x_slow = x_diff && (x_diff > 0 && x_diff < maxSpeed || x_diff < 0 && x_diff > -maxSpeed);
    int y_slow = y_diff && (y_diff > 0 && y_diff < maxSpeed || y_diff < 0 && y_diff > -maxSpeed);

    if (x_slow || y_slow) {
        screenMomentum *= 0.5;
    }

    if (screenMomentum > maxSpeed) {
        screenMomentum = maxSpeed;
    }
    if (screenMomentum < -maxSpeed) {
        screenMomentum = -maxSpeed;
    }

    if (screenXTarget > screenX) {
        screenMomentum += 0.1;
        screenX += screenMomentum;
        return 1;
    }else if (screenXTarget < screenX) {
        screenMomentum -= 0.1;
        screenX += screenMomentum;
        return 1;
    }else if (screenYTarget > screenY) {
        screenMomentum += 0.1;
        screenY += screenMomentum;
        return 1;
    }else if (screenYTarget < screenY) {
        screenMomentum -= 0.1;
        screenY += screenMomentum;
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

        sprite = getOAMSprite(1 + (s * 7));
        obj_set_pos(sprite, ps->screenX, ps->screenY);
    }
}

// Progress main game loop
void tickMainLoop() {
    vid_vsync();
    key_poll();
    mmFrame();

    if (moveScreenTowardsTarget()) {
        screenAnimalSprites();
        updateAnimalSprites();
    }

    REG_BG1HOFS = screenX;
    REG_BG1VOFS = screenY;

    oam_copy(oam_mem, obj_buffer, 127);
}