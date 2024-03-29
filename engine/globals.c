#include "pets.h"
#include "../src/animations.h"
#include "triggers.h"
#include "food_impl/118_peanuts_impl.h"
#include "../src/tick.h"
#include "food_impl/119_coconut_impl.h"
#include <stdio.h>
#include <stdlib.h>

int isHurt(struct Pet *pet) {
    return pet->hurt > 0;
}

int isEmptyish(struct Pet *pet) {
    return pet->id == 0 || isDead(pet);
}

int isDead(struct Pet *pet) {
    return pet->id > 0 && (pet->health + pet->battleModifierHealth) <= 0;
}

int expToLevel(int exp) {
    if (exp >= 5) {
        return 3;
    }
    if (exp >= 2) {
        return 2;
    }
    return 1;
}

int expToRemainingToLevelUp(int exp) {
    if (exp >=5) {
        exp = 5;
    }

    if (exp >= 2) {
        return exp - 2;
    }else if (exp > 0) {
        return exp + 1;
    }

    return 0;
}

struct Pet EmptyPet = {
        .id = 0,
        .health = 0,
        .attack = 0,
        .experience = 0,
        .battleModifierHealth = 0,
        .battleModifierAttack = 0,
        .heldItem = 0,
        .activations=0,
        .pin=0,
        .hurt=0,
        .cost=-1
};

struct Pet * randomOtherTeamMember(PetTeam team, struct Pet * exclude) {
    int start = rand() % 5;
    for (int s=start; s < start+5; s++) {
        int as = s % 5;
        if (team[as].id > 0 && !isDead(&team[as]) && &team[as] != exclude) {
            return &team[as];
        }
    }
    return &EmptyPet;
}

struct Pet * pets[100] = {};
const struct PetText * petTexts[100] = {};
struct Pet * foods[20] = {};
const struct PetText * foodTexts[100] = {};

struct Pet * tier1Pets[10] = {};
int tier1PetsLen = 2;
int tier1PetsFullness = 0;

struct Pet * tier1Foods[2] = {};
int tier1FoodsLen = 2;
int tier1FoodFullness = 0;

struct Pet * tier2Pets[10] = {};
int tier2PetsLen = 0;
int tier2PetsFullness = 0;

struct Pet * tier2Foods[3] = {};
int tier2FoodsLen = 3;
int tier2FoodFullness = 0;

struct Pet * tier3Pets[10] = {};
int tier3PetsLen = 11;
int tier3PetsFullness = 0;

struct Pet * tier3Foods[2] = {};
int tier3FoodsLen = 2;
int tier3FoodFullness = 0;

struct Pet * tier4Pets[12] = {};
int tier4PetsLen = 11;
int tier4PetsFullness = 0;

struct Pet * tier4Foods[2] = {};
int tier4FoodsLen = 2;
int tier4FoodFullness = 0;

struct Pet * tier5Pets[8] = {};
int tier5PetsLen = 8;
int tier5PetsFullness = 0;

struct Pet * tier5Foods[3] = {};
int tier5FoodsLen = 3;
int tier5FoodFullness = 0;

struct Pet * tier6Pets[9] = {};
int tier6PetsLen = 9;
int tier6PetsFullness = 0;

struct Pet * tier6Foods[4] = {};
int tier6FoodsLen = 4;
int tier6FoodFullness = 0;

struct Pet swapperPet = {};

void registerPet(int petId, const struct Pet * pet, const struct PetText * petText) {
    pets[petId] = pet;
    petTexts[petId] = petText;
    switch (pet->tier) {
        case 1:
            tier1Pets[tier1PetsFullness++] = pet;
            break;
        case 2:
            tier2Pets[tier2PetsFullness++] = pet;

            break;
        case 3:
            tier3Pets[tier3PetsFullness++] = pet;

            break;
        case 4:
            tier4Pets[tier4PetsFullness++] = pet;

            break;
        case 5:
            tier5Pets[tier5PetsFullness++] = pet;

            break;
        case 6:
            tier6Pets[tier6PetsFullness++] = pet;

            break;
    }

//    printf("ID %d, TIER %d, F %d\n", petId, pet->tier, fullness);
}

