#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "./engine/battle.h"
#include "engine/globals.h"

void deserializeTeam(char str[], int team[5]) {

    char *token;
    // Tokenize the string using strtok
    token = strtok(str, ",");
    int i = 0;
    while (token != NULL && i < 5) {
        team[i] = atoi(token);  // Convert token to integer
        token = strtok(NULL, ",");
        i++;
    }

    // Print the numbers
    for (i = 0; i < 5; i++) {
        printf("%d\n", team[i]);
    }
}
void main(int argc, char **argv) {
    prepareEngine();
    srand(0);

    int us[5] = {};
    int them[5] = {};

    if (strcmp(argv[1], "store") == 0) {
        srand(atoi(argv[3]));
        PetTeam dest = {{},{},{},{},{},{},{}};
        PetTeam frozen = {{},{},{},{},{},{},{}};

        int turn = atoi(argv[2]);
        randomizeStoreViaTurn(turn, 0, dest, frozen);

        for (int i=0; i<7; i++) {
            printf("%s,", serializePet(dest[i]));

        }
    } else if (strcmp(argv[1], "battle") == 0) {
        for (int i = 1; i < argc; ++i) {
            if (i == 1) {
                deserializeTeam(argv[i+1], &us);
            } else {
                deserializeTeam(argv[i+1], &them);
            }
        }
        prepareTeams(us, them);
        battle();
    }
}