
//{{BLOCK(flamingo)

//======================================================================
//
//	flamingo, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:31
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_FLAMINGO_H
#define GRIT_FLAMINGO_H

#define flamingoTilesLen 160
extern const unsigned int flamingoTiles[40];

#define flamingoMapLen 8
extern const unsigned short flamingoMap[4];

#define flamingoPalLen 512
extern const unsigned short flamingoPal[256];

#endif // GRIT_FLAMINGO_H

//}}BLOCK(flamingo)
