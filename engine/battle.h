int battle();
int prepareEngine();
int prepareTeams(int friendly[5], int enemies[5]);
struct Pet * getPlayerTeamPet(int index);
struct Pet * getEnemyTeamPet(int index);
const struct PetText * getPlayerTeamPetText(int index);
const struct PetText * getEnemyTeamPetText(int index);