void registerFood(int petId, const struct Pet * pet, const struct PetText * petText) {
    foods[petId - 101] = pet;
    foodTexts[petId - 101] = petText;

    switch (pet->tier) {
        case 1:
            tier1Foods[tier1FoodFullness++] = pet;
            break;
        case 2:
            tier2Foods[tier2FoodFullness++] = pet;
            break;
        case 3:
            tier3Foods[tier3FoodFullness++] = pet;
            break;
        case 4:
            tier4Foods[tier4FoodFullness++] = pet;
            break;
        case 5:
            tier5Foods[tier5FoodFullness++] = pet;
            break;
        case 6:
            tier6Foods[tier6FoodFullness++] = pet;
            break;
    }
}

int isItem(int id) {
    return id > 100 && id < 200;
}

int getRemappedId(int id) {
    if (id > 300) {
        return Whale.id;
    } else if (id > 200) {
        return Parrot.id;
    }
    return id;
}
const struct PetText* getPetTextByID(int petId) {
    return petTexts[getRemappedId(petId)];
}

struct Pet * getPetByID(int petId) {
    petId = getRemappedId(petId);
    if (!isItem(petId)) {
        return pets[petId];
    } else {
        return foods[petId-101];
    }
}

int storePosition(PetTeam store, struct Pet *pet) {
    for (int i=0; i<=7; i++) {
        if (&store[i] == pet) {
            return 100+i;
        }
    }
    return -1;
}

struct Pet * getPetByPosition(int usOrThem, PetTeam us, PetTeam them, int pos) {
    if (pos > 9 || pos < 0) {
        return &EmptyPet;
    }

    if (usOrThem == 0) {
        if (pos < 5) {
            return &us[pos];
        } else {
            return &them[pos-5];
        }
    } else {
        if (pos < 5) {
            return &them[pos];
        } else {
            return &us[pos-5];
        }
    }
}

struct Pet * getFriendByPosition(int usOrThem, PetTeam us, int pos) {
    if (pos > 9 || pos < 0) {
        return &EmptyPet;
    }

    if (usOrThem == 0) {
        if (pos < 5) {
            return &us[pos];
        } else {
            return &EmptyPet;
        }
    } else {
        if (pos < 5) {
            return &EmptyPet;
        } else {
            return &us[pos-5];
        }
    }
}


int getLastEnemyTeamPosition(int usOrThem, PetTeam us, PetTeam them) {
    if (usOrThem == 0) {
        for (int i=4; i>=0; i--) {
            if (them[i].id > 0 && !isDead(&them[i])) {
                return 5+i;
            }
        }
    }
    if (usOrThem == 1) {
        for (int i=0; i<=4; i++) {
            if (them[i].id > 0 && !isDead(&them[i])) {
                return i;
            }
        }
    }
    return -1;
}

int petTeamPosition(int usOrThem, PetTeam us, struct Pet * pet) {
    for (int i=0; i<=4; i++) {
        if (usOrThem == 0) {
            if (&us[4-i] == pet) {
                return 4-i;
            }
        } else {
            if (&us[i] == pet) {
                return i;
            }
        }
    }
    return -1;
}

int petPosition(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet) {
    for (int i=0; i<=4; i++) {
        if (usOrThem == 0) {
            if (&us[i] == pet) {
                return i;
            }
        } else {
            if (&them[i] == pet) {
                return i;
            }
        }
    }
    for (int i=0; i<=4; i++) {
        if (usOrThem == 1) {
            if (&us[i] == pet) {
                return i + 5;
            }
        } else {
            if (&them[i] == pet) {
                return i + 5;
            }
        }
    }

    return -1;
}

int getPetAttack(struct Pet *pet) {
    int attack =pet->attack + pet->battleModifierAttack;
    if (attack < 0) return 0;
    if (attack > 50) return 50;
    return attack;
}
int getPetHealth(struct Pet *pet) {
    int health = pet->health + pet->battleModifierHealth;
    if (health < 0) return 0;
    if (health > 50) return 50;
    return health;
}

void clonePet(struct Pet * src, struct Pet * dest) {
    dest->id = src->id;
    dest->attack = src->attack;
    dest->health = src->health;
    dest->battleModifierHealth = src->battleModifierHealth;
    dest->battleModifierAttack = src->battleModifierAttack;
    dest->experience = src->experience;
    dest->heldItem = src->heldItem;
    dest->tier = src->tier;
    dest->pin = src->pin;
    dest->activations = src->activations;
    dest->hurt = src->hurt;
}

void emptyPet(struct Pet * dest) {
    clonePet(&EmptyPet, dest);
}

void swapPets(struct Pet * src, struct Pet * dest) {
    clonePet(src, &swapperPet);
    clonePet(dest, src);
    clonePet(&swapperPet, dest);
    emptyPet(&swapperPet);
}


