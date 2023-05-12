
//{{BLOCK(can)

//======================================================================
//
//	can, 16x16@8, 
//	Transparent color : FF,AA,FF
//	+ 3 tiles (t|f|p reduced) not compressed
//	+ regular map (flat), not compressed, 2x2 
//	Total size: 192 + 8 = 200
//
//	Time-stamp: 2023-05-11, 22:29:05
//	Exported by Cearn's GBA Image Transmogrifier, v0.9.2
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

const unsigned int canTiles[48] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x01010101,0x01000000,0x07070707,
	0x08010000,0x07070707,0x18010000,0x08080808,0x18010000,0x18181818,0x18010000,0x19191818,
	0x03010000,0x14191803,0x03010000,0x14190303,0x03010000,0x14190303,0x18010000,0x19190318,
	0x18010000,0x18181818,0x08010000,0x18181818,0x01000000,0x08080808,0x00000000,0x01010101,
};

const unsigned short canMap[4] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x0001,0x0401,0x0002,0x1402,
};

//}}BLOCK(can)
