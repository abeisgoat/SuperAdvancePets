
//{{BLOCK(cow)

//======================================================================
//
//	cow, 16x16@4, 
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

#ifndef GRIT_COW_H
#define GRIT_COW_H

#define cowTilesLen 160
extern const unsigned int cowTiles[40];

#define cowMapLen 8
extern const unsigned short cowMap[4];

#define cowPalLen 512
extern const unsigned short cowPal[256];

#endif // GRIT_COW_H

//}}BLOCK(cow)
