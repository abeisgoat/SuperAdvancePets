
//{{BLOCK(shrimp)

//======================================================================
//
//	shrimp, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SHRIMP_H
#define GRIT_SHRIMP_H

#define shrimpTilesLen 160
extern const unsigned int shrimpTiles[40];

#define shrimpMapLen 8
extern const unsigned short shrimpMap[4];

#define shrimpPalLen 512
extern const unsigned short shrimpPal[256];

#endif // GRIT_SHRIMP_H

//}}BLOCK(shrimp)
