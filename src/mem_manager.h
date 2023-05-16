//
// Created by abe on 5/9/23.
//

#ifndef SUPERADVANCEPETS_PET_DATA_H
#define SUPERADVANCEPETS_PET_DATA_H

#include "mem_manager_enums.h"

int usePetGfxMem(int id);
int unusePetGfxMem(int id);

int getMemForNumber(int num);
enum UIElements32x16;
int getMemFor32x16UI(enum UIElements32x16 element);
int getMemFor16x16UI(enum UIElements16x16 element);
int getBannerTopForLvl(int lvl);
int getBannerBottomForExp(int exp);
int getMemForUIIcon(enum UIIcon icon);
int getMemForCursor(int frame);
void initSpriteMem();
int loadLabel(int upperOrLower, enum UILabels label);

#endif //SUPERADVANCEPETS_PET_DATA_H
