
//{{BLOCK(tiger)

//======================================================================
//
//	tiger, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_TIGER_H
#define GRIT_TIGER_H

#define tigerTilesLen 160
extern const unsigned int tigerTiles[40];

#define tigerMapLen 8
extern const unsigned short tigerMap[4];

#define tigerPalLen 512
extern const unsigned short tigerPal[256];

#endif // GRIT_TIGER_H

//}}BLOCK(tiger)