struct Pet * getRightMostPet(PetTeam team) {
    for (int i=4; i>=0; i--) {
        if (team[i].id > 0 && !isDead(&team[i])) {
            return &team[i];
        }
    }
    return &EmptyPet;
}

struct Pet * getLeftMostPet(PetTeam team) {
    for (int i=0; i<=4; i++) {
        if (team[i].id > 0 && !isDead(&team[i])) {
            return &team[i];
        }
    }
    return &EmptyPet;
}

int makeRoomLeftAt(PetTeam team, int index) {
    int firstLeftEmpty = -1;
    for (int i=index; i>=0; i--) {
        printf("index: %d == %d\n", i, team[i].id);
        if (team[i].id == 0 || isDead(&team[i])) {
            firstLeftEmpty = i;
            break;
        }
    }
    printf("first empty left is %d %d\n", firstLeftEmpty, index);
    if (firstLeftEmpty == -1) return 0;
    if (index == firstLeftEmpty) return 1;

    for (int i=firstLeftEmpty+1; i < 5; i++) {
        if (team[i-1].id == 0 && team[i].id != 0) {
            clonePet(&team[i], &team[i-1]);
            emptyPet(&team[i]);
            printf(">>> left shuffling %d to %d\n", i, i-1);
        }
    }

    int success = 0;

    if (team[index].id == 0) {
        success = 1;
    }

    return success;
}

int makeRoomRightAt(PetTeam team, int index) {
    int firstRightEmpty = -1;
    for (int i=index; i<5; i++) {
        if (isEmptyish(&team[i])) {
            firstRightEmpty = i;
            break;
        }
    }
    printf("first empty right is %d %d\n", firstRightEmpty, index);

    if (firstRightEmpty == -1) return 0;
    if (index == firstRightEmpty) return 1;

    for (int i=firstRightEmpty-1; i >= 0; i--) {
        if (team[i+1].id == 0 && team[i].id != 0) {
            clonePet(&team[i], &team[i+1]);
            emptyPet(&team[i]);
            printf(">>> shuffling %d to %d\n", i, i+1);
        }
    }

    int success = 0;

    if (team[index].id == 0) {
        success = 1;
    }

    return success;
}

int tryToMakeRoom(int usOrThem, PetTeam team, int index) {
    printf("trying to make room %d\n", index);
    int success;
    if (usOrThem == 0) {
        success = makeRoomLeftAt(team, index);
        if (!success) {
            success = makeRoomRightAt(team, index);
        }
    } else {
        success = makeRoomRightAt(team, index);
        if (!success) {
            success = makeRoomLeftAt(team, index);
        }
    }

    return success;
}

int shuffleRightOnce(PetTeam team) {
    int shuffled = 0;
    for (int i=3; i>=0; i--) {
        if (team[i+1].id == 0 && team[i].id != 0) {
            clonePet(&team[i], &team[i+1]);
            emptyPet(&team[i]);
            shuffled = 1;
            printf(">>> shuffling %d to %d\n", i, i+1);
        }
    }

    return shuffled;
}

int shuffleLeftOnce(PetTeam team) {
    int shuffled = 0;
    for (int i=1; i<=4; i++) {
        if (team[i-1].id == 0  && team[i].id != 0) {
            clonePet(&team[i], &team[i-1]);
            emptyPet(&team[i]);
            shuffled = 1;
        }
    }

    return shuffled;
}

int shuffleRight(PetTeam team) {
    int shuffled = 0;
    while (shuffleRightOnce(team) == 1) {
        shuffled = 1;
    }
    return shuffled;
}

int shuffleRightUntilPet(PetTeam team) {
    int shuffled = 0;

    if (team[4].id > 0) {
        return 2;
    }

    while (shuffleRightOnce(team) == 1) {
        shuffled = 1;
        if (team[4].id > 0) {
            return 2;
        }
    }
    return shuffled;
}

int shuffleLeftUntilPet(PetTeam team) {
    int shuffled = 0;

    if (team[0].id > 0) {
        return 2;
    }

    while (shuffleLeftOnce(team) == 1) {
        shuffled = 1;
        if (team[0].id > 0) {
            return 2;
        }
    }
    return shuffled;
}

int shuffleRightUntilEmpty(PetTeam team) {
    int shuffled = 0;

    if (team[4].id == 0) {
        return 2;
    }

    while (shuffleRightOnce(team) == 1) {
        shuffled = 1;
        if (team[4].id == 0) {
            return 2;
        }
    }
    return shuffled;
}

