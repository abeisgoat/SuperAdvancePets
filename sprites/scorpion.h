
//{{BLOCK(scorpion)

//======================================================================
//
//	scorpion, 16x16@4, 
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

#ifndef GRIT_SCORPION_H
#define GRIT_SCORPION_H

#define scorpionTilesLen 160
extern const unsigned int scorpionTiles[40];

#define scorpionMapLen 8
extern const unsigned short scorpionMap[4];

#define scorpionPalLen 512
extern const unsigned short scorpionPal[256];

#endif // GRIT_SCORPION_H

//}}BLOCK(scorpion)
