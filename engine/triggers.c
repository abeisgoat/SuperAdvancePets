#include "globals.h"
#include "battle.h"
#include "impl.h"

int applyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    if (pet->activations > 0) return 0;

    switch (pet->id) {
        case 1: // Ant
            antTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 2: // Badger
            badgerTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 3: // Cricket
            cricketTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 16:
            deerTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 29:
            hedgehogTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
    }
    return 0;
}

int applyHurtTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 6: // Blowfish
            blowfishTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
        case 9: // Camel
            camelTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
        case 28: // Gorilla
            return gorillaTriggerHurt(usOrThem, us, them, pet, pet, store);
    }
    return 0;
}

int applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        default:
            break;
    }
}

int applyBuyTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 102:
            cannedFoodTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        default:
            break;
    }
    return 0;
}

int applyBuyAssignTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * target, PetTeam store) {
    switch (pet->id) {
        case 101:
            appleTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 103:
            chiliTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 104:
            chocolateTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 105:
            cupcakeTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 106:
            garlicTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 107:
            honeyTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 108:
            meatBoneTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 109:
            melonTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 110:
            milkTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 111:
            mushroomTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 112:
            pearTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 113:
            pizzaTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 114:
            saladBowlTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 115:
            sleepingPillTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 116:
            steakTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        case 117:
            sushiTriggerBuyAssign(usOrThem, us, them, pet, target, store);
            pet->activations++;
            return 1;
        default:
            break;
    }
    return 0;
}

int applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 7:
            boarTriggerBeforeAttack(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
    }
}