/* source file for app class */

#include "app.h"

// constructor
PSX_App::PSX_App()
{

    __ramsize    = 0x00200000; // force 2MB of RAM
    __stacksize  = 0x00004000; // force 16KB of stack

    CurrentBuffer = 0; // keep track of the current buffer
}

/* here is where most of your coding should go */
void PSX_App::run(void)
{

    FntLoad(960, 256); // load bios font
    SetDumpFnt(FntOpen(5, 20, 320, 240, 0, 512)); //x,y, max length x,y,
                                                 // auto bg clear, max chars
	
	/* the main loop of the program */	
    while(1)
    {

		/* DRAWING GOES HERE! */
		FntPrint("Hello World!\n");
		
		/* args - x0, y0, x1, y1, r,g,b */
		drawLine(100, 400, 200, 200,
		         255, 0, 0);
		
		/* draw 10 random color pixels 
		 * drawPixel args - x,y, r,g,b */
		for(int i=300; i<=400; i+=10){
			for(int j=10; j<=110; j+= 10){
				drawPixel(i, j, rand()%255, rand()%255, rand()%255);
			}
		}
		
		/* draw a blue rectangle 
		 * args - top left x, top left y, bottom right x, bottom right y,
		 *        r,g,b  */
		drawRect(400, 200, 600, 400,
		         0, 0, 255);

        drawFrame(); // draw the frame
    }

    return;
}

