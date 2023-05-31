#include <stdio.h>
#include "globals.h"
#include "impl.h"
#include "../src/animations.h"
#include "triggers.h"
#include <time.h>
#include <stdlib.h>

PetTeam backedUpTeam = {
        {}, {}, {}, {}, {}
};

PetTeam playerTeam = {
        {},{},{},{},{}
};
PetTeam enemyTeam = {
        {},{},{},{},{}, {}, {}
};
PetTeam storeTeam = {};

void printTeam() {
    printf("Player Team: ");
    for (int i=0; i<=4; i++) {
        if (playerTeam[i].id == 0) {
            printf("Empty ");
        } else {
            printf("%s ", *getPetTextByID(playerTeam[i].id)->name);
        }
    }
    printf("\n");
}

void resetTeams() {
    for (int i=0; i<=4; i++) {
        emptyPet(&playerTeam[i]);
    }
    for (int i=0; i<=4; i++) {
        emptyPet(&enemyTeam[i]);
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

int getPetCost(struct Pet * pet) {
    if (pet->cost >= 0) {
        return pet->cost;
    }
    return 3;
}

int buyItemAtPosition(int index) {
    struct Pet *item = &enemyTeam[index];
    int cost = getPetCost(item);


    int trigger = applyBuyTrigger(0, playerTeam, enemyTeam, item, enemyTeam);

    if (!trigger) return 0;
    spendBankMoney(cost);
    resolveDeaths();
    resolveAnimation();
    emptyPet(item);
    return 1;
}

int buyAssignItemAtPosition(int index, int target) {
    struct Pet *item = &enemyTeam[index];
    struct Pet *activatingPet = &playerTeam[target];

    int cost = getPetCost(item);

    if (getBankMoney() < cost) {
        return 0;
    }

    int trigger = applyBuyAssignTrigger(0, playerTeam, enemyTeam, item, activatingPet, enemyTeam);

    if (!trigger) return 0;
    spendBankMoney(cost);

    trigger += applyEatsShopFoodTrigger(0, playerTeam, enemyTeam, activatingPet, enemyTeam);

    resolveDeaths();
    resolveAnimation();
    emptyPet(item);
    return 1;
}

int stepForward(int step) {
    resolveAnimation();
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

void resolveTriggers() {
    int hasTrigger = 1;
    while (hasTrigger) {
        hasTrigger = 0;
        for (int i = 0; i < 10; i++) {
            struct Pet *pet = getPetByPosition(0, playerTeam, enemyTeam, i);

            if (isHurt(pet) && !isDead(pet)) {
                if (getPetUsOrThem(playerTeam, enemyTeam, pet) == 0) {
                    hasTrigger += applyHurtTrigger(
                            0,
                            playerTeam,
                            enemyTeam,
                            pet, storeTeam);
                } else {
                    hasTrigger += applyHurtTrigger(
                            1,
                            enemyTeam,
                            playerTeam,
                            pet, storeTeam);
                }
                pet->hurt--;
            }

            if (isDead(pet)) {
                animateDeath(pet);
                if (getPetUsOrThem(playerTeam, enemyTeam, pet) == 0) {
                    hasTrigger += applyFaintTrigger(
                            0,
                            playerTeam,
                            enemyTeam,
                            pet, storeTeam);
                } else {
                    hasTrigger += applyFaintTrigger(
                            1,
                            enemyTeam,
                            playerTeam,
                            pet, storeTeam);
                }

                resolveAnimation();
            }
        }
    }

    resolveDeaths();
    for (int i=0; i<10; i++) {
        struct Pet *pet = getPetByPosition(0, playerTeam, enemyTeam, i);
        if (isDead(pet)) {
            cleanUp(pet);
            emptyPet(pet);

        }
    }
}

void backupTeam() {
    for (int i=0; i<7; i++) {
        clonePet(&playerTeam[i], &backedUpTeam[i]);
    }
}

void restoreTeam() {
    for (int i=0; i<7; i++) {
        clonePet(&backedUpTeam[i], &playerTeam[i]);
    }
}

void endTurn() {
    for (int i=0; i<=4; i++) {
        applyEndTurnTrigger(0, playerTeam, enemyTeam, &playerTeam[i], enemyTeam);
    }
    resolveTriggers();
}

void sellPet(int index) {
    struct Pet * pet = getPlayerTeamPet(index);
    addBankMoney(expToLevel(pet->experience));
    applySellTrigger(0, playerTeam, enemyTeam, pet, enemyTeam);
    emptyPet(pet);
    resolveTriggers();
}

int lastResult;

int getLastResult() {
    return lastResult;
}

int battle() {
    int step = 0;
    for (int i=0; i<=4;i++) {
        if (playerTeam[i].id > 0) {
            applyBattleStartTrigger(
                    0,
                    playerTeam,
                    enemyTeam,
                    &playerTeam[i],
                    storeTeam);
        }
    }

    for (int i=0; i<=4;i++) {
        if (enemyTeam[i].id > 0) {
            applyBattleStartTrigger(
                    1,
                    enemyTeam,
                    playerTeam,
                    &enemyTeam[i],
                    storeTeam);
        }
    }

    resolveTriggers();

    step = stepForward(step);
    if (step < 0) {
        lastResult = step;
        return step;
    }

    struct Pet *PlayerFighter;
    struct Pet *EnemyFighter;

    printf("[Battle begin %i vs %i]\n", playerTeamSize(), enemyTeamSize());

    while (isBattleOver() == 0) {
        int playerHasPet = shuffleRightUntilPet(playerTeam);
        int enemyHasPet = shuffleLeftUntilPet(enemyTeam);
        animateShuffleAtPosition(0, 0);
        resolveAnimation();

        sleep(30);

        if (playerHasPet != 2) {
            printf("Player has no pet. Battle over.");
            break;
        }
        if (enemyHasPet != 2) {
            printf("Enemy has no pet. Battle over.");
            break;
        }


        PlayerFighter = getRightMostPet(playerTeam);
        EnemyFighter = getLeftMostPet(enemyTeam);

        applyBeforeAttackTrigger(
                0,
            playerTeam,
            enemyTeam,
            PlayerFighter, storeTeam);

        applyBeforeAttackTrigger(
                1,
                enemyTeam,
                playerTeam,
                EnemyFighter, storeTeam);

        step = stepForward(step);
        if (step < 0) {
            lastResult = step;
            return step;
        }

        printf("%i :: FIGHT! %s [+%i/+%i] vs %s [+%i/+%i]\n",
               step,
               *getPetTextByID(PlayerFighter->id)->name,
               getPetAttack(PlayerFighter),
               getPetHealth(PlayerFighter),
               *getPetTextByID(EnemyFighter->id)->name,
               getPetAttack(EnemyFighter),
               getPetHealth(EnemyFighter));

        printf("%i :: [>> Animate head-on attack <<]\n", step);
        animateFighterAttack(PlayerFighter, EnemyFighter);
        resolveAnimation();

        int playerAttack = getPetAttack(PlayerFighter);
        int enemyAttack = getPetAttack(EnemyFighter);
        damagePet(1, enemyTeam, playerTeam, storeTeam, PlayerFighter, enemyAttack);
        damagePet(0, playerTeam, enemyTeam, storeTeam, EnemyFighter, playerAttack);
        resolveAnimation();
        sleep(30);

        resolveTriggers();

        step = stepForward(step);
        if (step < 0) {
            lastResult = step;
            return step;
        }

        printf("%i :: Round over leaving %i vs %i\n", step, playerTeamSize(), enemyTeamSize());
    }
}

void prepareEngine() {
    srand(time(NULL));
    registerPet(Ant.id, &Ant, &AntText);
    registerPet(Badger.id, &Badger, &BadgerText);
    registerPet(Beaver.id, &Beaver, &BeaverText);
    registerPet(Bee.id, &Bee, &BeeText);
    registerPet(Bison.id, &Bison, &BisonText);
    registerPet(Blowfish.id, &Blowfish, &BlowfishText);
    registerPet(Boar.id, &Boar, &BoarText);
    registerPet(Bus.id, &Bus, &BusText);
    registerPet(Camel.id, &Camel, &CamelText);
    registerPet(Cat.id, &Cat, &CatText);
    registerPet(Chick.id, &Chick, &ChickText);
    registerPet(Cow.id, &Cow, &CowText);
    registerPet(Crab.id, &Crab, &CrabText);
    registerPet(Cricket.id, &Cricket, &CricketText);
    registerPet(Crocodile.id, &Crocodile, &CrocodileText);
    registerPet(Deer.id, &Deer, &DeerText);
    registerPet(DirtyRat.id, &DirtyRat, &DirtyRatText);
    registerPet(Dodo.id, &Dodo, &DodoText);
    registerPet(Dog.id, &Dog, &DogText);
    registerPet(Dolphin.id, &Dolphin, &DolphinText);
    registerPet(Dragon.id, &Dragon, &DragonText);
    registerPet(Duck.id, &Duck, &DuckText);
    registerPet(Elephant.id, &Elephant, &ElephantText);
    registerPet(Fish.id, &Fish, &FishText);
    registerPet(Flamingo.id, &Flamingo, &FlamingoText);
    registerPet(Fly.id, &Fly, &FlyText);
    registerPet(Giraffe.id, &Giraffe, &GiraffeText);
    registerPet(Gorilla.id, &Gorilla, &GorillaText);
    registerPet(Hedgehog.id, &Hedgehog, &HedgehogText);
    registerPet(Hippo.id, &Hippo, &HippoText);
    registerPet(Horse.id, &Horse, &HorseText);
    registerPet(Kangaroo.id, &Kangaroo, &KangarooText);
    registerPet(Leopard.id, &Leopard, &LeopardText);
    registerPet(Mammoth.id, &Mammoth, &MammothText);
    registerPet(Monkey.id, &Monkey, &MonkeyText);
    registerPet(Mosquito.id, &Mosquito, &MosquitoText);
    registerPet(Otter.id, &Otter, &OtterText);
    registerPet(Ox.id, &Ox, &OxText);
    registerPet(Parrot.id, &Parrot, &ParrotText);
    registerPet(Peacock.id, &Peacock, &PeacockText);
    registerPet(Penguin.id, &Penguin, &PenguinText);
    registerPet(Pig.id, &Pig, &PigText);
    registerPet(Rabbit.id, &Rabbit, &RabbitText);
    registerPet(Ram.id, &Ram, &RamText);
    registerPet(Rat.id, &Rat, &RatText);
    registerPet(Rhino.id, &Rhino, &RhinoText);
    registerPet(Rooster.id, &Rooster, &RoosterText);
    registerPet(Scorpion.id, &Scorpion, &ScorpionText);
    registerPet(Seal.id, &Seal, &SealText);
    registerPet(Shark.id, &Shark, &SharkText);
    registerPet(Sheep.id, &Sheep, &SheepText);
    registerPet(Shrimp.id, &Shrimp, &ShrimpText);
    registerPet(Skunk.id, &Skunk, &SkunkText);
    registerPet(Sloth.id, &Sloth, &SlothText);
    registerPet(Snail.id, &Snail, &SnailText);
    registerPet(Snake.id, &Snake, &SnakeText);
    registerPet(Spider.id, &Spider, &SpiderText);
    registerPet(Squirrel.id, &Squirrel, &SquirrelText);
    registerPet(Swan.id, &Swan, &SwanText);
    registerPet(Tiger.id, &Tiger, &TigerText);
    registerPet(Turkey.id, &Turkey, &TurkeyText);
    registerPet(Turtle.id, &Turtle, &TurtleText);
    registerPet(Whale.id, &Whale, &WhaleText);
    registerPet(Worm.id, &Worm, &WormText);
    registerPet(ZombieCricket.id, &ZombieCricket, &ZombieCricketText);
    registerPet(ZombieFly.id, &ZombieFly, &ZombieFlyText);

    registerFood(Apple.id, &Apple, &AppleText);
    registerFood(CannedFood.id, &CannedFood, &CannedFoodText);
    registerFood(Chili.id, &Chili, &ChiliText);
    registerFood(Chocolate.id, &Chocolate, &ChocolateText);
    registerFood(Cupcake.id, &Cupcake, &CupcakeText);
    registerFood(Garlic.id, &Garlic, &GarlicText);
    registerFood(Honey.id, &Honey, &HoneyText);
    registerFood(MeatBone.id, &MeatBone, &MeatBoneText);
    registerFood(Melon.id, &Melon, &MelonText);
    registerFood(Milk.id, &Milk, &MilkText);
    registerFood(Mushroom.id, &Mushroom, &MushroomText);
    registerFood(Pear.id, &Pear, &PearText);
    registerFood(Pizza.id, &Pizza, &PizzaText);
    registerFood(SaladBowl.id, &SaladBowl, &SaladBowlText);
    registerFood(SleepingPill.id, &SleepingPill, &SleepingPillText);
    registerFood(Steak.id, &Steak, &SteakText);
    registerFood(Sushi.id, &Sushi, &SushiText);


    resetTeams();
}

void forceStore(int store[7]) {
    for (int i = 0; i < 7; i++) {
        emptyPet(&enemyTeam[i]);
        if (store[i] > 0) {
            clonePet(getPetByID(store[i]), &enemyTeam[i]);
        }
    }
}

void randomizeStore() {
    randomizeStoreViaTurn(getTurn(), 1, enemyTeam);
}

void prepareTeams(int friendly[5], int enemies[5]) {
    printf("Friendly Team:\n");
    for (int i=0; i <= 4; i++) {
        if (friendly[i] > 0) {
            printf("Pet[%i] %i\n", i, friendly[i]);

            deserializePet(friendly[i], &playerTeam[i]);
        } else {
            printf("Skipped pet in %i\n", i);
            emptyPet(&playerTeam[i]);
        }
    }
    printf("Enemy Team:\n");
    for (int i=0; i <= 4; i++) {
        if (enemies[i] > 0) {
            printf("Pet[%i] %i\n", i, enemies[i]);
            deserializePet(enemies[i], &enemyTeam[i]);
        } else {
            printf("Skipped pet in %i\n", i);
            emptyPet(&enemyTeam[i]);
        }
    }
}

struct Pet * getStoreTeamPet(int index) {
    return &storeTeam[index];
}

struct Pet * getPlayerTeamPet(int index) {
    return &playerTeam[index];
}
struct Pet * getEnemyTeamPet(int index) {
    return &enemyTeam[index];
}

const struct PetText * getPlayerTeamPetText(int index) {
    return getPetTextByID(playerTeam[index].id);
}
const struct PetText * getEnemyTeamPetText(int index) {
    return getPetTextByID(enemyTeam[index].id);
}

struct Pet * getPetByPin(int pin) {
    for (int i=0; i<7; i++) {
        if (playerTeam[i].pin == pin) {
            return &playerTeam[i];
        }
        if (enemyTeam[i].pin == pin) {
            return &enemyTeam[i];
        }
    }
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
