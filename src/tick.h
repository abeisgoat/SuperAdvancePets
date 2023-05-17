//
// Created by abe on 5/16/23.
//

#ifndef SUPERADVANCEPETSCLI_TICK_H
#define SUPERADVANCEPETSCLI_TICK_H
#include <tonc.h>
OBJ_ATTR * getOAMSprite(int index);
void refreshOAM();
void tickMainLoop();
void tickInit();
void setScene(int scene);
struct PetSprite * getPetSprite(int index);
void updateAnimalSprites();
void screenAnimalSprites();
int getScene();
int getScreenX();

#endif //SUPERADVANCEPETSCLI_TICK_H
