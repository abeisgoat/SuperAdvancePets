#ifndef GLOBAL_H
#define GLOBAL_H
#include "pets.h"

struct Pet * randomOtherTeamMember(PetTeam team, struct Pet * exclude);
void registerPet(int petId, const struct Pet * pet, const struct PetText * petText);
void registerFood(int petId, const struct Pet * pet, const struct PetText * petText);
struct Pet * getPetByID(int petId);
const struct PetText * getPetTextByID(int petId);
void emptyPet(struct Pet * dest);
void swapPets(struct Pet * src, struct Pet * dest);
void clonePet(struct Pet * src, struct Pet * dest);
int getPetAttack(struct Pet *pet);
int getPetHealth(struct Pet *pet);
int isDead(struct Pet *pet);
int isHurt(struct Pet *pet);
int damagePet(int usOrThem, PetTeam us, PetTeam them, PetTeam store, struct Pet *attacker, struct Pet *target, int damage);
int getLastEnemyTeamPosition(int usOrThem, PetTeam us, PetTeam them);
int petPosition(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet);
struct Pet * getPetByPosition(int usOrThem, PetTeam us, PetTeam them, int pos);
void randomizeStoreViaTurn(int turn, int initialSet, PetTeam dest, PetTeam frozenTeam);
char* serializePet(struct Pet pet);
int storePosition(PetTeam store, struct Pet *pet);
int expToLevel(int exp);
int expToRemainingToLevelUp(int exp);
void deserializePet(int petId, struct Pet * dest);
struct Pet * getRightMostPet(PetTeam team);
struct Pet * getLeftMostPet(PetTeam team);
int shuffleRightOnce(PetTeam team);
int shuffleLeftOnce(PetTeam team);
int shuffleRight(PetTeam team);
int shuffleLeft(PetTeam team);
int shuffleRightUntilPet(PetTeam team);
int shuffleLeftUntilPet(PetTeam team);
int shuffleRightUntilEmpty(PetTeam team);
int shuffleLeftUntilEmpty(PetTeam team);
struct Pet * getFriendByPosition(int usOrThem, PetTeam us, int pos);
void resetBankForTurn();
void addBankMoney(int i);
int spendBankMoney(int i);
void randomizeStoreViaTurn(int turn, int initialSet, PetTeam dest, PetTeam frozenTeam);
int getBankMoney();
int getPetUsOrThem(PetTeam us, PetTeam them, struct Pet *pet);
void printPet(struct Pet * pet);
void addCanBoost(int i);
int getCanBoost();
void resetCanBoost();
void resetGame();
int getTurn();
int addTurn();
void addLoss();
void addWin();
int getWins();
int getHearts();
int isItem(int id);
#endif