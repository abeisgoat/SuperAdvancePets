int battle();
void prepareEngine();
//void prepareTeams(int friendly[5], int enemies[5]);
void forceStore(int store[7]);
struct Pet * getPlayerTeamPet(int index);
struct Pet * getEnemyTeamPet(int index);
const struct PetText * getPlayerTeamPetText(int index);
const struct PetText * getEnemyTeamPetText(int index);
int shuffleForward();
void shuffleTeamsForward();
struct Pet * getPetByPin(int pin);
int buyItemAtPosition(int index);
int buyAssignItemAtPosition(int index, int target);
void randomizeStore();
void backupTeam();
void restoreTeam();
void endTurn();
int getPetCost(struct Pet * pet);
void sellPet(int playerIndex);
int getLastResult();
void freeze(int i);
void unfreeze(int i);
int isFrozen(int i);
void resolveTriggers();
void summonPet(struct Pet * src, struct Pet * dest);
void stackPets(struct Pet * pet, struct Pet * other);
int postBuyPet(struct Pet * pet);
void postSummonPet(struct Pet * pet);
int getFoodMultiple();
int nextTurn();
void postNextTurn();
void preparePlayerTeam(int friendly[5]);
void prepareEnemyTeam(int enemies[5]);
void seed();