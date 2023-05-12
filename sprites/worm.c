
//{{BLOCK(worm)

//======================================================================
//
//	worm, 16x16@8, 
//	Transparent color : FF,AA,FF
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 320 + 8 = 328
//
//	Time-stamp: 2023-05-11, 22:29:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int wormTiles[80] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x01000000,0x01010100,0x01000001,0x19191901,0x00010119,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x01010100,0x00010101,
	0x19191901,0x01012626,0x01191919,0x00010101,0x01192626,0x00000001,0x19192601,0x00000101,
	0x01190101,0x01192619,0x19191901,0x26192619,0x19190100,0x26261901,0x01010000,0x26260100,
	0x00000000,0x26010000,0x00000000,0x01000000,0x00000000,0x00000000,0x00000000,0x00000000,

	0x19010101,0x00010126,0x01000101,0x01011919,0x01010126,0x01011919,0x19261926,0x01011919,
	0x19261926,0x00010126,0x19261901,0x00000101,0x01010100,0x00000001,0x00000000,0x00000000,
};

const unsigned short wormMap[4] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x0001,0x0002,0x0003,0x0004,
};

//}}BLOCK(worm)
