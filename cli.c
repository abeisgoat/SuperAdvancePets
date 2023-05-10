#include "stdio.h"
#include "./engine/battle.h"

void main() {
    setupBattle();
    battle();

    int team[20] = {
                // ID H L E HE DE
                813220910,

    };

    for (int i=0; i < 20; i++) {
        printf("Team[%i] %i\n", i, team[i]);
    }
}