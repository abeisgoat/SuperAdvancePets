
//{{BLOCK(cat)

//======================================================================
//
//	cat, 16x16@4, 
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

#ifndef GRIT_CAT_H
#define GRIT_CAT_H

#define catTilesLen 160
extern const unsigned int catTiles[40];

#define catMapLen 8
extern const unsigned short catMap[4];

#define catPalLen 512
extern const unsigned short catPal[256];

#endif // GRIT_CAT_H

//}}BLOCK(cat)
