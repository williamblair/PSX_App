/* source file for app class */

#include "app.h"

// constructor
PSX_App::PSX_App()
{

    __ramsize    = 0x00200000; // force 2MB of RAM
    __stacksize  = 0x00004000; // force 16KB of stack

    CurrentBuffer = 0; // keep track of the current buffer
}

void PSX_App::run(void)
{

    FntLoad(960, 256); // load bios font
    SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); //x,y, max length x,y,
                                                 // auto bg clear, max chars

    while(1)
    {

        //FntPrint("Hello World!\n");

	/* DRAWING GOES HERE! */

        drawFrame(); // draw the frame
    }

    return;
}

