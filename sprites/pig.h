
//{{BLOCK(pig)

//======================================================================
//
//	pig, 16x16@4, 
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

#ifndef GRIT_PIG_H
#define GRIT_PIG_H

#define pigTilesLen 160
extern const unsigned int pigTiles[40];

#define pigMapLen 8
extern const unsigned short pigMap[4];

#define pigPalLen 512
extern const unsigned short pigPal[256];

#endif // GRIT_PIG_H

//}}BLOCK(pig)