int shuffleLeftUntilEmpty(PetTeam team) {
    int shuffled = 0;

    if (team[0].id == 0) {
        return 2;
    }

    while (shuffleLeftOnce(team) == 1) {
        shuffled = 1;
        if (team[0].id == 0) {
            return 2;
        }
    }
    return shuffled;
}

int getPetUsOrThem(PetTeam us, PetTeam them, struct Pet *pet) {
    for (int i=0; i<=4;i++) {
        if (&us[i] == pet) {
            return 0;
        }
        if (&them[i] == pet) {
            return 1;
        }
    }
}

int damagePet(int usOrThem, PetTeam us, PetTeam them, PetTeam store, struct Pet *attacker, struct Pet *target, int damage) {
    if (target->heldItem == Melon.id) {
        printf("Melon used.\n");
        target->heldItem = 0;
        damage -= 20;
    }

    if (target->heldItem == Garlic.id) {
        printf("Garlic used.\n");
        damage -= 2;
    }

    if (target->heldItem == Coconut.id) {
        printf("Coconut used.\n");
        damage = 0;
        target->heldItem = 0;
    }

    if (attacker->heldItem == Steak.id) {
        printf("Steak used.\n");
        damage += 20;
        attacker->heldItem = 0;
    }

    if (damage > 0) {
        if (attacker->heldItem == Peanuts.id) {
            damage = target->health;
            attacker->heldItem = 0;
        }
        if (attacker->heldItem == MeatBone.id) {
            damage += 3;
        }
        target->health -= damage;
        target->hurt++;
    }

    return isDead(target);
}

void printPet(struct Pet * pet) {
    const struct PetText * text = getPetTextByID(pet->id);
    if ((text->name) == 0) {
        printf("Unknown Pet!! Something is wrong %d", pet->id);
        return;
    }
    printf("%s %d/%d @ Lvl %d (%d experience)\n", *text->name, pet->attack, pet->health, expToLevel(pet->experience), pet->experience);
}

char* serializePet(struct Pet pet) {
    char* serialized;
    int item = pet.heldItem;
    if (item > 100) {
        item -= 100;
    }
    sprintf(serialized, "%02d%02d%d%02d%02d", pet.id, item, pet.experience, pet.attack, pet.health);
    return serialized;
}

void deserializePet(int num, struct Pet * dest) {
    int attack,defence,id,heldItem,experience;
    int defenseOffset,attackOffset,experienceOffset,heldItemOffset;

    defence = num % 100;
    defenseOffset = (defence * 1);
    attack = ((num % 10000) - defenseOffset) / 100;
    attackOffset = (attack * 100);
    experience = ((num % 100000) - attackOffset - defenseOffset) / 10000;
    experienceOffset = experience * 10000;
    heldItem = ((num % 10000000) - attackOffset - defenseOffset - experienceOffset) / 100000;
    heldItemOffset = heldItem * 100000;
    id = (num - attackOffset -defenseOffset - experienceOffset - heldItemOffset) / 10000000;

    emptyPet(dest);
    dest->id = id;
    dest->attack = attack;
    dest->health = defence;
    dest->heldItem = heldItem;
    dest->experience = experience;
    printPet(dest);
}

struct Pet * getRandomPetFromTier(int tier) {
    if (tier == 6) {
        return tier6Pets[rand() % tier6PetsFullness];
    }

    if (tier == 5) {
        return tier5Pets[rand() % tier5PetsFullness];
    }

    if (tier == 4) {
        return tier4Pets[rand() % tier4PetsFullness];
    }

    if (tier == 3) {
        return tier3Pets[rand() % tier3PetsFullness];
    }

    if (tier == 2) {
        return tier2Pets[rand() % tier2PetsFullness];
    }

    return tier1Pets[rand() % tier1PetsFullness];
}

struct Pet * getRandomPetFromNextTier(int turn) {
    if (turn > 8) {
        return tier6Pets[rand() % tier6PetsFullness];
    }
    if (turn > 6) {
        return tier5Pets[rand() % tier5PetsFullness];
    }
    if (turn > 4) {
        return tier4Pets[rand() % tier4PetsFullness];
    }
    if (turn > 2) {
        return tier3Pets[rand() % tier3PetsFullness];
    }
    return tier2Pets[rand() % tier2PetsFullness];
}

