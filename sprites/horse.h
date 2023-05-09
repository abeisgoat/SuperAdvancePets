
//{{BLOCK(horse)

//======================================================================
//
//	horse, 16x16@4, 
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

#ifndef GRIT_HORSE_H
#define GRIT_HORSE_H

#define horseTilesLen 160
extern const unsigned int horseTiles[40];

#define horseMapLen 8
extern const unsigned short horseMap[4];

#define horsePalLen 512
extern const unsigned short horsePal[256];

#endif // GRIT_HORSE_H

//}}BLOCK(horse)
