#ifndef SUPERADVANCEPETSCLI_TRIGGERS_H
#define SUPERADVANCEPETSCLI_TRIGGERS_H
#include "globals.h"
#include "battle.h"
#include "impl.h"

int applyFaintTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
int applyBattleStartTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
int applyBeforeAttackTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
int applyHurtTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
int applyBuyTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, PetTeam store);
int applyBuyAssignTrigger(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet, struct Pet * target,  PetTeam store);
#endif //SUPERADVANCEPETSCLI_TRIGGERS_H
