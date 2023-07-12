#include <stdio.h>
#include "../src/mem_manager_enums.h"

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

//int main (int argc, char const *argv[]) {
//
//    printf(ANSI_COLOR_RED     "This text is RED!"     ANSI_COLOR_RESET "\n");
//    printf(ANSI_COLOR_GREEN   "This text is GREEN!"   ANSI_COLOR_RESET "\n");
//    printf(ANSI_COLOR_YELLOW  "This text is YELLOW!"  ANSI_COLOR_RESET "\n");
//    printf(ANSI_COLOR_BLUE    "This text is BLUE!"    ANSI_COLOR_RESET "\n");
//    printf(ANSI_COLOR_MAGENTA "This text is MAGENTA!" ANSI_COLOR_RESET "\n");
//    printf(ANSI_COLOR_CYAN    "This text is CYAN!"    ANSI_COLOR_RESET "\n");
//
//    return 0;
//}
void animateToTeamPosition(int from, int to) {
    printf(ANSI_COLOR_BLUE ">> Animating self from %d to %d" ANSI_COLOR_RESET "\n", from, to);
}

void animatePoofAtPosition(int pos) {
    printf(ANSI_COLOR_BLUE ">> Animating POOF at %d" ANSI_COLOR_RESET "\n", pos);
}

void animateCashAtPosition(int pos) {
    printf(ANSI_COLOR_YELLOW ">> Animating GOLD at %d" ANSI_COLOR_RESET "\n", pos);
}

void animateStatsToTeamPosition(int from, int to) {
    printf(ANSI_COLOR_CYAN ">> Animation both stats from %d to %d" ANSI_COLOR_RESET "\n", from, to);
}
void animateStatHealthToTeamPosition(int from, int to) {
    printf(ANSI_COLOR_GREEN ">> Animation health up from %d to %d" ANSI_COLOR_RESET "\n", from, to);
}
void animateStatAttackToTeamPosition(int from, int to) {
    printf(ANSI_COLOR_YELLOW ">> Animation attack up from %d to %d" ANSI_COLOR_RESET "\n", from, to);
}
void animateDamageToTeamPosition(int from, int to) {
    printf(ANSI_COLOR_RED ">> Animation damage from %d to %d" ANSI_COLOR_RESET "\n", from, to);
}
void animateIconToTeamPosition(int from, int to, enum UIIcon icon) {
    printf(ANSI_COLOR_RED ">> Animation icon %d from %d to %d" ANSI_COLOR_RESET "\n", icon, from, to);
}

void animateAbilityFromTeamPosition(int from, int to) {

}

void resolveAnimation() {

}

void animateShuffleAtPosition() {

}

void animateDeath() {

}

void resolveDeaths() {

}

void resolveSpawns() {}

void animateFighterAttack() {

}

void cleanUp() {

}

void sleep(int frames) {}

int isAnimating() {
    return 0;
}