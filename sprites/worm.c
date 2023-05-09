
//{{BLOCK(worm)

//======================================================================
//
//	worm, 16x16@4, 
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

const unsigned int wormTiles[40] __attribute__((aligned(4)))=
{

	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x10000000,0x10011110,0x01199991,
	0x00000000,0x00000000,0x00000000,0x01111110,0x11669991,0x01111999,0x00011966,0x00119961,
	0x19691911,0x69699991,0x66919910,0x66101100,0x61000000,0x10000000,0x00000000,0x00000000,
	0x01169111,0x11991011,0x11991116,0x11999696,0x01169696,0x00119691,0x00011110,0x00000000,
};

const unsigned short wormMap[4] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x0004,
};

//}}BLOCK(worm)
