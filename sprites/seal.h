
//{{BLOCK(seal)

//======================================================================
//
//	seal, 16x16@4, 
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

#ifndef GRIT_SEAL_H
#define GRIT_SEAL_H

#define sealTilesLen 160
extern const unsigned int sealTiles[40];

#define sealMapLen 8
extern const unsigned short sealMap[4];

#define sealPalLen 512
extern const unsigned short sealPal[256];

#endif // GRIT_SEAL_H

//}}BLOCK(seal)
