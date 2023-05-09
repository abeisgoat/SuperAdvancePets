
//{{BLOCK(deer)

//======================================================================
//
//	deer, 16x16@4, 
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

#ifndef GRIT_DEER_H
#define GRIT_DEER_H

#define deerTilesLen 160
extern const unsigned int deerTiles[40];

#define deerMapLen 8
extern const unsigned short deerMap[4];

#define deerPalLen 512
extern const unsigned short deerPal[256];

#endif // GRIT_DEER_H

//}}BLOCK(deer)
