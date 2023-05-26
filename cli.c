#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./engine/battle.h"

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

    int us[5] = {};
    int them[5] = {};

    for (int i = 1; i < argc; ++i)
    {
        if (i == 1) {
            deserializeTeam(argv[i], &us);
        } else {
            deserializeTeam(argv[i], &them);
        }
    }
    prepareTeams(us, them);
    battle();
}