/* system.cpp - contains hardware init info */

#include "app.h"

void PSX_App::init(const u_int w, const u_int h)
{
    screen_width  = w;
    screen_height = h;

    bgcolor[0] = 50; // r
    bgcolor[1] = 50; // g
    bgcolor[2] = 50; // b

    if (*(char *)0xbfc7ff52=='E') 
        SetVideoMode(MODE_PAL);
    else 
        SetVideoMode(MODE_NTSC); // within the BIOS, if the address 0xBFC7FF52 equals 'E', set it as PAL (1). Otherwise, set it as NTSC (0)

    /* interlacing must be off if the resolution is 640,480
     * it also means that we don't have room to double buffer */
    if( h == 480 ) {
        GsInitGraph(screen_width, screen_height, GsNONINTER|GsOFSGPU, 1, 0); // set the graphics mode resolutions. You may also try using 'GsNONINTER' (read LIBOVR46.PDF in PSYQ/DOCS for detailed information)
        GsDefDispBuff(0, 0, 0, 0); // set the top left coordinates of the two buffers in video memory
    }
    else {
        GsInitGraph(w, h, GsINTER|GsOFSGPU, 1, 0); // set the graphics mode resolutions. You may also try using 'GsNONINTER' (read LIBOVR46.PDF in PSYQ/DOCS for detailed information)
        GsDefDispBuff(0, 0, 0, h); // set the top left coordinates of the two buffers in video memory
    }

	// init the ordering tables
	myOT[0].length = OT_LENGTH;
	myOT[1].length = OT_LENGTH;
	myOT[0].org = myOT_TAG[0];
	myOT[1].org = myOT_TAG[1];

	GsClearOt(0,0,&myOT[0]);
	GsClearOt(0,0,&myOT[1]);
	
	/* load the bios font */
	FntLoad(960, 256); // load bios font
    SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); //x,y, max length x,y,
                                                 // auto bg clear, max chars

	return;
}

void PSX_App::drawFrame(void)
{
	FntFlush(-1); // refresh the font
	CurrentBuffer=GsGetActiveBuff(); // get the current buffer
	GsSetWorkBase((PACKET*)GPUPacketArea[CurrentBuffer]); // setup the packet workbase
	GsClearOt(0,0,&myOT[CurrentBuffer]); // clear the ordering table
	DrawSync(0); // wait for all drawing to finish
	VSync(0); // wait for v_blank interrupt
	GsSwapDispBuff(); // flip the double buffers
	GsSortClear(bgcolor[0],
                bgcolor[1],
                bgcolor[2],
                &myOT[CurrentBuffer]); // clear the ordering table with a background color.

	GsDrawOt(&myOT[CurrentBuffer]); // Draw the ordering table for the CurrentBuffer

    return;
}
