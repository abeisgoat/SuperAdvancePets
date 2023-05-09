
//{{BLOCK(snail)

//======================================================================
//
//	snail, 16x16@4, 
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

const unsigned int snailTiles[40] __attribute__((aligned(4)))=
{

	0x00000000,0x01111100,0x11999910,0x91919191,0x99999991,0x99919911,0x99999916,0x99999916,
	0x00000000,0x00000000,0x00001111,0x00019999,0x00199999,0x01990099,0x01909909,0x01909909,
	0x99999991,0x99999991,0x91999910,0x99999910,0x99999910,0x99999910,0x99999100,0x11111000,
	0x01909099,0x11909099,0x19990009,0x19099909,0x01900099,0x00199999,0x00011199,0x00000011,
};

const unsigned short snailMap[4] __attribute__((aligned(4)))=
{
	0x0001,0x0002,0x0003,0x2004,
};

//}}BLOCK(snail)
