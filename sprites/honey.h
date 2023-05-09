
//{{BLOCK(honey)

//======================================================================
//
//	honey, 16x16@4, 
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

#ifndef GRIT_HONEY_H
#define GRIT_HONEY_H

#define honeyTilesLen 160
extern const unsigned int honeyTiles[40];

#define honeyMapLen 8
extern const unsigned short honeyMap[4];

#define honeyPalLen 512
extern const unsigned short honeyPal[256];

#endif // GRIT_HONEY_H

//}}BLOCK(honey)
