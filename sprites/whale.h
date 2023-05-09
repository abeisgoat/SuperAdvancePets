
//{{BLOCK(whale)

//======================================================================
//
//	whale, 16x16@4, 
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

#ifndef GRIT_WHALE_H
#define GRIT_WHALE_H

#define whaleTilesLen 160
extern const unsigned int whaleTiles[40];

#define whaleMapLen 8
extern const unsigned short whaleMap[4];

#define whalePalLen 512
extern const unsigned short whalePal[256];

#endif // GRIT_WHALE_H

//}}BLOCK(whale)
