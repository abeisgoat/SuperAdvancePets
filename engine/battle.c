#include <stdio.h>
#include "globals.h"
#include "impl.h"
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
            antTriggerFaint(usOrThem, us, them, pet, pet);
            break;
        case 3: // Cricket
            cricketTriggerFaint(usOrThem, us, them, pet, pet);
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

const struct PetText * getPlayerTeamPetText(int index) {
    return getPetTextByID(playerTeam[index].id);
}
const struct PetText * getEnemyTeamPetText(int index) {
    return getPetTextByID(enemyTeam[index].id);
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