struct Pet * getIndexedPetFromTier(int index) {
    if (index < tier1PetsFullness) {
        return tier1Pets[index];
    }
    index -= tier1PetsFullness;
    if (index < tier2PetsFullness) {
        return tier2Pets[index];
    }
    index -= tier2PetsFullness;
    if (index < tier3PetsFullness) {
        return tier3Pets[index];
    }
    index -= tier3PetsFullness;
    if (index < tier4PetsFullness) {
        return tier4Pets[index];
    }
    index -= tier4PetsFullness;
    if (index < tier5PetsFullness) {
        return tier5Pets[index];
    }
    index -= tier5PetsFullness;
    return tier6Pets[index];
}

struct Pet * getIndexedFoodFromTier(int index) {
    if (index < tier1FoodFullness) {
        return tier1Foods[index];
    }
    index -= tier1FoodFullness;
    if (index < tier2FoodFullness) {
        return tier2Foods[index];
    }
    index -= tier2FoodFullness;
    if (index < tier3FoodFullness) {
        return tier3Foods[index];
    }
    index -= tier3FoodFullness;
    if (index < tier4FoodFullness) {
        return tier4Foods[index];
    }
    index -= tier4FoodFullness;
    if (index < tier5FoodFullness) {
        return tier5Foods[index];
    }
    index -= tier5FoodFullness;
    return tier6Foods[index];
}

void randomizeStoreViaTurn(int turn, int initialSet, PetTeam dest, PetTeam frozenTeam) {
    int petsInPlay = 0;
    int foodInPlay = 0;
    int petToPlace = 0;
    int foodToPlace = 0;

    if (turn > 0) {
        petsInPlay += tier1PetsFullness;
        foodInPlay += tier1FoodFullness;
        // 3 pets, 1 food
        petToPlace = 3;
        foodToPlace = 1;
    }
    if (turn > 2) {
        petsInPlay += tier2PetsFullness;
        foodInPlay += tier2FoodFullness;
        petToPlace = 3;
        foodToPlace = 2;
        // 3 pets, 2 food
    }
    if (turn > 4) {
        petsInPlay += tier3PetsFullness;
        foodInPlay += tier3FoodFullness;
        petToPlace = 4;
        foodToPlace = 2;
        // 4 pets, 2 food
    }
    if (turn > 6) {
        petsInPlay += tier4PetsFullness;
        foodInPlay += tier4FoodFullness;
        petToPlace = 4;
        foodToPlace = 2;
        // 4 pets, 2 food
    }
    if (turn > 8) {
        petsInPlay += tier5PetsFullness;
        foodInPlay += tier5FoodFullness;
        petToPlace = 5;
        foodToPlace = 2;
        // 5 pets, 2 food
    }
    if (turn > 10) {
        petsInPlay += tier6PetsFullness;
        foodInPlay += tier6FoodFullness;
        petToPlace = 5;
        foodToPlace = 2;
        // 5 pets, 2 food
    }

    for (int i=0; i< 7;i++) {
        if (!isFrozen(i)) {
            struct Pet *randomPet;
            if (i < petToPlace) {
                randomPet = getIndexedPetFromTier(rand() % petsInPlay);
                clonePet(randomPet, &dest[i]);
            } else if (i >= (7 - foodToPlace)) {
                randomPet = getIndexedFoodFromTier(rand() % foodInPlay);
                clonePet(randomPet, &dest[i]);
            } else {
                emptyPet(&dest[i]);
            }
            if (dest[i].cost == 0) {
                dest[i].cost = -1;
            }

            if (rand() % 10000 == 1) {
                clonePet(&Sloth, &dest[i]);
            }
        } else {
//            clonePet(&frozenTeam[i], &dest[i]);
        }
    }
}

/*
 * Game state
 */
int bank=0;
int canBoost=0;
int turn=0;
int wins=0;
int hearts=0;

void addCanBoost(int i) {
    canBoost += i;
}

int getCanBoost() {
    return canBoost;
}

void resetCanBoost() {
    canBoost = 10;
}

void resetBankForTurn() {
    bank = 10;
}

void resetTurn() {
    turn = 0;
}

int getTurn() {
    return turn;
}

int addTurn() {
    turn += 1;
    return turn;
}

void addBankMoney(int i) {
    bank += i;
}

int getBankMoney() {
    return bank;
}

void addLoss() {
    hearts -= 1;
}
void addWin() {
    wins += 1;
}
int getWins() {
    return wins;
}
int getHearts() {
    return hearts;
}

int spendBankMoney(int i) {
    if (bank < i) {
        return 0;
    } else {
        bank -= i;
        return 1;
    }
}

void resetGame() {
    resetCanBoost();
    resetBankForTurn();
    resetTurn();
    hearts=5;
    wins=0;
}
