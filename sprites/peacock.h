
//{{BLOCK(peacock)

//======================================================================
//
//	peacock, 16x16@4, 
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

#ifndef GRIT_PEACOCK_H
#define GRIT_PEACOCK_H

#define peacockTilesLen 160
extern const unsigned int peacockTiles[40];

#define peacockMapLen 8
extern const unsigned short peacockMap[4];

#define peacockPalLen 512
extern const unsigned short peacockPal[256];

#endif // GRIT_PEACOCK_H

//}}BLOCK(peacock)
