
//{{BLOCK(snake)

//======================================================================
//
//	snake, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 160 + 8 = 168
//
//	Time-stamp: 2023-05-09, 15:00:21
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.6
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_SNAKE_H
#define GRIT_SNAKE_H

#define snakeTilesLen 160
extern const unsigned int snakeTiles[40];

#define snakeMapLen 8
extern const unsigned short snakeMap[4];

#endif // GRIT_SNAKE_H

//}}BLOCK(snake)
