
//{{BLOCK(sheep)

//======================================================================
//
//	sheep, 16x16@4, 
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

#ifndef GRIT_SHEEP_H
#define GRIT_SHEEP_H

#define sheepTilesLen 160
extern const unsigned int sheepTiles[40];

#define sheepMapLen 8
extern const unsigned short sheepMap[4];

#define sheepPalLen 512
extern const unsigned short sheepPal[256];

#endif // GRIT_SHEEP_H

//}}BLOCK(sheep)
