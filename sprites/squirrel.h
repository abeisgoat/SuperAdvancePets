
//{{BLOCK(squirrel)

//======================================================================
//
//	squirrel, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 160 + 8 = 680
//
//	Time-stamp: 2023-05-09, 13:06:34
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SQUIRREL_H
#define GRIT_SQUIRREL_H

#define squirrelTilesLen 160
extern const unsigned int squirrelTiles[40];

#define squirrelMapLen 8
extern const unsigned short squirrelMap[4];

#define squirrelPalLen 512
extern const unsigned short squirrelPal[256];

#endif // GRIT_SQUIRREL_H

//}}BLOCK(squirrel)
