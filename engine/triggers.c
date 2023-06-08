#include "globals.h"
#include "battle.h"
#include "impl.h"

int getTriggerID(int id) {
    if (id > 300) {
        id = Whale.id;
    } else if (id > 200) {
        id = id - 200; // Parrot
    }
    return id;
}

int applyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    if (pet->activations > 0) return 0;

    int id = getTriggerID(pet->id);
    switch (id) {
        case 1: // Ant
            antTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 2: // Badger
            badgerTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 14: // Cricket
            cricketTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 16: // Deer
            deerTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 25: // Flamingo
            flamingoTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 29: // Hedgehog
            hedgehogTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 34: // Mammoth
            mammothTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 45: // Rat
            ratTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 47: // Rooster
            roosterTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 51: // Sheep
            sheepTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 57: // Spider
            spiderTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 62: // Turtle
            turtleTriggerFaint(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 63: // Whale
            pet->activations++;
            whaleTriggerFaint(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyHurtTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 6: // Blowfish
            blowfishTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
        case 9: // Camel
            camelTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
        case 28: // Gorilla
            return gorillaTriggerHurt(usOrThem, us, them, pet, pet, store);
        case 40: // Peacock
            peacockTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 13: // Crab
            crabTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 15: // Crocodile
            crocodileTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 18: // Dodo
            dodoTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 20: // Dolphin
            dolphinTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 33: // Leopard
            leopardTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 36: // Mosquito
            mosquitoTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 53: // Skunk
            skunkTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
        case 63: // Whale
            whaleTriggerStartOfBattle(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyBuyTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 12: // Cow
            cowTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 37: // Otter
            otterTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 42: // Pig
            pigTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 55: // Snail
            snailTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 102: // Can
            cannedFoodTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 113:
            pizzaTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 117:
            sushiTriggerBuy(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        default:
            break;
    }
    return 0;
}

int applySellTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 3:
            beaverTriggerSell(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 22:
            duckTriggerSell(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 52:
            shrimpTriggerSell(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        default:
            break;
    }
    return 0;
}


int applyEndTurnTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 5: // Bison
            bisonTriggerEndOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
        case 27: // Giraffe
            giraffeTriggerEndOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
        case 35: // Monkey
            monkeyTriggerEndOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
        case 41: // Penguin
            penguinTriggerEndOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
        case 39: // Parrot
            parrotTriggerEndOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
        default:
            break;
    }
    return 0;
}

int applyBuyAssignTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * target, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
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
        default:
            break;
    }
    return 0;
}

int applyKnockoutTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 46:
            return rhinoTriggerKnockOut(usOrThem, us, them, pet, pet, store);
    }
    return 0;
}

int applyEatsShopFoodTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 49:
            sealTriggerEatsShopFood(usOrThem, us, them, pet, pet, store);
            return 1;
        case 64:
            wormTriggerEatsShopFood(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyStartOfTurnTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 59:
            swanTriggerStartOfTurn(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyLevelUpTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 24:
            fishTriggerLevelUp(usOrThem, us, them, pet, pet, store);
            return 1;
        case 42:
            pigTriggerLevelUp(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}


int applyFriendFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * activatingPet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 38: // Ox
            oxTriggerFriendFaint(usOrThem, us, them, pet, activatingPet, store);
            return 1;
        case 50: // Shark
            sharkTriggerFriendFaint(usOrThem, us, them, pet, activatingPet, store);
            return 1;
    }
    return 0;
}

int applyFriendSummonTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * activatingPet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 19: // Dog
            dogTriggerFriendSummoned(usOrThem, us, them, pet, activatingPet, store);
            return 1;
        case 31: // Horse
            horseTriggerFriendSummoned(usOrThem, us, them, pet, activatingPet, store);
            return 1;
        case 61: // Turkey
            turkeyTriggerFriendSummoned(usOrThem, us, them, pet, activatingPet, store);
            return 1;
    }
    return 0;
}

int applyFriendAfterAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * activatingPet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 56:
            snakeTriggerAfterAttack(usOrThem, us, them, pet, activatingPet, store);
            pet->activations++;
            return 1;
    }
    return 0;
}

int applyFriendEatsTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * activatingPet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 43:
            rabbitTriggerPetEatsShopFood(usOrThem, us, them, pet, activatingPet, store);
            pet->activations++;
            return 1;
    }
    return 0;
}

int applyBuyFriendTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * activatingPet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 21:
            dragonTriggerBuyFriend(usOrThem, us, them, pet, activatingPet, store);
            pet->activations++;
            return 1;
    }
    return 0;
}

int applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    int id = getTriggerID(pet->id);
    switch (id) {
        case 7:
            boarTriggerBeforeAttack(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
        case 23:
            elephantTriggerBeforeAttack(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
    }
    return 0;
}