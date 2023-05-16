#ifndef SUPERADVANCEPETSCLI_TRIGGERS_H
#define SUPERADVANCEPETSCLI_TRIGGERS_H
#include "globals.h"
#include "battle.h"
#include "impl.h"

void applyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
void applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
void applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);

#endif //SUPERADVANCEPETSCLI_TRIGGERS_H
