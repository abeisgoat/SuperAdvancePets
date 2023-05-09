
//{{BLOCK(duck)

//======================================================================
//
//	duck, 16x16@4, 
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

#ifndef GRIT_DUCK_H
#define GRIT_DUCK_H

#define duckTilesLen 160
extern const unsigned int duckTiles[40];

#define duckMapLen 8
extern const unsigned short duckMap[4];

#define duckPalLen 512
extern const unsigned short duckPal[256];

#endif // GRIT_DUCK_H

//}}BLOCK(duck)
