
//{{BLOCK(bison)

//======================================================================
//
//	bison, 16x16@4, 
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

#ifndef GRIT_BISON_H
#define GRIT_BISON_H

#define bisonTilesLen 160
extern const unsigned int bisonTiles[40];

#define bisonMapLen 8
extern const unsigned short bisonMap[4];

#define bisonPalLen 512
extern const unsigned short bisonPal[256];

#endif // GRIT_BISON_H

//}}BLOCK(bison)
