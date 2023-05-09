
//{{BLOCK(garlic)

//======================================================================
//
//	garlic, 16x16@4, 
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

#ifndef GRIT_GARLIC_H
#define GRIT_GARLIC_H

#define garlicTilesLen 160
extern const unsigned int garlicTiles[40];

#define garlicMapLen 8
extern const unsigned short garlicMap[4];

#define garlicPalLen 512
extern const unsigned short garlicPal[256];

#endif // GRIT_GARLIC_H

//}}BLOCK(garlic)
