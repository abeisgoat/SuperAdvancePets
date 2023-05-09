
//{{BLOCK(ram)

//======================================================================
//
//	ram, 16x16@4, 
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

#ifndef GRIT_RAM_H
#define GRIT_RAM_H

#define ramTilesLen 160
extern const unsigned int ramTiles[40];

#define ramMapLen 8
extern const unsigned short ramMap[4];

#define ramPalLen 512
extern const unsigned short ramPal[256];

#endif // GRIT_RAM_H

//}}BLOCK(ram)
