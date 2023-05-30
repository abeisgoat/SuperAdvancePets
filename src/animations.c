#include "tick.h"
#include "structs.h"
#include "scene_battle.h"
#include "../engine/pets.h"
#include "../engine/globals.h"
#include "../engine/battle.h"
#include "stdlib.h"
#include "mem_manager.h"
#include "mem_manager_enums.h"

void sleep(int frames) {
    for (int i=0; i<frames;i++) {
        screenAnimalSprites();
        tickMainLoop();
    }
}

struct ThrowableQueue {
    int from;
    int to;
    enum UIThrowable throwable;
    int x;
    int y;
    int dx;
    int dy;
    int sprite;
};

struct ThrowableQueue animations[10] = {
        {}, {}, {}, {}, {}, {}, {}, {}, {}, {}
};
int animationLen=0;
int deaths=0;

int animateThrowableToTeamPosition(struct ThrowableQueue* anim) {
    OBJ_ATTR *sprite = getOAMSprite(anim->sprite);

    int throwableMem = loadThrowable(anim->throwable);
    obj_set_attr(sprite,
                 ATTR0_SQUARE | ATTR0_8BPP,
                 ATTR1_SIZE_8x8,
                 ATTR2_PALBANK(0) | ATTR2_PRIO(5) | throwableMem);

    if (anim->dx > anim->x) {
        anim->x++;
    }
    if (anim->dx < anim->x) {
        anim->x--;
    }


    if (anim->dy > anim->y) {
        anim->y++;
    }
    if (anim->dy < anim->y) {
        anim->y--;
    }


    obj_set_pos(sprite, anim->x, anim->y);

    if (anim->x == anim->dx && anim->y == anim->dy) {
        return 0;
    } else {
        return 1;
    }
}


void animateToTeamPosition(int from, int to) {
}

void animatePoofAtPosition(int pos) {
}

void queueThrowableToTeamPosition(int from, int to, enum UIThrowable throwable) {
    struct ThrowableQueue * anim = &animations[animationLen];
    anim->to = to;
    anim->from = from;
    anim->throwable = throwable;
    anim->x=getWorldXForPetPosition(from) - getScreenX() + 4;
    anim->dx= getWorldXForPetPosition(to) - getScreenX() + 4;
    anim->y=67;

    if (from == to) {
        anim->dy = anim->y-20;
    } else {
        anim->dy = anim->y;
    }
    animations[animationLen].sprite = 110 + animationLen;
    animationLen++;
}

void animateStatsToTeamPosition(int from, int to) {
    queueThrowableToTeamPosition(from, to, UIThrowable_Stats);
}

void animateStatHealthToTeamPosition(int from, int to) {
    queueThrowableToTeamPosition(from, to, UIThrowable_StatHealth);
}

void animateStatAttackToTeamPosition(int from, int to) {
    queueThrowableToTeamPosition(from, to, UIThrowable_StatAttack);
}

void animateDamageToTeamPosition(int from, int to) {
    queueThrowableToTeamPosition(from, to, UIThrowable_Damage);
}

void animateAbilityFromTeamPosition(int from, int to) {

}

void animateShuffleAtPosition(int from, int to) {
    screenAnimalSprites();
    updateAnimalSprites();
    while (1) {
        int hasMovement = 0;
        for (int i = 0; i < 10; i++) {
            struct Pet *pet;
            struct PetSprite *ps;

            int thisHasMovement = 0;
            if (i < 5) {
                pet = getPlayerTeamPet(i);
            } else {
                pet = getEnemyTeamPet(i - 5);
            }


            for (int s = 0; s < 12; s++) {
                ps = getPetSprite(s);
                if (ps->petPin == pet->pin) {
                    break;
                }
            }

            if (pet->pin > 0 && pet->pin == ps->petPin) {
                int idealX = getWorldXForPetPosition(i);
                if (abs(ps->worldX - idealX) > 3) {
                    if (idealX > ps->worldX) {
                        ps->worldX += 1;
                        thisHasMovement = 1;
                    }
                    if (idealX < ps->worldX) {
                        ps->worldX -= 1;
                        thisHasMovement = 1;
                    }
                } else {
                    ps->worldX = idealX;
                }
            }

            hasMovement += thisHasMovement;
        }

        if (hasMovement == 0) break;
        updateAnimalSprites();
        screenAnimalSprites();
        tickMainLoop();
    }
}

void animateDeath(struct Pet * pet) {
//    updateAnimalSprites();
    deaths++;
}

void cleanUp(struct Pet * pet) {
    struct PetSprite * ps;

    for (int s = 0; s<12; s++) {
        ps = getPetSprite(s);
        if (ps->petPin == pet->pin) {
            break;
        }
    }

    if (ps->petPin > 0 && ps->petPin == pet->pin) {
        ps->worldY = 0;
    }
}

void animateFighterAttack(struct Pet * fighterLeft, struct Pet * fighterRight) {
    struct PetSprite * leftSprite;
    struct PetSprite * rightSprite;

    for (int i=0; i<12; i++) {
        struct PetSprite * potentialSprite = getPetSprite(i);

        if (potentialSprite->petPin == fighterLeft->pin) {
            leftSprite = potentialSprite;
        }
        if (potentialSprite->petPin == fighterRight->pin) {
            rightSprite = potentialSprite;
        }
    }

    leftSprite->worldX += 5;
    rightSprite->worldX -= 5;

    sleep(30);

    leftSprite->worldX -= 5;
    rightSprite->worldX += 5;
}

void resolveDeaths() {
    if (deaths) {
        sleep(30);
    }

    for (int i=0; i<12; i++) {
        struct PetSprite *ps = getPetSprite(i);
        struct Pet *pet = getPetByPin(ps->petPin);

        if (pet->id < 100 && isDead(pet)) {
            ps->petPin = 0;
        }
        if (pet->id > 100 && pet->activations > 0) {
            ps->petPin = 0;
        }
    }
    deaths = 0;
}
void resolveAnimation() {
    while (1) {
        int in_progress=0;

        for (int a=0; a<animationLen; a++) {
            struct ThrowableQueue * anim = &animations[a];
            if (animateThrowableToTeamPosition(anim)) {
                in_progress = 1;
            }
        }
        updateAnimalSprites();
        tickMainLoop();

        if (!in_progress) break;
    }

    for (int a=0; a<animationLen; a++) {
        obj_set_pos(getOAMSprite(animations[a].sprite), -16, -16);
    }

    if (animationLen) {
        sleep(30);
    }

    animationLen = 0;
    screenAnimalSprites();
    updateAnimalSprites();
    tickMainLoop();
}