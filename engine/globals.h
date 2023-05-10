#ifndef GLOBAL_H
#define GLOBAL_H
#include "pets.h"

struct Pet * randomOtherTeamMember(PetTeam team, struct Pet * exclude);
void registerPet(int petId, struct Pet * pet, struct PetText * petText);
struct Pet * getPetByID(int petId);
struct PetText * getPetTextByID(int petId);
struct Pet * spawnPet(int petId, struct Pet * dest);
int getPetAttack(struct Pet *pet);
int getPetDefence(struct Pet *pet);
int isDead(struct Pet *pet);
int petPosition(int usOrThem, PetTeam us, PetTeam them, struct Pet * pet);
int expToLevel(int exp);
void deserializePet(int petId, struct Pet * dest);
#endif