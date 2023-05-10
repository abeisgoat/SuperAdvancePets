
//{{BLOCK(ram)

//======================================================================
//
//	ram, 16x16@4, 
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

const unsigned int ramTiles[40] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,0x00000000,
	0x00000000,0x11111100,0x36663311,0x16663331,0x33999131,0x39191931,0x39999961,0x19919661,
	0x00000000,0x00000001,0x00000133,0x00011333,0x00161331,0x01661331,0x16666133,0x16666611,
	0x66999661,0x66666661,0x66666611,0x66661100,0x66619100,0x99199100,0x99111000,0x11000000,
	0x16666666,0x16666666,0x01666666,0x01966666,0x01991966,0x01991911,0x00110111,0x00000001,
};

const unsigned short ramMap[4] __attribute__((aligned(4))) __attribute__((visibility("hidden")))=
{
	0x0001,0x0002,0x0003,0x1004,
};

//}}BLOCK(ram)
