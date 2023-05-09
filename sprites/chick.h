
//{{BLOCK(chick)

//======================================================================
//
//	chick, 16x16@4, 
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

#ifndef GRIT_CHICK_H
#define GRIT_CHICK_H

#define chickTilesLen 160
extern const unsigned int chickTiles[40];

#define chickMapLen 8
extern const unsigned short chickMap[4];

#define chickPalLen 512
extern const unsigned short chickPal[256];

#endif // GRIT_CHICK_H

//}}BLOCK(chick)
