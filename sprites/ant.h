
//{{BLOCK(ant)

//======================================================================
//
//	ant, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_ANT_H
#define GRIT_ANT_H

#define antTilesLen 160
extern const unsigned int antTiles[40];

#define antMapLen 8
extern const unsigned short antMap[4];

#define antPalLen 512
extern const unsigned short antPal[256];

#endif // GRIT_ANT_H

//}}BLOCK(ant)
