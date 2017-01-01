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

    //POLY_F3 tri; // a simple triangle primitive
    //SetPolyF3(&tri); // register the triangle

	//setXY3(&tri, 50, 100, 100, 50, 150, 100); // set 2d coords
	//setRGB0(&tri, 255, 0, 0); // make the triangle red


    while(1)
    {

        //FntPrint("Hello World!\n\nBJ IS HERE!\n");

        //DrawPrim(&tri);
        //DrawPrim(&line);

        /* draw a bunch of rectangles */
        for(int i=0; i<50; i++){
            u_int tlX = rand()%(screen_width-100);
            u_int tlY = rand()%(screen_width-100);
            u_int brX = tlX + rand()%200;
            u_int brY = tlY + rand()%200;
            drawRect(tlX, tlY,
                     brX, brY,
                     rand()%255, rand()%255, rand()%255);
        }


        drawFrame(); // draw the frame
    }

    return;
}

