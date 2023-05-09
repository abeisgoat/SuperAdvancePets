
//{{BLOCK(parrot)

//======================================================================
//
//	parrot, 16x16@4, 
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

#ifndef GRIT_PARROT_H
#define GRIT_PARROT_H

#define parrotTilesLen 160
extern const unsigned int parrotTiles[40];

#define parrotMapLen 8
extern const unsigned short parrotMap[4];

#define parrotPalLen 512
extern const unsigned short parrotPal[256];

#endif // GRIT_PARROT_H

//}}BLOCK(parrot)
