
//{{BLOCK(rooster)

//======================================================================
//
//	rooster, 16x16@4, 
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

#ifndef GRIT_ROOSTER_H
#define GRIT_ROOSTER_H

#define roosterTilesLen 160
extern const unsigned int roosterTiles[40];

#define roosterMapLen 8
extern const unsigned short roosterMap[4];

#define roosterPalLen 512
extern const unsigned short roosterPal[256];

#endif // GRIT_ROOSTER_H

//}}BLOCK(rooster)
