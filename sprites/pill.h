
//{{BLOCK(pill)

//======================================================================
//
//	pill, 16x16@4, 
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

#ifndef GRIT_PILL_H
#define GRIT_PILL_H

#define pillTilesLen 160
extern const unsigned int pillTiles[40];

#define pillMapLen 8
extern const unsigned short pillMap[4];

#define pillPalLen 512
extern const unsigned short pillPal[256];

#endif // GRIT_PILL_H

//}}BLOCK(pill)
