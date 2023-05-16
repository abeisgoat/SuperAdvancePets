#include "globals.h"
#include "battle.h"
#include "impl.h"

void applyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        case 1: // Ant
            antTriggerFaint(usOrThem, us, them, pet, pet, store);
            break;
        case 2: // Badger
            badgerTriggerFaint(usOrThem, us, them, pet, pet, store);
            break;
        case 3: // Cricket
            cricketTriggerFaint(usOrThem, us, them, pet, pet, store);
            break;
    }
}

void applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        default:
            break;
    }
}

void applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store) {
    switch (pet->id) {
        default:
            break;
    }
}