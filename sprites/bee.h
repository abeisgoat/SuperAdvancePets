
//{{BLOCK(bee)

//======================================================================
//
//	bee, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_BEE_H
#define GRIT_BEE_H

#define beeTilesLen 160
extern const unsigned int beeTiles[40];

#define beeMapLen 8
extern const unsigned short beeMap[4];

#define beePalLen 512
extern const unsigned short beePal[256];

#endif // GRIT_BEE_H

//}}BLOCK(bee)
