
//{{BLOCK(mushroom)

//======================================================================
//
//	mushroom, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MUSHROOM_H
#define GRIT_MUSHROOM_H

#define mushroomTilesLen 160
extern const unsigned int mushroomTiles[40];

#define mushroomMapLen 8
extern const unsigned short mushroomMap[4];

#define mushroomPalLen 512
extern const unsigned short mushroomPal[256];

#endif // GRIT_MUSHROOM_H

//}}BLOCK(mushroom)
