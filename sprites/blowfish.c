
//{{BLOCK(blowfish)

//======================================================================
//
//	blowfish, 16x16@4, 
//	Transparent color : FF,AA,FF
//	+ 5 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 160 + 8 = 168
//
//	Time-stamp: 2023-05-10, 12:05:26
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int blowfishTiles[40] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x11001000,0xA111A100,0x31313110,0x33333310,0x33331331,0x33333331,
	0x00000000,0x00000000,0x00000000,0x00000101,0x00011A13,0x00161333,0x01663333,0x16633333,
	0xAAAAA111,0xAAAAAAA1,0xAAAAAAA1,0xAAAAA111,0xAAAA1A10,0x1AAA1100,0x1A111000,0x11100000,
	0x166333AA,0x01163AAA,0x01163AAA,0x0016AAAA,0x0001AAAA,0x000011AA,0x000001A1,0x00000010,
};

const unsigned short blowfishMap[4] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x0001,0x0002,0x0003,0x0004,
};

//}}BLOCK(blowfish)
