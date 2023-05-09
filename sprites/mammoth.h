
//{{BLOCK(mammoth)

//======================================================================
//
//	mammoth, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:32
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MAMMOTH_H
#define GRIT_MAMMOTH_H

#define mammothTilesLen 160
extern const unsigned int mammothTiles[40];

#define mammothMapLen 8
extern const unsigned short mammothMap[4];

#define mammothPalLen 512
extern const unsigned short mammothPal[256];

#endif // GRIT_MAMMOTH_H

//}}BLOCK(mammoth)
