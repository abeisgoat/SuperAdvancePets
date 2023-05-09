
//{{BLOCK(can)

//======================================================================
//
//	can, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 3 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 96 + 8 = 616
//
//	Time-stamp: 2023-05-09, 13:06:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CAN_H
#define GRIT_CAN_H

#define canTilesLen 96
extern const unsigned int canTiles[24];

#define canMapLen 8
extern const unsigned short canMap[4];

#define canPalLen 512
extern const unsigned short canPal[256];

#endif // GRIT_CAN_H

//}}BLOCK(can)
