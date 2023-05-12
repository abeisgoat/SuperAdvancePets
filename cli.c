#include <stdio.h>
#include "./engine/battle.h"
#include "engine/globals.h"

void main() {
    prepareEngine();

    int friendly[5] = {
            1320910,
                1310910,

    };
    int enemies[5] = {
            1320910,
            1320910,

    };

    prepareTeams(friendly, enemies);
    battle();

    int friendly2[5] = {
            1320910,
            1310910,

    };
    int enemies2[5] = {
            2320910,
            1320910,

    };

    prepareTeams(friendly2, enemies2);
    battle();
}