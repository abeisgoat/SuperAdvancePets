
//{{BLOCK(badger)

//======================================================================
//
//	badger, 16x16@4, 
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

#ifndef GRIT_BADGER_H
#define GRIT_BADGER_H

#define badgerTilesLen 160
extern const unsigned int badgerTiles[40];

#define badgerMapLen 8
extern const unsigned short badgerMap[4];

#define badgerPalLen 512
extern const unsigned short badgerPal[256];

#endif // GRIT_BADGER_H

//}}BLOCK(badger)
