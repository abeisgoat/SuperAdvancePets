
//{{BLOCK(pizza)

//======================================================================
//
//	pizza, 16x16@4, 
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

#ifndef GRIT_PIZZA_H
#define GRIT_PIZZA_H

#define pizzaTilesLen 160
extern const unsigned int pizzaTiles[40];

#define pizzaMapLen 8
extern const unsigned short pizzaMap[4];

#define pizzaPalLen 512
extern const unsigned short pizzaPal[256];

#endif // GRIT_PIZZA_H

//}}BLOCK(pizza)
