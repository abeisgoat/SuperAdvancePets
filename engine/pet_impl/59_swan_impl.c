
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

//TODO(LOWPRI): Make swan animate
void swanTriggerStartOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Swan trigger StartOfTurn");
//    int selfPos = petPosition(usOrThem, us, them, selfPet);
//    animateIconToTeamPosition(selfPos, selfPos, UIIcon_Coin);
//    resolveAnimation();
    addBankMoney(expToLevel(selfPet->experience));
}
