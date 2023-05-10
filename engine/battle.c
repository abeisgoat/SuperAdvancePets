#include <stdio.h>
#include "globals.h"
#include "1_pet_ant.h"
#include "2_pet_beaver.h"
#include "3_pet_cricket.h"
#include "4_pet_cricket_zombie.h"
#include <time.h>
#include <stdlib.h>

enum TriggerTransitionType {
    Junk=0,
    Health=1
};

struct TriggerTransition {
    int startPosition;
    int endPosition;
    enum TriggerTransitionType type;
};

struct Pet EmptyPet = {
        .id = 0
};

PetTeam playerTeam = {
        {},{},{},{},{}
};
PetTeam enemyTeam = {
        {},{},{},{},{}
};

void applyFaintTrigger(int usOrThem, int step, PetTeam us, PetTeam them, struct Pet * pet) {
    switch (pet->id) {
        case 1: // Ant
            antTriggerFeint(usOrThem, us, them, pet);
            break;
        case 3: // Cricket
            cricketTriggerFeint(usOrThem, us, them, pet);
            break;
    }
}

void applyBattleStartTrigger(int usOrThem, int step, PetTeam us, PetTeam them, struct Pet * pet) {
    switch (pet->id) {
        default:
            break;
    }
}

void applyBeforeAttackTrigger(int usOrThem, int step, PetTeam us, PetTeam them, struct Pet * pet) {
    switch (pet->id) {
        default:
            break;
    }
}

struct Pet * getPlayerFighter() {
    for (int i=4; i>=0; i--) {
        if (playerTeam[i].id > 0 && !isDead(&playerTeam[i])) {
            return &playerTeam[i];
        }
    }
}

struct Pet * getEnemyFighter() {
    for (int i=0; i<=4; i++) {
        if (enemyTeam[i].id > 0 && !isDead(&enemyTeam[i])) {
            return &enemyTeam[i];
        }
    }
}

void resetTeams() {
    for (int i=0; i<=4; i++) {
        playerTeam[i] = EmptyPet;
    }
    for (int i=0; i<=4; i++) {
        enemyTeam[i] = EmptyPet;
    }
}

int playerTeamSize() {
    int size = 0;
    for (int i=0; i<=4; i++) {
        if (playerTeam[i].id > 0 && !isDead(&playerTeam[i])) {
            size++;
        }
    }
    return size;
}

int enemyTeamSize() {
    int size = 0;
    for (int i=0; i<=4; i++) {
        if (enemyTeam[i].id > 0 && !isDead(&enemyTeam[i])) {
            size++;
        }
    }
    return size;
}

int isBattleOver() {
    return playerTeamSize() == 0 || enemyTeamSize() == 0 ? 1 : 0;
}

int stepForward(int step) {
    if (playerTeamSize() == 0 && enemyTeamSize() == 0) {
        printf("[Tie]\n");
        return -1;
    } else if (playerTeamSize() == 0) {
        printf("[Loss]\n");
        return -2;
    } else if (enemyTeamSize() == 0) {
        printf("[Win]\n");
        return -3;
    }

    return step + 1;
}

int battle() {
    int step = 0;
    for (int i=4; i>=0; i--) {
        if (playerTeam[i].id > 0) {
            applyBattleStartTrigger(
                    0,
                    step,
                    playerTeam,
                    enemyTeam,
                    &playerTeam[i]);
        }
    }
    for (int i=4; i>=0; i--) {
        if (enemyTeam[i].id > 0) {
            applyBattleStartTrigger(
                    0,
                    step,
                    playerTeam,
                    enemyTeam,
                    &playerTeam[i]);
        }
    }
    step = stepForward(step);
    if (step < 0) {
        return step;
    }

    struct Pet *PlayerFighter;
    struct Pet *EnemyFighter;

    printf("[Battle begin %i vs %i]\n", playerTeamSize(), enemyTeamSize());

    while (isBattleOver() == 0) {
        PlayerFighter = getPlayerFighter();
        EnemyFighter = getEnemyFighter();


        applyBeforeAttackTrigger(
                0,
                step,
            playerTeam,
            enemyTeam,
            PlayerFighter);

        applyBeforeAttackTrigger(
                1,
                step,
                enemyTeam,
                playerTeam,
                EnemyFighter);

        step = stepForward(step);
        if (step < 0) {
            return step;
        }

        printf("%i :: FIGHT! %s [+%i/+%i] vs %s [+%i/+%i]\n",
               step,
               *getPetTextByID(PlayerFighter->id)->name,
               getPetAttack(PlayerFighter),
               getPetDefence(PlayerFighter),
               *getPetTextByID(EnemyFighter->id)->name,
               getPetAttack(EnemyFighter),
               getPetDefence(EnemyFighter));

        PlayerFighter->battleModifierDefense -= getPetAttack(EnemyFighter);
        EnemyFighter->battleModifierDefense -= getPetAttack(PlayerFighter);

        printf("%i :: [>> Animate head-on attack <<]\n", step);

        if (isDead(PlayerFighter)) {
            printf("%i :: Player fighter %s died\n", step, *getPetTextByID(PlayerFighter->id)->name);
            applyFaintTrigger(
                    0,
                    step,
                    playerTeam,
                    enemyTeam,
                    PlayerFighter);
        }

        if (isDead(EnemyFighter)) {
            printf("%i :: Enemy fighter %s died\n", step, *getPetTextByID(EnemyFighter->id)->name);
            applyFaintTrigger(
                    1,
                    step,
                    enemyTeam,
                    playerTeam,
                    EnemyFighter);
        }

        step = stepForward(step);
        if (step < 0) {
            return step;
        }

        printf("%i :: Round over leaving %i vs %i\n", step, playerTeamSize(), enemyTeamSize());
    }
}

void prepareEngine() {
    srand(time(NULL));
    registerPet(1, &Ant, &AntText);
    registerPet(2, &Beaver, &BeaverText);
    registerPet(3, &Cricket, &CricketText);
    registerPet(4, &CricketZombie, &CricketZombieText);

    resetTeams();
}

void prepareTeams(int friendly[5], int enemies[5]) {
    printf("Friendly Team:\n");
    for (int i=0; i <= 4; i++) {
        if (friendly[i] > 0) {
            printf("Pet[%i] %i\n", i, friendly[i]);

            deserializePet(friendly[i], &playerTeam[i]);
        } else {
            printf("Skipped pet in %i\n", i);
            playerTeam[i] = EmptyPet;
        }
    }
    printf("Enemy Team:\n");
    for (int i=0; i <= 4; i++) {
        if (enemies[i] > 0) {
            printf("Pet[%i] %i\n", i, enemies[i]);
            deserializePet(enemies[i], &enemyTeam[i]);
        } else {
            printf("Skipped pet in %i\n", i);
            enemyTeam[i] = EmptyPet;
        }
    }
}

struct Pet * getPlayerTeamPet(int index) {
    return &playerTeam[index];
}
struct Pet * getEnemyTeamPet(int index) {
    return &enemyTeam[index];
}

/* Battle:
 * StartBattle
 * BeforeAttack
 * AfterAttack
 * Knockout
 *
 * Setup:
 * Buy
 * Sold
 * FriendSold
 * Eat
 * StartTurn
 * EndTurn
 * LevelUp
 * BuyFood
 *
 * Both:
 * Faint
 * FriendSummoned
 * Hurt
 *
 */
