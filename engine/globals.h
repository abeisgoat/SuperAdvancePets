#ifndef GLOBAL_H
#define GLOBAL_H
#include "pets.h"

struct Pet * randomOtherTeamMember(PetTeam team, struct Pet * exclude);
void registerPet(int petId, const struct Pet * pet, const struct PetText * petText);
void registerFood(int petId, const struct Pet * pet, const struct PetText * petText);
struct Pet * getPetByID(int petId);
const struct PetText * getPetTextByID(int petId);
struct Pet * spawnPet(int petId, struct Pet * dest);
struct Pet * emptyPet(struct Pet * dest);
struct Pet * clonePet(struct Pet * src, struct Pet * dest);
int getPetAttack(struct Pet *pet);
int getPetHealth(struct Pet *pet);
int isDead(struct Pet *pet);
void damagePet(struct Pet *pet, int damage);
int getLastEnemyTeamPosition(int usOrThem, PetTeam us, PetTeam them);
int petPosition(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet);
struct Pet * getPetByPosition(int usOrThem, PetTeam us, PetTeam them, int pos);
int storePosition(PetTeam store, struct Pet *pet);
int expToLevel(int exp);
void deserializePet(int petId, struct Pet * dest);
struct Pet * getPlayerFighter(PetTeam playerTeam);
struct Pet * getEnemyFighter(PetTeam enemyTeam);

#endif