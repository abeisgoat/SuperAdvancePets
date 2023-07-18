#ifndef SUPERADVANCEPETSCLI_ANIMATIONS_H
#define SUPERADVANCEPETSCLI_ANIMATIONS_H
#include "mem_manager_enums.h"
void animateToTeamPosition(int from, int to);
void resolveAnimation();
void  animateStatsToTeamPosition(int from, int to);
void  animateStatHealthToTeamPosition(int from, int to);
void  animateStatAttackToTeamPosition(int from, int to);
void  animateDamageToTeamPosition(int from, int to);
void animatePoofAtPosition(int pos);
void animateCashAtPosition(int pos);
void animateFailureAtPosition(int pos);
void animateAbilityFromTeamPosition(int from, int to);
void animateFighterAttack(struct Pet * fighterLeft, struct Pet * fighterRight);
void animateShuffleAtPosition(int from, int to);
void sleep(int frames);
void animateDeath(struct Pet * structPet);
void resolveDeaths();
void resolveSpawns();
void cleanUp(struct Pet * pet);
void animateIconToTeamPosition(int from, int to, enum UIIcon icon);
int isAnimating();
#endif //SUPERADVANCEPETSCLI_ANIMATIONS_H
