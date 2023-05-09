
//{{BLOCK(cheetah)

//======================================================================
//
//	cheetah, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ palette 256 entries, not compressed
//	+ 4 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 512 + 128 + 8 = 648
//
//	Time-stamp: 2023-05-09, 13:06:30
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_CHEETAH_H
#define GRIT_CHEETAH_H

#define cheetahTilesLen 128
extern const unsigned int cheetahTiles[32];

#define cheetahMapLen 8
extern const unsigned short cheetahMap[4];

#define cheetahPalLen 512
extern const unsigned short cheetahPal[256];

#endif // GRIT_CHEETAH_H

//}}BLOCK(cheetah)
