
//{{BLOCK(milk)

//======================================================================
//
//	milk, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 3 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 96 + 8 = 616
//
//	Time-stamp: 2023-05-09, 13:06:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MILK_H
#define GRIT_MILK_H

#define milkTilesLen 96
extern const unsigned int milkTiles[24];

#define milkMapLen 8
extern const unsigned short milkMap[4];

#define milkPalLen 512
extern const unsigned short milkPal[256];

#endif // GRIT_MILK_H

//}}BLOCK(milk)
