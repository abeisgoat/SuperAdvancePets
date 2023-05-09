
//{{BLOCK(steak)

//======================================================================
//
//	steak, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 4 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 128 + 8 = 648
//
//	Time-stamp: 2023-05-09, 13:06:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_STEAK_H
#define GRIT_STEAK_H

#define steakTilesLen 128
extern const unsigned int steakTiles[32];

#define steakMapLen 8
extern const unsigned short steakMap[4];

#define steakPalLen 512
extern const unsigned short steakPal[256];

#endif // GRIT_STEAK_H

//}}BLOCK(steak)
