
//{{BLOCK(cricket)

//======================================================================
//
//	cricket, 16x16@4, 
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

#ifndef GRIT_CRICKET_H
#define GRIT_CRICKET_H

#define cricketTilesLen 160
extern const unsigned int cricketTiles[40];

#define cricketMapLen 8
extern const unsigned short cricketMap[4];

#define cricketPalLen 512
extern const unsigned short cricketPal[256];

#endif // GRIT_CRICKET_H

//}}BLOCK(cricket)
