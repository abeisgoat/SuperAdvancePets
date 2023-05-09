
//{{BLOCK(kangaroo)

//======================================================================
//
//	kangaroo, 16x16@4, 
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

#ifndef GRIT_KANGAROO_H
#define GRIT_KANGAROO_H

#define kangarooTilesLen 160
extern const unsigned int kangarooTiles[40];

#define kangarooMapLen 8
extern const unsigned short kangarooMap[4];

#define kangarooPalLen 512
extern const unsigned short kangarooPal[256];

#endif // GRIT_KANGAROO_H

//}}BLOCK(kangaroo)
