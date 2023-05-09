
//{{BLOCK(beaver)

//======================================================================
//
//	beaver, 16x16@4, 
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

#ifndef GRIT_BEAVER_H
#define GRIT_BEAVER_H

#define beaverTilesLen 160
extern const unsigned int beaverTiles[40];

#define beaverMapLen 8
extern const unsigned short beaverMap[4];

#define beaverPalLen 512
extern const unsigned short beaverPal[256];

#endif // GRIT_BEAVER_H

//}}BLOCK(beaver)
