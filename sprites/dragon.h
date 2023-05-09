
//{{BLOCK(dragon)

//======================================================================
//
//	dragon, 16x16@4, 
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

#ifndef GRIT_DRAGON_H
#define GRIT_DRAGON_H

#define dragonTilesLen 160
extern const unsigned int dragonTiles[40];

#define dragonMapLen 8
extern const unsigned short dragonMap[4];

#define dragonPalLen 512
extern const unsigned short dragonPal[256];

#endif // GRIT_DRAGON_H

//}}BLOCK(dragon)
