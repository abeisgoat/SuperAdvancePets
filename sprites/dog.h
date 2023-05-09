
//{{BLOCK(dog)

//======================================================================
//
//	dog, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_DOG_H
#define GRIT_DOG_H

#define dogTilesLen 160
extern const unsigned int dogTiles[40];

#define dogMapLen 8
extern const unsigned short dogMap[4];

#define dogPalLen 512
extern const unsigned short dogPal[256];

#endif // GRIT_DOG_H

//}}BLOCK(dog)
