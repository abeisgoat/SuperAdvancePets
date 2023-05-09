
//{{BLOCK(bad_rat)

//======================================================================
//
//	bad_rat, 16x16@4, 
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

#ifndef GRIT_BAD_RAT_H
#define GRIT_BAD_RAT_H

#define bad_ratTilesLen 160
extern const unsigned int bad_ratTiles[40];

#define bad_ratMapLen 8
extern const unsigned short bad_ratMap[4];

#define bad_ratPalLen 512
extern const unsigned short bad_ratPal[256];

#endif // GRIT_BAD_RAT_H

//}}BLOCK(bad_rat)
