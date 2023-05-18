#ifndef SUPERADVANCEPETSCLI_STRUCTS_H
#define SUPERADVANCEPETSCLI_STRUCTS_H
struct PetSprite {
    int worldX;
    int worldY;
    int screenX;
    int screenY;
    int flip;
    int petPin;
    int visiblePet;
    int visibleStats;
    int shortStat;
};
#endif