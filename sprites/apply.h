
//{{BLOCK(apply)

//======================================================================
//
//	apply, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:29
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_APPLY_H
#define GRIT_APPLY_H

#define applyTilesLen 160
extern const unsigned int applyTiles[40];

#define applyMapLen 8
extern const unsigned short applyMap[4];

#define applyPalLen 512
extern const unsigned short applyPal[256];

#endif // GRIT_APPLY_H

//}}BLOCK(apply)
