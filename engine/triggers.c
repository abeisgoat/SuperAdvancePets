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
    }
    return 0;
}

int applyHurtTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 6: // Blowfish
            blowfishTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
        case 9:
            camelTriggerHurt(usOrThem, us, them, pet, pet, store);
            return 1;
    }
    return 0;
}

int applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        default:
            break;
    }
}

int applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 7:
            boarTriggerBeforeAttack(usOrThem, us, them, pet, pet, store);
            pet->activations++;
            return 1;
    }
}