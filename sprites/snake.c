
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

const unsigned int snakeTiles[40] __attribute__((aligned(4)))=
{

	0x01110000,0x14441000,0x44414100,0x41444100,0x4444BB10,0x44441BB1,0x44410110,0x39491000,
	0x00000000,0x00000000,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,0x00000001,
	0x39449100,0x14444910,0x13444910,0x99444100,0x49444100,0x44441000,0x33110000,0x11000000,
	0x00000111,0x00001441,0x01114444,0x14414499,0x01444444,0x00114444,0x00001113,0x00000001,
};

const unsigned short snakeMap[4] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x0004,
};

//}}BLOCK(snake)
