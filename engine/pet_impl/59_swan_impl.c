
#include "../globals.h"
#include "../../src/animations.h"
#include <stdio.h>

void swanTriggerStartOfTurn(int usOrThem, PetTeam us, PetTeam them, struct Pet * selfPet, struct Pet * activatingPet, PetTeam store) {
    printf("Activated Swan trigger StartOfTurn");
    int selfPos = petPosition(usOrThem, us, them, selfPet);
    animateCashAtPosition(selfPos);
    resolveAnimation();
    addBankMoney(expToLevel(selfPet->experience));
}
