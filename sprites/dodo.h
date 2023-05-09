
//{{BLOCK(dodo)

//======================================================================
//
//	dodo, 16x16@4, 
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

#ifndef GRIT_DODO_H
#define GRIT_DODO_H

#define dodoTilesLen 160
extern const unsigned int dodoTiles[40];

#define dodoMapLen 8
extern const unsigned short dodoMap[4];

#define dodoPalLen 512
extern const unsigned short dodoPal[256];

#endif // GRIT_DODO_H

//}}BLOCK(dodo)
