
//{{BLOCK(rabbit)

//======================================================================
//
//	rabbit, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:33
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_RABBIT_H
#define GRIT_RABBIT_H

#define rabbitTilesLen 160
extern const unsigned int rabbitTiles[40];

#define rabbitMapLen 8
extern const unsigned short rabbitMap[4];

#define rabbitPalLen 512
extern const unsigned short rabbitPal[256];

#endif // GRIT_RABBIT_H

//}}BLOCK(rabbit)
